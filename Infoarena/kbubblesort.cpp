#include <fstream>
#include <queue>
using namespace std;
ifstream f("kbubblesort.in");
ofstream g("kbubblesort.out");
int V[1000010],N,K,in,i,m;
queue < int > Q;
int main()
{
    f>>N>>K;
    for(i=1;i<=N;++i)
        f>>V[i];
    V[N+1]=100000000;
    for(i=1;i<=N;++i)
        if(V[i]>V[i+1] && V[i]>m)
            Q.push(i),m=V[i];
    m=0;
    while(K)
    {
        i=Q.front();
        if(in>=i)
            m=0;
        for(;V[i]>V[i+1] && K;i++,K--)
        {
            swap(V[i],V[i+1]);
            if(V[i-1]>V[i] && V[i-1]>m)
                m=V[i-1],Q.push(i-1);
        }
        in=Q.front();
        Q.pop();
    }
    for(i=1;i<=N;++i)
        g<<V[i]<<' ';
    return 0;
}
