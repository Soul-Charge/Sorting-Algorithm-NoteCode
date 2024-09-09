#include <stdio.h>
#include "headers.h"

// 使用插入排序对int数组进行升序排序
// https://visualgo.net/zh/sorting，可视化工具
void insertionSort(int *arr, int len)
{
  int i, j;
  int extractNum; // 提取出的元素的下标
  // 第一层循环从1开始，因为0号下标被认为是已排序的，从下标1到剩余的未排序元素
  for (i = 1; i < len; i++)
  {
    // 被抽出的元素是从未排序的第一个开始
    extractNum = i;
    // 将抽出元素和它前面的元素比较，若前面的大则和抽出元素交换一次，同时抽出元素的下标更新
    // 用新的抽出元素继续和前面的元素比较直到没有比该元素更大的元素
    for (j = i - 1; j >= 0; j--)
    {
      if (arr[j] > arr[extractNum])
      {
        swapInt(arr + j, arr + extractNum);
        extractNum = j;
      }
    }
  }
}