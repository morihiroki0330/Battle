#pragma once
#include "DimensionalStorage/StructStorage.h"
class Player : public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void PlayerMove();
	void PlayerFall();
	void PlayerDamage(int Damage);

	void InitValue();

	int GetPlayerHp()
	{return S_Player.M_PlayerHp;}

	bool PlayerIsSelf(const btCollisionObject& contactObject)
	{return S_Player.M_PlayerGhost.IsSelf(contactObject);}

	const Vector3& GetPosition()
	{return S_Player.M_PlayerPosition;}

	const Vector3& GetSpped()
	{return S_Player.M_PlayerPosition;}
private:
	DataPlayer S_Player;

	ClassOperation S_Operation;
	ClassObject S_Object;
	ClassGun S_Gun;

	FontRender FX;
	wchar_t M_X[256];
	
	FontRender FY;
	wchar_t M_Y[256];

	FontRender FZ;
	wchar_t M_Z[256];
}; 

