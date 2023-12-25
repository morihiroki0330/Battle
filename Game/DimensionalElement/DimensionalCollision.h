#pragma once
struct ObjectData
{
	int ObjectName = 0;//オブジェクトの名前
	int Tag = 0;//オブジェクトのタグ
	int Direction = 0;//オブジェクトの空方向
	float UpperLeftVertexPositionX = 0;//矩形の左上X
	float UpperLeftVertexPositionY = 0;//矩形の左上Y
	float LowerRightVertexPositionX = 0;//矩形の右下X
	float LowerRightVertexPositionY = 0;//矩形の右下Y
	float Wide = 0;
	float Height = 0;
};
enum
{
	DIRECTION_NON = 0,
	DIRECTION_UP = 1,
	DIRECTION_RIGHT = 2,
	DIRECTION_DOWN = 3,
	DIRECTION_LEFT = 4
};
class DimensionalCollision : public IGameObject
{
public:

	DimensionalCollision();
	void Reset();

	//当たり判定の生成
	void DecisionDataSet(float  Wide, float Height, float PositionX, float PositionY, int ObjectName, int Tag);
	void DecisionDataSet(float  Wide, float Height, float PositionX, float PositionY, int ObjectName, int Tag, int& Number);

	//当たり判定の削除
	void DecisionDataDelete(int ObjectName);

	//コピー
	bool CopyDecisionData(ObjectData& Decision, int ObjectName);//【本体】のコピー
	bool CopyDecisionsData(ObjectData& Decision, int Tag, int Count);//【タグが付いた複数の本体】のコピー
	bool CopyEmptyData(ObjectData& Decision, int ObjectName, int Direction);//【空】のコピー
	bool CopyEmptysData(ObjectData& Decision, int Tag, int Direction, int Count);//【タグが付いた複数の空】のコピー

	//座標更新
	void DecisionSetPosition(float PositionX, float PositionY, int ObjectName);
	void DecisionSetPosition(float PositionX, float PositionY, int ObjectName, int Number);

	//衝突判定
	bool EmptyAndEmptyCollision(int ObjectName1, int Direction1, int ObjectName2, int Direction2);//【空同士】の衝突
	bool DecisionAndDecisionCollision(int ObjectName1, int ObjectName2);//【本体同士】の衝突

	bool EmptyAndDecisionCollision(int ObjectName1, int Direction1, int ObjectName2);//【空】と【本体】の衝突

	bool EmptyAndDecisionsCollision(int ObjectName1, int Direction1, int Tag2);//【空】と【タグが付いた複数の本体】の衝突
	bool DecisionAndDecisionsCollision(int ObjectName1, int Tag2);//【本体】と【タグが付いた複数の本体】の衝突

	bool EmptyAndEmptysCollision(int ObjectName1, int Direction1, int Tag2, int Direction2);//【空】と【タグが付いた複数の空】の衝突
	bool DecisionAndEmptysCollision(int ObjectName1, int Tag2, int Direction2);//【本体】と【タグが付いた複数の空】の衝突

	bool DecisionAndDecisionsCollision(int ObjectName1, int Tag2, int Number);//【本体】と【指定タグが付いた複数の本体】の衝突
	bool EmptysAndEmptysCollision(int Tag1, int Direction1, int Number1, int Tag2, int Direction2);//【指定タグが付いた複数の空】と【タグが付いた複数の空】の衝突


	int OddConversion(int Number)
	{
		if (Number % 2 == 0)
		{
			return Number += 1;
		}
		else {
			return Number;
		}
	}
	int EvenConversion(int Number)
	{
		if (Number % 2 == 1)
		{
			return Number += 1;
		}
		else {
			return Number;
		}
	}

	Vector4 GetWidth()
	{
		return CollisionWidth;
	}
private:
	void DecisionInSideDataSet(int Count);
	void DecisionUpSetPosition(int Count);
	void DecisionRightSetPosition(int Count);
	void DecisionDownSetPosition(int Count);
	void DecisionLeftSetPosition(int Count);
public:
	ObjectData DecisionData[256][5];
	float EmptyWidth = 15.0f;
	float InitValue = 50000.0f;
	Vector4 CollisionWidth;//X:上の状突Y:右の衝突Z:下の衝突W:左の衝突
};

