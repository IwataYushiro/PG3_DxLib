#pragma once
class SceneManager
{
private:
	SceneManager();
	~SceneManager();

private:

public:
	static SceneManager* GetInstance();

	void SceneChange(int sceneNo);

};

