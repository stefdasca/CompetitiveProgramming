#include <fstream>
#include <algorithm>
#include<queue>
using namespace std;

ifstream f("acoperire.in");
ofstream g("acoperire.out");
struct interval{
    int x,y;
}v[1001];
int n,i,a,b,poz,leftmax,nr,ok;
bool cmp(interval t,interval u)
{
    if(t.x<u.x)
        return true;
    return false;
}
int main()
{
    f>>a>>b>>n;
    for(i=1;i<=n;i++)
        f>>v[i].x>>v[i].y;
    sort(v+1,v+n+1,cmp);
    /*for(i=1;i<=n;i++)
        g<<v[i].x<<" "<<v[i].y<<'\n';*/
    leftmax=0;
    for(i=1;i<=n&&a<b;i++)
    {
        if(v[i].x<=a)
        {
            if(v[i].y>leftmax)
                leftmax=v[i].y,poz=i;
            if(leftmax>=b)
            {
                nr++;
                ok=1;
                break;
            }
        }
        else
        {
            if(leftmax<=a)
            {
                g<<"-1"<<'\n';
                return 0;
            }
            nr++;
            a=leftmax;
            if(v[i].x<=a)
            {
                if(a<b)
                    if(v[i].y>a)
                        leftmax=v[i].y,poz=i;
                    else
                        leftmax=a;
                else
                    poz=i;
            }
            else
                poz=i;
        }
    }
    if(leftmax<b)
    {
        g<<"-1"<<'\n';
        return 0;
    }
    else
    {
        if(v[poz].x<b&&!ok)
            nr++;
    }
    g<<nr<<'\n';
    return 0;
}
