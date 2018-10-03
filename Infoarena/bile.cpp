#include<bits/stdc++.h>
#define AbsoluteEvil 1<<17
using namespace std;
ifstream f("bile.in");
ofstream g("bile.out");
int n;
struct qu
{
    int L, C;
    int ans;
};
qu v[AbsoluteEvil];
bool wasAdded[AbsoluteEvil];
int root[AbsoluteEvil],rang[AbsoluteEvil],card[AbsoluteEvil],ar[5];
int Find(int x)
{
    int R, y;
    for (R = x; root[R] != R; R = root[R]);
    for (; root[x] != x;)
    {
        y = root[x];
        root[x] = R;
        x = y;
    }
    return R;
}
void unite(int x, int y)
{
    if (rang[x] > rang[y])
        root[y] = x;
    else
        root[x] = y;
    if (rang[x] == rang[y])
        rang[y]++;
}
int find_the_number(int L, int C)
{
    return (L-1)*n+C;
}
int main()
{
    f>>n;
    for(int i=1;i<=n*n;++i)
        f>>v[i].L>>v[i].C;
    for(int i=n*n;i>=1;--i)
    {
        int l=0;
        if(v[i].L>1)
            if(wasAdded[find_the_number(v[i].L-1,v[i].C)])
                ar[++l]=find_the_number(v[i].L-1,v[i].C);
        if(v[i].L<n)
            if(wasAdded[find_the_number(v[i].L+1,v[i].C)])
                ar[++l]=find_the_number(v[i].L+1,v[i].C);
        if(v[i].C>1)
            if(wasAdded[find_the_number(v[i].L,v[i].C-1)])
                ar[++l]=find_the_number(v[i].L,v[i].C-1);
        if(v[i].C<n)
            if(wasAdded[find_the_number(v[i].L,v[i].C+1)])
                ar[++l]=find_the_number(v[i].L,v[i].C+1);
        if(l){
            card[Find(ar[1])]++;
            for(int j=2;j<=l;++j){
                if(Find(ar[1])!=Find(ar[j]))
                {
                    card[Find(ar[1])]+=card[Find(ar[j])];
                    int nr=card[Find(ar[1])];
                    unite(Find(ar[1]),Find(ar[j]));
                    card[Find(ar[1])]=nr;
                }
            }
            v[i-1].ans=max(v[i].ans,card[Find(ar[1])]);
            root[find_the_number(v[i].L,v[i].C)]=root[Find(ar[1])];
        }
        else{
            v[i-1].ans=v[i].ans;
            if(i==n*n)
                v[i-1].ans=1;
            root[find_the_number(v[i].L,v[i].C)]=find_the_number(v[i].L,v[i].C);
            card[find_the_number(v[i].L,v[i].C)]=1;
            rang[find_the_number(v[i].L,v[i].C)]=1;
        }
        wasAdded[find_the_number(v[i].L,v[i].C)]=1;
    }
    for(int i=1;i<=n*n;++i)
        g<<v[i].ans<<'\n';
    return 0;
}
