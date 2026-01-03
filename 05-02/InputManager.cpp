#include "InputManager.h"

InputManager* InputManager::instance = new InputManager();

char keys[256] = { 0 };
char preKeys[256] = { 0 };




bool InputManager::GetTriggerOn(int key) {
	return (instance->keys[key] != 0 && instance->preKeys[key] == 0);
}

bool InputManager::GetTriggerOff(int key) {
	return (instance->keys[key] == 0 && instance->preKeys[key] != 0);
}

bool InputManager::GetIsPush(int key) {
	return instance->keys[key] != 0;
}




void InputManager::Update() {
	memcpy( instance->preKeys, instance->keys, 256);
	Novice::GetHitKeyStateAll( instance->keys );
}
