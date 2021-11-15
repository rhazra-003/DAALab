#include <iostream>
#include <vector>

using namespace std;

// Recursive method which is of O(2^n) time complexity
int fibonacciExponential(int n) {

   if (n == 0) {
       return 0;
   }
   if (n == 1) {
       return 1;
   }

   return fibonacciExponential(n - 1) + fibonacciExponential(n - 2);

}

// Dynamic Programming method which is of O(n) time complexity
int fibonacciPolynomial(int n) {

   vector<int> fibSeries(n + 1, 0);
   fibSeries[1] = 1;

   for (int i = 2; i <= n; i++) {

       fibSeries[i] = fibSeries[i - 1] + fibSeries[i - 2];

   }

   return fibSeries[n];

}

int main() {

   int n{};
   cout << "Enter the value of n: ";
   cin >> n;

   cout << "\nFibonacci series with exponential time complexity\n";
   cout << "Fibonacci of " << n << " is " << fibonacciExponential(n) << "\n\n";

   cout << "Fibonacci series with polynomial time complexity\n";
   cout << "Fibonacci of " << n << " is " << fibonacciPolynomial(n) << "\n";

   return 0;
}