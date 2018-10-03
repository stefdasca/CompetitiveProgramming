#include<bits/stdc++.h>
using namespace std;
ifstream f("palindrom.in");
ofstream g("palindrom.out");
const int maxn = 400001;
char S[maxn],S1[maxn];
int P[maxn];
int N;
int main()
{
    f>>S+1;
    N = strlen(S + 1);
    memcpy(S1,S,sizeof(S));
    reverse(S1 + 1,S1 + N + 1);
    for(int i = 2;i <= N; ++i)
    {
        int aux = P[i - 1];
        while(aux && S1[i] != S1[aux + 1])
            aux = P[aux];
        if (S1[i] == S1[aux + 1])
            P[i] = aux + 1;
    }
    int pozcur = 0;
    for(int i = 1;i <= N; ++i)
    {
        while(pozcur && S[i] != S1[pozcur + 1])
            pozcur = P[pozcur];
        if (S[i] == S1[pozcur + 1]) pozcur++;
    }
    g<<S+1;
    for(int i = N - pozcur; i; --i)
        g<<S[i];
    return 0;
}
