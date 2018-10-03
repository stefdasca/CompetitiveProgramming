/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("queue.in");
ofstream g("queue.out");
int n,nr;
char c[25];
deque<int>F;
deque<int>S;
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        g<<i<<": ";
        f>>c;
        if(c[4]=='_')
        {
            nr=0;
            int poz=10;
            while(c[poz]>='0' && c[poz]<='9')
                nr=nr*10+(c[poz]-'0'),++poz;
            g<<"read("<<nr<<") "<<"push(1,"<<nr<<")"<<'\n';
            F.push_front(nr);
        }
        else
        {
            if(!S.empty())
            {
                g<<"pop(2) write("<<S.front()<<")"<<'\n';
                S.pop_front();
            }
            else
            {
                while(F.size()>1)
                {
                    g<<"pop(1) push(2,"<<F.front()<<")"<<" ";
                    int nr=F.front();
                    S.push_front(nr);
                    F.pop_front();
                }
                g<<"pop(1) write("<<F.front()<<")"<<'\n';
                F.pop_front();
            }
        }
    }
    return 0;
}
