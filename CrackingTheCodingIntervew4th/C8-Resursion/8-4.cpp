// 8.4 Write a method to compute all permutations of a string
/*
Given a string S. The task is to print all permutations of a given string.

Input:
The first line of input contains an integer T, denoting the number of test cases. Each test case contains a single string S in capital letter.

Output:
For each test case, print all permutations of a given string S with single space and all permutations should be in lexicographically increasing order.

Constraints:
1 ≤ T ≤ 10
1 ≤ size of string ≤ 5

Example:
Input:
2
ABC
ABSG

Output:
ABC ACB BAC BCA CAB CBA 
ABGS ABSG AGBS AGSB ASBG ASGB BAGS BASG BGAS BGSA BSAG BSGA GABS GASB GBAS GBSA GSAB GSBA SABG SAGB SBAG SBGA SGAB SGBA

Explanation:
Testcase 1: Given string ABC has permutations in 6 forms as ABC, ACB, BAC, BCA, CAB and CBA .

*/

#include <iostream>
#include <string>
using namespace std;

void perm(string s, int start)
{
    if (start == s.size() - 1)
    {
        cout << s << endl;
    }
    else
    {
        for (int i = 0; i < s.size(); i++)
        {
            swap(s[start], s[i]);
            perm(s, start + 1);
            swap(s[i], s[start]);
        }
    }
}

int main()
{
    string s = "ABC";
    perm(s, 0);
}