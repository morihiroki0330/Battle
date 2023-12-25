#pragma once
#include "DimensionalStorage/StructStorage.h"
struct MouseFlag
{
	bool M_LeftButtonFlag = false;
	bool M_RightButtonFlag = false;
};
class Mouse : public IGameObject
{
public:
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void MouseSet();
	void MouseMove();
	void MouseReset();

	void MouseCurSorSetPosition(Vector3& Position);

	void MouseFlagJudge();
	bool GetMouseFlag(int Number);
	void SetMouseFlag(int Number, bool Flag);

	Vector3 GetMousePosition()
	{return M_MouseCousorPosition;}

	Vector3 GetMouseMoveSpeed()
	{return M_MouseCousorMoveSpeed;}

	Vector2 GetDelta()
	{return M_Delta;}
private:
	SpriteRender M_MouseCursorTexture;
	Vector3 M_MouseCousorPosition;
	Vector3 M_MouseCousorMoveSpeed;

	POINT M_CursorPosition ={};
	HWND M_HWnd = GetConsoleWindow();
	
	Vector2 M_Client    = { 1535.0f,863.0f };
	Vector2 M_Window    = { 1920.0f,1080.0f };
	Vector2 M_PrevMouse = { 0.0f,0.0f };
	Vector2 M_Delta     = { 0.0f,0.0f };
	Vector2 M_Mouse     = { 0.0f,0.0f };
	Vector2 M_Converted = { 0.0f,0.0f };

	const double M_PI = 3.14159265358979323846;

	MouseFlag S_Flag;
	ClassGame S_Game;
	ClassObject S_Object;
	ClassDimensionalElement S_Element;
};