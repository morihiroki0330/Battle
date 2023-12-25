#pragma once
#include "DimensionalStorage/StructStorage.h"
class Bullet : public IGameObject
{
public:
	Bullet();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void Move()
	{
		S_Bullet.M_BulletPosition.x += S_Bullet.M_BulletSpeed.x;
		S_Bullet.M_BulletPosition.y += S_Bullet.M_BulletSpeed.y;
		S_Bullet.M_BulletPosition.z += S_Bullet.M_BulletSpeed.z;
	}

	bool BulletIsSelf(const btCollisionObject& contactObject)
	{return S_Bullet.M_BulletGhost.IsSelf(contactObject);}

	void BulletDead()
	{DeleteGO(this);}
private:
	DataBullet S_Bullet;

	ClassObject S_Object;
	ClassPlayer S_Player;
};

