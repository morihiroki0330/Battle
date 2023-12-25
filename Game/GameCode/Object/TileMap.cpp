#include "stdafx.h"
#include "TileMap.h"
TileMap::TileMap()
{
	M_TextureFilePath[GROUNDTYPE_GRASS] = L"Assets/modelData/TileMap/TileTexture/a.DDS";
	M_TextureFilePath[GROUNDTYPE_SOIL] = L"Assets/modelData/TileMap/TileTexture/b.DDS";
	M_TextureFilePath[GROUNDTYPE_SEE] = L"Assets/modelData/TileMap/TileTexture/c.DDS";
	M_TextureFilePath[GROUNDTEXTURE] = L"Assets/modelData/TileMap/TileMapData/TextureMap2.DDS";
	M_TextureFilePath[GROUNDHEIGHT] = L"Assets/modelData/TileMap/TileMapData/HeightMap.DDS";
}

bool TileMap::Start()
{
	ModelInitData M_InitData;
	M_InitData.m_tkmFilePath = "Assets/modelData/TileMap/TileModel/TileMap3.tkm";
	M_InitData.m_fxFilePath = "Assets/shader/Terrain.fx";
	M_InitData.m_vsEntryPointFunc = "VSMain";
	M_InitData.m_psEntryPointFunc = "PSMain";

	for (int i = 0; i < GROUNDTYPE_NUM; i++) 
	{
		M_Texture[i].InitFromDDSFile(M_TextureFilePath[i]);
		M_InitData.m_expandShaderResoruceView[i] = &M_Texture[i];
	}

	M_TileModel.InitForwardRendering(M_InitData);
	M_PhysicsStaticObject.CreateFromModel(M_TileModel.GetModel(), M_TileModel.GetModel().GetWorldMatrix());
	M_TileModel.Update();
	return true;
}

void TileMap::Update()
{
	M_TileModel.SetPosition(M_TilePosition);
	M_TileModel.Update();
}

void TileMap::Render(RenderContext& rc)
{
	M_TileModel.Draw(rc);
}
