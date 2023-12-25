#include "stdafx.h"
#include "Controller.h"
void Controller::Update()
{
	M_LStick.x = g_pad[0]->GetLStickXF();
	M_LStick.y = g_pad[0]->GetLStickYF();

	M_RStick.x = g_pad[0]->GetRStickXF();
	M_RStick.y = g_pad[0]->GetRStickYF();

	M_RStick.x *= 10.0f;
	M_RStick.y *= -10.0f;
}