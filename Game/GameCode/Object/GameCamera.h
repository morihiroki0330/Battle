#pragma once
#include "DimensionalStorage/StructStorage.h"
class GameCamera : public IGameObject
{
public:
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void CameraMove(Vector2 Position);
	void RightMove(Vector2 Position);
	void LeftMove(Vector2 Position);

	void CameraJust();
	void AngleJust();

	Vector3 GetCameraPosition()
	{return S_Camera.M_CameraPosition;}
	Vector3 GetCameraTarget()
	{return S_Camera.M_CameraTarget;}
	int GetAngle()
	{return S_Camera.M_Angle;}
private:
	DataCamera S_Camera;
	
	ClassPlayer S_Player;

	FontRender FX;
	wchar_t M_X[256];

	FontRender FY;
	wchar_t M_Y[256];
};

