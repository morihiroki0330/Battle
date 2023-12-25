#include "stdafx.h"
#include "Player.h"

#include "GameCode/GameCode.h"
#include "Operation/Operation.h"
Player::Player()
{	
	S_Player.M_PlayerModel.Init("Assets/modelData/Character/Character.tkm");
	S_Player.M_PlayerModel.Init("Assets/modelData/Enemy/Enemy.tkm");
	S_Player.M_PlayerController.Init(75.0f, 50.0f, S_Player.M_PlayerPosition);
	S_Player.M_PlayerGhost.CreateBox({ S_Player.M_PlayerPosition }, Quaternion::Identity, Vector3::One * 150.0f);
}
Player::~Player()
{
	DeleteGO(S_Gun.P_Gun);
}
bool Player::Start()
{
	S_Gun.P_Gun = NewGO<Gun>(0,"gun");
	S_Operation.P_Controller = FindGO<Controller>("controller");
	return true;
}
void Player::Update()
{
	InitValue();

	PlayerMove();
	PlayerFall();

	S_Player.M_PlayerPosition = S_Player.M_PlayerController.Execute(S_Player.M_PlayerSpeed, 1.0f / 60.0f);
	if (S_Player.M_PlayerPosition.y < -1000.0f)
	{
		S_Player.M_PlayerPosition.y = 2500.0f;
		S_Player.M_PlayerSpeed.y = 0.0f;
	}
	S_Player.M_PlayerController.SetPosition(S_Player.M_PlayerPosition);
	S_Player.M_PlayerGhost.SetPosition(S_Player.M_PlayerPosition);
	S_Player.M_PlayerModel.SetPosition(S_Player.M_PlayerPosition);
	S_Player.M_PlayerModel.Update();

	if (S_Player.M_CoolDownFlag)
	{
		S_Player.M_CoolDownTime++;
		if (S_Player.M_CoolDownTime >= S_Player.M_CoolDownTimeFixed)
		{
			S_Player.M_CoolDownFlag = false;
			S_Player.M_CoolDownTime = 0;
		}
	}

	swprintf_s(M_X, 256, L"SpeedY:%f", S_Player.M_PlayerSpeed.y);
	FX.SetText(M_X);
	FX.SetPosition({ -500.0f,200.0f,0.0f });
	FX.SetScale(1.0f);

	swprintf_s(M_Y, 256, L"PositionY:%f", S_Player.M_PlayerPosition.y);
	FY.SetText(M_Y);
	FY.SetPosition({ -500.0f,100.0f,0.0f });
	FY.SetScale(1.0f);

	swprintf_s(M_Z, 256, L"ControllerY:%f", S_Player.M_PlayerController.GetPosition().y);
	FZ.SetText(M_Z);
	FZ.SetPosition({ -500.0f,0.0f,0.0f });
	FZ.SetScale(1.0f);
}
void Player::Render(RenderContext& rc)
{
	S_Player.M_PlayerModel.Draw(rc);
	/*FX.Draw(rc);
	FY.Draw(rc);
	FZ.Draw(rc);*/
}

void Player::PlayerMove()
{
	S_Player.M_PlayerRight   *= S_Operation.P_Controller->GetLStick().x * 1550.0f;
	S_Player.M_PlayerForward *= S_Operation.P_Controller->GetLStick().y * 1550.0f;
	
	S_Player.M_PlayerSpeed.x += S_Player.M_PlayerRight.x + S_Player.M_PlayerForward.x;
	S_Player.M_PlayerSpeed.z += S_Player.M_PlayerRight.z + S_Player.M_PlayerForward.z;
}
void Player::PlayerFall()
{
	S_Player.M_PlayerSpeed.y -= 10.0f;
}
void Player::PlayerDamage(int Damage)
{
	if (!S_Player.M_CoolDownFlag)
	{
		S_Player.M_PlayerHp -= Damage;
		S_Player.M_CoolDownFlag = true;
	}
}

void Player::InitValue()
{
	S_Player.M_PlayerSpeed.x = 0.0f;
	S_Player.M_PlayerSpeed.z = 0.0f;
	
	S_Player.M_PlayerForward = g_camera3D->GetForward();
	S_Player.M_PlayerRight   = g_camera3D->GetRight();
	
	S_Player.M_PlayerForward.y = 0.0f;
	S_Player.M_PlayerRight.y   = 0.0f;
}