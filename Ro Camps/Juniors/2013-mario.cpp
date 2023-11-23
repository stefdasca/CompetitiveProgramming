/*
  Sort the points in increasing order of height. We can now do dp[i] = number of ways to get to position i from the highest possible position. 

  Given the small bounds, one can easily brute force the process of finding the nearest positions lower than the current one.

  The solution can be optimized further to around O(n log n) with lazy segment tree 
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int ym, xm, h, n;

struct segments
{
    int L, R, h;
};
segments v[10000];

bool cmp(segments a, segments b)
{
    return a.h < b.h;
}
long long dp[10000];

int main()
{
    ifstream cin("mario.in");
    ofstream cout("mario.out");
    
    cin >> ym >> xm >> h;
    cin >> n;
    
    for(int i = 0; i < n; i++)
        cin >> v[i].h >> v[i].L >> v[i].R;
    
    sort(v, v+n, cmp);
    
    for(int i = n - 1; i >= 0; i--)
        if(v[i].h <= ym && v[i].L <= xm && xm <= v[i].R)
        {
            dp[i] = 1;
            break;
        }
    
    long long tot = 0;
    for(int i = n-1; i >= 0; i--)
    {
        if(dp[i] == 0)  
            continue;
        
        // left
        
        bool obt = 0;
        for(int j = i-1; v[i].h - v[j].h <= h && j >= 0; j--)
            if(v[j].L <= v[i].L && v[i].L <= v[j].R)
            {
                dp[j] += dp[i];
                obt = 1;
                break;
            }
        
        if(!obt && v[i].h <= h)
            tot += dp[i];
            
        // right
        
        obt = 0;
        for(int j = i-1; v[i].h - v[j].h <= h && j >= 0; j--)
            if(v[j].L <= v[i].R && v[i].R <= v[j].R)
            {
                dp[j] += dp[i];
                obt = 1;
                break;
            }
        
        if(!obt && v[i].h <= h)
            tot += dp[i];
    }
    
    cout << tot << '\n';
    return 0;
}
