#include<bits/stdc++.h>
using namespace std;
ifstream f("tabela.in");
ofstream g("tabela.out");
int a,b;
int main()
{
    f>>a>>b;
    --a,--b;
    g<<(a^b);
    return 0;
}
