/*
5.1 You are given two 32-bit numbers, N and M, and two bit positions, i and j. 
Write a method to set all bits between i and j in N equal to M (e.g., M becomes a substring of N located at i and starting at j).
EXAMPLE:
Input: N = 10000000000, M = 10101, i = 2, j = 6
Output: N = 10001010100
*/

#include <iostream>
using namespace std;

int setPositions(int N, int M, int i, int j)
{
    /*
    Set all the bits after j in a number.
    Set all the bits before i in a number.
    Then perform Bitwise Or on both then we get the number with all the bits set except from i to j.
    Perform Bitwise And with the given N as to set the bits according to the N.
    Then shift M into the correct position i.e. in the range of i to j.
    And at the last perform Bitwise Or on (Shifted M and the N modifed in 4th step).
    The result will be N with M as substring from ith to jth bits
    */
   
    int max = ~0;
    // Set all the bits after j in a number.
    int left = max << (j + 1);
    // Set all the bits before i in a number.
    int right = (1 << i) - 1;
    // Then perform Bitwise Or on both then we get the number with all the bits set except from i to j.
    int mask = left | right;

    // Perform Bitwise And with the given N as to set the bits according to the N.
    int nPrime = N & mask;

    // Then shift M into the correct position i.e. in the range of i to j.
    int mPrime = M << i;

    //And at the last perform Bitwise Or on (Shifted M and the N modifed in 4th step).

    int res = nPrime | mPrime;

    return res;
}

int main()
{
    cout << setPositions(1024, 21, 2, 6) << endl; //1108
}