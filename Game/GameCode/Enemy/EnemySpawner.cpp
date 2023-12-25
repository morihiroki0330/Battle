#include "stdafx.h"
#include "EnemySpawner.h"

#include "GameCode/GameCode.h"
#include <cstdlib>
EnemySpawner::EnemySpawner()
{
	S_Spawner.M_EnemySpawnerModel.Init("Assets/modelData/Enemy/EnemySpawner.tkm");
}
bool EnemySpawner::Start()
{
	S_Player.P_Player = FindGO<Player>("player");
	S_Game.P_Horizon = FindGO<BattlefieldHorizon>("horizon");

	S_Spawner.M_EnemySpawnerPosition.x = S_Player.P_Player->GetPosition().x;
	S_Spawner.M_EnemySpawnerPosition.z = S_Player.P_Player->GetPosition().z + 500.0f;

	EnemyCreate();
	return true;
}
void EnemySpawner::Update()
{
	if (S_Spawner.M_EnemyCount <= 0 && S_Spawner.Flag)
	{
		S_Game.P_Horizon->ClearFlag();
		S_Spawner.Flag = false;
	}

	S_Spawner.M_EnemySpawnerModel.SetPosition(S_Spawner.M_EnemySpawnerPosition);
	S_Spawner.M_EnemySpawnerModel.Update();
}
void EnemySpawner::Render(RenderContext& rc)
{
	S_Spawner.M_EnemySpawnerModel.Draw(rc);
}

void EnemySpawner::EnemyCreate()
{
	srand((unsigned int)time(NULL));
	for (int Level = 0; Level < S_Spawner.M_Level; Level++)
	{
		for (int EnemyCount = 0; EnemyCount < S_Spawner.M_EnemyCountMax; EnemyCount++)
		{
			do
			{
				S_Spawner.AngleX = rand() % 381 - 190;
				S_Spawner.M_EnemySetPosition.x = S_Spawner.AngleX * 100.0f;
			} while (S_Spawner.M_EnemySetPosition.x > S_Player.P_Player->GetPosition().x - 1000.0f && S_Spawner.M_EnemySetPosition.x < S_Player.P_Player->GetPosition().x + 1000.0f);

			do
			{
				S_Spawner.AngleZ = rand() % 381 - 190;
				S_Spawner.M_EnemySetPosition.z = S_Spawner.AngleZ * 100.0f;
			} while (S_Spawner.M_EnemySetPosition.z > S_Player.P_Player->GetPosition().z - 1000.0f && S_Spawner.M_EnemySetPosition.z < S_Player.P_Player->GetPosition().z + 1000.0f);

			S_Enemy.P_Enemy = NewGO<Enemy>(0, "enemy");
			S_Enemy.P_Enemy->SetPosition(S_Spawner.M_EnemySetPosition);
			EnemyGenerate();
		}
	}
}

void EnemySpawner::EnemyDead(int Score)
{
	S_Game.P_Horizon->ScoreAdd(Score);
	S_Spawner.M_EnemyCount--;
}