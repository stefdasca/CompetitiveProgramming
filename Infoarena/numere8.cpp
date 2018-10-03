#include <fstream>
#include <cstring>
using namespace std;
ifstream fi("numere8.in");
ofstream fo("numere8.out");
int A[11],i,j,rez,smax,C[11],R[11],S[3],X[10],Y[10],x,y,c,nrc;
int main()
{
    for(i=1;i<=10;i++)
        fi>>A[i];
    for(i=1;i<=59049;i++)
    {
        c=i,nrc=0;
        memset(C,0,sizeof(C));
        while(c>0)
        {
           C[++nrc]=c%3;
           c/=3;
        }
        S[1]=S[2]=0;
        for(j=1;j<=nrc;j++)
            S[C[j]]+=A[j];
        if(S[1]==S[2])
        {
            rez++;
            if(S[1]>smax)
            {
                for(j=1;j<=nrc;j++)
                    R[j]=C[j];
                smax=S[1];
            }

        }
    }
    fo<<rez/2<<" "<<smax<<"\n";
    for(i=1;i<=10;i++)
        if(R[i]==1)
            X[++x]=A[i];
        else
            if(R[i]==2)
                Y[++y]=A[i];
    for(i=1;i<=x;i++)
        fo<<X[i]<<" ";
    fo<<"\n";
    for(i=1;i<=y;i++)
        fo<<Y[i]<<" ";
    return 0;
}
