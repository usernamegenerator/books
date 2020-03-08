// 8.3 Write a method that returns all subsets of a set.
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// https://sarangbishal.blogspot.com/2019/06/leetcode-78-subsets.html

vector<vector<int>> res;

void solve(vector<int> &input, int size, vector<int> subset)
{
    if (size == 0)
    {
        res.push_back(subset);
        return;
    }

    solve(input, size - 1, subset);

    subset.push_back(input[size - 1]);
    solve(input, size - 1, subset);
}

void findSubSets(vector<int> &input)
{
    vector<int> subset; // empty results
    solve(input, input.size(), subset);
}

void findSubSetsBinary(vector<int> input)
{
    int size = input.size();
    int res_size = pow(2, size);
    // iterate from 0-8. 000,001,010....111;
    for (int i = 0; i < res_size; i++)
    {
        vector<int> currentSubSet;
        // iterate the 3 bits
        for (int j = 0; j < size; j++)
        {
            if ((1 << j) & i)
            {
                currentSubSet.push_back(input[j]);
            }
        }
        res.push_back(currentSubSet);
    }
}

int main()
{
    vector<int> input = {1, 2, 3};
    // findSubSets(input);
    findSubSetsBinary(input);
}