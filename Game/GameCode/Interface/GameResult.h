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
	SpriteRender M_GameResultTexture;
	SpriteRender M_ResultButton;

	ClassGame S_Game;
	ClassDimensionalElement S_Element;
	ClassOperation S_Operation;
};

