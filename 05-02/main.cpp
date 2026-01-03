#include <Novice.h>
#include <Time.h>
#include <vector>
#include <list>
#include "Unit.h"
#include "Selector.h"
#include "Command.h"
#include "SelectorCommand.h"
#include "UnitCommand.h"
#include "InputManager.h"
#include "InputHandler.h"
#include "CommandHistory.h"
#include "SystemCommand.h"

const char kWindowTitle[] = "LE2B_05_カン_ケンリャン";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	srand((unsigned int)time(nullptr));

	/// ユニットリストの生成
	std::vector<Unit> unitList;
	{
		int unit[5][2];
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 2; j++) {
				if (j == 0)unit[i][j] = rand() % MapWidth;
				if (j == 1)unit[i][j] = rand() % MapHeight;

				if (i > 0) {
					if (unit[i - 1][j] == unit[i][j]) {
						if (unit[i][j] + 1 < MapWidth) {
							unit[i][j]++;
						} else {
							unit[i][j]--;
						}
					}
				}
			}
		}

		for (int i = 0; i < 5; i++) {
			unitList.emplace_back(unit[i][0], unit[i][1], i);
		}
	}

	/// ===========================Selector関連の初期化===========================
	/// Selectorの生成
	Selector* selector = new Selector;
	selector->ReadUnitList(&unitList);

	/// SelectorUnitを作る (借り)
	Unit* selectorUnit = nullptr;

	/// ========================CommandHistory関連の初期化============================
	CommandHistory* commandHistory = new CommandHistory;

	/// ===========================InputHandler関連の初期化===========================
	/// usingInputHandlerを作る (借り、使っているInputHandler)
	InputHandler* usingInputHandler = nullptr;

	/// selectInputHandlerの生成とコマンドの割り当て
	InputHandler* selectInputHandler = new InputHandler;
	selectInputHandler->AssignPressKeyA(new SelectorMoveCommand(selector, -1, 0));
	selectInputHandler->AssignPressKeyD(new SelectorMoveCommand(selector, 1, 0));
	selectInputHandler->AssignPressKeyW(new SelectorMoveCommand(selector, 0, -1));
	selectInputHandler->AssignPressKeyS(new SelectorMoveCommand(selector, 0, 1));
	selectInputHandler->AssignPressKeySpace(new SelectorUnitCommand(selector, selectorUnit));


	/// unitInputHandlerの生成とコマンドの割り当て
	InputHandler* unitInputHandler = new InputHandler;
	unitInputHandler->AssignPressKeyA(new UnitMoveCommand(selectorUnit, -1, 0));
	unitInputHandler->AssignPressKeyD(new UnitMoveCommand(selectorUnit, 1, 0));
	unitInputHandler->AssignPressKeyW(new UnitMoveCommand(selectorUnit, 0, -1));
	unitInputHandler->AssignPressKeyS(new UnitMoveCommand(selectorUnit, 0, 1));
	unitInputHandler->AssignPressKeySpace(new SelectorUnitCommand(selector, selectorUnit));
	unitInputHandler->AssignPressKeyCtrlZ(new UndoCommand(commandHistory));
	unitInputHandler->AssignPressKeyCtrlY(new RedoCommand(commandHistory));

	/// 初期状態はselectInputHandlerを使う
	usingInputHandler = selectInputHandler;


	/// ===========================コマンド関連の初期化===========================
	/// コマンド受け皿
	ICommand* currentCommand = nullptr;



	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// InputManagerの更新
		InputManager::Update();

		///
		/// ↓更新処理ここから
		///

		if (usingInputHandler->HandleInput()) {
			currentCommand = usingInputHandler->HandleInput();
			currentCommand->Exec();

			UndoCommand* undoCmd = dynamic_cast<UndoCommand*>(currentCommand);
			RedoCommand* redoCmd = dynamic_cast<RedoCommand*>(currentCommand);
			SelectorUnitCommand* selectCmd = dynamic_cast<SelectorUnitCommand*>(currentCommand);

			if (selector->GetSelectMode() == SelectMode_MoveUnit &&
				!undoCmd && !redoCmd && !selectCmd) {
				commandHistory->Exec(currentCommand);
			} 
		}

		selector->Update();
		if (selector->GetSelectMode() == SelectMode_SelectUnit &&
			usingInputHandler != selectInputHandler) {
			usingInputHandler = selectInputHandler;
		}

		if (selector->GetSelectMode() == SelectMode_MoveUnit &&
			usingInputHandler != unitInputHandler) {
			usingInputHandler = unitInputHandler;
			commandHistory->Clear();
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		/// マップ線とUIの描画
		for (int i = 1; i <= MapWidth; i++) {
			Novice::DrawLine(i * UnitSize, 0, i * UnitSize, MapHeight * UnitSize, 0xFFFFFFFF);
		}
		for (int i = 1; i <= (MapHeight - 1); i++) {
			Novice::DrawLine(0, i * UnitSize, MapWidth * UnitSize, i * UnitSize, 0xFFFFFFFF);
		}
		/// 文字の黒い背景描画
		Novice::DrawBox(0, MapHeight * UnitSize, 1280, 720 - (MapHeight * UnitSize), 0, 0x000000FF, kFillModeSolid);

		/// 文字の描画
		Novice::ScreenPrintf(10, MapHeight * UnitSize + 5, "WASD||arrow keys: move / space key : change unit mode");
		if (selector->GetSelectMode() == SelectMode_SelectUnit){
			Novice::ScreenPrintf(10, MapHeight * UnitSize + 30, "in Selector Mode, you cannot use the 'Undo' action.");
		} else {
			Novice::ScreenPrintf(10, MapHeight * UnitSize + 30, "You have %d more 'UnDo' actions available.", commandHistory->GetUndoCount());
			Novice::ScreenPrintf(10, MapHeight * UnitSize + 50, "You have %d more 'ReDo' actions available.", commandHistory->GetRedoCount());
		}

		/// Unitの描画
		for (auto& unit : unitList) {
			unit.Draw();
		}

		/// Selectorの描画
		selector->Draw();


		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (InputManager::GetTriggerOn(DIK_ESCAPE)) {
			break;
		}
	}

	delete selectInputHandler;
	delete unitInputHandler;
	delete selector;
	delete commandHistory;


	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
