//27.01
#pragma once

//有序的链式优先级队列
//优先级从高到低(优先级数字小表示优先级高)

typedef struct Node
{
  int data;
  int prio;   //优先级
  struct Node *next;
}Node, *PSLQueue;

void InitQueue(PSLQueue que);

bool Push(PSLQueue que, int val, int prio);

bool IsEmpty(PSLQueue que);

bool GetTop(PSLQueue que, int *rtval);

bool Pop(PSLQueue que, int *rtval);

void Clear(PSLQueue que);

void Destroy(PSLQueue que);
