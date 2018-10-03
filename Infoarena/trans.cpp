/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("trans.in");
ofstream g("trans.out");
int n,q;
int sb[16002],sw[16002],col,cost;
int dp[16002];
int mf,sc,a,b,j,i;
deque<int>dw;
deque<int>db;
int main()
{
    f>>n;
    for(i=1;i<=n;++i)
    {
        f>>col>>cost;
        sb[i]=sb[i-1]+(col==1)*cost;
        sw[i]=sw[i-1]+(col==0)*cost;
    }
    f>>q;
    for(i=1;i<=q;++i)
    {
        f>>mf>>sc;
        dw.clear();
        db.clear();
        dw.push_back(0);
        db.push_back(0);
        memset(dp,0,sizeof(dp));
        for(j=1;j<=n;++j){
            while(!db.empty() && db.front()<=j-mf-1)
                db.pop_front();
            while(!dw.empty() && dw.front()<=j-mf-1)
                dw.pop_front();
            a=sc+dp[dw.front()]+sw[j]-sw[dw.front()];
            b=sc+dp[db.front()]+sb[j]-sb[db.front()];
            dp[j]=min(a,b);
            while(!dw.empty() && dp[dw.back()]+sw[j]-sw[dw.back()]>=dp[j])
                dw.pop_back();
            dw.push_back(j);
            while(!db.empty() && dp[db.back()]+sb[j]-sb[db.back()]>=dp[j])
                db.pop_back();
            db.push_back(j);
        }
        g<<dp[n]<<'\n';
    }
    return 0;
}
