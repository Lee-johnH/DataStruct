#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "slqueue.h"

void InitQueue(PSLQueue que)
{
  assert(que != NULL);

  que->next = NULL;
}

static Node *BuyNode(int val, int prio)
{
  Node *p = (Node *)malloc(sizeof(Node));
  assert(p != NULL);

  p->data = val;
  p->prio = prio;
  p->next = NULL;

  return p;
}

//返回第一个优先级低于(优先级数字大于)prio的节点的前驱
static Node *SearchPre(PSLQueue que, int prio)
{
  Node *p;
  for(p = que; p->next != NULL; p = p->next)
  {
    if(p->next->prio > prio)
      break;
  }

  return p;
}

bool Push(PSLQueue que, int val, int prio)  //O(n)
{
  Node *p = BuyNode(val, prio);

  Node *q = SearchPre(que, prio); //O(n)

  p->next = q->next;
  q->next = p;

  return true;
}
bool IsEmpty(PSLQueue que)
{
  return que->next == NULL;
}

bool GetTop(PSLQueue que, int *rtval)
{
  if(IsEmpty(que))
    return false;

   *rtval = que->next->data;

   return true;
}

bool Pop(PSLQueue que, int *rtval)  //O(1)
{
    if(IsEmpty(que))
      return false;

    Node *p = que->next;
    *rtval = p->data;

    que->next = p->next;
    free(p);

    return true;
}

void Clear(PSLQueue que);
{
  Destroy(que);
}

void Destroy(PSLQueue que);
{
  Node *p;
  while(que->next != NULL)
  {
    p = que->next;
    que->next = p->next;
    free(p);
  }
}
