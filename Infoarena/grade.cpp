#include<bits/stdc++.h>
using namespace std;
ifstream f("grade.in");
ofstream g("grade.out");
int n,v[5002];
bitset<5002>put[5002];
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i];
    for(int i=1;i<=n;++i)
        put[i][i]=1;
    sort(v+1,v+n+1);
    for(int i=n;i>=1;--i)
    {
        int q=n;
        while(v[i] && q)
        {
            if(v[q] && !put[i][q])
            {
                g<<i<<" "<<q<<'\n';
                --v[i];
                --v[q];
                put[i][q]=put[q][i]=1;
            }
            --q;
        }
    }
    return 0;
}
