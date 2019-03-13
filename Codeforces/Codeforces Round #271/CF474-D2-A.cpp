#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
char p;
char c[102];
char dir[] = "qwertyuiopasdfghjkl;zxcvbnm,./";
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> p;
    cin >> c;
    for(int i = 0; i < strlen(c); ++i)
    {
        for(int j = 0; j < strlen(dir); ++j)
            if(dir[j] == c[i])
            {
                if(p == 'R')
                    cout << dir[j-1];
                else
                    cout << dir[j+1];
            }
    }
    return 0;
}

