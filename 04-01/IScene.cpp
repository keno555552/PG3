#include "IScene.h"

int IScene::sceneNo = (int)SCENE::TITLE;

IScene::~IScene() {}

int IScene::GetScene() const { return sceneNo; }
