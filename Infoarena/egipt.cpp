#include<bits/stdc++.h>
using namespace std;
ifstream f("egipt.in");
ofstream g("egipt.out");
int n,m,fr[4];
struct arr
{
    int nr,poz;
};
arr v[10002];
struct sol
{
    int a,b;
};
sol q[1000002];
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        f>>v[i].nr;
        v[i].poz=i;
        for(int j=v[i].nr;j<=3;++j)
            ++fr[j];
    }
    for(int i=1;i<=fr[1];++i){
        if(v[i].nr==3)
        {
            bool ok=0;
            for(int j=n;j>fr[2];--j)
                if(v[j].nr==1)
                {
                    ++m;
                    q[m].a=v[i].poz;
                    q[m].b=v[j].poz;
                    swap(v[i].nr,v[j].nr);
                    ok=1;
                    break;
                }
            if(ok==0)
            {
                for(int j=n;j>fr[2];--j)
                    if(v[j].nr==2)
                    {
                        ++m;
                        q[m].a=v[i].poz;
                        q[m].b=v[j].poz;
                        swap(v[i].nr,v[j].nr);
                        break;
                    }
                for(int j=fr[2];j>fr[1];--j)
                    if(v[j].nr==1)
                    {
                        ++m;
                        q[m].a=v[i].poz;
                        q[m].b=v[j].poz;
                        swap(v[i].nr,v[j].nr);
                        break;
                    }
            }
        }
        if(v[i].nr==2)
        {
            bool ok=0;
            for(int j=fr[2];j>fr[1];--j)
                if(v[j].nr==1)
                {
                    ++m;
                    q[m].a=v[i].poz;
                    q[m].b=v[j].poz;
                    swap(v[i].nr,v[j].nr);
                    ok=1;
                    break;
                }
            if(ok==0)
            {
               for(int j=fr[2];j>fr[1];--j)
                    if(v[j].nr==3)
                    {
                        ++m;
                        q[m].a=v[i].poz;
                        q[m].b=v[j].poz;
                        swap(v[i].nr,v[j].nr);
                        break;
                    }
                for(int j=fr[3];j>fr[2];--j)
                    if(v[j].nr==1)
                    {
                        ++m;
                        q[m].a=v[i].poz;
                        q[m].b=v[j].poz;
                        swap(v[i].nr,v[j].nr);
                        break;
                    }
            }
        }
    }
    for(int i=fr[1]+1;i<=fr[2];++i){
        if(v[i].nr==3)
        {
            bool ok=0;
            for(int j=n;j>fr[2];--j)
                if(v[j].nr==2)
                {
                    ++m;
                    q[m].a=v[i].poz;
                    q[m].b=v[j].poz;
                    swap(v[i].nr,v[j].nr);
                    ok=1;
                    break;
                }
        }
    }
    g<<m<<'\n';
    for(int i=1;i<=m;++i)
        g<<q[i].a<<" "<<q[i].b<<'\n';
    return 0;
}
