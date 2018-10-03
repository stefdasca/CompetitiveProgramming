#include<bits/stdc++.h>
using namespace std;
ifstream f("parantezare.in");
ofstream g("parantezare.out");
int m,fr[100002];
char c1[100002];
vector<int>v;
int main()
{
    f>>c1;
    f>>m;
    int l=strlen(c1);
    int d=-1;
    for(int i=0;i<l;++i)
       if(c1[i]=='(')
            v.push_back(i),++d;
        else
            if(c1[i]==')')
              fr[v[d]]=i,v.pop_back(),--d;
    for(int i=0;i<m;++i)
        f>>d,g<<fr[d]<<" ";
    return 0;
}
