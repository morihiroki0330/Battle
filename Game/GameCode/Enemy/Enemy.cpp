#include "stdafx.h"
#include "Enemy.h"

#include "GameCode/GameCode.h"
bool Enemy::Start()
{
	M_CreateFlag = true;
	M_EnemyModel.Init("Assets/modelData/Enemy/Enemy.tkm");
	M_EnemyController.Init(75.0f, 75.0f, M_EnemyPosition);
	
	S_EnemySpawner.P_EnemySpawner = FindGO<EnemySpawner>("enemyspawner");
	return true;
}
void Enemy::Update()
{
	S_Player.P_Player = FindGO<Player>("player");
	P_Bullet = FindGOs<Bullet>("bullet");
	if (P_Bullet.size() != 0)
	{EnemyHit();}
	if (M_EnemyController.IsOnGround())
	{EnemyMove();}
	EnemyFall();
	EnemyDead();
	EnemyToPlayer();

	EnemyCoolTime();

	M_EnemyPosition = M_EnemyController.Execute(M_EnemySpeed, 1.0f / 60.0f);
	if (M_EnemyPosition.y < -1000.0f)
	{
		M_EnemyPosition.y = 2500.0f;
		M_EnemySpeed.y = 0.0f;
	}
	M_EnemyController.SetPosition(M_EnemyPosition);
	M_EnemyModel.SetPosition(M_EnemyPosition);
	M_EnemyModel.Update();
}
void Enemy::Render(RenderContext& rc)
{
	M_EnemyModel.Draw(rc);
}

void Enemy::EnemyMove()
{
	float directionX = S_Player.P_Player->GetPosition().x - M_EnemyPosition.x;
	float directionZ = S_Player.P_Player->GetPosition().z - M_EnemyPosition.z;

	// ベクトルを正規化
	float distance = std::sqrt(directionX * directionX + directionZ * directionZ);
	directionX /= distance;
	directionZ /= distance;

	// 一定の速度で移動
	M_EnemySpeed.x = directionX * 650.0f;
	M_EnemySpeed.z = directionZ * 650.0f;
}
void Enemy::EnemyFall()
{
	M_EnemySpeed.y -= 15.0f;
}
void Enemy::EnemyDead()
{
	if (M_EnemyHp <= 0)
	{
		S_EnemySpawner.P_EnemySpawner->EnemyDead(M_EnemyScore);
		DeleteGO(this);
	}
}
void Enemy::EnemyHit()
{
	PhysicsWorld::GetInstance()->ContactTest(M_EnemyController, [&](const btCollisionObject& contactObject)
	{
		for (int i = 0 ;P_Bullet[i] != nullptr;i++)
		{
			if (P_Bullet[i]->BulletIsSelf(contactObject))
			{
				EnemyDamage();
				P_Bullet[i]->BulletDead();
				break;
			}
		}
	});
}
void Enemy::EnemyToPlayer()
{
	PhysicsWorld::GetInstance()->ContactTest(M_EnemyController, [&](const btCollisionObject& contactObject)
	{
		if (S_Player.P_Player->PlayerIsSelf(contactObject))
		{
			S_Player.P_Player->PlayerDamage(1);
		}
	});
}
void Enemy::EnemyDamage()
{
	if (!M_CoolFlag)
	{
		M_EnemyHp -= 1;
		M_CoolFlag = true;
	}
}
void Enemy::EnemyCoolTime()
{
	if (M_CoolFlag)
	{
		M_CoolTime++;
		if (M_CoolTime > 25)
		{
			M_CoolTime = 0;
			M_CoolFlag = false;
		}
	}
}

void Enemy::InitValue()
{
	M_EnemySpeed.x = 0.0f;
	M_EnemySpeed.z = 0.0f;
}