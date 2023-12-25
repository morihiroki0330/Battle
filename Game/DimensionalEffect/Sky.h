#pragma once
#include "DimensionalStorage/NumberStorage.h"
class Sky : public IGameObject
{
public:
	Sky();
	bool Start();
	void Render(RenderContext& rc);

	void SetType(SkyBoxStorage type)
	{Type = type;}
private:
	Texture M_Texture[5];
	const wchar_t* M_TextureFilePaths[5];
	ModelRender M_SkyBox;
	SkyBoxStorage Type = SkyBoxType_Morning;

	ModelRender M_Collision;
	Vector3 M_CollisionPosition = { 0.0f,0.0f,0.0f };
	PhysicsStaticObject M_PhysicsStaticObject;
};

