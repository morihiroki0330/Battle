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
	{return S_GunData.M_BulletCount;}
private:
	DataGun S_GunData;
	ClassGun S_Gun;
	ClassOperation S_Operation;
};

