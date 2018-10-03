#include<bits/stdc++.h>
using namespace std;
ifstream f("biti.in");
ofstream g("biti.out");
int n;
bool v[(1<<20)];
string s;
bool ok;
int qq;
void bkt()
{
    if(ok)
        return;
    if(qq==(1<<n)+n-1)
    {
        ok=1;
        return;
    }
    for(char x='0';x<='1';++x)
    {
        if(qq+1>=n)
        {
            int p2=2;
            int nr=0;
            for(int p=qq-1;p>qq-n;--p)
            {
                nr+=p2*(s[p]-'0');
                p2*=2;
            }
            nr+=(x-'0');
            if(!v[nr])
            {
                v[nr]=1;
                s[qq]=x;
                ++qq;
                bkt();
                if(ok)
                    return;
                --qq;
                v[nr]=0;
            }
        }
        else
        {
            s[qq]=x;
            ++qq;
            bkt();
            if(ok)
                return;
        }
    }
}
int main()
{
    f>>n;
    s.resize((1<<n)+n-1);
    bkt();
    g<<s.size()<<'\n';
    g<<s;
    return 0;
}
