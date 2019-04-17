/*
        Infoarena fft2d

    Given the graph described in the statement, find how many pairs (a, b) exist such that we can get from (0, a) to (F-1, b)

    We can observe that a road (x, a) to (y, b) is unique and it is a good one if a and b are different only among bits from x to y.
We can use dp to find for each black node how many roads does that node block and drop that number from the total answer.

*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ifstream f("fft2d.in");
ofstream g("fft2d.out");
int F, T;
vector<int>noduri[35];
map<ll, ll>mp[35][35];
int gg(int ff, int h1, int h2)
{
	return ((1 << ff) - 1) ^ ((1 << (ff - h1)) - 1) ^ ((1 << (ff - h2)) - 1);
}
int main()
{
    f >> F >> T;
    --F;
    for(int i = 1; i <= T; ++i)
    {
        int l, vl;
        f >> l >> vl;
        noduri[l].push_back(vl);
    }
    long long ans = (1LL<<F);
    ans *= ans;
    for(int h1 = F; h1 >= 0; --h1)
		for(int j = 0; j < noduri[h1].size(); ++j)
        {
            int x = noduri[h1][j];
			int cnt = 1 << (F - h1);
			for (int h2 = h1 + 1; h2 <= F; ++h2)
				cnt -= mp[h1][h2][gg(F, h1, h2) & x];
			ans -= 1LL * cnt * (1 << h1);
			for (int h2 = h1 - 1; h2 >= 0; --h2)
				mp[h2][h1][gg(F, h2, h1) & x] += cnt;
        }
    g << ans;
    return 0;
}
