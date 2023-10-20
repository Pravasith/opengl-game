#include "QuickSort.h"
#include <iostream>

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
 * */

void QuickSort::sort() {
  int input[] = {100, 0, -23, 28, 300000, 2, -4, 5858, 0x38};
}

int *qs(int arr[], int lo, int hi) {
  int p = hi;
  return arr;
}

void quick_sort(int arr[]) {
  int lo = -1, hi = 8;
  qs(arr, lo, hi);
}
