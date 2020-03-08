// 5.3 Given an integer, print the next smallest and next largest number
// that have the same number of 1 bits in their binary representation.
#include <iostream>
using namespace std;

// next largest number
// flip the rightmost non-tailing 0 to 1
// count 1s right to the flipped bit, n
// clear all the bits right to it
// flip n 0s to 1s from [0] to [n-1]

int nextLargest(int x)
{
    // find the rightmost non-tailing 0
    int i = 0;
    int countOnes = 0;
    while (((x >> i) & 0x0001) == 0)
    {
        i++;
    }
    while (((x >> i) & 0x0001) == 1)
    {
        countOnes++;
        i++;
    }
    cout << i << endl;
    cout << countOnes << endl;

    // flip to 1
    int mask = 0x0001 << i;
    int flipTo1 = x | mask;
    cout << flipTo1 << endl; // ‭0011 0110 1111 1100‬. 14076

    //flipTo1 = flipTo1 >> (i);
    //flipTo1 = flipTo1 << (i);
    // alternatively, can do this to clear last i bit
    flipTo1 = flipTo1 & ~((0x1 << i) - 1);
    cout << flipTo1 << endl; // ‭13952. ‭0011011010000000‬

    // set the tailing countOnes-1 bits to 1
    flipTo1 = flipTo1 | ((0x1 << (countOnes-1)) - 1);

    cout << flipTo1 << endl; // 13967
}

int main()
{
    // 1   1   0   1   1  0  0  1  1  1  1  1  0  0
    // 1   1   0   1   1  0  1  0  0  0  1  1  1  1
    int x = 13948; // ‭13967‬
    nextLargest(x);
}