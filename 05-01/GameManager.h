#pragma once
#include <memory>
#include "InputManager.h"
#include "IScene.h"
#include "StageScene.h"
#include "TitleScene.h"
#include "ClearScene.h"

class GameManager
{
private:
	/// シーンを保持するメンバ変数
	std::unique_ptr<IScene> sceneArr_[3];

	/// どのステージを呼び出すがを管理する変数
	int currentSceneNo_; /// 現在のシーン
	int prevSceneNo_; /// 前のシーン

public:

	GameManager(); /// コンストラクタ
	~GameManager(); /// デストラクタ

	int Run(); /// この関数でゲームループを呼び出す

};

