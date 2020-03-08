/*
Implement an algorithm to determine if a string has all unique characters. What if you can not use additional data structures?
*/
#include <iostream>
#include <string>
#include <map>
using namespace std;

bool uniqueCharUsingMap(string s)
{
    if (s.empty())
        return true;
    map<char,int> m;
    for(string::iterator it = s.begin(); it!=s.end();it++){
        if(m[*it]!=0)
            return false;
        m[*it]++;
    }
    return true;
}

bool uniqueCharUsingArray(const char* s, int size)
{
    if(s==nullptr)
        return true;
    bool charMap[256] ={false};
    for(int i = 0; i < size; i++){
        if(charMap[s[i]]==true)
            return false;
        charMap[s[i]] = true;
    }
    return true;
}

int main()
{
    string s("helloworld");
    string s1("abcdefgthil");
    cout << uniqueCharUsingMap(s) << endl;
    cout << uniqueCharUsingMap(s1) << endl;
    
    cout << uniqueCharUsingArray(s.c_str(),s.size()) << endl;
    cout << uniqueCharUsingArray(s1.c_str(),s1.size()) << endl;
    return 0;
}