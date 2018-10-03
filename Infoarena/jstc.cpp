#include <fstream>
#define nmax 1000004
using namespace std;
ifstream f("jstc.in");
ofstream g("jstc.out");
long long ans;
int A,B,K,top,X,y,p,aux,i;
int nxt[nmax], st[nmax];
char s[10 * nmax];
int main()
{
    f>> A >> B >> s;
    for(i = 0; s[i]; i++)
    {
        if(s[i]=='I')
        {
            st[++top]=++K;
            nxt[K]=K;
            continue;
        }
        if(s[i]=='E')
        {
            nxt[st[top]] = st[top] + 1;
            top--;
            continue;
        }
        X=(1LL*A*X+B)%K+1;
        y=X;
        while(y != nxt[y] && y <= K)
            y = nxt[y];
        p=X;
        while(p!=y)
        {
            aux=nxt[p];
            nxt[p]=y;
            p=aux;
        }
        if(y>K)
            ans--;
        else
            ans+=y;
    }
    g<<ans<<'\n';
    return 0;
}
