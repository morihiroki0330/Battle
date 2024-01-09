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
	{M_EnemyCount++;}

	int GetEnemyCount()
	{return M_EnemyCount;}
private:
	ModelRender M_EnemySpawnerModel;

	Vector3 M_EnemySpawnerPosition = { 0.0f,200.0f,0.0f };
	Vector3 M_EnemySetPosition = { 0.0f,2500.0f,0.0f };

	float AngleX = rand() % 381 - 190;
	float AngleZ = rand() % 381 - 190;

	int M_EnemyCount = 0;
	int M_EnemyCountMax = 15;
	int M_Level = 1;

	bool Flag = true;

	ClassGame S_Game;
	ClassEnemy S_Enemy;
	ClassPlayer S_Player;
};

