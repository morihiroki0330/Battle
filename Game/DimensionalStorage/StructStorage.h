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

/*此処からクラスのデータ*/

//ゲームタイトル
struct DataGameTitleGraphics
{
	SpriteRender M_BackGroundTexture;
	SpriteRender M_Cloud[10];
	SpriteRender M_TextTexture;

	Vector3 M_CloudPosition[10];
	Vector3 M_TextPosition = { 0.0f,300.0f,0.0f };

	int M_CloudCount;
	bool M_CloudFlag[10];
};
struct DataGameTitleButton
{
	SpriteRender M_StartButton;
	SpriteRender M_OptionButton;
	SpriteRender M_ExitButton;

	Vector3 M_StartButtonPosition  = { 0.0f , 100.0f  , 0.0f };
	Vector3 M_OptionButtonPosition = { 0.0f , -80.0f  , 0.0f };
	Vector3 M_ExitButtonPosition   = { 0.0f , -260.0f , 0.0f };

	bool M_StartFlag  = false;
	bool M_OptionFlag = false;
	bool M_ExitFlag   = false;
};

//ゲームリザルト
struct DataGameResultGraphics
{
	SpriteRender M_GameResultTexture;
};
struct DataGameResultButton
{
	SpriteRender M_ResultButton;
};

//プレイヤー
#include "physics/PhysicsGhostObject.h"
struct DataPlayer
{
	ModelRender M_PlayerModel;

	Vector3 M_PlayerPosition = { 0.0f , 500.0f , 0.0f };
	Vector3 M_PlayerSpeed    = { 0.0f , 0.0f   , 0.0f };
	Vector3 M_PlayerForward  = { 0.0f , 0.0f   , 0.0f };
	Vector3 M_PlayerRight    = { 0.0f , 0.0f   , 0.0f };

	CharacterController M_PlayerController;
	PhysicsGhostObject M_PlayerGhost;

	int M_PlayerHp = 100;
	
	bool M_CoolDownFlag = false;
	int M_CoolDownTime = 0;
	int M_CoolDownTimeFixed = 10;
};

//ゲームカメラ
struct DataCamera
{
	Vector3 M_CameraPosition = { 0.0f , 150.0f , 0.0f };
	Vector3 M_CameraTarget   = { 0.0f , 0.0f   , 9000000.0f };
	Vector2 M_MovePosition   = { 0.0f , 0.0f };

	int M_Angle = 0;

	const float M_CircleFication = 9000000.0f;
	const float M_MagniFication  = 10000.0f;
};

//銃弾
#include "physics/PhysicsGhostObject.h"
struct DataBullet
{
	ModelRender M_BulletModel;

	PhysicsGhostObject M_BulletGhost;

	Vector3 M_BulletPosition = { 0.0f , 0.0f , 0.0f };
	Vector3 M_BulletSpeed    = { 0.0f , 0.0f , 0.0f };

	float M_BuleetSpeedMagniFication = 100000.0f;

	int DeadTime = 0;
	int DeadTimeMax = 60;
};

//銃
struct DataGun
{
	bool M_CoolDownFlag = false;

	int M_CoolDownTime = 0;
	int M_CoolDownTimeFixed = 15;
	int M_BulletCount = 60;
	int M_BulletMaxCount = 60;
};

//スコープ
struct DataGunSight
{
	SpriteRender M_GunSightTexture;
};

//敵のスポナー
struct DataEnemySpawner
{
	ModelRender M_EnemySpawnerModel;
	Vector3 M_EnemySpawnerPosition = { 0.0f,200.0f,0.0f };
	Vector3 M_EnemySetPosition = { 0.0f,2500.0f,0.0f };

	int M_EnemyCount = 0;
	int M_EnemyCountMax = 15;
	int M_Level = 1;
	bool Flag = true;

	float AngleX = rand() % 381 - 190;
	float AngleZ = rand() % 381 - 190;
};

//敵
struct DataEnemy
{
	ModelRender M_EnemyModel;

	Vector3 M_EnemyPosition = { 0.0f,0.0f,0.0f };
	Vector3 M_EnemySpeed    = { 0.0f,0.0f,0.0f };

	CharacterController M_EnemyController;

	int M_EnemyHp  = 1;
	int M_EnemyScore = 500;
	int M_CoolTime = 0;

	bool M_CoolFlag = false;
	bool M_CreateFlag = false;
};

struct DataUiPlayerHp
{
	SpriteRender PlayerHpTexture;
	SpriteRender PlayerHpFrameTexture;
	int PlayerHp;
	int PlayerHpMemory;
	void InitTexture()
	{
		PlayerHpTexture.Init("Assets/Sprite/Ui/Hp/Hp.DDS", 280.0f, 80.0f, true);
		PlayerHpFrameTexture.Init("Assets/Sprite/Ui/Hp/HpFrame.DDS", 300.0f, 100.0f, true);
	}
	void UpdateTexture()
	{
		PlayerHpTexture.Update();
		PlayerHpFrameTexture.Update();
	}
	void DrawTexture(RenderContext& rc)
	{
		PlayerHpTexture.Draw(rc);
		PlayerHpFrameTexture.Draw(rc);
	}
};
struct DataUiEnemyCount
{
	SpriteRender EnemyCountTexture[3];
	SpriteRender EnemyIconTexture;
	int EnemyCount;
	int EnemyCountMemory;
	void InitTexture()
	{
		for (int i = 0; i < sizeof(EnemyCountTexture) / sizeof(EnemyCountTexture[0]); i++)
		{EnemyCountTexture[i].Init("Assets/Sprite/Ui/Count/0.DDS", 80.0f, 80.0f, true);}
		EnemyIconTexture.Init("Assets/Sprite/Ui/EnemyCounter/EnemyIcon.DDS", 150.0f, 75.0f, true);
	}
	void UpdateTexture()
	{
		for (int i = 0; i < sizeof(EnemyCountTexture) / sizeof(EnemyCountTexture[0]); i++)
		{EnemyCountTexture[i].Update();}
		EnemyIconTexture.Update();
	}
	void DrawTexture(RenderContext& rc)
	{
		for (int i = 0; i < sizeof(EnemyCountTexture) / sizeof(EnemyCountTexture[0]); i++)
		{EnemyCountTexture[i].Draw(rc);}
		EnemyIconTexture.Draw(rc);
	}
};
struct DataUiGun
{
	SpriteRender BulletCountTexture[2];
	SpriteRender GunFrameTexture;
	Vector4 BulletIn  = { 1.0f , 1.0f , 1.0f , 1.0f };
	Vector4 BulletOut = { 0.8f , 0.0f , 0.0f , 1.0f };
	int BulletCount;
	int BulletCountMemory;
	void InitTexture()
	{
		for (int i = 0; i < sizeof(BulletCountTexture) / sizeof(BulletCountTexture[0]); i++)
		{BulletCountTexture[i].Init("Assets/Sprite/Ui/Count/0.DDS", 50.0f, 50.0f, true);}
		GunFrameTexture.Init("Assets/Sprite/Ui/GunFrame.DDS", 300.0f, 100.0f, true);
	}
	void UpdateTexture()
	{
		for (int i = 0; i < sizeof(BulletCountTexture) / sizeof(BulletCountTexture[0]); i++)
		{BulletCountTexture[i].Update();}
		GunFrameTexture.Update();
	}
	void DrawTexture(RenderContext& rc)
	{
		for (int i = 0; i < sizeof(BulletCountTexture) / sizeof(BulletCountTexture[0]); i++)
		{BulletCountTexture[i].Draw(rc);}
		GunFrameTexture.Draw(rc);
	}
};
struct DataUiScore
{
	SpriteRender ScoreCountTexture[8];
	SpriteRender ScoreTexture;
	int ScoreCount;
	int ScoreCountMemory;
	void InitTexture()
	{
		for (int i = 0; i < sizeof(ScoreCountTexture) / sizeof(ScoreCountTexture[0]); i++)
		{ScoreCountTexture[i].Init("Assets/Sprite/Ui/Count/0.DDS", 80.0f, 80.0f, true);}
		ScoreTexture.Init("Assets/Sprite/Ui/Score.DDS", 320.0f, 80.0f, true);
	}
	void UpdateTexture()
	{
		for (int i = 0; i < sizeof(ScoreCountTexture) / sizeof(ScoreCountTexture[0]); i++)
		{ScoreCountTexture[i].Update();}
		ScoreTexture.Update();
	}
	void DrawTexture(RenderContext& rc)
	{
		for (int i = 0; i < sizeof(ScoreCountTexture) / sizeof(ScoreCountTexture[0]); i++)
		{ScoreCountTexture[i].Draw(rc);}
		ScoreTexture.Draw(rc);
	}
};
struct DataUiWave
{
	SpriteRender WaveTexture;
	SpriteRender WaveFrameTexture;
	int WaveCount;
	int WaveCountMemory;
	void InitTexture()
	{
		WaveTexture.Init("Assets/Sprite/Ui/Wave/Wave1.DDS", 250.0f, 80.0f, true);
		WaveFrameTexture.Init("Assets/Sprite/Ui/Wave/WaveFrame.DDS", 300.0f, 100.0f, true);
	}
	void UpdateTexture()
	{
		WaveTexture.Update();
		WaveFrameTexture.Update();
	}
	void DrawTexture(RenderContext& rc)
	{
		WaveTexture.Draw(rc);
		WaveFrameTexture.Draw(rc);
	}
};
struct DataUiMiniMap
{
	SpriteRender MiniMapFrameTexture;
	SpriteRender MiniMapTexture;
	SpriteRender MiniMapPlayerTexture;
	SpriteRender MiniMapPlayerDirectionTexture;
	SpriteRender MiniMapEnemyTexture[100];
	bool EnemyFlag[100];
	Vector2 CharacterUV = { 0.5f,0.5f };
	Vector2 NewUV = { 0.5f,0.5f };
	void InitTexture()
	{
		MiniMapFrameTexture.Init("Assets/Sprite/Ui/MiniMap/MiniMapFrame.DDS", 390.0f, 390.0f, true);

		SpriteInitData M_InitData;
		M_InitData.m_ddsFilePath[0] = "Assets/Sprite/Ui/MiniMap/TextureMap2.DDS";
		M_InitData.m_ddsFilePath[1] = "Assets/modelData/TileMap/TileTexture/a.DDS";
		M_InitData.m_ddsFilePath[2] = "Assets/modelData/TileMap/TileTexture/b.DDS";
		M_InitData.m_ddsFilePath[3] = "Assets/modelData/TileMap/TileTexture/c.DDS";

		M_InitData.m_fxFilePath = "Assets/shader/MiniMap.fx";
		M_InitData.m_vsEntryPointFunc = "VSMain";
		M_InitData.m_psEntryPoinFunc = "PSMain";

		M_InitData.m_expandConstantBuffer = &NewUV;
		M_InitData.m_expandConstantBufferSize = sizeof(NewUV);

		M_InitData.m_width = static_cast<UINT>(380.0f);
		M_InitData.m_height = static_cast<UINT>(380.0f);

		MiniMapTexture.MiniMapInit(M_InitData);

		for (int i = 0; i < sizeof(MiniMapEnemyTexture) / sizeof(MiniMapEnemyTexture[0]); i++)
		{MiniMapEnemyTexture[i].Init("Assets/Sprite/Ui/MiniMap/MiniMapEnemy.DDS", 15.0f, 15.0f, true);}
		MiniMapPlayerTexture.Init("Assets/Sprite/Ui/MiniMap/MiniMapPlayer.DDS", 15.0f, 15.0f, true);
		MiniMapPlayerDirectionTexture.Init("Assets/Sprite/Ui/MiniMap/MiniMapPlayerDirection.DDS", 15.0f, 20.0f, true);
	}
	void UpdateTexture()
	{
		for (int i = 0; i < sizeof(MiniMapEnemyTexture) / sizeof(MiniMapEnemyTexture[0]); i++)
		{MiniMapEnemyTexture[i].Update();}
		MiniMapFrameTexture.Update();
		MiniMapTexture.Update();
		MiniMapPlayerTexture.Update();
		MiniMapPlayerDirectionTexture.Update();
	}
	void DrawTexture(RenderContext& rc)
	{
		MiniMapFrameTexture.Draw(rc);
		MiniMapTexture.Draw(rc);
		MiniMapPlayerTexture.Draw(rc);
		MiniMapPlayerDirectionTexture.Draw(rc);
	}

	void ChangeFlag(bool Flag , int Number)
	{EnemyFlag[Number] = Flag;}
};
struct DataUiTime
{
	SpriteRender MinuteTexture[2];
	SpriteRender SecondTexture[2];
	int Second;
	int SecondMemory;
	int Minute;
	int MinuteMemory;
	int Comma;
	void InitTexture()
	{
		for (int i = 0; i < sizeof(MinuteTexture) / sizeof(MinuteTexture[0]); i++)
		{
			MinuteTexture[i].Init("Assets/Sprite/Ui/Count/0.DDS", 50.0f, 50.0f, true);
			SecondTexture[i].Init("Assets/Sprite/Ui/Count/0.DDS", 50.0f, 50.0f, true);
		}
	}
	void UpdateTexture()
	{
		for (int i = 0; i < sizeof(MinuteTexture) / sizeof(MinuteTexture[0]); i++)
		{
			MinuteTexture[i].Update();
			SecondTexture[i].Update();
		}
	}
	void DrawTexture(RenderContext& rc)
	{
		for (int i = 0; i < sizeof(MinuteTexture) / sizeof(MinuteTexture[0]); i++)
		{
			MinuteTexture[i].Draw(rc);
			SecondTexture[i].Draw(rc);
		}
	}
};

struct DataUi
{
	SpriteRender CanvasTexture;

	DataUiPlayerHp S_PlayerHp;
	DataUiEnemyCount S_EnemyCount;
	DataUiGun S_Gun;
	DataUiScore S_Score;
	DataUiWave S_Wave;
	DataUiMiniMap S_MiniMap;
	DataUiTime S_Time;

	void TextureInit()
	{
		CanvasTexture.Init("Assets/Sprite/Ui/Canvas.DDS", 1920.0f, 1080.0f, true);
		S_PlayerHp.InitTexture();
		S_EnemyCount.InitTexture();
		S_Gun.InitTexture();
		S_Score.InitTexture();
		S_Wave.InitTexture();
		S_MiniMap.InitTexture();
		S_Time.InitTexture();
	}
	void TextureUpdate()
	{
		CanvasTexture.Update();
		S_PlayerHp.UpdateTexture();
		S_EnemyCount.UpdateTexture();
		S_Gun.UpdateTexture();
		S_Score.UpdateTexture();
		S_Wave.UpdateTexture();
		S_MiniMap.UpdateTexture();
		S_Time.UpdateTexture();
	}
	void TextureRender(RenderContext& rc)
	{
		CanvasTexture.Draw(rc);
		S_PlayerHp.DrawTexture(rc);
		S_EnemyCount.DrawTexture(rc);
		S_Gun.DrawTexture(rc);
		S_Score.DrawTexture(rc);
		S_Wave.DrawTexture(rc);
		S_MiniMap.DrawTexture(rc);
		S_Time.DrawTexture(rc);
	}
};