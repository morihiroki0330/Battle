#pragma once
class Controller : public IGameObject
{
public:
	void Update();
	Vector2 GetLStick()
	{return M_LStick;}
	Vector2 GetRStick()
	{return M_RStick;}
private:
	Vector2 M_LStick = { 0.0f , 0.0f };
	Vector2 M_RStick = { 0.0f , 0.0f };
};

