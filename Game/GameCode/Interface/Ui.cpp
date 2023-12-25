#include "stdafx.h"
#include "Ui.h"
#include "GameCode/GameCode.h"
bool Ui::Start()
{
	S_Ui.TextureInit();

	Level2D.Init("Assets/Sprite/Level2D/Ui.casl", [&](Level2DRenderObjectData& objData)
	{
	if (objData.EqualObjectName("Canvas") == true)
		{
			S_Ui.CanvasTexture.SetPosition(objData.position);
			return true;
		}
			
	if (objData.EqualObjectName("MiniMap") == true)
	{
		S_Ui.S_MiniMap.MiniMapTexture.SetPosition(objData.position);
		return true;
	}
	if (objData.EqualObjectName("MiniMapPlayer") == true)
	{
		S_Ui.S_MiniMap.MiniMapPlayerTexture.SetPosition(objData.position);
		S_Ui.S_MiniMap.MiniMapPlayerDirectionTexture.SetPosition(objData.position);
		return false;
	}

	if (objData.EqualObjectName("MiniMapFrame") == true)
	{
		S_Ui.S_MiniMap.MiniMapFrameTexture.SetPosition(objData.position);
		return true;
	}
	if (objData.EqualObjectName("WaveFrame") == true)
	{
		S_Ui.S_Wave.WaveFrameTexture.SetPosition(objData.position);
		return true;
	}
	if (objData.EqualObjectName("HpFrame") == true)
	{
		S_Ui.S_PlayerHp.PlayerHpFrameTexture.SetPosition(objData.position);
		return true;
	}
	if (objData.EqualObjectName("GunFrame") == true)
	{
		S_Ui.S_Gun.GunFrameTexture.SetPosition(objData.position);
		return true;
	}
	if (objData.EqualObjectName("EnemyIcon") == true)
	{
		S_Ui.S_EnemyCount.EnemyIconTexture.SetPosition(objData.position);
		return true;
	}
	if (objData.EqualObjectName("Score") == true)
	{
		S_Ui.S_Score.ScoreTexture.SetPosition(objData.position);
		return true;
	}
		
	if (objData.EqualObjectName("Minute") == true)
	{
		for (int i = 0; i < sizeof(S_Ui.S_Time.MinuteTexture) / sizeof(S_Ui.S_Time.MinuteTexture[0]); i++)
		{
			S_Ui.S_Time.MinuteTexture[i].SetPosition(objData.position);
			objData.position.x += 30.0f;
		}
		return true;
	}
	if (objData.EqualObjectName("Second") == true)
	{
		for (int i = 0; i < sizeof(S_Ui.S_Time.SecondTexture) / sizeof(S_Ui.S_Time.SecondTexture[0]); i++)
		{
			S_Ui.S_Time.SecondTexture[i].SetPosition(objData.position);
			objData.position.x += 30.0f;
		}
		return true;
	}

	if (objData.EqualObjectName("Wave") == true)
	{
		S_Ui.S_Wave.WaveTexture.SetPosition(objData.position);
		return true;
	}
	if (objData.EqualObjectName("Hp") == true)
	{
		S_Ui.S_PlayerHp.PlayerHpTexture.SetPosition(objData.position);
		return true;
	}
	if (objData.EqualObjectName("BulletCount") == true)
	{
		for (int i = 0; i < sizeof(S_Ui.S_Gun.BulletCountTexture) / sizeof(S_Ui.S_Gun.BulletCountTexture[0]); i++)
		{
			S_Ui.S_Gun.BulletCountTexture[i].SetPosition(objData.position);
			objData.position.x += 30.0f;
		}
		return true;
	}
	if (objData.EqualObjectName("EnemyCount") == true)
	{
		for (int i = 0; i < sizeof(S_Ui.S_EnemyCount.EnemyCountTexture) / sizeof(S_Ui.S_EnemyCount.EnemyCountTexture[0]); i++)
		{
			S_Ui.S_EnemyCount.EnemyCountTexture[i].SetPosition(objData.position);
			objData.position.x += 40.0f;
		}
		return true;
	}
	if (objData.EqualObjectName("ScoreCount") == true)
	{
		for (int i = 0;i < sizeof(S_Ui.S_Score.ScoreCountTexture) / sizeof(S_Ui.S_Score.ScoreCountTexture[0]); i++)
		{
			S_Ui.S_Score.ScoreCountTexture[i].SetPosition(objData.position);
			objData.position.x += 40.0f;
		}		
		return true;
	}						
		return false;
	});

	S_Game.P_Horizon = FindGO<BattlefieldHorizon>("horizon");
	S_Gun.P_Gun = FindGO<Gun>("gun");
	S_Enemy.P_EnemySpawner = FindGO<EnemySpawner>("enemyspawner");
	S_Player.P_Player = FindGO<Player>("player");
	S_Object.P_GameCamera = FindGO<GameCamera>("gamecamera");

	P_Enemy.resize(sizeof(S_Ui.S_MiniMap.MiniMapEnemyTexture) / sizeof(S_Ui.S_MiniMap.MiniMapEnemyTexture[0]), nullptr);
	return true;
}
void Ui::Update()
{
	P_Enemy = FindGOs<Enemy>("enemy");
	Wave();
	BulletCount();
	EnemyCount();
	ScoreCount();
	PlayerHp();
	MiniMap();
	Time();
	S_Ui.TextureUpdate();

	swprintf_s(M_X, 256, L"Pivot:%f", S_Ui.S_MiniMap.MiniMapPlayerDirectionTexture.GetPivot().y);
	FX.SetText(M_X);
	FX.SetPosition({ 0.0f,200.0f,0.0f });
	FX.SetScale(1.0f);
}
void Ui::Render(RenderContext& rc)
{
	S_Ui.TextureRender(rc);
	FX.Draw(rc);
	for (int i = 0; i < P_Enemy.size(); i++)
	{
		if (S_Ui.S_MiniMap.EnemyFlag[i])
		{
			S_Ui.S_MiniMap.MiniMapEnemyTexture[i].Draw(rc);
		}
	}
}

void Ui::Wave()
{
	S_Ui.S_Wave.WaveCount = S_Game.P_Horizon->GetWave();
	if (S_Ui.S_Wave.WaveCount != S_Ui.S_Wave.WaveCountMemory)
	{
		switch (S_Ui.S_Wave.WaveCount)
		{
		case 1:
			S_Ui.S_Wave.WaveTexture.TextureSet("Assets/Sprite/Ui/Wave/Wave1.DDS");
			break;
		case 2:
			S_Ui.S_Wave.WaveTexture.TextureSet("Assets/Sprite/Ui/Wave/Wave2.DDS");
			break;
		case 3:
			S_Ui.S_Wave.WaveTexture.TextureSet("Assets/Sprite/Ui/Wave/Wave3.DDS");
			break;
		}
	}
	S_Ui.S_Wave.WaveCountMemory = S_Ui.S_Wave.WaveCount;
}
void Ui::BulletCount()
{
	S_Ui.S_Gun.BulletCount = S_Gun.P_Gun->GetBulletCount();
	if (S_Ui.S_Gun.BulletCount != S_Ui.S_Gun.BulletCountMemory)
	{
		NumberTexture(S_Ui.S_Gun.BulletCountTexture[0], (S_Ui.S_Gun.BulletCount / 10) % 10);
		NumberTexture(S_Ui.S_Gun.BulletCountTexture[1], (S_Ui.S_Gun.BulletCount % 10));
	}

	S_Ui.S_Gun.BulletCountMemory = S_Ui.S_Gun.BulletCount;

	if (S_Ui.S_Gun.BulletCount == 0)
	{
		S_Ui.S_Gun.BulletCountTexture[0].SetMulColor(S_Ui.S_Gun.BulletOut);
		S_Ui.S_Gun.BulletCountTexture[1].SetMulColor(S_Ui.S_Gun.BulletOut);
		S_Ui.S_Gun.GunFrameTexture.SetMulColor(S_Ui.S_Gun.BulletOut);
	}else {
		S_Ui.S_Gun.BulletCountTexture[0].SetMulColor(S_Ui.S_Gun.BulletIn);
		S_Ui.S_Gun.BulletCountTexture[1].SetMulColor(S_Ui.S_Gun.BulletIn);
		S_Ui.S_Gun.GunFrameTexture.SetMulColor(S_Ui.S_Gun.BulletIn);
	}
}
void Ui::EnemyCount()
{
	S_Ui.S_EnemyCount.EnemyCount = S_Enemy.P_EnemySpawner->GetEnemyCount();
	if (S_Ui.S_EnemyCount.EnemyCount != S_Ui.S_EnemyCount.EnemyCountMemory)
	{
		NumberTexture(S_Ui.S_EnemyCount.EnemyCountTexture[0], (S_Ui.S_EnemyCount.EnemyCount / 100) % 10);
		NumberTexture(S_Ui.S_EnemyCount.EnemyCountTexture[1], (S_Ui.S_EnemyCount.EnemyCount / 10) % 10);
		NumberTexture(S_Ui.S_EnemyCount.EnemyCountTexture[2], (S_Ui.S_EnemyCount.EnemyCount % 10));
	}
	S_Ui.S_EnemyCount.EnemyCountMemory = S_Ui.S_EnemyCount.EnemyCount;
}
void Ui::ScoreCount()
{
	S_Ui.S_Score.ScoreCount = S_Game.P_Horizon->GetScore();
	if (S_Ui.S_Score.ScoreCount != S_Ui.S_Score.ScoreCountMemory)
	{
		NumberTexture(S_Ui.S_Score.ScoreCountTexture[0], (S_Ui.S_Score.ScoreCount / 10000000));
		NumberTexture(S_Ui.S_Score.ScoreCountTexture[1], (S_Ui.S_Score.ScoreCount / 1000000) % 10);
		NumberTexture(S_Ui.S_Score.ScoreCountTexture[2], (S_Ui.S_Score.ScoreCount / 100000) % 10);
		NumberTexture(S_Ui.S_Score.ScoreCountTexture[3], (S_Ui.S_Score.ScoreCount / 10000) % 10);
		NumberTexture(S_Ui.S_Score.ScoreCountTexture[4], (S_Ui.S_Score.ScoreCount / 1000) % 10);
		NumberTexture(S_Ui.S_Score.ScoreCountTexture[5], (S_Ui.S_Score.ScoreCount / 100) % 10);
		NumberTexture(S_Ui.S_Score.ScoreCountTexture[6], (S_Ui.S_Score.ScoreCount / 10) % 10);
		NumberTexture(S_Ui.S_Score.ScoreCountTexture[7], (S_Ui.S_Score.ScoreCount / 10));
	}
	S_Ui.S_Score.ScoreCountMemory = S_Ui.S_Score.ScoreCount;
}
void Ui::PlayerHp()
{
	S_Ui.S_PlayerHp.PlayerHp = S_Player.P_Player->GetPlayerHp();
	if (S_Ui.S_PlayerHp.PlayerHp != S_Ui.S_PlayerHp.PlayerHpMemory)
	{
		if (S_Ui.S_PlayerHp.PlayerHp >= 0.66 * 100)
		{
			S_Ui.S_PlayerHp.PlayerHpTexture.SetMulColor({ 0.0f,1.0f,0.0f,1.0f });//緑
		}else {
			if (S_Ui.S_PlayerHp.PlayerHp >= 0.33 * 100)
			{
				S_Ui.S_PlayerHp.PlayerHpTexture.SetMulColor({ 1.0f,1.0f,0.0f,1.0f });//黄
			}else {
				if (S_Ui.S_PlayerHp.PlayerHp >= 0.0 * 100)
				{
					S_Ui.S_PlayerHp.PlayerHpTexture.SetMulColor({ 1.0f,0.0f,0.0f,1.0f });//赤
				}
			}
		}
	}
	S_Ui.S_PlayerHp.PlayerHpMemory = S_Ui.S_PlayerHp.PlayerHp;
}
void Ui::MiniMap()
{
	//マップの座標
	const Vector2 Size = { 38000.0f,38000.0f };

	Vector2 Speed = { S_Player.P_Player->GetSpped().x,S_Player.P_Player->GetSpped().z };

	Vector2 Normalize = { Speed.x / Size.x ,-Speed.y / Size.y };

	Vector2 UV = { S_Ui.S_MiniMap.CharacterUV.x + Normalize.x , S_Ui.S_MiniMap.CharacterUV.y + Normalize.y };

	S_Ui.S_MiniMap.NewUV = UV;

	//エネミーの座標
	for (int i = 0; i < P_Enemy.size(); i++)
	{
		Vector3 Pos = { ((-S_Player.P_Player->GetPosition().x / 10) + (P_Enemy[i]->GetPosition().x / 10)) + 770.0f , ((-S_Player.P_Player->GetPosition().z / 10) + (P_Enemy[i]->GetPosition().z / 10)) + 350.0f , 0.0f };
		if ((abs)(S_Ui.S_MiniMap.MiniMapPlayerTexture.GetPosition().x - Pos.x) < 190.0f && (abs)(S_Ui.S_MiniMap.MiniMapPlayerTexture.GetPosition().y - Pos.y) < 190.0f)
		{
			S_Ui.S_MiniMap.ChangeFlag(true, i);
		}
		else {
			S_Ui.S_MiniMap.ChangeFlag(false, i);
		}
		S_Ui.S_MiniMap.MiniMapEnemyTexture[i].SetPosition(Pos);
	}

	//矢印の向き
	S_Ui.S_MiniMap.MiniMapPlayerDirectionTexture.SetPivot({0.5f, -0.5f});

	Quaternion Rot;
	Rot.SetRotationDegZ(-float(S_Object.P_GameCamera->GetAngle() / 10));
	S_Ui.S_MiniMap.MiniMapPlayerDirectionTexture.SetRotation(Rot);

}
void Ui::Time()
{
	S_Ui.S_Time.Comma++;
	if (S_Ui.S_Time.Comma >= 60)
	{
		S_Ui.S_Time.Second++;
		S_Ui.S_Time.Comma = 0;
	}
	if (S_Ui.S_Time.Second >= 60)
	{
		S_Ui.S_Time.Minute++;
		S_Ui.S_Time.Second = 0;
	}
	if (S_Ui.S_Time.SecondMemory != S_Ui.S_Time.Second || S_Ui.S_Time.MinuteMemory != S_Ui.S_Time.Minute)
	{
		NumberTexture(S_Ui.S_Time.MinuteTexture[0], (S_Ui.S_Time.Minute / 10));
		NumberTexture(S_Ui.S_Time.MinuteTexture[1], (S_Ui.S_Time.Minute % 10));

		NumberTexture(S_Ui.S_Time.SecondTexture[0], (S_Ui.S_Time.Second / 10));
		NumberTexture(S_Ui.S_Time.SecondTexture[1], (S_Ui.S_Time.Second % 10));
	}
	S_Ui.S_Time.MinuteMemory = S_Ui.S_Time.Minute;
	S_Ui.S_Time.SecondMemory = S_Ui.S_Time.Second;
}

void Ui::NumberTexture(SpriteRender& Sprite, int Number)
{
	switch (Number)
	{
	case 0:
		Sprite.TextureSet("Assets/Sprite/Ui/Count/0.DDS");
		break;
	case 1:
		Sprite.TextureSet("Assets/Sprite/Ui/Count/1.DDS");
		break;
	case 2:
		Sprite.TextureSet("Assets/Sprite/Ui/Count/2.DDS");
		break;
	case 3:
		Sprite.TextureSet("Assets/Sprite/Ui/Count/3.DDS");
		break;
	case 4:
		Sprite.TextureSet("Assets/Sprite/Ui/Count/4.DDS");
		break;
	case 5:
		Sprite.TextureSet("Assets/Sprite/Ui/Count/5.DDS");
		break;
	case 6:
		Sprite.TextureSet("Assets/Sprite/Ui/Count/6.DDS");
		break;
	case 7:
		Sprite.TextureSet("Assets/Sprite/Ui/Count/7.DDS");
		break;
	case 8:
		Sprite.TextureSet("Assets/Sprite/Ui/Count/8.DDS");
		break;
	case 9:
		Sprite.TextureSet("Assets/Sprite/Ui/Count/9.DDS");
		break;
	}
}