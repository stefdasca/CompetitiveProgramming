// https://www.infoarena.ro/problema/ahocorasick
#include<bits/stdc++.h>
using namespace std;
struct trie{
    trie *fii[26], *fail;
    vector<int> v;
    int occ;
    trie(){
        occ = 0;
        fail = NULL;
        memset(fii, 0, sizeof(fii));
    }
};
ifstream f("ahocorasick.in");
ofstream g("ahocorasick.out");
char r[1000005], c[10005];
int n, sol[105], szr, szc;
trie *rad = new trie;
// bagam fiecare cuvant ca la trie, retinand si pozitia
void baga(char c[], int i)
{
    szc = strlen(c);
    trie *t = rad;
    for (int j = 0; j < szc; ++j){
        int q = c[j]-'a';
        if(t->fii[q] == NULL)
            t->fii[q] = new trie;
        t = t->fii[q];
    }
    t->v.push_back(i);
}
int main() 
{
    f >> r >> n;
    szr = strlen(r);
    for (int i = 1; i <= n; ++i)
    {
        f >> c;
        baga(c, i);
    }
    int vf = -1;
    // bfs in nodurile triei, aflam pentru fiecare nod, nodul fail ca la KMP
    vector<trie*> qu;
    qu.push_back(rad);
    rad->fail = rad;
    while(vf != qu.size()-1)
    {
        trie *t = qu[++vf];
        for (int i = 0; i < 26; ++i)
            if(t->fii[i])
            {
                trie *fail = t->fail;
                while(fail != rad && fail->fii[i] == NULL)
                    fail = fail->fail;
                if(fail->fii[i] != NULL && fail->fii[i] != t->fii[i])
                    fail = fail->fii[i];
                t->fii[i]->fail = fail;
                qu.push_back(t->fii[i]);
            }
    }
    // actualizam solutia in ordine inversa a bfs-ului
    rad->fail = NULL;
    trie *t = rad;
    for (int i = 0; i < szr; ++i)
    {
        int q = r[i]-'a';
        while(t != rad && t->fii[q] == NULL)
            t = t->fail;
        if(t->fii[q] != NULL)
            t = t->fii[q];
        ++t->occ;
    }
    for(int i = vf; i >= 0; --i)
    {
        t = qu[i];
        if(t->fail != NULL)
            t->fail->occ += t->occ;
        for (int j = 0; j < t->v.size(); ++j)
            sol[t->v[j]] = t->occ;
    }
    for (int i = 1; i <= n; ++i)
        g << sol[i] << '\n';
    return 0;
}
