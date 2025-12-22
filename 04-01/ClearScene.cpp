#include "ClearScene.h"

void ClearScene::Init() {
	sceneNo = (int)SCENE::CLEAR;
}

void ClearScene::Update() {
	if (InputManager::GetTriggerOn(DIK_SPACE)) {
		sceneNo = (int)SCENE::TITLE;
	}
}

void ClearScene::Draw() {

	/// BG
	Novice::DrawBox(0, 0, 1280, 720, 0, 0x222255FF, kFillModeSolid);

	/// Text
	Novice::ScreenPrintf(610, 300, "CLEAR!");
	Novice::ScreenPrintf(560, 360, "Push Space To Start");
}
