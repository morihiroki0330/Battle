#include "stdafx.h"
#include "GunSound.h"

#include "GameCode/GameCode.h"
#include "DimensionalStorage/NumberStorage.h"
GunSound::GunSound()
{
	P_GunSe = NewGO<SoundSource>(0);
	S_Gun.P_Gun = FindGO<Gun>("gun");
	S_Interface.P_Sound = FindGO<Sound>("sound");
	if (S_Gun.P_Gun->GetBulletCount() > 0)
	{
		P_GunSe->Init(SE_GUNSHOT);
	}else {
		P_GunSe->Init(SE_GUNSHOTOUT);
	}
	P_GunSe->SetVolume(S_Interface.P_Sound->GetSeVolume());
	P_GunSe->Play(false);
}