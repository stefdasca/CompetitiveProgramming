#include<bits/stdc++.h>
using namespace std;
ifstream f("bratara.in");
ofstream g("bratara.out");
int c,n,v[100002];
void first_cer()
{
    int Ln=v[1]%10+((v[1]/10)%10)*10;
    int Lb=1;
    int sol=0;
    for(int i=2;i<=n;++i)
    {
        int nr=v[i];
        while(nr>=100)
            nr/=10;
        if(nr==Ln)
            ++Lb;
        else
        {
            if(Lb>=2)
                ++sol;
            Lb=1;
        }
        Ln=v[i]%10+((v[i]/10)%10)*10;
    }
    if(Lb>=2)
        ++sol;
    g<<sol;
}
vector<int>vv[102];
void second_cer()
{
    int Ln=v[1]%10+((v[1]/10)%10)*10;
    int nr=v[1];
    while(nr>=100)
        nr/=10;
    vv[nr].push_back(1);
    int Lb=1;
    int sol=-1;
    int l=0,r=0;
    for(int i=2;i<=n;++i)
    {
        int nr=v[i];
        while(nr>=100)
            nr/=10;
        if(nr==Ln)
        {
            int nnr=v[i]%10+((v[i]/10)%10)*10;
            ++Lb;
            if(nnr<10)
                continue;
            int b=0;
            int e=vv[nnr].size()-1;
            while(b<=e)
            {
                int mid=(b+e)/2;
                if(vv[nnr][mid]>=i-Lb+1)
                {
                    if(i-vv[nnr][mid]+1>sol){
                        sol=i-vv[nnr][mid]+1;
                        l=vv[nnr][mid];
                        r=i;
                    }
                    e=mid-1;
                }
                else
                    b=mid+1;
            }
        }
        else
            Lb=1;
        vv[nr].push_back(i);
        Ln=v[i]%10+((v[i]/10)%10)*10;
    }
    if(sol==-1)
        g<<-1;
    else
        g<<sol<<" "<<l<<" "<<r<<'\n';
}
int main()
{
    f>>c;
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i];
    if(c==1)
        first_cer();
    else
        second_cer();
    return 0;
}
