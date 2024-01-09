#pragma once
#include "DimensionalStorage/StructStorage.h"
class Gun : public IGameObject
{
public:
	Gun();
	~Gun();
	void Update();

	void Shot();
	void Reload();

	int GetBulletCount()
	{return M_BulletCount;}
private:
	bool M_CoolDownFlag = false;
	bool M_ReloadFlag = true;

	int M_CoolDownTime      = 0;
	int M_CoolDownTimeFixed = 15;
	int M_BulletCount       = 60;
	int M_BulletMaxCount    = 60;

	ClassGun S_Gun;
	ClassOperation S_Operation;
};

