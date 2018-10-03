#include <fstream>
#include<algorithm>
using namespace std;
int ok[50];
int main()
{   int pa,pb,a[50],n,k,i,j,b[50],aux,x,opt;
    ifstream fin("triunghi5.in");
    ofstream fout("triunghi5.out");
    fin>>opt>>n>>k;
    for (i=1;i<=n;i++)
        fin>>a[i];
    sort(a+1,a+n+1);
    if (opt==1)
    {
        b[1]=b[2]=a[1];
        for (i=3;i<=k;i++)
            b[i]=b[i-1]+b[i-2];
        for (i=1;i<=k;++i)
            fout<<b[i]<<' ';
        fout<<"\n";
    }
    else
    {
        if (a[1]==a[2])
        {
            b[1]=b[2]=a[1];
            ok[1]=ok[2]=1;       //in sirul b bifam toate elementele
            pa=3;                // ce apartin lui a
        }
        else
        {
            b[1]=b[2]=1;
            if (a[1]==1)         //  se bifeaza elementul 1 in cazul
            {
                ok[1]=1;         // in care este element din a
                pa=2;
            }
            else
                pa=1;

        }
        pb=2;
        while (pa<n)
        {
            x=b[pb]+b[pb-1];

            if (b[pb]+x<=a[pa] && x<=a[pa+1]-a[pa])
                b[++pb]=x;
            else
            {
                b[++pb]=a[pa++];
                ok[pb]=1;
            }
        }
        while (pa==n)
        {
            x=b[pb]+b[pb-1];
            if(b[pb]<=a[pa]-x)
                b[++pb]=x;
            else
            {
                b[++pb]=a[pa++];
                ok[pb]=1;
            }
        }
        while (b[pb]<=2000000000-b[pb-1])
        {
            b[pb+1]=b[pb]+b[pb-1];
            pb++;
        }
        for (i=1;i<=pb;i++)
            if (ok[i]) fout<<b[i]<<" ";
        x=k-n;
        for(i=1;x && i<=pb;i++)
            if (!ok[i])
            {
                fout<<b[i]<<" ";
                --x;
            }
        fout<<"\n";
    }
    fin.close();
    fout.close();

    return 0;
}
