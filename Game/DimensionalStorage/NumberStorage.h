#pragma once
enum CollisionStorage
{
	COLLISION_CURSOR,
	COLLISION_STARTBUTTON,
	COLLISION_OPTIONBUTTON,
	COLLISION_EXITBUTTON,
	COLLISION_RESULTBUTTON,
	COLLISION_NON
};
enum TagStorage
{
	TAG_NON
};
enum MapStorage
{
	MAP_NON
};

enum MouseFlagStorage
{
	MOUSE_LEFTBUTTON = 0,
	MOUSE_RIGHTBUTTON = 1,
	MOUSE_FLICK = 2,
	MOUSE_WHEEL = 3
};

enum SoundNumberStorage
{
	SE_GUNSHOT,
	SE_GUNSHOTOUT,
};

enum FadeStateStorage
{
	ENSTATE_FADEIN = 1,
	ENSTATE_FADEOUT = 2,
	ENSTATE_IDLE = 3,
};

enum SkyBoxStorage
{
	SkyBoxType_Morning,
	SkyBoxType_Noon,
	SkyBoxType_Night,
	SkyBoxType_Num
};

