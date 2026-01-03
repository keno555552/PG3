#pragma once
#include <Novice.h>

class InputManager
{
public:
	/// シングルトンパターンの実装
	static InputManager* instance;

	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	static const char* GetKeys() { return instance->keys; }
	static const char* GetPreKeys() { return instance->preKeys; }

	static bool GetTriggerOn(int key);
	static bool GetTriggerOff(int key);
	static bool GetIsPush(int key);

	static void Update();
};

