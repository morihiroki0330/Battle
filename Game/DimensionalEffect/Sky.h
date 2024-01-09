#pragma once
#include "DimensionalStorage/NumberStorage.h"
class Sky : public IGameObject
{
public:
	Sky();
	bool Start();
	void Render(RenderContext& rc);
private:
	ModelRender M_Collision;
	ModelRender M_SkyBox;
	
	Texture M_Texture[5];
	const wchar_t* M_TextureFilePaths[5];
	
	Vector3 M_CollisionPosition = { 0.0f,0.0f,0.0f };

	SkyBoxStorage M_Type = SkyBoxType_Morning;

	PhysicsStaticObject M_PhysicsStaticObject;
};

