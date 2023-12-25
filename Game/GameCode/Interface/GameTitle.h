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
	DataGameTitleGraphics S_Graphics;
	DataGameTitleButton S_Button;

	ClassGame S_Game;
	ClassDimensionalElement S_Element;
	ClassDimensionalEffect S_Effect;
	ClassOperation S_Operation;
};

