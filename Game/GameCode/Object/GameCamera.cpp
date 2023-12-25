#include "stdafx.h"
#include "GameCamera.h"

#include "GameCode/GameCode.h"
bool GameCamera::Start()
{
	g_camera3D->SetFar(1500000.0f);
	S_Player.P_Player = FindGO<Player>("player");
	S_Camera.M_CameraPosition.y = S_Player.P_Player->GetPosition().y + S_Camera.M_CameraPosition.y;
	return true;
}

void GameCamera::Update()
{
	S_Camera.M_CameraPosition.x = S_Player.P_Player->GetPosition().x;
	S_Camera.M_CameraPosition.y = S_Player.P_Player->GetPosition().y + 100.0f;
	S_Camera.M_CameraPosition.z = S_Player.P_Player->GetPosition().z;

	g_camera3D->SetPosition(S_Camera.M_CameraPosition);
	g_camera3D->SetTarget(S_Camera.M_CameraTarget);

	swprintf_s(M_X, 256, L"S_Camera.M_CameraTarget.z:%f", S_Camera.M_CameraTarget.z);
	FX.SetText(M_X);
	FX.SetPosition({ 0.0f,0.0f,0.0f });
	FX.SetScale(1.0f);

	swprintf_s(M_Y, 256, L"Angle:%d", S_Camera.M_Angle);
	FY.SetText(M_Y);
	FY.SetPosition({ 0.0f,-100.0f,0.0f });
	FY.SetScale(1.0f);
}
void GameCamera::Render(RenderContext& rc)
{
	FX.Draw(rc);
	FY.Draw(rc);
}

void GameCamera::CameraMove(Vector2 Position)
{
	S_Camera.M_MovePosition.x = (int)(Position.x);
	S_Camera.M_MovePosition.y = (int)(Position.y);

	RightMove(S_Camera.M_MovePosition);
	LeftMove(S_Camera.M_MovePosition);

	CameraJust();
	AngleJust();
}
void GameCamera::RightMove(Vector2 Position)
{
	if (Position.x > 0.0f)
	{
		if ((S_Camera.M_CameraTarget.x > 0.0f || S_Camera.M_CameraTarget.x == 0.0f) && (S_Camera.M_CameraTarget.z > 0.0f))
		{
			S_Camera.M_CameraTarget.x += (abs(Position.x) * S_Camera.M_MagniFication);
			S_Camera.M_CameraTarget.z -= (abs(Position.x) * S_Camera.M_MagniFication);
		}else {
			if ((S_Camera.M_CameraTarget.x > 0.0f) && (S_Camera.M_CameraTarget.z < 0.0f || S_Camera.M_CameraTarget.z == 0.0f))
			{
				S_Camera.M_CameraTarget.x -= (abs(Position.x) * S_Camera.M_MagniFication);
				S_Camera.M_CameraTarget.z -= (abs(Position.x) * S_Camera.M_MagniFication);
			}else {
				if ((S_Camera.M_CameraTarget.x < 0.0f || S_Camera.M_CameraTarget.x == 0.0f) && (S_Camera.M_CameraTarget.z < 0.0f))
				{
					S_Camera.M_CameraTarget.x -= (abs(Position.x) * S_Camera.M_MagniFication);
					S_Camera.M_CameraTarget.z += (abs(Position.x) * S_Camera.M_MagniFication);
				}else {
					if ((S_Camera.M_CameraTarget.x < 0.0f) && (S_Camera.M_CameraTarget.z > 0.0f || S_Camera.M_CameraTarget.z == 0.0f))
					{
						S_Camera.M_CameraTarget.x += (abs(Position.x) * S_Camera.M_MagniFication);
						S_Camera.M_CameraTarget.z += (abs(Position.x) * S_Camera.M_MagniFication);
					}
				}
			}
		}
		S_Camera.M_Angle += Position.x;
	}
}
void GameCamera::LeftMove(Vector2 Position)
{

	if (Position.x < 0.0f)
	{
		if ((S_Camera.M_CameraTarget.x < 0.0f || S_Camera.M_CameraTarget.x == 0.0f) && (S_Camera.M_CameraTarget.z > 0.0f))
		{
			S_Camera.M_CameraTarget.x -= (abs(Position.x) * S_Camera.M_MagniFication);
			S_Camera.M_CameraTarget.z -= (abs(Position.x) * S_Camera.M_MagniFication);
		}else {
			if ((S_Camera.M_CameraTarget.x < 0.0f) && (S_Camera.M_CameraTarget.z < 0.0f || S_Camera.M_CameraTarget.z == 0.0f))
			{
				S_Camera.M_CameraTarget.x += (abs(Position.x) * S_Camera.M_MagniFication);
				S_Camera.M_CameraTarget.z -= (abs(Position.x) * S_Camera.M_MagniFication);
			}else {
				if ((S_Camera.M_CameraTarget.x > 0.0f || S_Camera.M_CameraTarget.x == 0.0f) && (S_Camera.M_CameraTarget.z < 0.0f))
				{
					S_Camera.M_CameraTarget.x += (abs(Position.x) * S_Camera.M_MagniFication);
					S_Camera.M_CameraTarget.z += (abs(Position.x) * S_Camera.M_MagniFication);
				}else {
					if ((S_Camera.M_CameraTarget.x > 0.0f) && (S_Camera.M_CameraTarget.z > 0.0f || S_Camera.M_CameraTarget.z == 0.0f))
					{
						S_Camera.M_CameraTarget.x -= (abs(Position.x) * S_Camera.M_MagniFication);
						S_Camera.M_CameraTarget.z += (abs(Position.x) * S_Camera.M_MagniFication);
					}
				}
			}
		}
		S_Camera.M_Angle += Position.x;
	}
}

void GameCamera::CameraJust()
{
	if ((abs)(S_Camera.M_CameraTarget.x) + (abs)(S_Camera.M_CameraTarget.z) != S_Camera.M_CircleFication)
	{
		if (S_Camera.M_Angle > 0)
		{
			if (S_Camera.M_Angle <= 900)
			{
				S_Camera.M_CameraTarget.x = S_Camera.M_MagniFication * S_Camera.M_Angle;
				S_Camera.M_CameraTarget.z = S_Camera.M_CircleFication - S_Camera.M_CameraTarget.x;
			}else {
				if (S_Camera.M_Angle <= 1800)
				{
					S_Camera.M_CameraTarget.z = (900 - S_Camera.M_Angle) * S_Camera.M_MagniFication;
					S_Camera.M_CameraTarget.x = S_Camera.M_CircleFication + S_Camera.M_CameraTarget.z;
				}else {
					if (S_Camera.M_Angle <= 2700)
					{
						S_Camera.M_CameraTarget.x = (1800 - S_Camera.M_Angle) * S_Camera.M_MagniFication;
						S_Camera.M_CameraTarget.z = -(S_Camera.M_CircleFication + S_Camera.M_CameraTarget.x);
					}else {
						if (S_Camera.M_Angle <= 3600)
						{
							S_Camera.M_CameraTarget.z = (2700 - S_Camera.M_Angle) * -S_Camera.M_MagniFication;
							S_Camera.M_CameraTarget.x = -(S_Camera.M_CircleFication - S_Camera.M_CameraTarget.z);
						}
					}
				}
			}
		}else {
			if (S_Camera.M_Angle < 0)
			{
				if (S_Camera.M_Angle >= -900)
				{
					S_Camera.M_CameraTarget.x = S_Camera.M_MagniFication * S_Camera.M_Angle;
					S_Camera.M_CameraTarget.z = S_Camera.M_CircleFication + S_Camera.M_CameraTarget.x;
				}else {
					if (S_Camera.M_Angle >= -1800)
					{
						S_Camera.M_CameraTarget.z = (900 + S_Camera.M_Angle) * S_Camera.M_MagniFication;
						S_Camera.M_CameraTarget.x = -(S_Camera.M_CircleFication + S_Camera.M_CameraTarget.z);
					}else {
						if (S_Camera.M_Angle >= -2700)
						{
							S_Camera.M_CameraTarget.x = (1800 + S_Camera.M_Angle) * - S_Camera.M_MagniFication;
							S_Camera.M_CameraTarget.z = -(S_Camera.M_CircleFication - S_Camera.M_CameraTarget.x);
						}else {
							if (S_Camera.M_Angle >= -3600)
							{
								S_Camera.M_CameraTarget.z = (2700 + S_Camera.M_Angle) * -S_Camera.M_MagniFication;
								S_Camera.M_CameraTarget.x = (S_Camera.M_CircleFication - S_Camera.M_CameraTarget.z);
							}
						}
					}
				}
			}else {
				if (S_Camera.M_Angle == 0)
				{
					S_Camera.M_CameraTarget.x = 0.0f;
					S_Camera.M_CameraTarget.z = S_Camera.M_CircleFication;
				}
			}
		}
	}

	if (S_Camera.M_MovePosition.y < 0.0f)
	{
		S_Camera.M_CameraTarget.y += (abs(S_Camera.M_MovePosition.y) * S_Camera.M_MagniFication);
	}else {
		if (S_Camera.M_MovePosition.y > 0.0f)
		{
			S_Camera.M_CameraTarget.y -= (abs(S_Camera.M_MovePosition.y) * S_Camera.M_MagniFication);
		}
	}
}
void GameCamera::AngleJust()
{
	if (S_Camera.M_Angle > 3600)
	{
		S_Camera.M_Angle = 0;
	}else {
		if (S_Camera.M_Angle < -3600)
		{
			S_Camera.M_Angle = 0;
		}
	}
}