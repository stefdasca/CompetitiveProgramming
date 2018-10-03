#include <iostream>
#include <fstream>
using namespace std;
struct player
{
    int won,lost,tre;
};
player p[401];
int v[1001];
bool visited[905];
int main()
{
    ifstream cin ("joc10.in");
    ofstream cout ("joc10.out");
    int n,m,aux,penalty,min=2100000000,who,room,cnt=0,poz;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            visited[j]=0;
            cin>>v[j];
        }
        penalty=1;
        poz=1;
        while(v[poz]!=9999 and v[poz]!=0 and visited[poz]==0)
        {
            penalty+=(v[poz]%10);
            visited[poz]=1;
            poz=v[poz]/10;
            penalty++;
        }
        if(v[poz]==0)
        {
            p[i].lost=penalty;
        }
        if(v[poz]==9999)
        {
            p[i].won=penalty;
            p[i].tre=poz;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(p[i].won!=0 and p[i].won<min)
        {
            min=p[i].won;
            who=i;
            room=p[i].tre;
        }

    }
    for(int i=1;i<=n;i++)
    {
        if(p[i].lost !=0 && p[i].lost<=min)
            cnt++;
    }
    cout<<who<<" "<<room<<" "<<min<<" "<<cnt;
    return 0;
}
