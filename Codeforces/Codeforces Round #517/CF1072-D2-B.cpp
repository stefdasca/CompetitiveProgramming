#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+5 ;
int n ;
int arr[MAX] , arr1[MAX] , ans[MAX];
bool solve(int idx)
{
    if(idx == -1)
        return 1 ;
    for(int i = 0 ; i <= 3 ; ++i)
    {
       int x = i | ans[idx+1] ;
       int y = i & ans[idx+1] ;
       if(x == arr[idx] && y == arr1[idx])
       {
           ans[idx] = i ;
           if(solve(idx-1) == 1)
            return 1 ;
       }
    }
    return 0 ;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0 ; i < n-1 ; ++i)
        cin >> arr[i];
    for(int i = 0 ; i < n-1 ; ++i)
        cin >> arr1[i];
    for(int i = 0 ; i <= 3 ; ++i)
    {
        ans[n-1] = i ;
        if(solve(n-2))
        {
            cout << "YES\n";
            for(int j = 0 ; j < n ; ++j)
                cout << ans[j] << " ";
            return 0 ;
        }
    }
    cout << "NO";
    return 0;
}
