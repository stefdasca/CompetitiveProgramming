#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    
    vector<int> v(n), v2(n);
    
    for(int i = 0; i < n; i++)
        cin >> v[i], v[i]--;
    for(int i = 0; i < n; i++)
        cin >> v2[i], v2[i]--;
    
    vector<int> pos(n), pos2(n); // position arrays 
    for(int i = 0; i < n; i++)
    {
        pos[v[i]] = i;
        pos2[v2[i]] = i;
    }
    
    vector<int> swapped(n);
    
    // for each value we check if it's in front and if not, we add a swap and jump over potential holes
    int ans = 0;
    int pos_first = 0;
    for(int i = 0; i < n; i++) // in second array
    {
        while(pos_first < n && swapped[v[pos_first]] == 1)
            pos_first++;
        if(v[pos_first] == v2[i])
            pos_first++;
        else
        {
            ans++;
            swapped[v2[i]] = 1;
        }
    }
    
    cout << ans;
    return 0;
}
