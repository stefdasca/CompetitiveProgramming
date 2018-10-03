/// Understanding girls be like
#include<fstream>
#include<cstring>
using namespace std;
ifstream f("pm.in");
ofstream g("pm.out");
short x,y,vsum[103];
struct vect
{
    short vm[102],lm; /// ultimu = -
    short vp[102],lp; /// ultimu = +
};
vect v[253];
vect v2[253];
int main()
{
    f>>x>>y;
    v[1].vp[1]=1,v[1].lp=1;
    v[2].vm[1]=1,v[2].lm=1;
    for(int i=2;i<=x+y;++i)
    {
        if(i%2==0){
            for(int j=1;j<=min(i,251);++j)
                memset(v2[j].vm,0,sizeof(v2[j].vm)),memset(v2[j].vp,0,sizeof(v2[j].vp)),v2[j].lm=0,v2[j].lp=0;
            for(int j=1;j<=min(i,251);++j)
            {
                for(int k=1;k<=v[j].lm;++k)
                    v2[j].vp[k]+=v[j].vm[k];
                v2[j].lp=max(v2[j].lp,v[j].lm);
                for(int k=1;k<=v[j].lp;++k)
                    v2[j].vp[k]+=v[j].vp[k],v2[j+1].vm[k]+=v[j].vp[k];
                v2[j].lp=max(v2[j].lp,v[j].lp);
                v2[j+1].lm=max(v2[j+1].lm,v[j].lp);
            }
            for(int j=1;j<=min(i+1,251);++j)
            {
                for(int k=1;k<=v2[j].lm;++k)
                    if(v2[j].vm[k]>9)
                    {
                        v2[j].vm[k+1]+=v2[j].vm[k]/10;
                        v2[j].vm[k]%=10;
                        if(k==v2[j].lm)
                            ++v2[j].lm;
                    }
                for(int k=1;k<=v2[j].lp;++k)
                    if(v2[j].vp[k]>9)
                    {
                        v2[j].vp[k+1]+=v2[j].vp[k]/10;
                        v2[j].vp[k]%=10;
                        if(k==v2[j].lp)
                            ++v2[j].lp;
                    }
            }
        }
        else
        {
            for(int j=1;j<=min(i,251);++j)
                memset(v[j].vm,0,sizeof(v[j].vm)),memset(v[j].vp,0,sizeof(v[j].vp)),v[j].lm=0,v[j].lp=0;
            for(int j=1;j<=min(i,251);++j)
            {
                for(int k=1;k<=v2[j].lm;++k)
                    v[j].vp[k]+=v2[j].vm[k];
                v[j].lp=max(v[j].lp,v2[j].lm);
                for(int k=1;k<=v2[j].lp;++k)
                    v[j].vp[k]+=v2[j].vp[k],v[j+1].vm[k]+=v2[j].vp[k];
                v[j].lp=max(v[j].lp,v2[j].lp);
                v[j+1].lm=max(v[j+1].lm,v2[j].lp);
            }
            for(int j=1;j<=min(i+1,251);++j)
            {
                for(int k=1;k<=v[j].lm;++k)
                    if(v[j].vm[k]>9)
                    {
                        v[j].vm[k+1]+=v[j].vm[k]/10;
                        v[j].vm[k]%=10;
                        if(k==v[j].lm)
                            ++v[j].lm;
                    }
                for(int k=1;k<=v[j].lp;++k)
                    if(v[j].vp[k]>9)
                    {
                        v[j].vp[k+1]+=v[j].vp[k]/10;
                        v[j].vp[k]%=10;
                        if(k==v[j].lp)
                            ++v[j].lp;
                    }
            }
        }
    }
    int Len=0;
    if((x+y)%2==0){
        for(int j=1;j<=max(v2[y+1].lm,v2[y+1].lp);++j)
            vsum[j]=v2[y+1].vm[j]+v2[y+1].vp[j];
        Len=max(v2[y+1].lm,v2[y+1].lp);
    }
    else{
        for(int j=1;j<=max(v[y+1].lm,v[y+1].lp);++j)
            vsum[j]=v[y+1].vm[j]+v[y+1].vp[j];
        Len=max(v[y+1].lm,v[y+1].lp);
    }
     for(int k=1;k<=Len;++k)
        if(vsum[k]>9)
        {
            vsum[k+1]+=vsum[k]/10;
            vsum[k]%=10;
            if(k==Len)
                ++Len;
        }
    for(int k=Len;k>=1;--k)
        g<<vsum[k];
    return 0;
}
