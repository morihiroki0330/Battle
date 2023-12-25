#pragma once
#include "DimensionalStorage/StructStorage.h"
class GameResult : public IGameObject
{
public:
	GameResult();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	DataGameResultGraphics S_Graphics;
	DataGameResultButton S_Button;

	ClassGame S_Game;
	ClassDimensionalElement S_Element;
	ClassOperation S_Operation;
};

