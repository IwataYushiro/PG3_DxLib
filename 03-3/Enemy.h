#pragma once
class Enemy
{
private:
	Enemy();
	~Enemy();

public:
	static Enemy* GetInstance();

	//接近フェーズ
	void Approach();

	//攻撃フェーズ
	void Attack();
	
	//離脱フェーズ
	void Leave();

	//更新
	void Update(char* keys, char* oldkeys);
private:
	//メンバ関数ポインタのテーブル
	static void (Enemy::* pfuncTable[])();
	
	//現行動フェーズ
	size_t phase_;
};

