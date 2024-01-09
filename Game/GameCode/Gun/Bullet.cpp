#include "stdafx.h"
#include "Bullet.h"

#include "GameCode/GameCode.h"
Bullet::Bullet()
{
	M_BulletModel.Init("Assets/modelData/Gun/Bullet.tkm");
	M_BulletGhost.CreateBox({ M_BulletPosition},Quaternion::Identity,Vector3::One * 10.0f);
}
bool Bullet::Start()
{
	S_Object.P_GameCamera = FindGO<GameCamera>("gamecamera");
	S_Player.P_Player = FindGO<Player>("player");

	M_BulletPosition.x = S_Player.P_Player->GetPosition().x;
	M_BulletPosition.y = S_Object.P_GameCamera->GetCameraPosition().y;
	M_BulletPosition.z = S_Player.P_Player->GetPosition().z;

	M_BulletSpeed.x = S_Object.P_GameCamera->GetCameraTarget().x / M_BuleetSpeedMagniFication;
	M_BulletSpeed.y = S_Object.P_GameCamera->GetCameraTarget().y / M_BuleetSpeedMagniFication;
	M_BulletSpeed.z = S_Object.P_GameCamera->GetCameraTarget().z / M_BuleetSpeedMagniFication;
	return true;
}
void Bullet::Update()
{
	DeadTime++;
	if (DeadTime >= DeadTimeMax)
	{BulletDead();}

	Move();

	M_BulletGhost.SetPosition(M_BulletPosition);
	M_BulletModel.SetPosition(M_BulletPosition);
	M_BulletModel.Update();
}
void Bullet::Render(RenderContext& rc)
{
	M_BulletModel.Draw(rc);
}