#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
int arr[200002];
vector<int>v[5];
bool cmp(int a, int b)
{
    return arr[a] < arr[b];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        if(arr[i] >= 0)
            arr[i] = -arr[i] - 1;
    }
    int mn = 1;
    for(int i = 2; i <= n; ++i)
        if(arr[i] < arr[mn])
            mn = i;
    if(n%2 == 1)
        arr[mn] = -arr[mn] - 1;
    for(int i = 1; i <= n; ++i)
        cout << arr[i] << " ";
    return 0;
}

