#include <stdio.h>
#include "slqueue.h"

int main()
{
    Node head;
    InitQueue(&head);

    Push(&head, 2, 3);
    Push(&head, 3, 7);
    Push(&head, 4, 2);
    Push(&head, 5, 5);
    Push(&head, 6, 8);

    int tmp;
    bool flg = true;
    while(flg)
    {
        if((flg = Pop(&head, &tmp)))
        {
            printf("%d\n", tmp);
        }
    }

    return 0;
}
