#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void countSort(vector<int> &nums) {
   int max = *max_element(nums.begin(), nums.end());
   int min = *min_element(nums.begin(), nums.end());
   int range = max - min + 1;

   vector<int> count(range), output(nums.size());
   for (int num: nums)
       count[num - min]++;

   for (int i = 1; i < count.size(); i++)
       count[i] += count[i - 1];

   for (int i = nums.size() - 1; i >= 0; i--) {
       output[count[nums[i] - min] - 1] = nums[i];
       count[nums[i] - min]--;
   }

   for (int i = 0; i < nums.size(); i++)
       nums[i] = output[i];
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

   countSort(nums);

   cout << "Array after sort:\n[";
   for (auto num: nums)
       cout << num << " ";
   cout << "]\n";

   return 0;
}