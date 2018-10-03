/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("caps.in");
ofstream g("caps.out");
int k,q,lvl;
char c[100002],capsed[100002];
int hml[100002][52],hml2[100002][52];
long long val,sol;
long long L2;
long long mat[50][55][3];
char divimp(long long len, int NoC)
{
    if(L2==k)
    {
        if(NoC==0)
            return c[len];
        else
            return capsed[len];
    }
    if(len<=L2/4)
    {
        L2/=4;
        return divimp(len,NoC);
    }
    else
        if(L2/4<len && len<=(L2/4)*3)
        {
            L2/=4;
            if(len%L2==0)
                return divimp(L2,1-NoC);
            else
                return divimp(len%L2,1-NoC);
        }
        else
            if(len>(L2/4)*3)
            {
                L2/=4;
                if(len%L2==0)
                    return divimp(L2,NoC);
                else
                    return divimp(len%L2,NoC);
            }
}
void prec()
{
    f>>k>>q;
    f>>c+1;
    for(int i=1;i<=k;++i)
        if(c[i]>='a')
            capsed[i]=c[i]-32;
        else
            capsed[i]=c[i]+32;
    for(int i=1;i<=k;++i)
        for(int j=0;j<=25;++j)
        {
            hml[i][j]=hml[i-1][j]+(c[i]==('A'+j));
            hml[i][26+j]=hml[i-1][26+j]+(c[i]==('a'+j));
            hml2[i][j]=hml2[i-1][j]+(capsed[i]==('A'+j));
            hml2[i][26+j]=hml2[i-1][26+j]+(capsed[i]==('a'+j));
        }
    L2=k*4;
    for(int i=0;i<=51;++i){
        mat[1][i][0]=hml[k][i];
        mat[1][i][1]=hml2[k][i];
    }
    for(int i=2;L2<=2e18;L2*=4,++i)
        for(int j=0;j<=51;++j)
        {
            mat[i][j][0]=2*(mat[i-1][j][0]+mat[i-1][j][1]);
            mat[i][j][1]=mat[i][j][0];
        }
}
void hma(int cod,long long poz,int lvl,int NoC)
{
    if(lvl==1)
    {
        if(NoC==0)
            sol+=hml[poz][cod];
        else
            sol+=hml2[poz][cod];
        return;
    }
    else
    {
        if(poz<=L2/4)
        {
            L2/=4;
            hma(cod,poz,lvl-1,NoC);
        }
        else
            if(L2/4<poz && poz<=(L2/2))
            {
                sol+=mat[lvl-1][cod][NoC];
                L2/=4;
                if(poz%L2==0)
                    hma(cod,L2,lvl-1,1-NoC);
                else
                    hma(cod,poz%L2,lvl-1,1-NoC);
            }
            else
                if(L2/2<poz && poz<=(L2/4)*3)
                {
                    L2/=4;
                    sol+=mat[lvl-1][cod][NoC]+mat[lvl-1][cod][1-NoC];
                    if(poz%L2==0)
                        hma(cod,L2,lvl-1,1-NoC);
                    else
                        hma(cod,poz%L2,lvl-1,1-NoC);
                }
                else
                    if(poz>(L2/4)*3)
                    {
                        L2/=4;
                        sol+=mat[lvl-1][cod][NoC]+2*mat[lvl-1][cod][1-NoC];
                        if(poz%L2==0)
                            hma(cod,L2,lvl-1,NoC);
                        else
                            hma(cod,poz%L2,lvl-1,NoC);
                    }
    }
}
void solve()
{
    for(int i=1;i<=q;++i)
    {
        f>>val;
        L2=k;
        sol=0;
        lvl=1;
        while(L2<val)
            L2*=4,++lvl;
        char Lit=divimp(val,0);
        g<<Lit<<" ";
        while(L2<val)
            L2*=4;
        int cod=0;
        if(Lit<='Z')
            cod=Lit-'A';
        else
            cod=26+Lit-'a';
        hma(cod,val,lvl,0);
        g<<sol<<'\n';
    }
}
int main()
{
    prec();
    solve();
    return 0;
}
