#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void showArr(int *arr, int len)
{
  for (int i = 0; i < len; i++)
  {
    printf("%d ", arr[i]);
  }
}

// 交换两个int变量的值
void swapInt(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}