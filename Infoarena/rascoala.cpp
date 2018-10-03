#include<fstream>
#include<algorithm>
#include<cstring>
using namespace std;
struct poz
{
    int l,c;
    int val;
};
bool test(poz a, poz b)
{
    if(a.val!=b.val)
        return a.val<b.val;
    if(a.l!=b.l)
        return a.l<b.l;
    return a.c<b.c;
}
char c1[5000];
int main()
{
    ifstream f("rascoala.in");
    ofstream g("rascoala.out");
    poz v[250001];
    poz v2[2002];
    int c,n,m,k;
    int ar[250001];
    int mx[3][502],mn[3][502];
    f>>c;
    f>>n>>m>>k;
    int cot=1;
    for(int i=1;i<=n;++i)
    {
        f.get();
        f.get(c1,4000,'\n');
        int qq=strlen(c1);
        for(int j=0;j<qq;++j)
            if(c1[j]==' ');
            else{
                int nr=0;
                while(c1[j]!=' ' && j<qq)
                    nr=nr*10+(c1[j]-'0'),++j;
                v[cot].val=nr;
                ++cot;
            }
    }
    --cot;
    for(int i=1;i<=cot;ar[i]=v[i].val,++i);
    cot=1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j,++cot)
            v[cot].l=i,v[cot].c=j;
    sort(ar+1,ar+n*m+1);
    int min1=1,valmin,prvmin,trmin;
    while(k)
    {
        prvmin=min1-1;
        while(ar[min1]==ar[min1+1])
            ++min1;
        valmin=ar[min1];
        if(min1!=n*m)
            if(k>=(ar[min1+1]-ar[min1])*min1)
                k-=(ar[min1+1]-ar[min1])*min1,++min1;
            else
            {
                trmin=min1;
                if(k>=min1);
                else
                if(k>=prvmin)
                    min1=k;
                else
                    min1=prvmin;
                break;
            }
        else
            break;
    }
    trmin=min1;
    if(k>=min1);
    else
    if(k>=prvmin)
        min1=k;
    else
        min1=prvmin;
    if(c==1)
    {
        g<<min1<<'\n';
        g<<valmin+k/trmin<<'\n';
    }
    else
    {
         sort(v+1,v+n*m+1,test);
         int dmax=0;
         for(int i=1;i<=n;++i)
            mn[1][i]=10000; // minim pe linie
         for(int i=1;i<=m;++i)
            mn[2][i]=10000; // minim pe coloana
         for(int i=1;i<=min1;++i){
            if(v[i].c>mx[1][v[i].l])
                mx[1][v[i].l]=v[i].c;
            if(v[i].c<mn[1][v[i].l])
                mn[1][v[i].l]=v[i].c;
            if(v[i].l>mx[2][v[i].c])
                mx[2][v[i].c]=v[i].l;
            if(v[i].l<mn[2][v[i].c])
                mn[2][v[i].c]=v[i].l;
         }
         int ct=1;
         for(int i=1;i<=n;++i){
            if(mn[1][i]!=10000)
                v2[ct].l=i,v2[ct++].c=mn[1][i];
            if(mx[1][i])
                v2[ct].l=i,v2[ct++].c=mx[1][i];
         }
         for(int i=1;i<=m;++i){
            if(mn[2][i]!=10000)
                v2[ct].l=mn[2][i],v2[ct++].c=i;
            if(mx[2][i])
                v2[ct].l=mx[2][i],v2[ct++].c=i;
         }
         for(int i=1;i<ct;++i)
            for(int j=i+1;j<ct;++j)
            {
                int dx=v2[i].l-v2[j].l;
                if(dx<0)
                    dx=-dx;
                int dy=v2[i].c-v2[j].c;
                if(dy<0)
                    dy=-dy;
                dmax=max(dmax,dx+dy);
            }
        g<<dmax<<'\n';
    }
    return 0;
}
