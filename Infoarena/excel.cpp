#include<bits/stdc++.h>
using namespace std;
ifstream f("excel.in");
ofstream g("excel.out");
int nr,lv;
struct ln
{
    long long nrl,val;
};
ln v[301];
bool test(ln a,ln b)
{
    return a.nrl<b.nrl;
}
char c1[1002];
char b[50],yy=0;
void alcsir(int nr)
{
    yy=0;
    int q=26;
    while(nr)
    {
        int mod=nr%q;
        if(mod==0)
            b[yy++]='Z',nr-=q;
        else
        {
            int add=(mod*26/q)-1;
            b[yy++]='A'+add,nr-=mod;
        }
        q*=26;
    }
}
int main()
{
    while(f>>c1>>nr){
        int l=1;
        int nrl=0;
        int nrc=0;
        while(c1[l]>='0' && c1[l]<='9')
            nrl=nrl*10+c1[l]-'0',++l;
        ++l;
        while(l<strlen(c1))
            nrc=nrc*10+c1[l]-'0',++l;
        alcsir(nrc);
        for(int i=yy-1;i>=0;--i)
            if(b[i]=='>')
                g<<"Y";
            else
                g<<b[i];
        g<<nrl<<'\n';
        bool ok=0;
        for(int i=1;i<=lv;++i)
            if(v[i].nrl==nrl){
                v[i].val+=nr;
                ok=1;
                break;
            }
        if(ok==0)
            ++lv,v[lv].nrl=nrl,v[lv].val=nr;
    }
    sort(v+1,v+lv+1,test);
    if(v[1].nrl>1)
        g<<v[1].nrl-1<<" "<<0<<" ";
    for(int i=1;i<=lv;++i){
        if(v[i].val==0)
            g<<1<<" "<<v[i].val<<" ";
        else
            g<<v[i].val<<" ";
        if(v[i+1].nrl-v[i].nrl>1)
            g<<v[i+1].nrl-v[i].nrl-1<<" "<<0<<" ";
    }
    return 0;
}
