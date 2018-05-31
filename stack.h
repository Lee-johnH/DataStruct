#ifndef _STACK_H
#define _STACK_H

/*该程序是利用栈将算式的中序表达式转后序表达式*/
/*对应符号在栈内的优先级相对栈外要高，栈内没有右括号!*/

/*栈内*/
#define OPERA_RRIO_PLUS_IN              4   /*栈内加号*/
#define OPERA_RRIO_MINUS_IN             4   /*栈内减号*/
#define OPERA_RRIO_MULTIPLY_IN          2   /*栈内乘号*/
#define OPERA_RRIO_DIVISION_IN          2   /*栈内除号*/
#define OPERA_RRIO_LEFT_BRACKETS_IN     10   /*栈内左括号*/

/*栈外*/
#define OPERA_RRIO_PLUS_OUT             5   /*栈外加号*/
#define OPERA_RRIO_MINUS_OUT            5   /*栈外减号*/
#define OPERA_RRIO_MULTIPLY_OUT         3   /*栈外乘号*/
#define OPERA_RRIO_DIVISION_OUT         3   /*栈外除号*/
#define OPERA_RRIO_LEFT_BRACKETS_OUT    1   /*栈外左括号*/
#define OPERA_RRIO_RIGHT_BRACKETS_OUT   10   /*栈外右括号*/
#define OPERA_PRIO_ERR                  -1   /*出错*/

#endif
