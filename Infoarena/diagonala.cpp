#include <fstream>
#define maxd 200002
using namespace std;
ifstream f("diagonala.in");
ofstream g("diagonala.out");
int i,n,sol,a[maxd],b[maxd],c[maxd],d[maxd],A[maxd],B[maxd];
void solve(int x)
{
    int st=1,ST=1,dr=0,DR=0,idx=1;
    for(int i=1;i<=n;++i)
    {
        A[i]=a[i]+x*i;
        B[i]=b[i]+x*i;
        /// c = deque sortat crescator pt capetele din dreapta
        /// d = deque sortat descrescator pt capetele din stanga
        while(st<=dr && A[c[dr]]<=A[i])
            --dr;
        c[++dr]=i;
        while(ST<=DR && B[d[DR]]>=B[i])
            --DR;
        d[++DR]=i;
        /// scoaterea elementelor daca ce e in stanga e mai mare decat ce e in dreapta
        while(A[c[st]]>B[d[ST]])
        {
            if(c[st]==idx)
                ++st;
            if(d[ST]==idx)
                ++ST;
            ++idx;
        }
        sol=max(sol,i-idx+1);
    }
}
int main()
{
    f>>n;
    for(i=1;i<=n;++i)
        f>>a[i]>>b[i];
    solve(1);
    solve(-1);
    g<<sol;
    return 0;
}
