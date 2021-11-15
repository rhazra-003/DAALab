#include<iostream>

using namespace std;

// Returns length of LCS for X[0..m-1], Y[0..n-1]
int LCS(string &s1, string &s2, int m, int n) {

   int L[m + 1][n + 1];
   int i, j;

   // Builds up L[m+1][n+1] in bottom up approach
   for (i = 0; i <= m; i++) 
   {
       for (j = 0; j <= n; j++) 
       {
           if (i == 0 || j == 0)
               L[i][j] = 0;
           else if (s1[i - 1] == s2[j - 1])
               L[i][j] = 1 + L[i - 1][j - 1];
           else
               L[i][j] = max(L[i - 1][j], L[i][j - 1]);
       }
   }

   // L[m][n] contains the answer
   return L[m][n];
}

int main() {
   string s1, s2;

   cout << "Enter string 1: ";
   cin >> s1;
   cout << "Enter string 2: ";
   cin >> s2;

   cout << "\nLength of LCS is = " << LCS(s1, s2, s1.length(), s2.length());
   return 0;
}