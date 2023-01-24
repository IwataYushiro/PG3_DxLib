#include "Enemy.h"
#include "DxLib.h"

Enemy::Enemy()
{
	phase_ = 0;
}

Enemy::~Enemy()
{
}

//メンバ関数ポインタテーブルの実体
void (Enemy::* Enemy::pfuncTable[])() =
{
	&Enemy::Approach,
	&Enemy::Attack,
	&Enemy::Leave
};

Enemy* Enemy::GetInstance()
{
	static Enemy instance;

	return &instance;
}

void Enemy::Approach()
{
	DrawString(100, 100, "接近しまーす", GetColor(255, 0, 0));
	DrawBox(100, 120, 200, 220, GetColor(255, 255, 255), true);

	DrawString(300, 350, "接近フェーズ", GetColor(255, 255, 255));
}

void Enemy::Attack()
{
	DrawString(100, 100, "撃ちまーす", GetColor(0, 255, 0));
	DrawBox(100, 120, 200, 220, GetColor(255, 255, 255), true);

	DrawString(400, 120, "ばーん", GetColor(0, 255, 0));
	DrawBox(400, 140, 450, 190, GetColor(255, 255, 255), true);

	DrawString(300, 350, "攻撃フェーズ", GetColor(255, 255, 255));
}

void Enemy::Leave()
{
	DrawString(100, 100, "じゃあねー", GetColor(0, 0, 255));
	DrawBox(100, 120, 200, 220, GetColor(255, 255, 255), false);

	DrawString(300, 350, "離脱フェーズ", GetColor(255, 255, 255));
	
}

void Enemy::Update(char* keys, char* oldkeys)
{
	(this->*pfuncTable[phase_])();

	if (keys[KEY_INPUT_SPACE] && !oldkeys[KEY_INPUT_SPACE])
	{
		phase_++;
	}
	if (phase_ >= 3)
	{
		phase_ = 0;
	}

	DrawString(300, 380, "スペースキーで切り替え", GetColor(255, 255, 255));
}
