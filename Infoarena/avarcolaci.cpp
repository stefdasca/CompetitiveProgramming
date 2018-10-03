#include <bits/stdc++.h>
using namespace std;
ifstream f("avarcolaci.in");
ifstream f2("avarcolaci.in");
ofstream g("avarcolaci.out");
int test, n;
int main()
{
    f>> test;
    f2 >> test;
    for(;test;--test){
        int x = -1,k = 0;
        f2>> n; f>> n;
        n<<=1;
        for (int i = 1; i <= n; ++i){
            int y;
            f>> y;
            if(y == x)
                ++k;
            else
            {
                --k;
                if(k < 0){
                    x = y;
                    k = 1;
                }
            }
        }
        k = 0;
        for (int i = 1; i <= n; ++i){
            int y;
            f2>> y;
            if(y == x)
                ++k;
        }
        if(k >= n/2+1)
            g << x << "\n";
        else
            g<< "Mozart\n";
    }
    return 0;
}
