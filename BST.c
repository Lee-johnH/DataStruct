#include <stdio.h>

typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

Status SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{
    if(!T)
    {
        *p = f;
        return false;
    }

    if(T->data == key)
    {
        *p = T;
        return true;
    }
    else if(T->data < key)
    {
        f = T;
        SearchBST(T->lchild, key, f, p);
    }
    else
    {
        f = T;
        SearchBST(T->rchild, key, f, p);
    }
}

Status InsertBST(BiTree *T, int key)
{
    BiTNode *p, *s;
    if(!SearchBST(*T, int key, NULL, &p))
    {
        s = (BiTNode *)malloc(sizeof(BiTNode));
        s->data = key;
        s->lchild = NULL;
        s->rchild = NULL;

        if(!p)
        {
            *T = s;
        }
        else if(key > p->data)
        {
            p->rchild = s;
        }
        else
        {
            p->lchild = s;
        }

        return true;
    }
    else
    {
        return false;
    }

}

Status DeleteBST(BiTree *T, int key)
{
    if(!*T)
        return false;

    if((*T)->data == key)
        return Delete(T);
    else if((*T)->data < key)
        return DeleteBST(&(*T)->lchild, key);
    else
        return DeleteBST(&(*T)->rchild, key);
}

Status Delete(BiTree *T)
{

    BiTree q, s;

    if((*T)->rchild == NULL)
    {
        q = *T;
        *T = (*T)->lchild;
        free(q);
    }
    else if((*T)->lchild == NULL)
    {
        q = *T;
        *T = (*T)->rchild;
        free(q);
    }
    else
    {
        q = *T;
        s = (*T)->lchild;
        while(s)
        {
            q = s;
            s = s->rchild;
        }
        (*T)->data = s->data;

        if(q != *T)
        {
            q->rchild = s->lchild;
        }
        else
        {
            q->lchild = s->lchild;
        }

        free(s);

    }

    return true;
}
