#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, poz[300002];
int pe[300002];
struct mutari
{
    int a, b;
};
mutari v[2000002];
int x = 0;
int bring[300002];
void schimb(int aa, int bb)
{
    ++x;
    v[x] = {aa, bb};
  //  cout << "xxx " << x << " " << aa << " " << bb << '\n';
    int a = pe[aa];
    int b = pe[bb];
    swap(pe[aa], pe[bb]);
    swap(poz[a], poz[b]);
  //  for(int i = 1; i <= n; ++i)
   //     cout << pe[i] << " ";
   // cout << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> pe[i], poz[pe[i]] = i;
    int st = 0;
    int dr = n/2;
    for(int i = 1; i <= n; ++i)
    {
        if(i%2 == 1)
            ++st, ++dr;
        int po = 0;
        int tbb = 0;
        if(i%2 == 1)
        {
            po = i/2 + i%2;
            tbb = n/2 + i/2 + i%2;
            if(poz[po] <= n/2)
            {
                schimb(poz[po], n);
                schimb(poz[po], st);
                schimb(poz[po], tbb);
            }
            else
            {
                if(poz[po] == tbb)
                    continue;
                schimb(poz[po], st);
                schimb(poz[po], tbb);
            }
        }
        if(i%2 == 0)
        {
            po = n/2 + i/2;
            tbb = i/2 + i%2;
            if(poz[po] == tbb)
                continue;
            if(poz[po] > n/2)
                schimb(poz[po], st);
            else
            {
                if(poz[po] == tbb)
                    continue;
                schimb(poz[po], n);
                schimb(poz[po], tbb);
            }
        }
    }
    for(int i = 1; i <= n/2; ++i)
        if(pe[i] != i)
            swap(pe[i], pe[i + n/2]), x++, v[x] = {i, i + n/2};
    cout << x << '\n';
    for(int i = 1; i <= x; ++i)
        cout << v[i].a << " " << v[i].b << '\n';
    return 0;
}

