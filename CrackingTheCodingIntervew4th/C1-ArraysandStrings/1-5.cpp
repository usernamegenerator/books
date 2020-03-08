// 1.5 Write a method to replace all spaces in a string with ‘%20’.

#include <cstring>
#include <iostream>
using namespace std;




char* replace(char* s, int len)
{
    int count =0;
    for(int i=0;i<len;i++){
        if(s[i]==' '){
            count++;
        }
    }
    int index = 0;
    char *newS = (char*)malloc((len+count*2+1)*sizeof(char));
    for(int i=0;i<len;i++){
        if(s[i]!=' '){
            newS[index++] = s[i];
        }
        else{
            newS[index++] = '%';
            newS[index++] = '2';
            newS[index++] = '0';
        }
    }
    newS[index] = '\0';
    cout << len+count*2+1 << endl;
    cout << index << endl;
    return newS;
}

int main()
{
    char s[] = "hello world ni hao";
    char *newS = replace(s,strlen(s));
    cout << newS << endl;
    cout << strlen(newS) << endl;
    return 0;
}