#pragma once
#include "DimensionalStorage/NumberStorage.h"
class Fade : public IGameObject
{
public:
	Fade();
	void Update();
	void Render(RenderContext& rc);

	void StartFadeIn() { M_State = ENSTATE_FADEIN; }
	void StartFadeOut() { M_State = ENSTATE_FADEOUT; }

	void FadeIn();
	void FadeOut();

	const bool IsFade() const
	{return M_State != ENSTATE_IDLE;}

	int a = 1;
private:
	SpriteRender M_FadeTexture;
	Vector4 M_ButtonCollar = { 1.0f, 1.0f, 1.0f, 1.0f };

	int M_State = ENSTATE_FADEIN;
	bool M_AlphaResetDecision = true;
	float M_Alpha             = 10.0f;
	float FadeSpeed           = 5.0f;
};



