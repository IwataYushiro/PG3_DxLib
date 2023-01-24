#pragma once
class Enemy
{
private:
	Enemy();
	~Enemy();

public:
	static Enemy* GetInstance();

	//�ڋ߃t�F�[�Y
	void Approach();

	//�U���t�F�[�Y
	void Attack();
	
	//���E�t�F�[�Y
	void Leave();

	//�X�V
	void Update(char* keys, char* oldkeys);
private:
	//�����o�֐��|�C���^�̃e�[�u��
	static void (Enemy::* pfuncTable[])();
	
	//���s���t�F�[�Y
	size_t phase_;
};

