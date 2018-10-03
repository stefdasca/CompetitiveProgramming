#include<bits/stdc++.h>
using namespace std;
ifstream f("interval.in");
ofstream g("interval.out");
int a,b,q,t;
long long nr;
int main()
{
    f>>a>>b;
    f>>q;
    for(int i=1;i<=q;++i)
    {
        f>>t>>nr;
        if(t==1)
        {
            long long A=a+(a%nr>0)*(nr-a%nr);
            long long B=b-b%nr;
            long long sol=(B-A)/nr+1;
            g<<sol<<'\n';
        }
        if(t==2)
        {
            long long A=a+(a%nr>0)*(nr-a%nr);
            long long B=b-b%nr;
            long long sol=(B-A)/nr+1;
            sol=sol*(sol-1);
            sol/=2;
            g<<sol<<'\n';
        }
        if(t==3)
        {
            long long sol=0;
            for(int j=a;j<b;++j)
            {
                int be=j+1;
                int e=b;
                if(1LL*j*(j+1)>nr)
                    sol+=(b-j);
                else
                    if(1LL*j*b<=nr)
                        continue;
                    else
                        while(be<=e)
                        {
                            int mid=(be+e)/2;
                            if(1LL*j*mid>nr && (mid-1==j || 1LL*j*(mid-1)<=nr)){
                                sol+=(b-mid+1);
                                break;
                            }
                            if(1LL*j*mid>nr)
                                e=mid-1;
                            else
                                be=mid+1;
                        }
            }
            g<<sol<<'\n';
        }
    }
    return 0;
}
