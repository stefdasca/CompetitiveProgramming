/// OrangeWarrior #1
#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
ifstream f("luna.in");
ofstream g("luna.out");
int n,m,mat[52][52],k;
struct countries
{
    vector<pair<int,int>>v;
};
countries v[5002];
bool gut(int tara, int linii, int coloane)
{
    int b=0;
    int e=v[tara].v.size()-1;
    while(b<=e)
    {
        int m=(b+e)/2;
        if(v[tara].v[m].x==linii && v[tara].v[m].y==coloane)
            return 1;
        if(v[tara].v[m].x<linii || v[tara].v[m].x==linii && v[tara].v[m].y<coloane)
            b=m+1;
        else
            e=m-1;
    }
    swap(linii,coloane);
    b=0;
    e=v[tara].v.size()-1;
    while(b<=e)
    {
        int m=(b+e)/2;
        if(v[tara].v[m].x==linii && v[tara].v[m].y==coloane)
            return 1;
        if(v[tara].v[m].x<linii || v[tara].v[m].x==linii && v[tara].v[m].y<coloane)
            b=m+1;
        else
            e=m-1;
    }
    return 0;
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            f>>mat[i][j];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;j++)
        {
            int l=1;
            int cmax=1e9;
            while(1)
            {
                int c=1;
                while(mat[i+l-1][j+c-1]==mat[i][j] && j+c-1<=m)
                {
                    v[mat[i][j]].v.push_back(make_pair(l,c));
                    ++c;
                    if(c>cmax){
                        c=cmax;
                        break;
                    }
                    else
                        if(mat[i+l-1][j+c-1]!=mat[i][j]){
                            --c;
                            break;
                        }
                }
                cmax=min(cmax,c);
                if(mat[i+l][j]!=mat[i][j])
                    break;
                else
                    ++l;
            }
        }
    for(int i=1;i<=2500;++i)
        if(v[i].v.size())
            sort(v[i].v.begin(),v[i].v.end());
    f>>k;
    for(int i=1;i<=k;++i)
    {
        int tara, lines, columns;
        f>>tara>>lines>>columns;
        if(v[tara].v.size()==0)
            g<<"Tara de provenienta nu are parcele pe Luna!"<<'\n';
        else
            if(gut(tara, lines, columns)==1)
                g<<"Cererea poate fi satisfacuta!"<<'\n';
            else
                g<<"Cererea nu poate fi satisfacuta!"<<'\n';
    }
    return 0;
}
