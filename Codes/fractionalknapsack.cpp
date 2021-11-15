#include <bits/stdc++.h>
#include <vector>

using namespace std;

// Comparison function to sort items according to val/weight ratio
bool cmp(pair<int, int> &pair1, pair<int, int> &pair2) {
   double r1 = (double) pair1.first / (double) pair1.second;
   double r2 = (double) pair2.first / (double) pair2.second;
   return r1 > r2;
}

// Greedy function
double fractionalKnapsack(int weight, vector<pair<int, int>> &items) {

   // Sorting items in decreasing order on the basis of ratio
   sort(items.begin(), items.end(), cmp);

   // Current weight in knapsack
   int curWeight = 0;
   // Value in knapsack
   double finalValue = 0.0;


   // Looping through all Items
   for (auto &item: items) {
       // If adding item won't overflow, add it completely
       if (curWeight + item.second <= weight) {
           curWeight += item.second;
           finalValue += item.first;
       }
       // If we can't add current item, add fractional part of it
       else {
           int remainWeight = weight - curWeight;
           finalValue += item.first * ((double) remainWeight / (double) item.second);
       }
   }

   return finalValue;
}

int main() {
   // Weight of knapsack
   int knapsackWeight{};
   // Item array
   vector<pair<int, int>> items;

   cout << "Enter the weight of knapsack: ";
   cin >> knapsackWeight;

   int num{};
   cout << "Enter number of items: ";
   cin >> num;

   for (int i = 0; i < num; i++) {
       int value{}, weight{};
       cout << "Enter the value and weight of item " << i + 1 << ":\n";
       cin >> value >> weight;

       items.push_back(pair<int, int>(value, weight));
   }

   cout << endl << "Maximum value we can obtain => " << fractionalKnapsack(knapsackWeight, items);

   return 0;
}