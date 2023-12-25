#pragma once
class Sound : public IGameObject
{
public:
	Sound();
	float GetSeVolume()
	{return M_SeVolume;}
	float GetBgmVolume()
	{return M_BgmVolume;}
private:
	float M_SeVolume  = 0.5f;
	float M_BgmVolume = 1.0f;
};

