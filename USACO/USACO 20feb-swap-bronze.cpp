#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ifstream cin("swap.in");
    ofstream cout("swap.out");
    
    int n, k;
    cin >> n >> k;
    
    int L1, L2, R1, R2;
    cin >> L1 >> R1;
    cin >> L2 >> R2;
    
    L1--, R1--, L2--, R2--;
    
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        v[i] = i+1;
    
    vector<int> v2 = v;
    
    // here i kept the vectors
    vector<vector<int> > states;
    
    states.push_back(v2);
    
    // while i didn't get back to the original state
    while(1)
    {
        // do the operations, the period is small
        reverse(v2.begin() + L1, v2.begin() + R1 + 1);
        reverse(v2.begin() + L2, v2.begin() + R2 + 1);
        if(v2 == states[0])
            break;
        else
            states.push_back(v2);
    }
    
    int len = states.size();
    
    // print the right vector
    vector<int> ans = states[k % len];
    for(auto x : ans)
        cout << x << '\n';
    return 0;
}
