#include "QuickSort.h"
#include <iostream>
#include <ostream>

/*
 * What is QuickSort?
 * ---
 * Step 1: Do a weak sort
 * Go through the list, and put all the elements lesser than the pivot item
 * value. Always remember to distinguish between indices and values
 *
 * Let's say the pivot is 0x38 in the list (the pivot can be anything):
 * 0, 100, -23, 28, 300_000, 2, -4, 5858, 0x38
 * ^ - Pointer 1                          ^ - Our pivot
 * ^ - Pointer 2
 * Is 0 greater than 0x38? (0x38 = 56 just FYI)
 * No, so we move Pointer 1 forward
 *
 * 0, 100, -23, 28, 300_000, 2, -4, 5858, 0x38
 *    ^ - P1                              ^ - Our pivot
 * ^ - P2
 *
 * Think of the 2nd pointer is where the pivot would eventually be after the
 * weak sort ends
 * Is 100 greater than 0x38? Yes, so we move our 2nd pointer to the
 * right
 *
 * 0, 100, -23, 28, 300_000, 2, -4, 5858, 0x38
 *    ^ - P1                              ^ - Our chosen pivot
 *    ^ - P2 - we're using P2 to keep track of our pivot
 *
 * remember, we want our P2 (pivot) to separate the numbers less than 0x38, so
 * we keep swapping elements lesser than 0x38 to the left and the higher than
 * 0x38 elements stay on the right of our pivot (P2).
 *
 * Is 100 greater than 0x38?
 * Yes, so we move our 2nd pointer ONE unit to the right
 *
 * 0, 100, -23, 28, 300_000, 2, -4, 5858, 0x38
 *    ^ - P1                              ^ - Our chosen pivot
 *    ^ - P2 - remember, we're using P2 to keep track of our pivot
 *
 * Is -23 greater than 0x38?
 *
 * 0, 100, -23, 28, 300_000, 2, -4, 5858, 0x38
 *    ^    ^ - P1                         ^ - Our chosen pivot
 *    ^ - P2
 *
 * No it's not! So we swap -23 with our temporary pivot (P2)
 * and remember to move P2 to the right by one unit.
 *
 * After swapping the array now looks like this -
 *
 * 0, -23, 100, 28, 300_000, 2, -4, 5858, 0x38
 *         ^ - P1                         ^ - Our chosen pivot
 *         ^ - P2
 *
 * You see what happened above? We had all the elements lesser than -23
 * move to the left of the pivot (P2)
 *
 * Now we do the same and repeat the process over and over again until we reach
 * the end of the list
 *
 * 0, -23, 28, 100, 300_000, 2, -4, 5858, 0x38
 *             ^ - P1                     ^ - Our chosen pivot
 *             ^ - P2
 *
 * 0, -23, 28, 100, 300_000, 2, -4, 5858, 0x38
 *             ^    ^ - P1                ^ - Our chosen pivot
 *             ^ - P2
 *
 * 0, -23, 28, 100, 300_000, 2, -4, 5858, 0x38
 *             ^             ^ - P1       ^ - Our chosen pivot
 *             ^ - P2
 *
 * 0, -23, 28, 2, 300_000, 100, -4, 5858, 0x38
 *                ^        ^ - P1         ^ - Our chosen pivot
 *                ^ - P2
 *                Remember that we need to move P2 by ONE unit
 *                to the right everytime we "swap"
 *
 * 0, -23, 28, 2, -4, 100, 300_000, 5858, 0x38
 *                    ^    ^ - P1         ^ - Our chosen pivot
 *                    ^ - P2
 *
 * 0, -23, 28, 2, -4, 100, 300_000, 5858,   0x38
 *                    ^             ^ - P1  ^ - Our chosen pivot
 *                    ^ - P2
 *
 * 0, -23, 28, 2, -4, 100, 300_000, 5858,   0x38
 *                    ^             ^ - P1  ^ - Our chosen pivot
 *                    ^ - P2
 *
 * So now the array is weakly sorted what you need to
 * do is make your weak_sort algorithm recursive.
 *
 * You need to cut the list in half, and then repeat the algorithm
 * two times. Run it on the left half, and then run it on the right
 * half.
 *
 * And then cut each side of the list in half again. So now you have
 * 4 pieces. Then run your weak sort algorithm again on each list.
 *
 * Repeat the process again until the list is no longer breakable.
 *
 *
 * */

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
