/*
9.2 Write a method to sort an array of strings so that all the anagrams are next to each other.
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

void sortAnagrams(vector<string> words)
{
    map<string,vector<int>> m;

    for (int i = 0; i < words.size(); i++)
    {
        string sorted = words[i];
        sort(sorted.begin(),sorted.end());
        m[sorted].push_back(i);
    }
    
    for(map<string,vector<int>>::iterator it = m.begin();it!=m.end();it++)
    {
        for(auto index: it->second)
        {
            cout << words[index] << " ";
        }
        cout << endl;
    }
    
   
    cout << endl;
}

int main()
{
    vector<string> words = {"cat", "dog", "tac", "god", "act"};
    sortAnagrams(words);
}