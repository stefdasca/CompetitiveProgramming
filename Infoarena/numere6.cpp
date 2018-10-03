#include <bits/stdc++.h>
using namespace std;
ifstream f("numere6.in");
ofstream g("numere6.out");
int d[2][9001];
int dv[100];
vector<int>dc[9001];
int a, b, i, j, k, lp, nd = 0;
int main()
{
    f >> a >> b;
    int l = 0;
    for(i=1; i<=b; i++){
        if(b%i == 0){
            dv[++nd] = i;
            for(j=1; j<=9; j++)
                if(i%j == 0)
                    dc[i].push_back(j);
        }
    }
    for(i=1; i<=9; i++)
        if(b%i == 0)
            d[0][i] = 1;
    l = 0;
    for(i=2; i<=a; i++){
        lp = l;
        l = 1^l;
        for(j=1; j<=nd; j++){
            for(k=0; k<dc[dv[j]].size(); k++){
                d[l][dv[j]] += d[lp][dv[j]/ dc[dv[j]][k]];
            }
            d[l][dv[j]] %= 9973;
        }
        for(j=1; j<=nd; j++){
            d[lp][dv[j]] = 0;
        }
    }
    g << d[l][b] << "\n";
}
