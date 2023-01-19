#include "SceneManager.h"
#include "DxLib.h"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

SceneManager* SceneManager::GetInstance()
{
	static SceneManager instance;

	return &instance;
}

void SceneManager::SceneChange(int sceneNo)
{
	sceneNo++;
	if (sceneNo <= 4)
	{
		sceneNo = 0;
	}
}