#include "stdafx.h"
#include "GunSight.h"

#include "GameCode/GameCode.h"
GunSight::GunSight()
{
	M_GunSightTexture.Init("Assets/Sprite/Gun/Sight/Sight.DDS", 150.0f, 150.0f, true);
}
bool GunSight::Start()
{
	S_Object.P_GameCamera = FindGO<GameCamera>("gamecamera");
	return true;
}
void GunSight::Update()
{
	M_GunSightTexture.Update();
}
void GunSight::Render(RenderContext& rc)
{
	M_GunSightTexture.Draw(rc);
}
