#include<bits/stdc++.h>
using namespace std;
ifstream f("dinozaur.in");
ofstream g("dinozaur.out");

// WTF

// ifstream f("piramide.in");
// ofstream g("piramide.out");
char c1[100002];
int fr[27];
int main()
{
    f>>c1;
    int l=strlen(c1);
    for(int i=0;i<l;++i)
    {
        fr[c1[i]-'a']++;
        if(fr[c1[i]-'a']==2){
            g<<1;
            return 0;
        }
    }
    g<<0;
    return 0;
}
