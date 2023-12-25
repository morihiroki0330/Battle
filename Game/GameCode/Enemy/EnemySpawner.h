#pragma once
#include "DimensionalStorage/StructStorage.h"
class EnemySpawner : public IGameObject
{
public:
	EnemySpawner();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void EnemyCreate();
	void EnemyDead(int Score);
	void EnemyGenerate()
	{S_Spawner.M_EnemyCount++;}

	int GetEnemyCount()
	{return S_Spawner.M_EnemyCount;}
private:
	DataEnemySpawner S_Spawner;

	ClassGame S_Game;
	ClassEnemy S_Enemy;
	ClassPlayer S_Player;
};

