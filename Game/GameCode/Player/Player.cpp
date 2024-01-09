#include "stdafx.h"
#include "Player.h"

#include "GameCode/GameCode.h"
#include "Operation/Operation.h"
Player::Player()
{	
	M_PlayerModel.Init("Assets/modelData/Character/Character.tkm");
	M_PlayerModel.Init("Assets/modelData/Enemy/Enemy.tkm");
	M_PlayerController.Init(75.0f, 50.0f, M_PlayerPosition);
	M_PlayerGhost.CreateBox({ M_PlayerPosition }, Quaternion::Identity, Vector3::One * 150.0f);
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

	M_PlayerPosition = M_PlayerController.Execute(M_PlayerSpeed, 1.0f / 60.0f);
	if (M_PlayerPosition.y < -1000.0f)
	{
		M_PlayerPosition.y = 2500.0f;
		M_PlayerSpeed.y = 0.0f;
	}
	M_PlayerController.SetPosition(M_PlayerPosition);
	M_PlayerGhost.SetPosition(M_PlayerPosition);
	M_PlayerModel.SetPosition(M_PlayerPosition);
	M_PlayerModel.Update();

	if (M_CoolDownFlag)
	{
		M_CoolDownTime++;
		if (M_CoolDownTime >= M_CoolDownTimeFixed)
		{
			M_CoolDownFlag = false;
			M_CoolDownTime = 0;
		}
	}
}
void Player::Render(RenderContext& rc)
{
	M_PlayerModel.Draw(rc);
}

void Player::PlayerMove()
{
	M_PlayerRight   *= S_Operation.P_Controller->GetLStick().x * 1550.0f;
	M_PlayerForward *= S_Operation.P_Controller->GetLStick().y * 1550.0f;
	
	M_PlayerSpeed.x += M_PlayerRight.x + M_PlayerForward.x;
	M_PlayerSpeed.z += M_PlayerRight.z + M_PlayerForward.z;
}
void Player::PlayerFall()
{
	M_PlayerSpeed.y -= 10.0f;
}
void Player::PlayerDamage(int Damage)
{
	if (!M_CoolDownFlag)
	{
		M_PlayerHp -= Damage;
		M_CoolDownFlag = true;
	}
}

void Player::InitValue()
{
	M_PlayerSpeed.x = 0.0f;
	M_PlayerSpeed.z = 0.0f;
	
	M_PlayerForward = g_camera3D->GetForward();
	M_PlayerRight   = g_camera3D->GetRight();
	
	M_PlayerForward.y = 0.0f;
	M_PlayerRight.y   = 0.0f;
}