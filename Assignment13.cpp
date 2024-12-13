#include <iostream>
#include<unordered_set>
using namespace std;

int findLongestConsSubset(int arr[], int n)
{
    unordered_set<int> S;
    int ans = 0;

    for (int i = 0; i < n; i++)
        S.insert(arr[i]);

    for (int i = 0; i < n; i++) {
      
        if (S.find(arr[i] - 1) == S.end()) {
         
            int j = arr[i];
            while (S.find(j) != S.end())
                j++;

            ans = max(ans, j - arr[i]);
        }
    }
    return ans;
}

int main()
{
    int arr[] = { 1, 3, 8, 14, 4, 10, 2, 11 };
    int n = sizeof arr / sizeof arr[0];
    cout << "The largest subset of consecutive numbers in this set is "
        << findLongestConsSubset(arr, n);
    return 0;
}