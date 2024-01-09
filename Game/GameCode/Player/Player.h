#pragma once
#include "DimensionalStorage/StructStorage.h"
#include "physics/PhysicsGhostObject.h"
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
	{return M_PlayerHp;}

	bool PlayerIsSelf(const btCollisionObject& contactObject)
	{return M_PlayerGhost.IsSelf(contactObject);}

	const Vector3& GetPosition()
	{return M_PlayerPosition;}

	const Vector3& GetSpped()
	{return M_PlayerPosition;}
private:
	ModelRender M_PlayerModel;

	Vector3 M_PlayerPosition = { 0.0f , 500.0f , 0.0f };
	Vector3 M_PlayerSpeed    = { 0.0f , 0.0f   , 0.0f };
	Vector3 M_PlayerForward  = { 0.0f , 0.0f   , 0.0f };
	Vector3 M_PlayerRight    = { 0.0f , 0.0f   , 0.0f };

	CharacterController M_PlayerController;
	PhysicsGhostObject M_PlayerGhost;

	int M_PlayerHp = 100;
	int M_CoolDownTime = 0;
	int M_CoolDownTimeFixed = 10;

	bool M_CoolDownFlag = false;

	ClassOperation S_Operation;
	ClassObject S_Object;
	ClassGun S_Gun;
}; 

