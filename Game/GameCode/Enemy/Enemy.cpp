#include "stdafx.h"
#include "Enemy.h"

#include "GameCode/GameCode.h"
bool Enemy::Start()
{
	S_Enemy.M_CreateFlag = true;
	S_Enemy.M_EnemyModel.Init("Assets/modelData/Enemy/Enemy.tkm");
	S_Enemy.M_EnemyController.Init(75.0f, 75.0f, S_Enemy.M_EnemyPosition);
	
	S_EnemySpawner.P_EnemySpawner = FindGO<EnemySpawner>("enemyspawner");
	return true;
}
void Enemy::Update()
{
	S_Player.P_Player = FindGO<Player>("player");
	P_Bullet = FindGOs<Bullet>("bullet");
	if (P_Bullet.size() != 0)
	{EnemyHit();}
	if (S_Enemy.M_EnemyController.IsOnGround())
	{EnemyMove();}
	EnemyFall();
	EnemyDead();
	EnemyToPlayer();

	EnemyCoolTime();

	S_Enemy.M_EnemyPosition = S_Enemy.M_EnemyController.Execute(S_Enemy.M_EnemySpeed, 1.0f / 60.0f);
	if (S_Enemy.M_EnemyPosition.y < -1000.0f)
	{
		S_Enemy.M_EnemyPosition.y = 2500.0f;
		S_Enemy.M_EnemySpeed.y = 0.0f;
	}
	S_Enemy.M_EnemyController.SetPosition(S_Enemy.M_EnemyPosition);
	S_Enemy.M_EnemyModel.SetPosition(S_Enemy.M_EnemyPosition);
	S_Enemy.M_EnemyModel.Update();
}
void Enemy::Render(RenderContext& rc)
{
	S_Enemy.M_EnemyModel.Draw(rc);
}

void Enemy::EnemyMove()
{
	float directionX = S_Player.P_Player->GetPosition().x - S_Enemy.M_EnemyPosition.x;
	float directionZ = S_Player.P_Player->GetPosition().z - S_Enemy.M_EnemyPosition.z;

	// ベクトルを正規化
	float distance = std::sqrt(directionX * directionX + directionZ * directionZ);
	directionX /= distance;
	directionZ /= distance;

	// 一定の速度で移動
	S_Enemy.M_EnemySpeed.x = directionX * 650.0f;
	S_Enemy.M_EnemySpeed.z = directionZ * 650.0f;
}
void Enemy::EnemyFall()
{
	S_Enemy.M_EnemySpeed.y -= 15.0f;
}
void Enemy::EnemyDead()
{
	if (S_Enemy.M_EnemyHp <= 0)
	{
		S_EnemySpawner.P_EnemySpawner->EnemyDead(S_Enemy.M_EnemyScore);
		DeleteGO(this);
	}
}
void Enemy::EnemyHit()
{
	PhysicsWorld::GetInstance()->ContactTest(S_Enemy.M_EnemyController, [&](const btCollisionObject& contactObject)
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
	PhysicsWorld::GetInstance()->ContactTest(S_Enemy.M_EnemyController, [&](const btCollisionObject& contactObject)
	{
		if (S_Player.P_Player->PlayerIsSelf(contactObject))
		{
			S_Player.P_Player->PlayerDamage(1);
		}
	});
}
void Enemy::EnemyDamage()
{
	if (!S_Enemy.M_CoolFlag)
	{
		S_Enemy.M_EnemyHp -= 1;
		S_Enemy.M_CoolFlag = true;
	}
}
void Enemy::EnemyCoolTime()
{
	if (S_Enemy.M_CoolFlag)
	{
		S_Enemy.M_CoolTime++;
		if (S_Enemy.M_CoolTime > 25)
		{
			S_Enemy.M_CoolTime = 0;
			S_Enemy.M_CoolFlag = false;
		}
	}
}

void Enemy::InitValue()
{
	S_Enemy.M_EnemySpeed.x = 0.0f;
	S_Enemy.M_EnemySpeed.z = 0.0f;
}