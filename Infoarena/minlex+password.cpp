#include<bits/stdc++.h>
using namespace std;
ifstream f("password.in");
ofstream g("password.out");
char S[100002];
int min1,p=1,l=1;
int main()
{
    f>>S;
    int N=strlen(S);
    while((p < N) && (min1+l+1 < N)){
        if(S[min1+l] == S[p+l])
            ++l;
        if(S[min1+l] < S[p+l])
            p=p+l+1,l=0;
        if(S[min1+l] > S[p+l])
            min1=max(min1+l+1, p),p=min1+1,l=0;
    }
    g<<min1;
    return 0;
}
