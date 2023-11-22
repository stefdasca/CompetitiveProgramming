/*
   In short, you need to be careful about avoiding any case where the interval makes no sense, you would be left with something less than 0 or anything similar
*/
#include <iostream>
#include <fstream>

using namespace std;

int n, tp[3][1002];

int minIn = 10000000, maxIn;
int minOut = 10000000, maxOut;

pair<int, int> valid(int x)
{
    pair<int, int> ans = {x, x};
    for(int i = 0; i < n; i++)
    {
        if(tp[0][i] == 0)
        {
            ans.first += tp[1][i];
            ans.second += tp[2][i];
        }
        if(tp[0][i] == 2)
        {
            ans.first -= tp[2][i];
            ans.second -= tp[1][i];
            if(ans.second < 0)
                return {-1, -1};
            ans.first = max(ans.first, 0);
        }
        if(tp[0][i] == 1)
        {
            ans.first = max(ans.first, tp[1][i]);
            ans.second = min(ans.second, tp[2][i]);
            if(ans.first > ans.second)
                return {-1, -1};
        }
    }
    return ans;
}
int main()
{
    ifstream cin("traffic.in");
    ofstream cout("traffic.out");
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        
        if(s.size() == 3)
            tp[0][i] = 2;
        if(s.size() == 4)
            tp[0][i] = 1;
        
        cin >> tp[1][i];
        cin >> tp[2][i];
    }
    
    for(int i = 0; i <= 1000000; i++)
    {
        pair<int, int> cnt = valid(i);
        if(cnt.first >= 0)
        {
            minIn = min(minIn, i);
            maxIn = i;
            minOut = min(minOut, cnt.first);
            maxOut = max(maxOut, cnt.second);
        }
    }
    
    cout << minIn << " " << maxIn << '\n';
    cout << minOut << " " << maxOut << '\n';
    return 0;
}
