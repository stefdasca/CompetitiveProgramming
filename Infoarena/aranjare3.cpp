#include<bits/stdc++.h>
using namespace std;
ifstream f("aranjare3.in");
ofstream g("aranjare3.out");
int n;
vector<int>sta[3];
vector<pair<int,int> >sol;
int who[5][5];
void dei(int nrs, int left, int right)
{
    int mid=(left+right)/2;
    if(left==right)
    {
        sol.push_back({nrs,0});
        sta[0].push_back(sta[nrs].back());
        sta[nrs].pop_back();
        return;
    }
    while(sta[nrs].back()>=left && sta[nrs].back()<=right)
    {
        if(sta[nrs].back()<=mid)
        {
            sol.push_back({nrs,who[nrs][1]});
            sta[who[nrs][1]].push_back(sta[nrs].back());
            sta[nrs].pop_back();
        }
        else
        {
            sol.push_back({nrs,who[nrs][2]});
            sta[who[nrs][2]].push_back(sta[nrs].back());
            sta[nrs].pop_back();
        }
    }
    dei(who[nrs][1],left,mid);
    dei(who[nrs][2],mid+1,right);
}
int main()
{
    f>>n;
    who[0][1]=1;who[0][2]=2;who[1][1]=0;who[1][2]=2;who[2][1]=0;who[2][2]=1;
    for(int i=1;i<=n;++i)
    {
        int nr;
        f>>nr;
        sta[0].push_back(nr);
    }
    dei(0,1,n);
    g<<2<<" "<<sol.size()<<'\n';
    for(int i=0;i<sol.size();++i)
        g<<sol[i].first<<" "<<sol[i].second<<'\n';
    return 0;
}
