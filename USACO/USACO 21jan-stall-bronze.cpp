/*
  Sorting and then checking values one by one
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n, v[21], v2[21];
int main()
{
    
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    sort(v + 1, v + n + 1);
    for(int i = 1; i <= n; i++)
        cin >> v2[i];
    sort(v2 + 1, v2 + n + 1);
        
    long long ans = 1;
    int poz2 = n;
    for(int i = n; i >= 1; i--)
    {
        while(poz2 > 0 && v2[poz2] >= v[i])
            poz2--;
        ans = ans * (i - poz2);
    }
    
    cout << ans;
    return 0;
}
