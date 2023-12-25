#include "stdafx.h"
#include "Bullet.h"

#include "GameCode/GameCode.h"
Bullet::Bullet()
{
	S_Bullet.M_BulletModel.Init("Assets/modelData/Gun/Bullet.tkm");
	S_Bullet.M_BulletGhost.CreateBox({ S_Bullet.M_BulletPosition},Quaternion::Identity,Vector3::One * 10.0f);
}
bool Bullet::Start()
{
	S_Object.P_GameCamera = FindGO<GameCamera>("gamecamera");
	S_Player.P_Player = FindGO<Player>("player");

	S_Bullet.M_BulletPosition.x = S_Player.P_Player->GetPosition().x;
	S_Bullet.M_BulletPosition.y = S_Object.P_GameCamera->GetCameraPosition().y;
	S_Bullet.M_BulletPosition.z = S_Player.P_Player->GetPosition().z;

	S_Bullet.M_BulletSpeed.x = S_Object.P_GameCamera->GetCameraTarget().x / S_Bullet.M_BuleetSpeedMagniFication;
	S_Bullet.M_BulletSpeed.y = S_Object.P_GameCamera->GetCameraTarget().y / S_Bullet.M_BuleetSpeedMagniFication;
	S_Bullet.M_BulletSpeed.z = S_Object.P_GameCamera->GetCameraTarget().z / S_Bullet.M_BuleetSpeedMagniFication;
	return true;
}
void Bullet::Update()
{
	S_Bullet.DeadTime++;
	if (S_Bullet.DeadTime >= S_Bullet.DeadTimeMax)
	{BulletDead();}

	Move();

	S_Bullet.M_BulletGhost.SetPosition(S_Bullet.M_BulletPosition);
	S_Bullet.M_BulletModel.SetPosition(S_Bullet.M_BulletPosition);
	S_Bullet.M_BulletModel.Update();
}
void Bullet::Render(RenderContext& rc)
{
	S_Bullet.M_BulletModel.Draw(rc);
}