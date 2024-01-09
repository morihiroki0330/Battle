#pragma once
#include "DimensionalStorage/StructStorage.h"
#include "physics/PhysicsGhostObject.h"
class Bullet : public IGameObject
{
public:
	Bullet();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void Move()
	{
		M_BulletPosition.x += M_BulletSpeed.x;
		M_BulletPosition.y += M_BulletSpeed.y;
		M_BulletPosition.z += M_BulletSpeed.z;
	}

	bool BulletIsSelf(const btCollisionObject& contactObject)
	{return M_BulletGhost.IsSelf(contactObject);}

	void BulletDead()
	{DeleteGO(this);}
private:
	ModelRender M_BulletModel;

	PhysicsGhostObject M_BulletGhost;

	Vector3 M_BulletPosition = { 0.0f , 0.0f , 0.0f };
	Vector3 M_BulletSpeed    = { 0.0f , 0.0f , 0.0f };

	float M_BuleetSpeedMagniFication = 100000.0f;

	int DeadTime = 0;
	int DeadTimeMax = 60;

	ClassObject S_Object;
	ClassPlayer S_Player;
};

