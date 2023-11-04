#include "QuickSort.h"
#include <iostream>
#include <ostream>

int weakSort(int *a, int l, int r) {
  int tempPivotIndex = l - 1;

  for (int i = l; i < r; i++) {
    if (a[i] <= a[r]) {
      tempPivotIndex++;

      int temp = a[i];
      a[i] = a[tempPivotIndex];
      a[tempPivotIndex] = temp;
    }
  }

  tempPivotIndex++;

  int temp = a[tempPivotIndex];
  a[tempPivotIndex] = a[r];
  a[r] = temp;

  return tempPivotIndex;
}

void print(int *a, int size) {
  for (int i = 0; i < size; ++i)
    std::cout << a[i] << " ";

  std::cout << "\n";
}

void repeat(int a[], int l, int r) {
  if (l >= r)
    return;

  int pivotIndex = weakSort(a, l, r);

  repeat(a, l, pivotIndex - 1);
  repeat(a, pivotIndex + 1, r);
}

void QuickSort::sort() {
  int input[] = {100, 0, -23, 28, 300000, 2, -4, 5858, 0x38};
  int size = 9;

  print(input, size);
  repeat(input, 0, 8);
  print(input, size);

  std::cout << std::endl;
}
