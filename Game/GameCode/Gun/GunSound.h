#pragma once
#include "DimensionalStorage/StructStorage.h"
class GunSound : public IGameObject
{
public:
	GunSound();
	void Update()
	{
		if (!P_GunSe->IsPlaying())
		{DeleteGO(this);}
	}
private:
	ClassGun S_Gun;
	ClassInterface S_Interface;
	SoundSource* P_GunSe = nullptr;
};

