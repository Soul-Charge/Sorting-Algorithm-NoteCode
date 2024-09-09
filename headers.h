#include <stdbool.h>

void swapInt(int *a, int *b);
void showArr(int *arr, int len);
bool isSorted(int arr[], int len);
void testSort(void (*sortFunc)(int[], int), int arr[], int len);
void testSortAll(void (*sortFunc)(int[], int));

void selectionSort(int *arr, int len);
void insertionSort(int *arr, int len); 