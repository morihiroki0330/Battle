#pragma once
#include "DimensionalStorage/StructStorage.h"
class Game : public IGameObject
{
public:
	Game();
	~Game();
private:
	ClassGame S_Game;
	ClassDimensionalElement S_Element;
	ClassDimensionalEffect S_Effect;
	ClassOperation S_Operation;
	ClassInterface S_Interface;
};

