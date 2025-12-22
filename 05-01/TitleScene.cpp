#include "TitleScene.h"

void TitleScene::Init(){
	sceneNo = (int)SCENE::TITLE;
}

void TitleScene::Update() {
	if (InputManager::GetTriggerOn(DIK_SPACE)) {
		sceneNo = (int)SCENE::STAGE;
	}
}

void TitleScene::Draw() {
	/// Text
	Novice::ScreenPrintf(610, 300, "<Title>");
	Novice::ScreenPrintf(560, 360, "Push Space To Start");
}
