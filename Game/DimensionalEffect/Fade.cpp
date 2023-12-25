#include "stdafx.h"
#include "Fade.h"
Fade::Fade()
{
	M_FadeTexture.Init("Assets/Sprite/Black.DDS", 1920.0f, 1080.0f, true);
	M_FadeTexture.Update();
}
void Fade::Update()
{
	if (M_State == ENSTATE_FADEIN)
	{
		FadeIn();
	}else {
		if (M_State == ENSTATE_FADEOUT)
		{
			FadeOut();
		}
	}
}
void Fade::Render(RenderContext& rc)
{
	if (M_Alpha > 0.0f)
	{
		M_FadeTexture.SetMulColor({ 1.0f,1.0f,1.0f, M_Alpha });
		M_FadeTexture.Draw(rc);
	}
}

void Fade::FadeIn()
{
	if (M_AlphaResetDecision)
	{
		M_Alpha = 10.0f;
		M_AlphaResetDecision = false;
	}
	M_Alpha -= FadeSpeed * g_gameTime->GetFrameDeltaTime();
	if (M_Alpha <= 0.0f)
	{
		M_Alpha = 0.0f;
		M_State = ENSTATE_IDLE;
		M_AlphaResetDecision = true;
	}
}
void Fade::FadeOut()
{
	if (M_AlphaResetDecision)
	{
		M_Alpha = 0.0f;
		M_AlphaResetDecision = false;
	}
	M_Alpha += FadeSpeed * g_gameTime->GetFrameDeltaTime();
	if (M_Alpha >= 10.0f)
	{
		M_Alpha = 10.0f;
		M_State = ENSTATE_IDLE;
		M_AlphaResetDecision = true;
	}
}