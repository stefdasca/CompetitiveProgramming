/*

    https://ivaniscoding.wordpress.com/2018/08/25/communication-2-navigation/

*/
#include "Annalib.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> v[100005];
int color[100005];

void dfs(int nod, int dad)
{
	for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
		int new_color = (nod < vecin) + color[nod];
		color[vecin] = new_color % 2;
		dfs(vecin, nod);
	}
}

void Anna(int K, int N, int T, int A[], int B[])
{
	for(int i = 0; i < N - 1; i++)
    {
        v[A[i]].push_back(B[i]);
        v[B[i]].push_back(A[i]);
	}
	dfs(T, -1);
	for(int i = 1; i <= N; i++)
        Flag(i, color[i]);
}
