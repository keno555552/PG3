#pragma once
#include <Novice.h>

/// シーン番号を管理する列挙型
enum class SCENE {
	TITLE,
	STAGE,
	CLEAR,
	SCENE_NUM
};

class IScene
{
protected:
	static int sceneNo;

public:
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	virtual ~IScene();

	int GetScene() const;
};

