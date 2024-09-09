#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "headers.h"

// 对int数组进行选择排序处理，从小到大
void selectionSort(int *arr, int len)
{
  // 三个数组下标
  int i, j;

  // 第一层循环是遍历数组
  for (i = 0; i < len; i++)
  {
    // 把min的定义放这里貌似还挺重要的，正好对应了每次遍历元素时从此处开始往后比较
    int min = i;
    // 第二层循环是对于每次遍历的基础上，将其和后面所有元素比较
    for (j = i + 1; j < len; j++)
    {
      // 先找出第一层遍历时比较出的最小值，之后在用此最小值找是否有更小的值，以找到整个数组的最小值
      // 使用单独的临时最小值下标变量进行比较来实现
      if (arr[j] < arr[min])
        min = j;
    }
    swapInt(arr + i, arr + min);
  }
}