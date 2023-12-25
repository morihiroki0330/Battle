#include "stdafx.h"
#include "GameTitle.h"

#include "GameCode/GameCode.h"
#include "DimensionalElement/DimensionalElement.h"
#include "DimensionalEffect/DimensionalEffect.h"
#include "DimensionalStorage/NumberStorage.h"
#include "Operation/Operation.h"
GameTitle::GameTitle()
{
	S_Graphics.M_BackGroundTexture.Init("Assets/Sprite/GameTitle/BackGround.DDS", 1920.0f, 1080.0f, true);
	S_Graphics.M_TextTexture.Init("Assets/Sprite/GameTitle/Text.DDS", 1520.0f, 150.0f, true);

	S_Button.M_StartButton.Init("Assets/Sprite/GameTitle/StartButton.DDS", 300.0f, 150.0f, true);
	S_Button.M_OptionButton.Init("Assets/Sprite/GameTitle/OptionButton.DDS", 300.0f, 150.0f, true);
	S_Button.M_ExitButton.Init("Assets/Sprite/GameTitle/ExitButton.DDS", 300.0f, 150.0f, true);
}
bool GameTitle::Start()
{
	S_Game.P_Horizon        = FindGO<BattlefieldHorizon>("horizon");
	S_Element.P_Collision   = FindGO<DimensionalCollision>("collision");
	S_Effect.P_Fade         = FindGO<Fade>("fade");
	S_Operation.P_Mouse     = FindGO<Mouse>("mouse");

	S_Element.P_Collision->DecisionDataSet(S_Button.M_StartButton.GetWideAndHeight().x  , S_Button.M_StartButton.GetWideAndHeight().y  , S_Button.M_StartButtonPosition.x  , S_Button.M_StartButtonPosition.y  , COLLISION_STARTBUTTON , TAG_NON);
	S_Element.P_Collision->DecisionDataSet(S_Button.M_OptionButton.GetWideAndHeight().x , S_Button.M_OptionButton.GetWideAndHeight().y , S_Button.M_OptionButtonPosition.x , S_Button.M_OptionButtonPosition.y , COLLISION_OPTIONBUTTON , TAG_NON);
	S_Element.P_Collision->DecisionDataSet(S_Button.M_ExitButton.GetWideAndHeight().x   , S_Button.M_ExitButton.GetWideAndHeight().y   , S_Button.M_ExitButtonPosition.x   , S_Button.M_ExitButtonPosition.y   , COLLISION_EXITBUTTON , TAG_NON);
	return true;
}
void GameTitle::Update()
{
	Button();
	ButtonAfter();

	S_Element.P_Collision->DecisionSetPosition(S_Button.M_StartButtonPosition.x  , S_Button.M_StartButtonPosition.y  , COLLISION_STARTBUTTON);
	S_Element.P_Collision->DecisionSetPosition(S_Button.M_OptionButtonPosition.x , S_Button.M_OptionButtonPosition.y , COLLISION_OPTIONBUTTON);
	S_Element.P_Collision->DecisionSetPosition(S_Button.M_ExitButtonPosition.x   , S_Button.M_ExitButtonPosition.y   , COLLISION_EXITBUTTON);

	S_Graphics.M_TextTexture.SetPosition(S_Graphics.M_TextPosition);
	S_Button.M_StartButton.SetPosition(S_Button.M_StartButtonPosition);
	S_Button.M_OptionButton.SetPosition(S_Button.M_OptionButtonPosition);
	S_Button.M_ExitButton.SetPosition(S_Button.M_ExitButtonPosition);

	S_Graphics.M_BackGroundTexture.Update();
	S_Graphics.M_TextTexture.Update();
	S_Button.M_StartButton.Update();
	S_Button.M_OptionButton.Update();
	S_Button.M_ExitButton.Update();
}
void GameTitle::Render(RenderContext& rc)
{
	S_Graphics.M_BackGroundTexture.Draw(rc);
	S_Graphics.M_TextTexture.Draw(rc);
	S_Button.M_StartButton.Draw(rc);
	S_Button.M_OptionButton.Draw(rc);
	S_Button.M_ExitButton.Draw(rc);
}

void GameTitle::Button()
{
	if (S_Element.P_Collision->DecisionAndDecisionCollision(COLLISION_CURSOR, COLLISION_STARTBUTTON) && S_Operation.P_Mouse->GetMouseFlag(MOUSE_LEFTBUTTON))
	{
		if (!S_Button.M_StartFlag && !S_Button.M_OptionFlag && !S_Button.M_ExitFlag)
		{
			S_Effect.P_Fade->StartFadeOut();
			S_Button.M_StartFlag = true;
		}
	}else {
		if (S_Element.P_Collision->DecisionAndDecisionCollision(COLLISION_CURSOR, COLLISION_OPTIONBUTTON) && S_Operation.P_Mouse->GetMouseFlag(MOUSE_LEFTBUTTON))
		{
			if (!S_Button.M_StartFlag && !S_Button.M_OptionFlag && !S_Button.M_ExitFlag)
			{
				S_Button.M_OptionFlag = true;
			}
		}else {
			if (S_Element.P_Collision->DecisionAndDecisionCollision(COLLISION_CURSOR, COLLISION_EXITBUTTON) && S_Operation.P_Mouse->GetMouseFlag(MOUSE_LEFTBUTTON))
			{
				if (!S_Button.M_StartFlag && !S_Button.M_OptionFlag && !S_Button.M_ExitFlag)
				{
					S_Effect.P_Fade->StartFadeOut();
					S_Button.M_ExitFlag = true;
				}
			}
		}
	}
}
void GameTitle::ButtonAfter()
{
	if (!S_Effect.P_Fade->IsFade())
	{
		if (S_Button.M_StartFlag)
		{
			S_Game.P_Horizon->Create(1);
		}else {
			if (S_Button.M_OptionFlag)
			{

			}else {
				if (S_Button.M_ExitFlag)
				{
					exit(EXIT_FAILURE);
				}
			}
		}
	}
}