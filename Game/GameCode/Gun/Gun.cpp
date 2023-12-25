#include "stdafx.h"
#include "Gun.h"

#include "GameCode/GameCode.h"
#include "DimensionalStorage/NumberStorage.h"
#include "Operation/Operation.h"
Gun::Gun()
{
	S_Gun.P_GunSight = NewGO<GunSight>(0, "gunsight");
	S_Operation.P_Mouse = FindGO<Mouse>("mouse");
}
Gun::~Gun()
{
	DeleteGO(S_Gun.P_GunSight);
}
void Gun::Update()
{
	Shot();
	Reload();
}

void Gun::Shot()
{
	if (S_Operation.P_Mouse->GetMouseFlag(MOUSE_LEFTBUTTON) && !S_GunData.M_CoolDownFlag && S_GunData.M_BulletCount > 0)
	{
		NewGO<Bullet>(0, "bullet");
		NewGO<GunSound>(0, "gunsound");
		S_GunData.M_CoolDownFlag = true;
		S_GunData.M_BulletCount--;
	}else {
		if (S_GunData.M_CoolDownFlag)
		{
			S_GunData.M_CoolDownTime++;
			if (S_GunData.M_CoolDownTime >= S_GunData.M_CoolDownTimeFixed)
			{
				S_GunData.M_CoolDownFlag = false;
				S_GunData.M_CoolDownTime = 0;
			}
		}
		if (S_Operation.P_Mouse->GetMouseFlag(MOUSE_LEFTBUTTON))
		{
			NewGO<GunSound>(0, "gunsound");
		}
	}
}
void Gun::Reload()
{
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{S_GunData.M_BulletCount = S_GunData.M_BulletMaxCount;}
}