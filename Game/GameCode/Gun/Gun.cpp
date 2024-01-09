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
	if (S_Operation.P_Mouse->GetMouseFlag(MOUSE_LEFTBUTTON) && !M_CoolDownFlag && M_BulletCount > 0)
	{
		NewGO<Bullet>(0, "bullet");
		NewGO<GunSound>(0, "gunsound");
		M_CoolDownFlag = true;
		M_BulletCount--;
	}else {
		if (M_CoolDownFlag)
		{
			M_CoolDownTime++;
			if (M_CoolDownTime >= M_CoolDownTimeFixed)
			{
				M_CoolDownFlag = false;
				M_CoolDownTime = 0;
			}
		}
	}
}
void Gun::Reload()
{
	if (GetAsyncKeyState(VK_SPACE) & 0x8000 && M_ReloadFlag)
	{
		NewGO<GunSound>(0, "gunsound");
		M_BulletCount = M_BulletMaxCount;
		M_ReloadFlag = false;
	}
}