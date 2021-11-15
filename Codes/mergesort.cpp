#include <iostream>
#include <vector>

using namespace std;

// Merges two subarrays of array[]
void merge(vector<int> &array, int const left, int const mid, int const right) {
   int const subArrayOne = mid - left + 1;
   int const subArrayTwo = right - mid;

   // Create temp arrays
   vector<int> leftArray(subArrayOne), rightArray(subArrayTwo);

   // Copy data
   for (auto i = 0; i < subArrayOne; i++)
       leftArray[i] = array[left + i];
   for (auto j = 0; j < subArrayTwo; j++)
       rightArray[j] = array[mid + 1 + j];

   // Initial index of first sub-array and second sub-array
   int indexOfSubArrayOne{}, indexOfSubArrayTwo{};
   // Initial index of merged array
   int indexOfMergedArray = left;

   // Merge the temp arrays back into array[left..right]
   while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
       if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
           array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
           indexOfSubArrayOne++;
       } else {
           array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
           indexOfSubArrayTwo++;
       }
       indexOfMergedArray++;
   }

   // Copy the remaining elements of
   // left[], if there are any
   while (indexOfSubArrayOne < subArrayOne) {
       array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
       indexOfSubArrayOne++;
       indexOfMergedArray++;
   }
   
   // Copy the remaining elements of
   // right[], if there are any
   while (indexOfSubArrayTwo < subArrayTwo) {
       array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
       indexOfSubArrayTwo++;
       indexOfMergedArray++;
   }
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(vector<int> &array, int const begin, int const end) {
   if (begin >= end)
       return;

   auto mid = begin + (end - begin) / 2;
   mergeSort(array, begin, mid);
   mergeSort(array, mid + 1, end);
   merge(array, begin, mid, end);
}

int main() {
   vector<int> nums;
   int size{};
   cout << "Enter size of array: ";
   cin >> size;
   cout << "Enter values for your array:\n";
   while (size--) {
       int element;
       cin >> element;
       nums.push_back(element);
   }

   cout << "\nArray before sort:\n[";
   for (auto num: nums)
       cout << num << " ";
   cout << "]\n\n";

   mergeSort(nums, 0, nums.size() - 1);

   cout << "Array after sort:\n[";
   for (auto num: nums)
       cout << num << " ";
   cout << "]\n";

   return 0;
}