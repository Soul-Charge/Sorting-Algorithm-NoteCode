#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "headers.h"
#include "insertionSort.c"
#include "utils.c"

// 1. 空数组
int emptyArr[] = {};
int lenEmpty = sizeof(emptyArr) / sizeof(emptyArr[0]);

// 2. 单个元素的数组
int singleElementArr[] = {42};
int lenSingle = sizeof(singleElementArr) / sizeof(singleElementArr[0]);

// 3. 已经排序的数组
int sortedArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int lenSorted = sizeof(sortedArr) / sizeof(sortedArr[0]);

// 4. 反向排序的数组
int reverseArr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
int lenReverse = sizeof(reverseArr) / sizeof(reverseArr[0]);

// 5. 包含重复元素的数组
int duplicateArr[] = {5, 1, 3, 5, 2, 5, 3, 5, 4, 2};
int lenDuplicate = sizeof(duplicateArr) / sizeof(duplicateArr[0]);

// 6. 随机排列的数组
int randomArr[] = {36, 48, 4, 30, 12, 35, 45};
int lenRandom = sizeof(randomArr) / sizeof(randomArr[0]);

int main(void)
{
  // system("chcp 65001");
  testSortAll(insertionSort);

  return 0;
}

// 检查数组是否已排序
bool isSorted(int arr[], int len)
{
  for (int i = 0; i < len - 1; i++)
  {
    if (arr[i] > arr[i + 1])
      return false; // 如果发现一个元素大于下一个元素，返回 false
  }
  return true; // 数组已经按升序排序
}

// 通用的排序测试函数
void testSort(void (*sortFunc)(int[], int), int arr[], int len)
{
  // 创建数组副本，用于保持原始数组不变
  int arrCopy[len];
  memcpy(arrCopy, arr, len * sizeof(int)); // 复制数组

  printf("测试排序算法...\n");

  // 打印排序前的数组
  printf("排序前的数组: ");
  for (int i = 0; i < len; i++)
  {
    printf("%d ", arrCopy[i]);
  }
  printf("\n");

  // 调用传入的排序算法
  sortFunc(arrCopy, len);

  // 打印排序后的数组
  printf("排序后的数组: ");
  for (int i = 0; i < len; i++)
  {
    printf("%d ", arrCopy[i]);
  }
  printf("\n");

  // 检查数组是否已正确排序
  if (isSorted(arrCopy, len))
  {
    printf("测试通过，数组已正确排序！\n");
  }
  else
  {
    printf("测试失败，数组排序不正确。\n");
  }
  printf("\n");
}

void testSortAll(void (*sortFunc)(int[], int))
{
  // 使用 testSort 函数测试不同的数组
  printf("===== 测试空数组 =====\n");
  testSort(sortFunc, emptyArr, lenEmpty);

  printf("===== 测试单元素数组 =====\n");
  testSort(sortFunc, singleElementArr, lenSingle);

  printf("===== 测试已排序数组 =====\n");
  testSort(sortFunc, sortedArr, lenSorted);

  printf("===== 测试反向排序数组 =====\n");
  testSort(sortFunc, reverseArr, lenReverse);

  printf("===== 测试包含重复元素的数组 =====\n");
  testSort(sortFunc, duplicateArr, lenDuplicate);

  printf("===== 测试随机排列数组 =====\n");
  testSort(sortFunc, randomArr, lenRandom);
  system("pause");
}