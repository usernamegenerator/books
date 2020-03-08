/*
5.5 Write a function to determine the number of bits required to convert integer A to integer B.
Input: 31, 14
Output: 2
*/

#include <iostream>
using namespace std;
int howManyBit(int a, int b)
{
    int i = 0;
    int count = 0;
    
    while (i < 32)
    {
        if ( ((a >> i) & 0x1) ^ ((b >> i) & 0x1) )
        {
            count++;
        }
        i++;
    }
    return count;
}

int main()
{
    int a = 31;
    int b = 14;
    cout << howManyBit(31, 14) << endl;
}