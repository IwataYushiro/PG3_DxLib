#pragma once
class SceneManager
{
private:
	SceneManager();
	~SceneManager();

public:
	enum Scene
	{
		title,
		newgame,
		gameplay,
		gameclear,
	};

private:
	int scene = title;

public:
	static SceneManager* GetInstance();

	void SceneChange(int sceneNo);

	int GetSceneIndex() { return scene; }
};

