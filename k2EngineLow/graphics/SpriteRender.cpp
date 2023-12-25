#include "k2EngineLowPreCompile.h"
#include "SpriteRender.h"

namespace nsK2EngineLow
{
	void SpriteRender::Init
	(
		const char* Sprite,
		const float w,
		const float h,
		bool ColorOut,
		bool ColorChange,
		AlphaBlendMode alphaBlendMode
	)
	{
		if (ColorChange)
		{
			InitData.m_fxFilePath = "Assets/shader/ColorChange.fx";
		}else {
			if (ColorOut)
			{
				InitData.m_fxFilePath = "Assets/shader/ColorOut.fx";
			}else {
				InitData.m_fxFilePath = "Assets/shader/sprite.fx";
			}
		}
		InitData.m_vsEntryPointFunc = "VSMain";
		InitData.m_psEntryPoinFunc = "PSMain";

		InitData.m_ddsFilePath[0] = Sprite;

		InitData.m_width = static_cast<UINT>(w);
		InitData.m_height = static_cast<UINT>(h);

		InitData.m_alphaBlendMode = alphaBlendMode;

		M_InitFlag = true;

		M_WideAndHeight.x = w;
		M_WideAndHeight.y = h;

		m_sprite.Init(InitData);
	}

	void SpriteRender::WeatherInit
	(
		const char* Sprite,
		const float w,
		const float h,
		AlphaBlendMode alphaBlendMode
	)
	{
		InitData.m_fxFilePath = "Assets/shader/Weather.fx";

		InitData.m_vsEntryPointFunc = "VSMain";
		InitData.m_psEntryPoinFunc = "PSMain";

		InitData.m_ddsFilePath[0] = Sprite;

		InitData.m_width = static_cast<UINT>(w);
		InitData.m_height = static_cast<UINT>(h);

		InitData.m_alphaBlendMode = alphaBlendMode;

		m_sprite.Init(InitData);
	}

	void SpriteRender::MiniMapInit
	(
		SpriteInitData Data,
		AlphaBlendMode alphaBlendMode
	)
	{
		Data.m_alphaBlendMode = alphaBlendMode;
		m_sprite.Init(Data);
	}

	void SpriteRender::TextureSet(const char* Sprite)
	{
		InitData.m_ddsFilePath[0] = Sprite;
		m_sprite.Init(InitData);
	}

	void SpriteRender::Draw(RenderContext& rc)
	{
		g_renderingEngine->InRenderObject(this);
	}

	void SpriteRender::OnRender2D(RenderContext& rc)
	{
		m_sprite.Draw(rc);
	}
}

