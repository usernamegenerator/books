/*
8.5 Implement an algorithm to print all valid (e.g., properly opened and closed) combinations of n-pairs of parentheses.
EXAMPLE:
input: 3 (e.g., 3 pairs of parentheses)
output: ()()(), ()(()), (())(), ((()))
*/

#include <iostream>
using namespace std;

void print(int l, int r, char *str, int count)
{
    if (l < 0 || r < l)
        return; // invalid state
    if (l == 0 && r == 0)
    {
        //System.out.println(str); // found one, so print it
        cout << str << endl;
    }
    else
    {
        if (l > 0)
        { // try a left paren, if there are some available
            str[count] = '(';
            print(l - 1, r, str, count + 1);
            //on the way back, below code is executed
        }
        if (r > l)
        { // try a right paren, if there’s a matching left
            str[count] = ')';
            print(l, r - 1, str, count + 1);
        }
    }
}

int main()
{
    int count = 3;
    char *str = new char[3];
    print(count, count, str, 0);
}