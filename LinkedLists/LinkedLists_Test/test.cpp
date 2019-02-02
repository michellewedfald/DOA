#include "pch.h"
#include "LinkedList.h" //
class LinkedListTest : public testing::Test
{
protected:

	void SetUp()
	{
	}

	void TearDown()
	{
	}

	LinkedList <T> uut; //Help
};

TEST_F(LinkedListTest, Ctor_SizeCorrect)
{
	ASSERT_EQ(0, uut.length());
}



TEST_F(LinkedListTest, HeadInsert_HeadInsertInsertOne_ContentsAndLengthOK)
{
	uut.headInsert(10);
	ASSERT_EQ(10, uut.at(0));
	ASSERT_EQ(1, uut.length());
}

TEST_F(LinkedListTest, HeadInsert_HeadInsertTwo_ContentsAndLengthOK)
{
	uut.headInsert(10);
	uut.headInsert(20);

	ASSERT_EQ(2, uut.length());
	ASSERT_EQ(20, uut.at(0));
	ASSERT_EQ(10, uut.at(1));
}

TEST_F(LinkedListTest, HeadRemove_HeadRemoveOne_ContensAndLengthOK)
{	
	uut.headInsert(10);
	uut.headRemove();
	ASSERT_EQ(0, uut.length());
}

TEST_F(LinkedListTest, HeadRemove_HeadRemoveTwo_ContentsAndLengthOK)
{
	uut.headInsert(10);
	uut.headInsert(20);
	uut.headInsert(30);
	uut.headRemove();
	uut.headRemove();
	ASSERT_EQ(10, uut.at(0));
	ASSERT_EQ(1, uut.length());
}

TEST_F(LinkedListTest, insert_insertone_InsertedAtCorrectPosition)
{
	uut.headInsert(10);
	uut.headInsert(20);
	uut.headInsert(30);
	uut.Insert(1, 2);
	ASSERT_EQ(1, uut.at(2));
	ASSERT_EQ(4, uut.length());
}

TEST_F(LinkedListTest, insert_inserttwo_InsertedAtCorrectAndAtTheEnd)
{
	uut.headInsert(10);
	uut.headInsert(20);
	uut.headInsert(30);
	uut.headInsert(40);
	uut.Insert(1, 2);
	uut.Insert(1, 5);
	ASSERT_EQ(1, uut.at(2));
	ASSERT_EQ(6, uut.length());
	ASSERT_EQ(1, uut.at(5));
}

TEST_F(LinkedListTest, remove_removeone_lengthAndContentIsCorrect)
{
	uut.headInsert(10);
	uut.headInsert(20);
	uut.headInsert(30);
	uut.remove(2);
	ASSERT_EQ(2, uut.length());
	ASSERT_EQ(30, uut.at(0));
	ASSERT_EQ(20, uut.at(1));
}

TEST_F(LinkedListTest, remove_removetwo_lengthAndContentIsCorrect)
{
	uut.headInsert(10);
	uut.headInsert(20);
	uut.headInsert(30);
	uut.headInsert(40);
	uut.remove(2);
	uut.remove(3);
	ASSERT_EQ(2, uut.length());
	ASSERT_EQ(40, uut.at(0));
	ASSERT_EQ(30, uut.at(1));
}

TEST_F(LinkedListTest, At_GetOneElementAtPosition)
{
	uut.headInsert(10);
	uut.headInsert(20);
	uut.headInsert(30);
	ASSERT_EQ(20, uut.at(1));
}

TEST_F(LinkedListTest, At_GetTwoElementsAtPositions)
{
	uut.headInsert(10);
	uut.headInsert(20);
	uut.headInsert(30);
	ASSERT_EQ(20, uut.at(1));
	ASSERT_EQ(30, uut.at(0));
}

TEST_F(LinkedListTest, Length_LengthOnThreeNodeList)
{
	uut.headInsert(10);
	uut.headInsert(20);
	uut.headInsert(30);
	ASSERT_EQ(3, uut.length());
}

//Length er testet i de andre testcases

TEST_F(LinkedListTest, Clear_ClearListWithZeroElement)
{
	uut.Clear();
	ASSERT_EQ(0, uut.length());
}

TEST_F(LinkedListTest, Clear_ClearListWithThreeElements)
{
	uut.headInsert(10);
	uut.headInsert(20);
	uut.headInsert(30);
	uut.Clear();
	ASSERT_EQ(0, uut.length());
}
