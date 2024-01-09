#pragma once
/*
UIに表示するステータス
・プレイヤーのHP〇
・銃弾の弾薬〇
・銃の種類〇
・銃の標準〇
・スコアボード〇
・ミニマップ〇
・タイム〇
・現在のウェーブ〇
・残りエネミー数〇
・背景〇
*/

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
		{
			EnemyCountTexture[i].Init("Assets/Sprite/Ui/Count/0.DDS", 80.0f, 80.0f, true);
		}
		EnemyIconTexture.Init("Assets/Sprite/Ui/EnemyCounter/EnemyIcon.DDS", 150.0f, 75.0f, true);
	}
	void UpdateTexture()
	{
		for (int i = 0; i < sizeof(EnemyCountTexture) / sizeof(EnemyCountTexture[0]); i++)
		{
			EnemyCountTexture[i].Update();
		}
		EnemyIconTexture.Update();
	}
	void DrawTexture(RenderContext& rc)
	{
		for (int i = 0; i < sizeof(EnemyCountTexture) / sizeof(EnemyCountTexture[0]); i++)
		{
			EnemyCountTexture[i].Draw(rc);
		}
		EnemyIconTexture.Draw(rc);
	}
};
struct DataUiGun
{
	SpriteRender BulletCountTexture[2];
	SpriteRender GunFrameTexture;
	SpriteRender GunTexture;
	Vector4 BulletIn  = { 1.0f , 1.0f , 1.0f , 1.0f };
	Vector4 BulletOut = { 0.8f , 0.0f , 0.0f , 1.0f };
	int BulletCount;
	int BulletCountMemory;
	void InitTexture()
	{
		for (int i = 0; i < sizeof(BulletCountTexture) / sizeof(BulletCountTexture[0]); i++)
		{
			BulletCountTexture[i].Init("Assets/Sprite/Ui/Count/0.DDS", 50.0f, 50.0f, true);
		}
		GunFrameTexture.Init("Assets/Sprite/Ui/Gun/GunFrame.DDS", 300.0f, 100.0f, true);
		GunTexture.Init("Assets/Sprite/Ui/Gun/Gun.DDS", 350.0f, 450.0f, true);
	}
	void UpdateTexture()
	{
		for (int i = 0; i < sizeof(BulletCountTexture) / sizeof(BulletCountTexture[0]); i++)
		{
			BulletCountTexture[i].Update();
		}
		GunFrameTexture.Update();
		GunTexture.Update();
	}
	void DrawTexture(RenderContext& rc)
	{
		for (int i = 0; i < sizeof(BulletCountTexture) / sizeof(BulletCountTexture[0]); i++)
		{
			BulletCountTexture[i].Draw(rc);
		}
		GunFrameTexture.Draw(rc);
		GunTexture.Draw(rc);
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
		{
			ScoreCountTexture[i].Init("Assets/Sprite/Ui/Count/0.DDS", 80.0f, 80.0f, true);
		}
		ScoreTexture.Init("Assets/Sprite/Ui/Score.DDS", 320.0f, 80.0f, true);
	}
	void UpdateTexture()
	{
		for (int i = 0; i < sizeof(ScoreCountTexture) / sizeof(ScoreCountTexture[0]); i++)
		{
			ScoreCountTexture[i].Update();
		}
		ScoreTexture.Update();
	}
	void DrawTexture(RenderContext& rc)
	{
		for (int i = 0; i < sizeof(ScoreCountTexture) / sizeof(ScoreCountTexture[0]); i++)
		{
			ScoreCountTexture[i].Draw(rc);
		}
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
		{
			MiniMapEnemyTexture[i].Init("Assets/Sprite/Ui/MiniMap/MiniMapEnemy.DDS", 15.0f, 15.0f, true);
		}
		MiniMapPlayerTexture.Init("Assets/Sprite/Ui/MiniMap/MiniMapPlayer.DDS", 15.0f, 15.0f, true);
		MiniMapPlayerDirectionTexture.Init("Assets/Sprite/Ui/MiniMap/MiniMapPlayerDirection.DDS", 15.0f, 20.0f, true);
	}
	void UpdateTexture()
	{
		for (int i = 0; i < sizeof(MiniMapEnemyTexture) / sizeof(MiniMapEnemyTexture[0]); i++)
		{
			MiniMapEnemyTexture[i].Update();
		}
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

	void ChangeFlag(bool Flag, int Number)
	{
		EnemyFlag[Number] = Flag;
	}
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

#include "DimensionalStorage/StructStorage.h"
#include "level2D/Level2DRender.h"
class Ui : public IGameObject
{
public:
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	void Wave();
	void BulletCount();
	void EnemyCount();
	void ScoreCount();
	void PlayerHp();
	void Time();
	void MiniMap();

	void NumberTexture(SpriteRender& Sprite, int Number);
private:
	DataUi S_Ui;
	
	ClassGame S_Game;
	ClassGun S_Gun;
	ClassPlayer S_Player;
	ClassEnemy S_Enemy;
	ClassObject S_Object;
	
	std::vector<Enemy*> P_Enemy;

	Level2DRender Level2D;

	

	int Count = 0;
};

