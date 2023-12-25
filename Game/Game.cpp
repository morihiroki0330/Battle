#include "stdafx.h"
#include "Game.h"

#include "GameCode/GameCode.h"
#include "DimensionalElement/DimensionalElement.h"
#include "DimensionalEffect/DimensionalEffect.h"
#include "DimensionalStorage/NumberStorage.h"
#include "Operation/Operation.h"
Game::Game()
{
	PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();

	S_Game.P_Horizon = NewGO<BattlefieldHorizon>(0, "horizon");

	S_Element.P_Collision  = NewGO<DimensionalCollision>(0, "collision");

	S_Effect.P_Fade       = NewGO<Fade>(3, "fade");
	S_Effect.P_Fade->a = 2;
	S_Effect.P_Fade       = NewGO<Fade>(3, "fade");
	S_Effect.P_Fade->a = 45;


	S_Interface.P_Sound      = NewGO<Sound>(0, "sound");
	
	S_Operation.P_Mouse      = NewGO<Mouse>(1, "mouse");
	S_Operation.P_Controller    = NewGO<Controller>(1, "controller");
}
Game::~Game()
{
	DeleteGO(S_Game.P_Horizon);
	
	DeleteGO(S_Element.P_Collision);
	
	DeleteGO(S_Effect.P_Fade);

	DeleteGO(S_Interface.P_Sound);

	DeleteGO(S_Operation.P_Mouse);
	DeleteGO(S_Operation.P_Controller);
	
}