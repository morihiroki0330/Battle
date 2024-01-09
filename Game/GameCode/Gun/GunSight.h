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
	SpriteRender M_GunSightTexture;
	ClassObject S_Object;
};

