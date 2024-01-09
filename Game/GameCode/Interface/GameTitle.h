#pragma once
#include "DimensionalStorage/StructStorage.h"
class GameTitle : public IGameObject
{
public:
	GameTitle();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void Button();
	void ButtonAfter();
private:
	SpriteRender M_BackGroundTexture;
	SpriteRender M_Cloud[10];
	SpriteRender M_TextTexture;
	
	SpriteRender M_StartButton;
	SpriteRender M_OptionButton;
	SpriteRender M_ExitButton;

	Vector3 M_CloudPosition[10];
	Vector3 M_TextPosition         = { 0.0f , 300.0f  , 0.0f };
	Vector3 M_StartButtonPosition  = { 0.0f , 100.0f  , 0.0f };
	Vector3 M_OptionButtonPosition = { 0.0f , -80.0f  , 0.0f };
	Vector3 M_ExitButtonPosition   = { 0.0f , -260.0f , 0.0f };

	int M_CloudCount;

	bool M_CloudFlag[10];
	bool M_StartFlag = false;
	bool M_OptionFlag = false;
	bool M_ExitFlag = false;

	ClassGame S_Game;
	ClassDimensionalElement S_Element;
	ClassDimensionalEffect S_Effect;
	ClassOperation S_Operation;
};

