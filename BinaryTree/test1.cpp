#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//����һ�Ŷ�����,Լ���û�����ǰ������ķ�ʽ��������
void CreateBiTree(BiTree *T)
{
	char c;

	scanf("%c", &c);
	if(' ' == c)
		*T = NULL;
	else
	{
		*T = (BiTNode *)malloc(sizeof(BiTNode));
		(*T)->data = c;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}

//���ʶ������ڵ�ľ������
void visit(ElemType c, int level)
{
	printf("%c λ�ڵ� %d ��\n", c, level);
}

//ǰ�����������
void PreOrderTraverse(BiTree T, int level)
{
	if(T)
	{
		visit(T->data, level);
		PreOrderTraverse(T->lchild, level + 1);
		PreOrderTraverse(T->rchild, level + 1);
	}
}

int main()
{
	int level = 1;
	BiTree T = NULL;
	
	CreateBiTree(&T);
	PreOrderTraverse(T, level);

	return 0;
}