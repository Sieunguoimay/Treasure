#include"KeyManager.h"
KeyManager&KeyManager::Instance(){
	static KeyManager keyManager;
	return keyManager;
}