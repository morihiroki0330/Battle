#pragma once
#include "DimensionalStorage/StructStorage.h"
class GameCamera : public IGameObject
{
public:
	bool Start();
	void Update();

	void CameraMove(Vector2 Position);
	void RightMove(Vector2 Position);
	void LeftMove(Vector2 Position);

	void CameraJust();
	void AngleJust();

	Vector3 GetCameraPosition()
	{return M_CameraPosition;}
	Vector3 GetCameraTarget()
	{return M_CameraTarget;}
	int GetAngle()
	{return M_Angle;}
private:
	Vector3 M_CameraPosition = { 0.0f , 150.0f , 0.0f };
	Vector3 M_CameraTarget   = { 0.0f , 0.0f   , 9000000.0f };
	Vector2 M_MovePosition   = { 0.0f , 0.0f };

	int M_Angle = 0;

	const float M_CircleFication = 9000000.0f;
	const float M_MagniFication  = 10000.0f;
	
	ClassPlayer S_Player;
};

