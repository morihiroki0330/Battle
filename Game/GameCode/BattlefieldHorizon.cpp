#include "stdafx.h"
#include "BattlefieldHorizon.h"

#include "GameCode.h"
#include "DimensionalElement/DimensionalElement.h"
#include "DimensionalEffect/DimensionalEffect.h"
#include "DimensionalStorage/NumberStorage.h"

BattlefieldHorizon::BattlefieldHorizon()
{
	Create(0);
}
BattlefieldHorizon::~BattlefieldHorizon()
{

}
bool BattlefieldHorizon::Start()
{
	return true;
}
void BattlefieldHorizon::Update()
{
	S_Effect.P_Fade = FindGO<Fade>("fade");
	PSA = FindGOs<Fade>("fade");

	S_Element.P_Collision = FindGO<DimensionalCollision>("collision");

	if (M_ClearFlag)
	{
		S_Effect.P_Fade->StartFadeOut();
		Clear = true;
		M_ClearFlag = false;
	}

	if (!S_Effect.P_Fade->IsFade())
	{
		if (Clear)
		{
			Create(2);
			Clear = false;
		}
	}
}
void BattlefieldHorizon::Reset()
{
	bool Clear = false;
	bool M_ClearFlag = false;
}
void BattlefieldHorizon::Create(int Number)
{
	switch (Number)
	{
	case 0:
		if (S_Interface.P_GameResult != nullptr)
		{
			DeleteGO(S_Interface.P_GameResult);
			S_Element.P_Collision->DecisionDataDelete(COLLISION_STARTBUTTON);
			S_Element.P_Collision->DecisionDataDelete(COLLISION_OPTIONBUTTON);
			S_Element.P_Collision->DecisionDataDelete(COLLISION_EXITBUTTON);
			S_Element.P_Collision->DecisionDataDelete(COLLISION_RESULTBUTTON);
			Reset();
		}
		S_Interface.P_GameTitle = NewGO<GameTitle>(0, "gametitle");
		break;
	case 1:
		DeleteGO(S_Interface.P_GameTitle);
		S_Effect.P_Fade->StartFadeIn();
		S_Effect.P_Sky = NewGO<Sky>(0, "sky");

		S_Player.P_Player = NewGO<Player>(0, "player");

		S_Object.P_TileMap = NewGO<TileMap>(0, "tilemap");
		S_Object.P_GameCamera = NewGO<GameCamera>(0, "gamecamera");

		S_Enemy.P_EnemySpawner = NewGO<EnemySpawner>(0, "enemyspawner");

		S_Interface.P_Ui = NewGO<Ui>(1, "ui");
		break;
	case 2:
		DeleteGO(S_Player.P_Player);
		DeleteGO(S_Object.P_TileMap);
		DeleteGO(S_Object.P_GameCamera);
		DeleteGO(S_Enemy.P_EnemySpawner);
		DeleteGO(S_Effect.P_Sky);
		DeleteGO(S_Interface.P_Ui);

		S_Effect.P_Fade->StartFadeIn();

		S_Interface.P_GameResult = NewGO<GameResult>(0, "gameresult");
	}
}