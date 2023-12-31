#include "stdafx.h"
#include "GameResult.h"

#include "GameCode/GameCode.h"
#include "DimensionalElement/DimensionalElement.h"
#include "DimensionalStorage/NumberStorage.h"
#include "Operation/Operation.h"
GameResult::GameResult()
{
	M_GameResultTexture.Init("Assets/Sprite/GameResult/BackGround.DDS", 1920.0f, 1080.0f, true);
	M_ResultButton.Init("Assets/Sprite/GameResult/ResultButton.DDS", 300.0f, 150.0f, true);
}
bool GameResult::Start()
{
	S_Game.P_Horizon      = FindGO<BattlefieldHorizon>("horizon");
	S_Element.P_Collision = FindGO<DimensionalCollision>("collision");
	S_Operation.P_Mouse   = FindGO<Mouse>("mouse");

	S_Element.P_Collision->DecisionDataSet(M_ResultButton.GetWideAndHeight().x , M_ResultButton.GetWideAndHeight().y , 0.0f , 0.0f , COLLISION_RESULTBUTTON , TAG_NON);
	return true;
}
void GameResult::Update()
{
	if (S_Element.P_Collision->DecisionAndDecisionCollision(COLLISION_CURSOR, COLLISION_RESULTBUTTON) && S_Operation.P_Mouse->GetMouseFlag(MOUSE_LEFTBUTTON))
	{S_Game.P_Horizon->Create(0);}

	M_GameResultTexture.Update();
	M_ResultButton.Update();
}
void GameResult::Render(RenderContext& rc)
{
	M_GameResultTexture.Draw(rc);
	M_ResultButton.Draw(rc);
}