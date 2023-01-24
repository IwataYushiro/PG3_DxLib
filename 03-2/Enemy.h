#pragma once
class Enemy
{
public:
	Enemy();
	~Enemy();
private:
	const int isNum = 5;

	static bool isAlive;

public:
	void Dead();
	void Draw(int x, int y);
};

