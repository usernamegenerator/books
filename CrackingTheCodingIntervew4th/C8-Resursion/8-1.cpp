// 8.1 Write a method to generate the nth Fibonacci number.

#include <iostream>
using namespace std;

int fib(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    // 0	1	1	2	3	5	8	13	21	34	55	89	144	233	377	610	987	1597	2584	4181	6765
    cout << fib(3) << endl;
    cout << fib(4) << endl;
    cout << fib(5) << endl;
    cout << fib(6) << endl;
    cout << fib(7) << endl;
    cout << fib(8) << endl;
    cout << fib(9) << endl;
    cout << fib(10) << endl;
    cout << fib(11) << endl;
    cout << fib(12) << endl;
}