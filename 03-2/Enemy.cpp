#include "Enemy.h"
#include "DxLib.h"

bool Enemy::isAlive = true;

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Dead()
{
	isAlive = false;
}

void Enemy::Draw(int x,int y)
{
	if (isAlive)
	{
		DrawBox(x, y, x + 100, y + 100, GetColor(255, 0, 0), true);
	}
}
