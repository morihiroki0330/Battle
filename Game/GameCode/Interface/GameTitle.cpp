#include "stdafx.h"
#include "GameTitle.h"

#include "GameCode/GameCode.h"
#include "DimensionalElement/DimensionalElement.h"
#include "DimensionalEffect/DimensionalEffect.h"
#include "DimensionalStorage/NumberStorage.h"
#include "Operation/Operation.h"
GameTitle::GameTitle()
{
	M_BackGroundTexture.Init("Assets/Sprite/GameTitle/BackGround.DDS", 1920.0f, 1080.0f, true);
	M_TextTexture.Init("Assets/Sprite/GameTitle/Text.DDS", 1520.0f, 150.0f, true);

	M_StartButton.Init("Assets/Sprite/GameTitle/StartButton.DDS", 300.0f, 150.0f, true);
	M_OptionButton.Init("Assets/Sprite/GameTitle/OptionButton.DDS", 300.0f, 150.0f, true);
	M_ExitButton.Init("Assets/Sprite/GameTitle/ExitButton.DDS", 300.0f, 150.0f, true);
}
bool GameTitle::Start()
{
	S_Game.P_Horizon        = FindGO<BattlefieldHorizon>("horizon");
	S_Element.P_Collision   = FindGO<DimensionalCollision>("collision");
	S_Effect.P_Fade         = FindGO<Fade>("fade");
	S_Operation.P_Mouse     = FindGO<Mouse>("mouse");

	S_Element.P_Collision->DecisionDataSet(M_StartButton.GetWideAndHeight().x  , M_StartButton.GetWideAndHeight().y  , M_StartButtonPosition.x  , M_StartButtonPosition.y  , COLLISION_STARTBUTTON , TAG_NON);
	S_Element.P_Collision->DecisionDataSet(M_OptionButton.GetWideAndHeight().x , M_OptionButton.GetWideAndHeight().y , M_OptionButtonPosition.x , M_OptionButtonPosition.y , COLLISION_OPTIONBUTTON , TAG_NON);
	S_Element.P_Collision->DecisionDataSet(M_ExitButton.GetWideAndHeight().x   , M_ExitButton.GetWideAndHeight().y   , M_ExitButtonPosition.x   , M_ExitButtonPosition.y   , COLLISION_EXITBUTTON , TAG_NON);
	return true;
}
void GameTitle::Update()
{
	Button();
	ButtonAfter();

	S_Element.P_Collision->DecisionSetPosition(M_StartButtonPosition.x  , M_StartButtonPosition.y  , COLLISION_STARTBUTTON);
	S_Element.P_Collision->DecisionSetPosition(M_OptionButtonPosition.x , M_OptionButtonPosition.y , COLLISION_OPTIONBUTTON);
	S_Element.P_Collision->DecisionSetPosition(M_ExitButtonPosition.x   , M_ExitButtonPosition.y   , COLLISION_EXITBUTTON);

	M_TextTexture.SetPosition(M_TextPosition);
	M_StartButton.SetPosition(M_StartButtonPosition);
	M_OptionButton.SetPosition(M_OptionButtonPosition);
	M_ExitButton.SetPosition(M_ExitButtonPosition);

	M_BackGroundTexture.Update();
	M_TextTexture.Update();
	M_StartButton.Update();
	M_OptionButton.Update();
	M_ExitButton.Update();
}
void GameTitle::Render(RenderContext& rc)
{
	M_BackGroundTexture.Draw(rc);
	M_TextTexture.Draw(rc);
	M_StartButton.Draw(rc);
	M_OptionButton.Draw(rc);
	M_ExitButton.Draw(rc);
}

void GameTitle::Button()
{
	if (S_Element.P_Collision->DecisionAndDecisionCollision(COLLISION_CURSOR, COLLISION_STARTBUTTON) && S_Operation.P_Mouse->GetMouseFlag(MOUSE_LEFTBUTTON))
	{
		if (!M_StartFlag && !M_OptionFlag && !M_ExitFlag)
		{
			S_Effect.P_Fade->StartFadeOut();
			M_StartFlag = true;
		}
	}else {
		if (S_Element.P_Collision->DecisionAndDecisionCollision(COLLISION_CURSOR, COLLISION_OPTIONBUTTON) && S_Operation.P_Mouse->GetMouseFlag(MOUSE_LEFTBUTTON))
		{
			if (!M_StartFlag && !M_OptionFlag && !M_ExitFlag)
			{
				M_OptionFlag = true;
			}
		}else {
			if (S_Element.P_Collision->DecisionAndDecisionCollision(COLLISION_CURSOR, COLLISION_EXITBUTTON) && S_Operation.P_Mouse->GetMouseFlag(MOUSE_LEFTBUTTON))
			{
				if (!M_StartFlag && !M_OptionFlag && !M_ExitFlag)
				{
					S_Effect.P_Fade->StartFadeOut();
					M_ExitFlag = true;
				}
			}
		}
	}
}
void GameTitle::ButtonAfter()
{
	if (!S_Effect.P_Fade->IsFade())
	{
		if (M_StartFlag)
		{
			S_Game.P_Horizon->Create(1);
		}else {
			if (M_OptionFlag)
			{

			}else {
				if (M_ExitFlag)
				{
					exit(EXIT_FAILURE);
				}
			}
		}
	}
}