#include "Enemy.h"
#include "DxLib.h"

Enemy::Enemy()
{
	phase_ = 0;
}

Enemy::~Enemy()
{
}

//�����o�֐��|�C���^�e�[�u���̎���
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
	DrawString(100, 100, "�ڋ߂��܁[��", GetColor(255, 0, 0));
	DrawBox(100, 120, 200, 220, GetColor(255, 255, 255), true);

	DrawString(300, 350, "�ڋ߃t�F�[�Y", GetColor(255, 255, 255));
}

void Enemy::Attack()
{
	DrawString(100, 100, "�����܁[��", GetColor(0, 255, 0));
	DrawBox(100, 120, 200, 220, GetColor(255, 255, 255), true);

	DrawString(400, 120, "�΁[��", GetColor(0, 255, 0));
	DrawBox(400, 140, 450, 190, GetColor(255, 255, 255), true);

	DrawString(300, 350, "�U���t�F�[�Y", GetColor(255, 255, 255));
}

void Enemy::Leave()
{
	DrawString(100, 100, "���Ⴀ�ˁ[", GetColor(0, 0, 255));
	DrawBox(100, 120, 200, 220, GetColor(255, 255, 255), false);

	DrawString(300, 350, "���E�t�F�[�Y", GetColor(255, 255, 255));
	
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

	DrawString(300, 380, "�X�y�[�X�L�[�Ő؂�ւ�", GetColor(255, 255, 255));
}
