#include<bits/stdc++.h>
using namespace std;
ifstream f("minge.in");
ofstream g("minge.out");
char nr[2002];
int main()
{
    f>>nr;
    int l=strlen(nr);
    if(nr[l-1]%2==1){
        int tr=0;
        bool ok=0;
        for(int j=0;j<l;++j){
            if(nr[j]-'0'+tr>=2)
                ok=1;
            if(ok==1)
                g<<(nr[j]-'0'+tr)/2;
            tr=(nr[j]-'0')%2;
            tr*=10;
        }
    }
    else
    {
        int nr1[2002];
        for(int j=0;j<l;++j)
            nr1[j]=nr[j]-'0';
        nr1[l-1]-=2;
        int q=l-1;
        while(nr1[q]<0)
        {
            nr1[q]+=10;
            nr1[q-1]--;
            --q;
        }
        int tr=0;
        for(int j=0;j<l;++j)
        {
            tr=tr*10+nr1[j];
            nr1[j]=tr/2;
            tr=tr%2;
        }
        if(nr1[l-1]%2==0)
            --nr1[l-1];
        q=l-1;
        while(nr1[q]<0)
        {
            nr1[q]+=10;
            nr1[q-1]--;
            --q;
        }
        bool ok=0;
        for(int j=0;j<l;++j)
        {
            if(nr1[j]>0)
                ok=1;
            if(ok==1)
                g<<nr1[j];
        }
    }
    return 0;
}
