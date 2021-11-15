#include <iostream>

using namespace std;

// Recursive method which is of O(2^n) time complexity
int factorialExponential(int n)
{
    int res = 1, i;
    for (i = 2; i <= n; i++)
        res *= i;
    return res;
}

// Using While loop method which is of O(n) time complexity
int factorialPolynomial(int n)
{
    if(n == 0)
          return 1;
    int i = n, fact = 1;
    while (n / i != n) {
        fact = fact * i;
        i--;
    }
    return fact;
}

int main() {

   int n{};
   cout << "Enter the value of n: ";
   cin >> n;

   cout << "\nFactorial of number with exponential time complexity\n";
   cout << "Factorial of " << n << " is " << factorialExponential(n) << "\n\n";

   cout << "Factorial of number with polynomial time complexity\n";
   cout << "Factorial of " << n << " is " << factorialPolynomial(n) << "\n";

   return 0;
}