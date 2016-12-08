#include "tasks.h"
#include <stdexcept>

int power(int a) {
  int ans = 1;
  for (int i = 0; i < a; i++)
    ans = ans * 10;
  return ans;
}

int Rev(int a) {
  int b = a;
  char str[100];
  int count = 0;
  while (b != 0) {
    str[count] = b % 10;
    b /= 10;
    count++;
  }


  int ans = 0;
  for (int i = 0; i < count; i++) {
    ans += str[i] * power(count - i - 1);
  }

  if (a < 0)
    b *= -1;

  return ans;
}

//----------------------------------------

char* Prefix(char** a, int count) {
  int num = -2, i, j;
  for (i = 0; a[0][i] != 0; i++) {
    char ch = a[0][i];

    for (j = 0; j < count; j++)
      if (a[j][i] != ch) {
        num = i - 1;
        break;
      }
    if (num != -2)
      break;
  }

  if ((i == strlen(a[0])) && (j == count))
    num = strlen(a[0]) - 1;

  char* ans;

  ans = new char[num + 1];
  for (int i = 0; i <= num; i++)
    ans[i] = a[0][i];
  ans[num + 1] = 0;

  return ans;
}

//----------------------------------------

void ReversePair(CNode* list) {
  if (list == 0)
    throw std::logic_error("List is empty!");
  else
    while ((list != 0) && (list->next != 0)) {
      int c = list->data;
      list->data = list->next->data;
      list->next->data = c;
      list = list->next->next;
    }
}

//----------------------------------------

void PairSum(int *m, int sum, int &num1, int&num2, int count) {
  int dif;
  for (int i = 0; i < count; i++) {
    dif = sum - m[i];
    for (int j = i; j < count; j++)
      if (dif == m[j]) {
        num1 = i;
        num2 = j;
        return;
      }
  }
  throw std::logic_error("Those numbers doesn't exist.");
}