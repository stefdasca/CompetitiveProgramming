#include <iostream>
#include <fstream>
#include <cmath>
#include <queue>
#include <climits>
#include <iomanip>
using namespace std;
int xi[4]={0,0,-1,1};
int yi[4]={-1,1,0,0};
int mat[51][51],n,m,li,ci,lf,cf;
double lmax;
ifstream fin("excursie.in");
ofstream fout("excursie.out");
double d[51][51],drum[51][51];
bool OK(int i ,int j)
{
    if(i<1||j<1||i>n||j>m)return false;
    return true;
}
void lee()
{
    queue< pair < int , int > > q;
    q.push(make_pair(li,ci));
    d[li][ci]=0;
    while(!q.empty())
    {    int x=q.front().first;
         int y=q.front().second;
         q.pop();
         for(int i=0;i<4;++i)
         {
             int X,Y;
             X=x+xi[i];
             Y=y+yi[i];
             double nr;
             double dr=sqrt( (mat[x][y]-mat[X][Y])*(mat[x][y]-mat[X][Y]) +1)  ;
             if(mat[x][y]-mat[X][Y]==0)nr=1;
             else if(mat[x][y]>mat[X][Y])
             {
                 nr=dr*(mat[x][y]-mat[X][Y]);
             }
             else nr=dr*(mat[X][Y]-mat[x][y]);

             if(mat[x][y]>mat[X][Y])nr/=2;
             if(OK(X,Y)&&d[X][Y]>d[x][y]+nr)
             {
                 d[X][Y]=d[x][y]+nr;
                 drum[X][Y]=drum[x][y]+dr;
                 q.push(make_pair(X,Y) );

             }
             else if(OK(X,Y)&&d[X][Y]==d[x][y]+nr)if(drum[X][Y]>drum[x][y]+dr)drum[X][Y]=drum[x][y]+dr;
         }
    }
    fout<<fixed<<setprecision(3)<<d[lf][cf]<<" "<<drum[lf][cf];

}
int main()
{

    fin>>n>>m;
    fin>>lmax;
    for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j)
    fin>>mat[i][j];
    fin>>li>>ci>>lf>>cf;
    for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j)
    d[i][j]=200000000;
    lee();


    return 0;
}
