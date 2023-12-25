#include "stdafx.h"
#include "DimensionalCollision.h"
DimensionalCollision::DimensionalCollision()
{
	for (int A = 0; A < 256; A++)
	{
		for (int B = DIRECTION_NON; B <= DIRECTION_LEFT; B++)
		{
			DecisionData[A][B].ObjectName = (int)(InitValue);
			DecisionData[A][B].Tag = (int)(InitValue);
			DecisionData[A][B].UpperLeftVertexPositionX = (InitValue);
			DecisionData[A][B].UpperLeftVertexPositionY = (InitValue);
			DecisionData[A][B].LowerRightVertexPositionX = (InitValue);
			DecisionData[A][B].LowerRightVertexPositionY = (InitValue);
			DecisionData[A][B].Wide = (int)(InitValue);
			DecisionData[A][B].Height = (int)(InitValue);
		}
	}
}

void DimensionalCollision::Reset()
{
	for (int A = 0; A < 256; A++)
	{
		for (int B = DIRECTION_NON; B <= DIRECTION_LEFT; B++)
		{
			DecisionData[A][B].ObjectName = (int)(InitValue);
			DecisionData[A][B].Tag = (int)(InitValue);
			DecisionData[A][B].UpperLeftVertexPositionX = (InitValue);
			DecisionData[A][B].UpperLeftVertexPositionY = (InitValue);
			DecisionData[A][B].LowerRightVertexPositionX = (InitValue);
			DecisionData[A][B].LowerRightVertexPositionY = (InitValue);
			DecisionData[A][B].Wide = (int)(InitValue);
			DecisionData[A][B].Height = (int)(InitValue);
		}
	}
}

//当たり判定の生成
void DimensionalCollision::DecisionDataSet(float  Wide, float Height, float PositionX, float PositionY, int ObjectName, int Tag)
{
	for (int Count = 0; Count < 256; Count++)
	{
		if (DecisionData[Count][DIRECTION_NON].ObjectName == (int)(InitValue))
		{
			DecisionData[Count][DIRECTION_NON].ObjectName = ObjectName;

			DecisionData[Count][DIRECTION_NON].Tag = Tag;

			DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionX = (PositionX - (Wide / 2));

			DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionY = (PositionY + (Height / 2));

			DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionX = (PositionX + (Wide / 2));

			DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionY = (PositionY - (Height / 2));

			DecisionData[Count][DIRECTION_NON].Wide = (Wide);
			DecisionData[Count][DIRECTION_NON].Height = (Height);

			DecisionInSideDataSet(Count);
			return;
		}
	}
}
void DimensionalCollision::DecisionDataSet(float  Wide, float Height, float PositionX, float PositionY, int ObjectName, int Tag, int& Number)
{
	for (int Count = 0; Count < 256; Count++)
	{
		if (DecisionData[Count][DIRECTION_NON].ObjectName == (int)(InitValue))
		{
			DecisionData[Count][DIRECTION_NON].ObjectName = ObjectName;

			DecisionData[Count][DIRECTION_NON].Tag = Tag;

			DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionX = (PositionX - (Wide / 2));

			DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionY = (PositionY + (Height / 2));

			DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionX = (PositionX + (Wide / 2));

			DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionY = (PositionY - (Height / 2));

			DecisionData[Count][DIRECTION_NON].Wide = (Wide);
			DecisionData[Count][DIRECTION_NON].Height = (Height);

			Number = Count;

			DecisionInSideDataSet(Count);
			return;
		}
	}
}
void DimensionalCollision::DecisionInSideDataSet(int Count)
{
	for (int Direction = DIRECTION_UP; Direction <= DIRECTION_LEFT; Direction++)
	{
		DecisionData[Count][Direction].ObjectName = DecisionData[Count][DIRECTION_NON].ObjectName;
		DecisionData[Count][Direction].Tag = DecisionData[Count][DIRECTION_NON].Tag;
	}

	DecisionData[Count][DIRECTION_UP].UpperLeftVertexPositionX = DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionX + (EmptyWidth);
	DecisionData[Count][DIRECTION_UP].UpperLeftVertexPositionY = (DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionY);
	DecisionData[Count][DIRECTION_UP].LowerRightVertexPositionX = DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionX + (-EmptyWidth);
	DecisionData[Count][DIRECTION_UP].LowerRightVertexPositionY = DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionY + (-EmptyWidth);

	DecisionData[Count][DIRECTION_RIGHT].UpperLeftVertexPositionX = DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionX + (-EmptyWidth);
	DecisionData[Count][DIRECTION_RIGHT].UpperLeftVertexPositionY = DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionY + (-EmptyWidth);
	DecisionData[Count][DIRECTION_RIGHT].LowerRightVertexPositionX = (DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionX);
	DecisionData[Count][DIRECTION_RIGHT].LowerRightVertexPositionY = DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionY + (EmptyWidth);

	DecisionData[Count][DIRECTION_DOWN].UpperLeftVertexPositionX = DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionX + (EmptyWidth);
	DecisionData[Count][DIRECTION_DOWN].UpperLeftVertexPositionY = DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionY + (EmptyWidth);
	DecisionData[Count][DIRECTION_DOWN].LowerRightVertexPositionX = DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionX + (-EmptyWidth);
	DecisionData[Count][DIRECTION_DOWN].LowerRightVertexPositionY = (DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionY);

	DecisionData[Count][DIRECTION_LEFT].UpperLeftVertexPositionX = (DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionX);
	DecisionData[Count][DIRECTION_LEFT].UpperLeftVertexPositionY = DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionY + (-EmptyWidth);
	DecisionData[Count][DIRECTION_LEFT].LowerRightVertexPositionX = DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionX + (EmptyWidth);
	DecisionData[Count][DIRECTION_LEFT].LowerRightVertexPositionY = DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionY + (EmptyWidth);
}

void DimensionalCollision::DecisionDataDelete(int Number)
{
	for (int A = 0; A < 256; A++)
	{
		for (int B = DIRECTION_NON; B <= DIRECTION_LEFT; B++)
		{
			if (DecisionData[A][B].ObjectName == Number)
			{
				DecisionData[A][B].ObjectName = (int)(InitValue);
				DecisionData[A][B].Tag = (int)(InitValue);
				DecisionData[A][B].UpperLeftVertexPositionX = (InitValue);
				DecisionData[A][B].UpperLeftVertexPositionY = (InitValue);
				DecisionData[A][B].LowerRightVertexPositionX = (InitValue);
				DecisionData[A][B].LowerRightVertexPositionY = (InitValue);
				DecisionData[A][B].Wide = (int)(InitValue);
				DecisionData[A][B].Height = (int)(InitValue);
			}
		}
	}
}

//コピー
bool DimensionalCollision::CopyDecisionData(ObjectData& Decision, int ObjectName)
{
	for (int Count = 0; Count < 256; Count++)
	{
		if (DecisionData[Count][DIRECTION_NON].ObjectName == ObjectName)
		{
			Decision.ObjectName = DecisionData[Count][DIRECTION_NON].ObjectName;
			Decision.Tag = DecisionData[Count][DIRECTION_NON].Tag;
			Decision.UpperLeftVertexPositionX = DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionX;
			Decision.UpperLeftVertexPositionY = DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionY;
			Decision.LowerRightVertexPositionX = DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionX;
			Decision.LowerRightVertexPositionY = DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionY;
			return true;
		}
	}
	return false;
}
bool DimensionalCollision::CopyDecisionsData(ObjectData& Decision, int Tag, int Count)
{
	if (DecisionData[Count][DIRECTION_NON].Tag == Tag)
	{
		Decision.ObjectName = DecisionData[Count][DIRECTION_NON].ObjectName;
		Decision.Tag = DecisionData[Count][DIRECTION_NON].Tag;
		Decision.UpperLeftVertexPositionX = DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionX;
		Decision.UpperLeftVertexPositionY = DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionY;
		Decision.LowerRightVertexPositionX = DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionX;
		Decision.LowerRightVertexPositionY = DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionY;
		return true;
	}
	return false;
}
bool DimensionalCollision::CopyEmptyData(ObjectData& Decision, int ObjectName, int Direction)
{
	for (int Count = 0; Count < 256; Count++)
	{
		if (DecisionData[Count][DIRECTION_NON].ObjectName == ObjectName)
		{
			Decision.UpperLeftVertexPositionX = DecisionData[Count][Direction].UpperLeftVertexPositionX;
			Decision.UpperLeftVertexPositionY = DecisionData[Count][Direction].UpperLeftVertexPositionY;
			Decision.LowerRightVertexPositionX = DecisionData[Count][Direction].LowerRightVertexPositionX;
			Decision.LowerRightVertexPositionY = DecisionData[Count][Direction].LowerRightVertexPositionY;
			return true;
		}
	}
	return false;
}
bool DimensionalCollision::CopyEmptysData(ObjectData& Decision, int Tag, int Direction, int Count)
{
	if (DecisionData[Count][DIRECTION_NON].Tag == Tag)
	{
		Decision.ObjectName = DecisionData[Count][Direction].ObjectName;
		Decision.Tag = DecisionData[Count][Direction].Tag;
		Decision.UpperLeftVertexPositionX = DecisionData[Count][Direction].UpperLeftVertexPositionX;
		Decision.UpperLeftVertexPositionY = DecisionData[Count][Direction].UpperLeftVertexPositionY;
		Decision.LowerRightVertexPositionX = DecisionData[Count][Direction].LowerRightVertexPositionX;
		Decision.LowerRightVertexPositionY = DecisionData[Count][Direction].LowerRightVertexPositionY;
		return true;
	}
	return false;
}

//座標更新
void DimensionalCollision::DecisionSetPosition(float PositionX, float PositionY, int ObjectName)
{
	for (int Count = 0; Count < 256; Count++)
	{
		if (DecisionData[Count][DIRECTION_NON].ObjectName == ObjectName)
		{
			DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionX = (PositionX - (DecisionData[Count][DIRECTION_NON].Wide / 2));

			DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionY = (PositionY + (DecisionData[Count][DIRECTION_NON].Height / 2));

			DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionX = (PositionX + (DecisionData[Count][DIRECTION_NON].Wide / 2));

			DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionY = (PositionY - (DecisionData[Count][DIRECTION_NON].Height / 2));

			DecisionUpSetPosition(Count);
			DecisionRightSetPosition(Count);
			DecisionLeftSetPosition(Count);
			DecisionDownSetPosition(Count);
			return;
		}
	}
}
void DimensionalCollision::DecisionSetPosition(float PositionX, float PositionY, int ObjectName, int Number)
{
	if (DecisionData[Number][DIRECTION_NON].ObjectName == ObjectName)
	{
		DecisionData[Number][DIRECTION_NON].UpperLeftVertexPositionX = (PositionX - (DecisionData[Number][DIRECTION_NON].Wide / 2));
		DecisionData[Number][DIRECTION_NON].UpperLeftVertexPositionY = (PositionY + (DecisionData[Number][DIRECTION_NON].Height / 2));

		DecisionData[Number][DIRECTION_NON].LowerRightVertexPositionX = (PositionX + (DecisionData[Number][DIRECTION_NON].Wide / 2));

		DecisionData[Number][DIRECTION_NON].LowerRightVertexPositionY = (PositionY - (DecisionData[Number][DIRECTION_NON].Height / 2));

		DecisionUpSetPosition(Number);
		DecisionRightSetPosition(Number);
		DecisionLeftSetPosition(Number);
		DecisionDownSetPosition(Number);
		return;
	}
}
void DimensionalCollision::DecisionUpSetPosition(int Count)
{
	DecisionData[Count][DIRECTION_UP].UpperLeftVertexPositionX = DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionX + (EmptyWidth);
	DecisionData[Count][DIRECTION_UP].UpperLeftVertexPositionY = (DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionY);
	DecisionData[Count][DIRECTION_UP].LowerRightVertexPositionX = DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionX + (-EmptyWidth);
	DecisionData[Count][DIRECTION_UP].LowerRightVertexPositionY = DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionY + (-EmptyWidth);
}
void DimensionalCollision::DecisionRightSetPosition(int Count)
{
	DecisionData[Count][DIRECTION_RIGHT].UpperLeftVertexPositionX = DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionX + (-EmptyWidth);
	DecisionData[Count][DIRECTION_RIGHT].UpperLeftVertexPositionY = DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionY + (-EmptyWidth);
	DecisionData[Count][DIRECTION_RIGHT].LowerRightVertexPositionX = (DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionX);
	DecisionData[Count][DIRECTION_RIGHT].LowerRightVertexPositionY = DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionY + (EmptyWidth);
}
void DimensionalCollision::DecisionDownSetPosition(int Count)
{
	DecisionData[Count][DIRECTION_DOWN].UpperLeftVertexPositionX = DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionX + (EmptyWidth);
	DecisionData[Count][DIRECTION_DOWN].UpperLeftVertexPositionY = DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionY + (EmptyWidth);
	DecisionData[Count][DIRECTION_DOWN].LowerRightVertexPositionX = DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionX + (-EmptyWidth);
	DecisionData[Count][DIRECTION_DOWN].LowerRightVertexPositionY = (DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionY);
}
void DimensionalCollision::DecisionLeftSetPosition(int Count)
{
	DecisionData[Count][DIRECTION_LEFT].UpperLeftVertexPositionX = (DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionX);
	DecisionData[Count][DIRECTION_LEFT].UpperLeftVertexPositionY = DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionY + (-EmptyWidth);
	DecisionData[Count][DIRECTION_LEFT].LowerRightVertexPositionX = DecisionData[Count][DIRECTION_NON].UpperLeftVertexPositionX + (EmptyWidth);
	DecisionData[Count][DIRECTION_LEFT].LowerRightVertexPositionY = DecisionData[Count][DIRECTION_NON].LowerRightVertexPositionY + (EmptyWidth);
}

//衝突判定
bool DimensionalCollision::EmptyAndEmptyCollision(int ObjectName1, int Direction1, int ObjectName2, int Direction2)
{
	ObjectData Decision1;
	ObjectData Decision2;
	if (CopyEmptyData(Decision1, ObjectName1, Direction1) && CopyEmptyData(Decision2, ObjectName2, Direction2))
	{
		for (int X = Decision1.UpperLeftVertexPositionX; X <= Decision1.LowerRightVertexPositionX; X++)
		{
			for (int Y = Decision1.LowerRightVertexPositionY; Y <= Decision1.UpperLeftVertexPositionY; Y++)
			{
				if ((X >= Decision2.UpperLeftVertexPositionX && X <= Decision2.LowerRightVertexPositionX) && (Y <= Decision2.UpperLeftVertexPositionY && Y >= Decision2.LowerRightVertexPositionY))
				{
					CollisionWidth.x = Decision2.UpperLeftVertexPositionY;
					return true;
				}
			}
		}
	}
	return false;
}
bool DimensionalCollision::EmptyAndDecisionCollision(int ObjectName1, int Direction1, int ObjectName2)
{
	ObjectData Decision1;
	ObjectData Decision2;
	if (CopyEmptyData(Decision1, ObjectName1, Direction1) && CopyDecisionData(Decision2, ObjectName2))
	{
		for (int X = Decision1.UpperLeftVertexPositionX; X <= Decision1.LowerRightVertexPositionX; X++)
		{
			for (int Y = Decision1.LowerRightVertexPositionY; Y <= Decision1.UpperLeftVertexPositionY; Y++)
			{
				if ((X >= Decision2.UpperLeftVertexPositionX && X <= Decision2.LowerRightVertexPositionX) && (Y <= Decision2.UpperLeftVertexPositionY && Y >= Decision2.LowerRightVertexPositionY))
				{
					CollisionWidth.x = Decision2.UpperLeftVertexPositionY;
					return true;
				}
			}
		}
	}
	return false;
}

bool DimensionalCollision::EmptyAndDecisionsCollision(int ObjectName1, int Direction1, int Tag2)
{
	ObjectData Decision1;
	ObjectData Decision2;
	for (int Count = 0; Count < 256; Count++)
	{
		if (CopyEmptyData(Decision1, ObjectName1, Direction1) && CopyDecisionsData(Decision2, Tag2, Count))
		{
			for (int X = Decision1.UpperLeftVertexPositionX; X <= Decision1.LowerRightVertexPositionX; X++)
			{
				for (int Y = Decision1.LowerRightVertexPositionY; Y <= Decision1.UpperLeftVertexPositionY; Y++)
				{
					if ((X >= Decision2.UpperLeftVertexPositionX && X <= Decision2.LowerRightVertexPositionX) && (Y <= Decision2.UpperLeftVertexPositionY && Y >= Decision2.LowerRightVertexPositionY))
					{
						CollisionWidth.x = Decision2.UpperLeftVertexPositionY;
						return true;
					}
				}
			}
		}
	}
	return false;
}
bool DimensionalCollision::DecisionAndDecisionsCollision(int ObjectName1, int Tag2)
{
	ObjectData Decision1;
	ObjectData Decision2;
	for (int Count = 0; Count < 256; Count++)
	{
		if (CopyDecisionData(Decision1, ObjectName1) && CopyDecisionsData(Decision2, Tag2, Count))
		{
			for (int X = Decision1.UpperLeftVertexPositionX; X <= Decision1.LowerRightVertexPositionX; X++)
			{
				for (int Y = Decision1.LowerRightVertexPositionY; Y <= Decision1.UpperLeftVertexPositionY; Y++)
				{
					if ((X >= Decision2.UpperLeftVertexPositionX && X <= Decision2.LowerRightVertexPositionX) && (Y <= Decision2.UpperLeftVertexPositionY && Y >= Decision2.LowerRightVertexPositionY))
					{
						CollisionWidth.x = Decision2.UpperLeftVertexPositionY;
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool DimensionalCollision::DecisionAndDecisionCollision(int ObjectName1, int ObjectName2)
{
	ObjectData Decision1;
	ObjectData Decision2;
	if (CopyDecisionData(Decision1, ObjectName1) && CopyDecisionData(Decision2, ObjectName2))
	{
		for (int X = Decision1.UpperLeftVertexPositionX; X <= Decision1.LowerRightVertexPositionX; X++)
		{
			for (int Y = Decision1.LowerRightVertexPositionY; Y <= Decision1.UpperLeftVertexPositionY; Y++)
			{
				if ((X >= Decision2.UpperLeftVertexPositionX && X <= Decision2.LowerRightVertexPositionX) && (Y <= Decision2.UpperLeftVertexPositionY && Y >= Decision2.LowerRightVertexPositionY))
				{
					CollisionWidth.x = Decision2.UpperLeftVertexPositionY;
					return true;
				}
			}
		}
	}
	return false;
}

bool DimensionalCollision::EmptyAndEmptysCollision(int ObjectName1, int Direction1, int Tag2, int Direction2)
{
	ObjectData Decision1;
	ObjectData Decision2;
	for (int Count = 0; Count < 256; Count++)
	{
		if (CopyEmptyData(Decision1, ObjectName1, Direction1) && CopyEmptysData(Decision2, Tag2, Direction2, Count))
		{
			for (int X = Decision1.UpperLeftVertexPositionX; X <= Decision1.LowerRightVertexPositionX; X++)
			{
				for (int Y = Decision1.LowerRightVertexPositionY; Y <= Decision1.UpperLeftVertexPositionY; Y++)
				{
					if ((X >= Decision2.UpperLeftVertexPositionX && X <= Decision2.LowerRightVertexPositionX) && (Y <= Decision2.UpperLeftVertexPositionY && Y >= Decision2.LowerRightVertexPositionY))
					{
						CollisionWidth.x = Decision2.UpperLeftVertexPositionY;
						return true;
					}
				}
			}
		}
	}
	return false;
}
bool DimensionalCollision::DecisionAndEmptysCollision(int ObjectName1, int Tag2, int Direction2)
{
	ObjectData Decision1;
	ObjectData Decision2;
	for (int Count = 0; Count < 256; Count++)
	{
		if (CopyDecisionData(Decision1, ObjectName1) && CopyEmptysData(Decision2, Tag2, Direction2, Count))
		{
			for (int X = Decision1.UpperLeftVertexPositionX; X <= Decision1.LowerRightVertexPositionX; X++)
			{
				for (int Y = Decision1.LowerRightVertexPositionY; Y <= Decision1.UpperLeftVertexPositionY; Y++)
				{
					if ((X >= Decision2.UpperLeftVertexPositionX && X <= Decision2.LowerRightVertexPositionX) && (Y <= Decision2.UpperLeftVertexPositionY && Y >= Decision2.LowerRightVertexPositionY))
					{
						CollisionWidth.x = Decision2.UpperLeftVertexPositionY;
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool DimensionalCollision::DecisionAndDecisionsCollision(int ObjectName1, int Tag2, int Number)
{
	ObjectData Decision1;
	ObjectData Decision2;

	if (CopyDecisionData(Decision1, ObjectName1) && CopyDecisionsData(Decision2, Tag2, Number))
	{
		for (int X = Decision1.UpperLeftVertexPositionX; X <= Decision1.LowerRightVertexPositionX; X++)
		{
			for (int Y = Decision1.LowerRightVertexPositionY; Y <= Decision1.UpperLeftVertexPositionY; Y++)
			{
				if ((X >= Decision2.UpperLeftVertexPositionX && X <= Decision2.LowerRightVertexPositionX) && (Y <= Decision2.UpperLeftVertexPositionY && Y >= Decision2.LowerRightVertexPositionY))
				{
					CollisionWidth.x = Decision2.UpperLeftVertexPositionY;
					return true;
				}
			}
		}
	}
	return false;
}
bool DimensionalCollision::EmptysAndEmptysCollision(int Tag1, int Direction1, int Number1, int Tag2, int Direction2)
{
	ObjectData Decision1;
	CopyEmptysData(Decision1, Tag1, Direction1, Number1);
	ObjectData Decision2;
	for (int Count = 0; Count < 256; Count++)
	{
		if (CopyEmptysData(Decision2, Tag2, Direction2, Count))
		{
			for (int X = Decision1.UpperLeftVertexPositionX; X <= Decision1.LowerRightVertexPositionX; X++)
			{
				for (int Y = Decision1.LowerRightVertexPositionY; Y <= Decision1.UpperLeftVertexPositionY; Y++)
				{
					if ((X >= Decision2.UpperLeftVertexPositionX && X <= Decision2.LowerRightVertexPositionX) && (Y <= Decision2.UpperLeftVertexPositionY && Y >= Decision2.LowerRightVertexPositionY))
					{
						CollisionWidth.x = Decision2.UpperLeftVertexPositionY;
						return true;
					}
				}
			}
		}
	}
	return false;
}