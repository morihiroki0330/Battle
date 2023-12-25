#pragma once
enum EnGroundType
{
	GROUNDTYPE_GRASS,
	GROUNDTYPE_SOIL,
	GROUNDTYPE_SEE,
	GROUNDTEXTURE,
	GROUNDHEIGHT,
	GROUNDTYPE_NUM
};
class TileMap : public IGameObject
{
public:
	TileMap();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	ModelRender M_TileModel;

	Vector3 M_TilePosition={0.0f,0.0f,0.0f};

	PhysicsStaticObject M_PhysicsStaticObject;

	Texture M_Texture[GROUNDTYPE_NUM];

	const wchar_t* M_TextureFilePath[GROUNDTYPE_NUM];
};

