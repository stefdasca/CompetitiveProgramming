#include<bits/stdc++.h>
using namespace std;
string s;
bool can(int L, int C)
{
    if(s.size() > L * C)
        return 0;
    return 1;
}
void afis(int L, int C)
{
    int nrast = L * C - s.size();
    int astL = nrast / L;
    int modd = nrast % L;
    int zz = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        if(zz == 0)
        {
            if(modd)
                cout << '*', --modd, ++zz;
            for(int j = 1; j <= astL; ++j)
                cout << "*", ++zz;
        }
        cout << s[i];
        ++zz;
        if(zz == C)
            cout << '\n', zz = 0;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    for(int i = 1; i <= 5; ++i)
        for(int j = 1; j <= 20; ++j)
            if(can(i, j))
            {
                cout << i << " " << j << '\n';
                afis(i, j);
                return 0;
            }
    return 0;
}
