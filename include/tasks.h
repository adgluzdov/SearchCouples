#ifndef __TASKS_H__
#define __TASKS_H__

struct CNode {
  int data;
  CNode* next;

  CNode(int a) {
    data = a;
    next = 0;
  }
};

int power(int a);
int Rev(int a);

char* Prefix(char** a, int count);

void ReversePair(CNode* list);

void PairSum(int *m, int sum, int &num1, int&num2, int count);

#endif