/*
1.3 Design an algorithm and write code to remove the duplicate characters in a string without using any additional buffer. NOTE: One or two additional variables are fine. An extra copy of the array is not.
FOLLOW UP
Write the test cases for this method.
_
_________________________________________________________________
 */

#include <iostream>
#include <cstring>
using namespace std;

void removeDuplicate(char* s, int len)
{
    if(s==nullptr)
        return;
    // first element don't need to copy
    // index points to the array that already have duplicates removed
    int index = 1;
    // iterate through the array
    for(int i = 1 ; i < len; i++){
        int j;
        // check the char before current index
        for(j = 0; j < index; j++){
            // if there are duplicate, then skip this, do not increment index
            if(s[j]==s[i]){
                break;
            }
        }
        // if there are no duplicate char till the end
        // add back to the same array using index
        if(j==index)
            s[index++] = s[i];
            
    }
    s[index] = '\0';
}

int main(){
    char s[] = "helloworld";
    char s1[] = "abcd";
    char s2[] = "aaaa";
    char *s3 = nullptr;
    char s4[] = "aaaabbbb";
    removeDuplicate(s,strlen(s));
    removeDuplicate(s1,strlen(s1));
    removeDuplicate(s2,strlen(s2));
    //removeDuplicate(s3,strlen(s3));
    removeDuplicate(s4,strlen(s4));
    cout << s << endl;
    cout << s1 << endl;
    cout << s2 << endl;
    //cout << s3 << endl;
    cout << s4 << endl;

    return 0;
}