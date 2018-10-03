#include<bits/stdc++.h>
using namespace std;
ifstream f("multimi3.in");
ofstream g("multimi3.out");
int p,q,mat[1002][1002],v[1002];
int main()
{
    f>>p>>q;
    if(p<=q)
    {
        for(int i=1;i<=p;++i)
        {
            int q=i;
            for(int j=1;j<=p;++j)
            {
                mat[i][j]=q+(j-1)*p;
                ++q;
                if(q>p)
                    q=1;
            }
        }
        for(int i=1;i<=p;++i)
        {
            int dif=i;
            for(int j=p+1;j<=q;++j)
                if(((j-p)&1))
                    mat[i][j]=dif+(j-1)*p;
                else
                    mat[i][j]=(p+1)-dif+(j-1)*p;
        }
    }
    else
    {
        for(int i=1;i<=q-2;++i)
            for(int j=1;j<=p;++j)
                if(i&1)
                    mat[j][i]=(i-1)*p+j;
                else
                    mat[j][i]=i*p-j+1;
        for(int j=1;j<=p/2+p%2;++j)
            mat[j][q]=mat[j][q-2]+2*p+p/2;
        for(int j=p%2+p/2+1;j<=p;++j)
            mat[j][q]=mat[j][q-2]+p+p/2;
        long long sumnec=1LL*(p*q)*(p*q+1)/2;
        sumnec/=p;
        for(int i=1;i<=p;++i)
        {
            int sum=0;
            for(int j=1;j<=q;++j)
                sum+=mat[i][j];
            mat[i][q-1]=sumnec-sum;
        }
    }
    for(int i=1;i<=p;g<<'\n',++i)
        for(int j=1;j<=q;++j)
            g<<mat[i][j]<<" ";
    return 0;
}
