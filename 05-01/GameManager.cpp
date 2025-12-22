#include "GameManager.h"
#include <Novice.h>

GameManager::GameManager() {

	/// 各シーンの配列
	sceneArr_[(int)SCENE::TITLE] = std::make_unique<TitleScene>();
	sceneArr_[(int)SCENE::STAGE] = std::make_unique<StageScene>();
	sceneArr_[(int)SCENE::CLEAR] = std::make_unique<ClearScene>();

	/// 最初のシーンをタイトルシーンに設定
	currentSceneNo_ = (int)SCENE::TITLE;
}

GameManager::~GameManager() {
}

int GameManager::Run() {
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();
		InputManager::Update();

		// シーンのチェック
		prevSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetScene();

		// シーン変更チェック
		if (InputManager::GetTriggerOn(DIK_M)) {
			if(currentSceneNo_ < (int)SCENE::SCENE_NUM - 1)currentSceneNo_++;
			else currentSceneNo_ = 0;
		}
		if (prevSceneNo_ != currentSceneNo_) {
			sceneArr_[currentSceneNo_]->Init();
		}

		/// 更新処理
		sceneArr_[currentSceneNo_]->Update(); // シーンごとの更新処理

		/// 描画処理
		sceneArr_[currentSceneNo_]->Draw();
		Novice::ScreenPrintf(0, 0, "Push M To Change Scene", currentSceneNo_);
		Novice::ScreenPrintf(0, 20, "Current Scene:%d", currentSceneNo_);



		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (InputManager::GetTriggerOn(DIK_ESCAPE)) {
			break;
		}
	}
	return 0;
}
