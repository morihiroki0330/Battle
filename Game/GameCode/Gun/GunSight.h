#pragma once
#include "DimensionalStorage/StructStorage.h"
class GunSight : public IGameObject
{
public:
	GunSight();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	DataGunSight S_GunSight;
	ClassObject S_Object;
};

