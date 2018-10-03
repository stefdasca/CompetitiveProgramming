#include<bits/stdc++.h>
using namespace std;
ifstream f("siruri3.in");
ofstream g("siruri3.out");
int n,x,m[102][102],nr1,nr0;
struct xxx
{
    int l,c;
};
xxx v[5];
bool inside(int a, int b)
{
    return (1<=a && a<=n) && (1<=b && b<=n);
}
int ox[]={-1,0,1,0};
int oy[]={0,1,0,-1};
bool good(int La, int Ca, int Lb, int Cb, int val)
{
    if(!inside(La,Ca) || !inside(Lb,Cb))
        return 0;
    if(m[La][Ca]!=val || m[Lb][Cb]!=val)
        return 0;
    if(val==0)
    {
        if(!nr1){
            v[2]={La,Ca},v[1]={Lb,Cb};
            return 1;
        }
    }
    if(val==1)
    {
        if(!nr0){
            v[2]={La,Ca},v[1]={Lb,Cb};
            return 1;
        }
    }
    for(int i=0;i<=3;++i)
    {
        int Lx=La+ox[i];
        int Cx=Ca+oy[i];
        if(!inside(Lx,Cx))
            continue;
        if(m[Lx][Cx]==1-val)
        {
            v[2]={La,Ca},v[1]={Lb,Cb},v[3]={Lx,Cx};
            return 1;
        }
    }
    for(int i=0;i<=3;++i)
    {
        int Lx=Lb+ox[i];
        int Cx=Cb+oy[i];
        if(!inside(Lx,Cx))
            continue;
        if(m[Lx][Cx]==1-val)
        {
            v[1]={La,Ca},v[2]={Lb,Cb},v[3]={Lx,Cx};
            return 1;
        }
    }
}
int main()
{
    f>>n>>x;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            f>>m[i][j];
    for(int i=1;i<=x;++i)
    {
        int R;
        f>>R;
        nr1+=(R==1),nr0+=(R==0);
    }
    if(n==1)
    {
        if(x>1)
            g<<-1;
        else
            if( (m[1][1]==1 && nr1==1) || (m[1][1]==0 && nr0==1) )
                g<<1<<" "<<1;
            else
                g<<-1;
        return 0;
    }
    if(abs(nr1-nr0)<=1)
    {
        for(int i=1;i<=n;++i)
            for(int j=1;j<n;++j)
                if(m[i][j]!=m[i][j+1])
                {
                    v[1]={i,j},v[2]={i,j+1};
                    j=n;
                    i=n;
                    break;
                }
        if(v[1].l==0)
            for(int i=1;i<=n;++i)
                for(int j=1;j<n;++j)
                    if(m[j][i]!=m[j+1][i])
                    {
                        v[1]={j,i},v[2]={j+1,i};
                        j=n;
                        i=n;
                        break;
                    }
        if(v[1].l==0)
            g<<-1;
        else
        {
            if(m[v[1].l][v[1].c]==0)
                swap(v[1],v[2]);
            for(int i=1;i<=min(nr1,nr0);++i)
            {
                if(nr1>=nr0)
                    g<<v[1].l<<" "<<v[1].c<<'\n'<<v[2].l<<" "<<v[2].c<<'\n';
                else
                    g<<v[2].l<<" "<<v[2].c<<'\n'<<v[1].l<<" "<<v[1].c<<'\n';
            }
            if(nr1>nr0)
                g<<v[1].l<<" "<<v[1].c<<'\n';
            else
                if(nr1<nr0)
                    g<<v[2].l<<" "<<v[2].c<<'\n';
        }
        return 0;
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        {
            if(good(i,j,i+1,j,(nr1>nr0)))
            {
                j=n;
                i=n;
                break;
            }
            if(good(i,j,i,j+1,(nr1>nr0)))
            {
                j=n;
                i=n;
                break;
            }
        }
    if(v[1].l==0)
        g<<-1;
    else
    {
        for(int i=1;i<=min(nr0,nr1);++i)
        {
            g<<v[3].l<<" "<<v[3].c<<'\n';
            g<<v[2].l<<" "<<v[2].c<<'\n';
        }
        int pos=1;
        for(int i=min(nr0,nr1)+1;i<=max(nr0,nr1);++i)
        {
            g<<v[pos].l<<" "<<v[pos].c<<'\n';
            pos=3-pos;
        }
    }
    return 0;
}
