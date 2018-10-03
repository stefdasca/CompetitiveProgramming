#include <fstream>
using namespace std;
ifstream fin("barbar.in");
ofstream fout("barbar.out");
short f[1002][1002],x[1000001],y[1000001],x1,y1,x2,y2,n,m;
int drag;
short cx[1000001],cy[1000001];
short dx[4]={-1,0,+1,0};
short dy[4]={0,+1,0,-1};
short lee(short k)
{
    short j,fl,nr;
    int z,p,u,uc,i,xx,yy;
    p=1;
    u=0;
    for(z=1; z<=drag && k; z++)
    {
        u++;
        cx[u]=x[z];
        cy[u]=y[z];
        f[x[z]][y[z]]=2;
    }
    fl=1;
    nr=k-1;
    while(nr>0 && p<=u)
    {
        uc=u;
        for(i=p; i<=u && fl; i++)
            for(j=0; j<4; j++)
            {
                xx=cx[i]+dx[j];
                yy=cy[i]+dy[j];
                if(f[xx][yy]==0)
                    if(xx==x1 && yy==y1)
                        {fl=0; break;}
                    else
                        uc++,cx[uc]=xx,cy[uc]=yy,f[xx][yy]=2;
            }
        if(!fl)
            break;
        p=u+1;
        u=uc;
        nr--;
    }
    if(fl==0)
    {
        for(i=1; i<=n; i++)
            for(j=1; j<=m; j++)
                if(f[i][j]==2)
                    f[i][j]=0;
        return 0;
    }
    f[x1][y1]=3;
    p=u=1;
    cx[p]=x1;
    cy[p]=y1;
    while(p<=u)
    {
        for(i=0; i<4; i++)
        {
            xx=cx[p]+dx[i];
            yy=cy[p]+dy[i];
            if(f[xx][yy]==0)
                u++,cx[u]=xx,cy[u]=yy,f[xx][yy]=3;
        }
        p++;
    }
    if(f[x2][y2]!=3)
        fl=0;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(f[i][j]==2 || f[i][j]==3)
                f[i][j]=0;
    return fl;
}
int main()
{
    short i,j,pas,rez;
    char c;
    fin >> n >> m;
    drag=0;
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++)
        {
            fin>>c;
            switch(c)
            {
                case 'I': x1=i,y1=j; break;
                case '0': x2=i,y2=j; break;
                case 'O': x2=i,y2=j; break;
                case '*': f[i][j]=1; break;
                case 'D': drag++; x[drag]=i,y[drag]=j; break;
                default: break;
            }
        }
    }
    for(i=0; i<=n+1; i++)
        f[i][0]=f[i][m+1]=1;
    for(i=0; i<=m+1; i++)
        f[0][i]=f[n+1][i]=1;
    pas=1<<11;
    rez=0;
    while(pas)
    {
        if(lee(rez+pas))
            rez+=pas;
        pas/=2;
    }
    if(rez==0)
    {
        rez=lee(0);
        rez--;
    }
    fout<<rez;

    return 0;
}
