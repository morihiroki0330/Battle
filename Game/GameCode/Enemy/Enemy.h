#pragma once
#include "DimensionalStorage/StructStorage.h"
class Enemy : public IGameObject
{
public:
	bool Start();
	void Update();
	void Render(RenderContext& rc);
	void SetPosition(Vector3 Pos)
	{S_Enemy.M_EnemyPosition = Pos;}

	void EnemyMove();
	void EnemyFall();
	void EnemyDead();

	void EnemyHit();
	void EnemyToPlayer();
	void EnemyDamage();
	void EnemyCoolTime();

	void InitValue();
	Vector3 GetPosition()
	{return S_Enemy.M_EnemyPosition;}

	bool GetFlag()
	{
		return S_Enemy.M_CreateFlag;
	}
private:
	DataEnemy S_Enemy;

	ClassGame S_Game;
	ClassPlayer S_Player;
	std::vector<Bullet*> P_Bullet;
	ClassEnemy S_EnemySpawner;
};

