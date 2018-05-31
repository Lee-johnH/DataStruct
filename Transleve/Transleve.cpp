/*
	该程序是二叉树的层次遍历
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 32

typedef char Datatype;

typedef struct Node
{
    Datatype data;
    struct Node *lchild, *rchild;
}BSTree;

typedef struct
{
    BSTree *queue[MAXSIZE];
    int rear, front;
}SeQueue;

void CreateBSTree(BSTree **T)
{
    Datatype data;
    scanf("%c", &data);

    if(' ' == data)
        *T = NULL;
    else
    {
        *T = (BSTree *)malloc(sizeof(BSTree));
        (*T)->data = data;
        CreateBSTree(&(*T)->lchild);
        CreateBSTree(&(*T)->rchild);
    }
}

void Init_SeQueue(SeQueue **q)
{
	*q = (SeQueue *)malloc(sizeof(SeQueue));
	(*q)->rear = 0;
	(*q)->front = 0;
}

void In_SeQueue(SeQueue **q, BSTree *t)
{
    if(((*q)->rear + 1) % MAXSIZE == (*q)->front)
        printf("Queue is full!\n");
    else
    {
        (*q)->rear = ((*q)->rear+1) % MAXSIZE;
        (*q)->queue[(*q)->rear] = t;
    }
}

bool Empty_SeQueue(SeQueue *q)
{
    return (q->rear == q->front);
}

void Out_SeQueue(SeQueue **q, BSTree **t)
{
    if(Empty_SeQueue(*q))
        printf("Queue is empty\n");
    else
    {
        (*q)->front = ((*q)->front + 1)%MAXSIZE;
        *t = (*q)->queue[(*q)->front];
    }
}

void Transleve(BSTree *t)
{
    SeQueue *q;
    BSTree *p;
    
    if(t)
        printf("%c ", t->data);
        
	Init_SeQueue(&q);

    In_SeQueue(&q, t);
    
    while(!Empty_SeQueue(q))
    {
        Out_SeQueue(&q, &p);

        if(p->lchild)
        {
            printf("%c ", p->lchild->data);
            In_SeQueue(&q, p->lchild);
        }
        if(p->rchild)
        {
            printf("%c ", p->rchild->data);
            In_SeQueue(&q, p->rchild);
        }
    }
}


int main(void)
{
    BSTree *T;
    
    CreateBSTree(&T);


    printf("层序遍历结果: ");
    Transleve(T);

    printf("\n");

    return 0;
}