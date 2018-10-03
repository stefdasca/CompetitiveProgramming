#include<bits/stdc++.h>
using namespace std;
ifstream f("poly.in");
ofstream g("poly.out");
int n,sol[30002];
int v[30002];
deque<int>scos;
struct compar2
{
    bool operator()( int x, int y ){
        return sol[x]<sol[y];
    }
};
priority_queue <int,vector<int>,compar2> h_i;
int shit[]= {2, 3, 7, 11, 19, 23, 37};
int main()
{
    f>>n;
    f>>v[1];
    sol[1]=1;
    h_i.push(1);
    for(int i=2;i<=n;++i)
    {
        f>>v[i];
        bool ok=0;
        while(!ok)
        {
            int nr=h_i.top();
            ok=1;
            for(int j=0;j<7;++j)
                if(v[i]%shit[j]==0 && v[nr]%shit[j]==0){
                    ok=0;
                    break;
                }
            if(ok==0)
            {
                scos.push_back(nr);
                h_i.pop();
                if(h_i.empty()){
                    sol[i]=1;
                    break;
                }
            }
            else{
                sol[i]=sol[nr]+1;
                break;
            }
        }
        while(!scos.empty())
            h_i.push(scos.back()),scos.pop_back();
        h_i.push(i);
    }
    int max1=0;
    for(int i=1;i<=n;++i)
        max1=max(max1,sol[i]);
    g<<max1;
    return 0;
}
