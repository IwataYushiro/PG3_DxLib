#pragma once
class Enemy
{
private:
	Enemy();
	~Enemy();
	const int isNum = 5;

	static bool isAlive;

public:
	static Enemy* GetInstance();
	void Dead();
	void Draw(int x, int y);
};

