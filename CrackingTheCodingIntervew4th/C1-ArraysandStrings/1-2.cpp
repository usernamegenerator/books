/*
Write code to reverse a C-Style String. (C-String means that “abcd” is represented as five characters, including the null character.)
*/
#include <iostream>
#include <cstring>
using namespace std;

void reverse(char* s, const int size)
{
    for(int i = 0, j = size-1; i<j; i++,j--)
    {
        cout << s[i] << " " << s[j] << endl;
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
 
    return;
}

int main()
{
    char s[] = "abcdefghij";
    // int l = sizeof(s)/sizeof(char); // this includes the \0 ending, so gives 1 extra
    
    int len = strlen(s);
    cout << s << endl;
    reverse(s,len);
    cout << s << endl;
    return 0;    
}