#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<string>> anagram(vector<string> vec)
{
    vector<vector<string>> res;
    map<string, vector<string>> hash;
    int n = vec.size();

    for (int i = 0; i < n; i++)
    {
        string s = vec[i];
        sort(s.begin(), s.end());
        hash[s].push_back(vec[i]);
    }

    for (auto it = hash.begin(); it != hash.end(); ++it)
    {
        res.push_back(it->second);
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }

    vector<vector<string>> res = anagram(words);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}