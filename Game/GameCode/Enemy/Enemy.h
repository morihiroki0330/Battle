#pragma once
#include "DimensionalStorage/StructStorage.h"
class Enemy : public IGameObject
{
public:
	bool Start();
	void Update();
	void Render(RenderContext& rc);
	void SetPosition(Vector3 Pos)
	{M_EnemyPosition = Pos;}

	void EnemyMove();
	void EnemyFall();
	void EnemyDead();

	void EnemyHit();
	void EnemyToPlayer();
	void EnemyDamage();
	void EnemyCoolTime();

	void InitValue();
	Vector3 GetPosition()
	{return M_EnemyPosition;}

	bool GetFlag()
	{return M_CreateFlag;}
private:
	ModelRender M_EnemyModel;

	Vector3 M_EnemyPosition = { 0.0f,0.0f,0.0f };
	Vector3 M_EnemySpeed = { 0.0f,0.0f,0.0f };

	CharacterController M_EnemyController;

	int M_EnemyHp = 1;
	int M_EnemyScore = 500;
	int M_CoolTime = 0;

	bool M_CoolFlag = false;
	bool M_CreateFlag = false;

	ClassGame S_Game;
	ClassPlayer S_Player;
	std::vector<Bullet*> P_Bullet;
	ClassEnemy S_EnemySpawner;
};

