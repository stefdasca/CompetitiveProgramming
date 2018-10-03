#include<fstream>
using namespace std;
ifstream f("domino1.in");
ofstream g("domino1.out");
int N,x,y,v1,v2,ok,i,j,k1,k2,k3,k4,k=0;
struct art {int v; bool ok;} z,st[10003];
int main ()
{
    f>>N>>k1>>k2;
    f>>x>>y;
    ok=k1>0;
    v1=x*10+y; v2=y*10+x;
    if(v2>v1 && ok){
        z.v=v2;
        z.ok=1;
        --k1;
    }
    else{
        z.v=v1;
        z.ok=0;
    }
    st[++k]=z;
    for(i=2; i<=N; ++i)
    {   f>>x>>y;
        v1=x*10+y;
        v2=y*10+x;
        if(v1>=v2 || !ok)
        {   j=k;
            while(v1>st[j].v && k2 && j)
            {
                if(st[j].ok)
                    ++k1;
                --j;
                --k2;
            }
            k=j;
            z.v=v1;
            z.ok=0;
            st[++k]=z;
        }
        else
        {   j=k;
            k3=k;
            k4=k2;
            while(v2>st[j].v  && k2 && j)
            {   if(st[j].ok)
                    ++k1;
                --j;
                --k2;
            }
            k=j;
            while(st[k+1].v==st[j].v && (k1+k2==0))
            {   if(st[j].ok)
                {
                    ++k1;
                    st[j].ok=0;
                }
                --j;
            }
            if(k1){
                z.v=v2;
                z.ok=1;
                --k1;
            }
           else
           {    j=k3; k2=k4;
                while(v1>st[j].v && k2 && j)
                {   if (st[j].ok)
                        ++k1;
                    --j;
                    --k2;
                }
                k=j; z.v=v1; z.ok=0;
           }
            st[++k]=z;
        }
    }
    for(i=1; i<=k-k2; ++i)
        g<<st[i].v;
    return 0;
}
