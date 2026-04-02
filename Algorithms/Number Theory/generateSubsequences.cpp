#include <iostream>
#include <vector>
using namespace std;
/*
 * Find all subsequences of a string.
 */
vector<string> generateSubsequences(const string &str)
{
    int n = str.size();
    vector<string> subsequences;

    // There are 2^n possible subsequences
    int total = 1 << n; // same as pow(2, n)

    for (int mask = 1; mask < total; ++mask)
    { // start from 1 to skip empty subsequence if needed
        string subseq = "";
        for (int i = 0; i < n; ++i)
        {
            // Check if i-th bit is set in mask
            if (mask & (1 << i))
            {
                subseq += str[i];
            }
        }
        subsequences.push_back(subseq);
    }

    return subsequences;
}