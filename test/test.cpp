#include <gtest/gtest.h>
#include "tasks.h"

TEST(reverse, CanReverse)
{
  int a = 456;

  EXPECT_EQ(654, Rev(a));
}

TEST(reverse, CanReverseNegative)
{
  int a = -31;

  EXPECT_EQ(-13, Rev(a));
}

TEST(reverse, CanReverseOneDigit)
{
  int a = 2;

  EXPECT_EQ(a, Rev(a));
}

TEST(reverse, CanReverse0)
{
  int a = 0;

  EXPECT_EQ(0, Rev(a));
}

//-------------------------------------------

TEST(prefix, CanFindPrefix) {
  char *strs[] = { "ab7d", "ajcd", "abcd" };

  char a[] = "a";

  char *ans = Prefix(strs, 3);

  for (int i = 0; a[i] != 0; i++)
    EXPECT_EQ(a[i], ans[i]);
}

TEST(prefix, CanFindPrefixFromAllWord) {
  char *strs[] = { "abcd", "abcd", "abcd" };

  char a[] = "abcd";

  char *ans = Prefix(strs, 3);

  for (int i = 0; a[i] != 0; i++)
    EXPECT_EQ(a[i], ans[i]);
}

TEST(prefix, 0prefix) {
  char *strs[] = { "7bcd", "ab6d", "ab78" };

  char *ans = Prefix(strs, 3);

  EXPECT_EQ(0, *ans);
}

//--------------------------------------------------

TEST(reversePair, CanReversePair) {
  CNode List[] = { 1, 2, 3, 4 };
  CNode newList[] = { 2, 1, 4, 3 };

  for (int i = 0; i < 3; i++) {
    List[i].next = &List[i + 1];
    newList[i].next = &newList[i + 1];
  }


  ReversePair(List);

  for (int i = 0; i < 4; i++) {
    EXPECT_EQ(List[i].data, newList[i].data);
  }
}

TEST(reversePair, throwsEmptyList) {
  CNode *list = 0;

  ASSERT_ANY_THROW(ReversePair(list));
}

TEST(reversePair, OneElement) {
  CNode *List = new CNode(1);

  ReversePair(List);

  EXPECT_EQ(1, List->data);
}

//-----------------------------------------------------------

TEST(sumPair, CanFindPair) {
  int a[] = {1, 6, 0, 3, -5, 2};
  int num1, num2, sum = 3;

  PairSum(a, sum, num1, num2, 6);

  EXPECT_EQ(a[num1] + a[num2], sum);
}

TEST(sumPair, ThrowsWhenPairDoesntExist) {
  int a[] = { 1, 6, 0, 7, -5, 9 };
  int num1, num2, sum = 3;

  ASSERT_ANY_THROW(PairSum(a, sum, num1, num2, 6));
}

int main(int ac, char* av[])
{
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}