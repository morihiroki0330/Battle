#pragma once
/*此処からクラスのポインタ*/
class BattlefieldHorizon;
struct ClassGame
{
	BattlefieldHorizon* P_Horizon = nullptr;
};

class GameTitle;
class GameResult;
class Sound;
class Ui;
struct ClassInterface
{
	GameTitle* P_GameTitle   = nullptr;
	GameResult* P_GameResult = nullptr;
	Sound* P_Sound           = nullptr;
	Ui* P_Ui                 = nullptr;
};

class Enemy;
class EnemySpawner;
struct ClassEnemy
{
	Enemy* P_Enemy               = nullptr;
	EnemySpawner* P_EnemySpawner = nullptr;
};

class Player;
struct ClassPlayer
{
	Player* P_Player             = nullptr;
};

class TileMap;
class GameCamera;
struct ClassObject
{
	TileMap* P_TileMap       = nullptr;
	GameCamera* P_GameCamera = nullptr;
};

class Gun;
class GunSight;
class GunSound;
class Bullet;
struct ClassGun
{
	Gun* P_Gun           = nullptr;
	GunSight* P_GunSight = nullptr;
	GunSound* P_GunSound = nullptr;
	Bullet* P_Bullet     = nullptr;
};

class DimensionalCollision;
struct ClassDimensionalElement
{
	DimensionalCollision* P_Collision = nullptr;
};

class Fade;
class Sky;
struct ClassDimensionalEffect
{
	Fade* P_Fade = nullptr;
	Sky* P_Sky   = nullptr;
};

class Mouse;
class Controller;
struct ClassOperation
{
	Mouse* P_Mouse           = nullptr;
	Controller* P_Controller = nullptr;
};