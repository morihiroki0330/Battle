#include "stdafx.h"
#include "Sky.h"
Sky::Sky()
{
	M_TextureFilePaths[SkyBoxType_Morning] = L"Assets/modelData/SkyBox/SkyBox_Morning.DDS";
	M_TextureFilePaths[SkyBoxType_Noon] = L"Assets/modelData/SkyBox/SkyBox_Noon.DDS";
	M_TextureFilePaths[SkyBoxType_Night] = L"Assets/modelData/SkyBox/SkyBox_Night.DDS";
}
bool Sky::Start()
{
	ModelInitData InitData;
	InitData.m_tkmFilePath = "Assets/modelData/SkyBox/SkyBox.tkm";
	InitData.m_fxFilePath = "Assets/shader/SkyBoxMap.fx";
	InitData.m_vsEntryPointFunc = "VSMain";
	InitData.m_psEntryPointFunc = "PSMain";

	for (int i = 0; i < SkyBoxType_Num; i++)
	{M_Texture[i].InitFromDDSFile(M_TextureFilePaths[i]);}
	InitData.m_expandShaderResoruceView[0] = &M_Texture[Type];
	M_SkyBox.InitForwardRendering(InitData);
	M_SkyBox.Update();

	M_Collision.Init("Assets/modelData/SkyBox/Collision.tkm");
	M_PhysicsStaticObject.CreateFromModel(M_Collision.GetModel(), M_Collision.GetModel().GetWorldMatrix());
	M_Collision.Update();
	return true;
}
void Sky::Render(RenderContext& rc)
{
	M_SkyBox.Draw(rc);
}