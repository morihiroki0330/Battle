#pragma once
//ステージは38000.0f*38000.0f
//探知機は3000.0f*3000.0f
//探知機のアスペクトは380f*380f
#include "DimensionalStorage/StructStorage.h"
class BattlefieldHorizon : public IGameObject
{
public:
	BattlefieldHorizon();
	~BattlefieldHorizon();
	bool Start();
	void Update();
	void Create(int Number);
	
	void Reset();
	void ClearFlag()
	{M_ClearFlag = true;}

	void ScoreAdd(int Score)
	{M_Score += Score;}

	int GetWave()
	{return M_Wave;}
	int GetScore()
	{return M_Score;}
private:
	ClassInterface S_Interface;
	ClassPlayer S_Player;
	ClassEnemy S_Enemy;
	ClassObject S_Object;

	ClassDimensionalEffect S_Effect;
	ClassDimensionalElement S_Element;

	bool Clear = false;
	bool M_ClearFlag = false;

	int M_Wave = 1;
	int M_Score = 0;

	std::vector<Fade*> PSA;
};

