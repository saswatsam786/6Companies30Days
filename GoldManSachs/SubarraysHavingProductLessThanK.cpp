#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubArrayProductLessThanK(const vector<int> &a, int n, long long k)
    {
        int start = 0, end = 0, res = 0, len = 0;
        long long product = 1;
        while (end < n)
        {
            product *= a[end];
            len += 1;
            while (product >= k and start <= end)
            {
                product /= a[start];
                start++;
                len -= 1;
            }

            if (product < k)
            {

                res += len;
            }
            end++;
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends