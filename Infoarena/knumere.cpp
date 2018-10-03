#include <fstream>
#include <deque>
using namespace std;
const int NMAX=1000005;
ifstream f("knumere.in");
ofstream g("knumere.out");
deque <int> D;
int a[NMAX],dif[NMAX];
int main()
{
    int n,k,na=0,sol=2*1000000005;
    f>>n>>k;
    for(int i=1;i<=n;i++)
        f>>a[i];
    for(int i=2;i<=n;i++)
        dif[++na]=a[i]-a[i-1];
    k=n-k-1;
    for(int i=1;i<=na;i++)
    {
        while(!D.empty() && dif[i]>=dif[D.back()])
            D.pop_back();
        D.push_back(i);
        if(D.front()<=i-k)
            D.pop_front();
        if(i>=k)
            sol=min(sol,dif[D.front()]);
    }
    g<<sol<<"\n";
    return 0;
}
