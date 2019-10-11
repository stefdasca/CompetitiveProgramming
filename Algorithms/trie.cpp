// https://www.infoarena.ro/problema/trie

#include<bits/stdc++.h>
using namespace std;
ifstream f("trie.in");
ofstream g("trie.out");
struct trie
{
    int cnt, nrfii, here;
    trie *f[30];
    trie()
    {
        cnt = nrfii = here = 0;
        memset(f, 0, sizeof(f));
    }
};
int test, n;
trie *rad = new trie;
trie *t;
char c[25];
int main()
{
    while(f>>test)
    {
        f>>c;
        n = strlen(c);
        bool ok;
        if(test==0)
        {
            t = rad;
            for (int i = 0; i < n; ++i)
            {
                int q = c[i]-'a';
                if(t->f[q] == NULL)
                {
                    ++t->nrfii;
                    t->f[q] = new trie;
                    ++t->f[q]->cnt;
                }
                else
                    ++t->f[q]->cnt;
                t = t->f[q];
            }
            ++t->here;
        }
        if(test==1)
        {
            t = rad;
            ok = false;
            for (int i = 0; i < n; ++i)
            {
                int q = c[i]-'a';
                if(t->f[q]->cnt == 1)
                {
                    delete t->f[q];
                    t->f[q] = NULL;
                    --t->nrfii;
                    ok = true;
                    break;
                }
                --t->f[q]->cnt;
                t = t->f[q];
            }
            if(!ok)
                --t->here;
        }
        if(test==2)
        {
            t = rad;
            ok=0;
            for (int i = 0; i < n; ++i)
            {
                int q = c[i]-'a';
                if(!t->f[q])
                {
                    ok=1;
                    break;
                }
                t = t->f[q];
            }
            if(ok)
                g<<0<<'\n';
            else
                g<<t->here<<'\n';
        }
        if(test==3)
        {
            t = rad;
            ok =0;
            for (int i = 0; i < n; ++i)
            {
                int q = c[i]-'a';
                if(!t->f[q])
                {
                    ok=1;
                    g<<i<<'\n';
                    break;
                }
                t = t->f[q];
            }
            if(!ok)
                g<<n<<'\n';
        }
    }
    return 0;
}
