/*
Assume you have a method isSubstring which checks if one word is a substring of another. 
Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring 
(i.e., “waterbottle” is a rotation of “erbottlewat”).
*/

#include <iostream>
#include <string>

using namespace std;


// check if s2 is a substring of s1
bool isSubString(string s1, string s2)
{
    if(s1.find(s2)==string::npos){
        return false;
    }
    return true;
}

bool isRotate(string s1, string s2)
{
    if(s1.length()!=s2.length())
        return false;
    string s3 = s2.append(s2);
    return isSubString(s3,s1);
}

int main()
{
    string s1 = "waterbottle";
    string s2 = "erbottlewat";

    string s3 = "apple";
    string s4 = "pleap";

    string s5 = "apple";
    string s6 = "ppale";


    cout << isRotate(s1,s2) << endl;
    cout << isRotate(s3,s4) << endl;
    cout << isRotate(s5,s6) << endl;
}