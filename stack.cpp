#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

#int Priority(char opera, bool InStack)
{
    int prio = OPERA_RRIO_ERR;
    if(InStack)
    {
        switch(opera)
        {
            case '+':
                prio = OPERA_PRIO_PLUS_IN;
                break;
            case '-':
                prio = OPERA_PRIO_MINUS_IN;
                break;
            case '*':
                prio = OPERA_PRIO_MULTIPLY_IN;
                break;
            case '/':
                prio = OPERA_PRIO_DIVISION_IN;
                break;
            case '(':
                prio = OPERA_PRIO_LEFT_BRACKETS_IN;
                break;
            default:
                prio = OPERA_PRIO_ERR;
                break;
        }
    }
    else
    {
        switch(opera)
        {
            case '+':
                prio = OPERA_PRIO_PLUS_OUT;
                break;
            case '-':
                prio = OPERA_PRIO_MINUS_OUT;
                break;
            case '*':
                prio = OPERA_PRIO_MULTIPLY_OUT;
                break;
            case '/':
                prio = OPERA_PRIO_DIVISION_OUT;
                break;
            case '(':
                prio = OPERA_PRIO_LEFT_BRACKETS_OUT;
                break;
            case ')':
                prio = OPERA_PRIO_RIGHT_BRACKETS_OUT;
                break;
            default:
                prio = OPERA_PRIO_ERR;
                break;
        }
    }

    return prio;
}

void MidToLast(char *last, const char *mid)
{
    char *stack = (char *)malloc(strlen(mid));  //不是字符串,大小不用+1
    int top = 0;    //栈顶指针，当前可以存放数据的下标

    int i = 0; //last的下标
    int prioIn; //栈内符号优先级
    int prioOut;//栈外符号优先级

    while(*mid != '\0')
    {
        if(isdigit(*mid))
        {
            last[i++] = *mid++;
        }
        else if(top == 0)    //栈空
        {
            stack[top++] = *mid++;
        }
        else
        {
            prioOut = Priority(*mid, false);
            prioIn = Priority(stack[top-1], true);
            if(prioOut < prioIn)    //栈外优先级高
            {
                stack[top++] = *mid++;
            }
            else if(prioOut == prioIn)  //左右括号匹配
            {
                mid++;
                top--;
            }
            else //栈内的优先级高
            {
                last[i++] = stack[--top];
            }
        }
    }

    while(top > 0)
    {
        last[i++] = stack[--top];
    }

    last[i] = '\0';

    free(stack);
}

int main()
{
    char last[100];
    MidToLast(last, "5+4*2-3*(4-2)");
    printf("%s\n", last);
    return 0;
}
