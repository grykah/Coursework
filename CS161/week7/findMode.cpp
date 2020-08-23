/**********************************************************
** Author: Hailey Wilder
** Date: 11/03/16
** Description: The file contains a function for
**              determining the mode(s) of an int
**              array, which returns the result as a
**              vector sorted in ascending order.
**********************************************************/

#include <algorithm>    // needed for the std::sort() function
#include <vector>       // needed to use the std::vector type

using std::vector;
using std::sort;


/*********************************************************************
** Description: Determines values from an unsorted list ints that are
**              the modes.
** Parameter: Takes numbers to sort, returns a vector of modes in
** ascending order.
*********************************************************************/

vector<int> findMode(int nums[], int size) {
  int maxCount = 1;    // highest found frequency
  vector<int> modes;  // all modes

  // loop through all the ints
  for (int i = 0; i < size; i++) {

    int curCount = 1;  // counter for occurrences of a value
                      // at i, count starting from i + 1

    // starting at the index after i, loop through the integers
    // in the list, seeking any matches with the value at index i

    // note: starting after index i will prevent duplicate values
    // from being pushed to modes
    for (int j = i + 1; j < size; j++) {

      // if a match is found, increment the counter
      if (nums[i] == nums[j]) {
        curCount++;
      }
    }

    // if the counter for index i matches the maximum frequency
    // seen thus far, push the value stored at index i to modes
    if (curCount == maxCount) {
      modes.push_back(nums[i]);
    }

    // if the counter for index i is greater than the maximum
    // frequency seen, update maxCount, clear all values stored in
    // modes (since there are other values that occur more
    // frequently), and push the value stored at index i to modes
    if (curCount > maxCount) {
      maxCount = curCount;
      modes.clear();
      modes.push_back(nums[i]);
    }
  }

  // sort all the modes
  sort(modes.begin(), modes.end());

  return modes;
}
