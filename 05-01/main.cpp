#include <Novice.h>
#include "InputHandler.h"
#include "Command.h"
#include "Player.h"

const char kWindowTitle[] = "LE2B_05_カン_ケンリャン";

// キー入力結果を受け取る箱
char keys[256] = { 0 };
char preKeys[256] = { 0 };

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	MoveLeftCommand moveLeftCommand;
	MoveRightCommand moveRightCommand;

	InputHandler* inputHandler = new InputHandler;
	inputHandler->AssignPressKeyA(&moveLeftCommand);
	inputHandler->AssignPressKeyD(&moveRightCommand);

	ICommand* receivedCommand = nullptr;

	Player* player = new Player();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		receivedCommand = inputHandler->HandleInput();

		if (receivedCommand != nullptr) {
			receivedCommand->Exec(*player);
		}
		player->Update();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		player->Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete inputHandler;
	delete player;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
