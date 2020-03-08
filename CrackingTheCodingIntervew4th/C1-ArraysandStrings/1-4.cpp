// 1.4 Write a method to decide if two strings are anagrams or not.

#include <iostream>
#include <string>
using namespace std;

bool isAnagram(const string s1,const  string s2){
    int count[52]={0};
    for(string::const_iterator it = s1.begin();it!=s1.end();it++){
        if(*it <= 'z' && *it>='a'){
            count[*it-'a']++;
        }
        if(*it <= 'Z' && *it>='A'){
            count[*it-'A']++;
        }
    }

    for(string::const_iterator it = s2.begin();it!=s2.end();it++){
        if(*it <= 'z' && *it>='a'){
            count[*it-'a']--;
        }
        if(*it <= 'Z' && *it>='A'){
            count[*it-'A']--;
        }
    }

    for(int i = 0; i < 52;i++){
        if(count[i]!=0)
            return false;
    }
    return true;
}

int main()
{
    string s1 = "Tom Marvolo Riddle";
    //string s2 = "I am Lord Voldemort";
    string s2 = "II am Lord Voldemort";
    cout << isAnagram(s1,s2) << endl;
    return 0;
}