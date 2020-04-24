/*
		NOI 18-CityMapping
	
	Let's find distances from 1 to all other nodes and sort the nodes based on the distance value.
	
	Now we can find the father of vertex i in sorted order using a "divide and conquer" like approach.
	
	Let's say we have a subtree of nodes left, we are going to go to the largest node(wrt subtree size)
until we get to a leaf, and based on the value of the distance from that leaf to the node we're searching for,
we are going to find the new root. We will repeat this until we have only one node left, which will be the father
of the current node.
	
	For more details, access the official solution(the one based on Tree Binary Search + the 100 point optimization)
	
	https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/NOI/official/2018-editorial.pdf
*/
#include "citymapping.h"
#include <bits/stdc++.h>
using namespace std;
 
long long dist[1002];

bool cmp(int a, int b)
{
	return dist[a] < dist[b];
}
int rad = 1;
vector<int> v[1002];
int sts[1002], nu[1002];
void dfs(int dad, int nod)
{
	sts[nod] = 1;
	for(int i = 0; i < v[nod].size(); ++i)
	{
		int vecin = v[nod][i];
		if(vecin == dad)
			continue;
		dfs(nod, vecin);
		sts[nod] += sts[vecin];
	}
}
int bgL(int nod)
{
	bool ok = 1;
	int bst = 0;
	for(int i = 0; i < v[nod].size(); ++i)
	{
		int vecin = v[nod][i];
		if(sts[vecin] > sts[nod] || nu[vecin])
			continue;
		ok = 0;
		if(sts[vecin] > sts[bst])
			bst = vecin;
	}
	if(ok)
		return nod;
	return bgL(bst);
}
int bgg;
int optnd(int nod, long long dst)
{
	if(dist[nod] - dist[bgg] == dst)
		return nod;
	int bst = 0;
	for(int i = 0; i < v[nod].size(); ++i)
	{
		int vecin = v[nod][i];
		if(sts[vecin] > sts[nod] || nu[vecin])
			continue;
		if(sts[vecin] > sts[bst])
			bst = vecin;
	}
	return optnd(bst, dst);
}
int bstson(int nod)
{
	int bst = 0;
	for(int i = 0; i < v[nod].size(); ++i)
	{
		int vecin = v[nod][i];
		if(sts[vecin] > sts[nod] || nu[vecin])
			continue;
		if(sts[vecin] > sts[bst])
			bst = vecin;
	}
	return bst;
}
int dfssz(int rt)
{
	int ans = 1;
	for(int i = 0; i < v[rt].size(); ++i)
	{
		int vecin = v[rt][i];
		if(sts[vecin] > sts[rt] || nu[vecin])
			continue;
		ans += dfssz(vecin);
	}
	return ans;
}
pair<int, int> solve(int nod, int pzx)
{
	int rt = 1;
	int lft = pzx;
	while(lft > 1)
	{
		int ans = bgL(rt);
		long long RL = abs(dist[ans] - dist[rt]);
		long long LX = get_distance(nod, ans);
		long long RX = abs(dist[nod] - dist[rt]);
		long long dvg = ((RL+RX) - LX) / 2;
		bgg = rt;
		int nxt = optnd(rt, dvg);
		nu[bstson(nxt)] = 1;
		rt = nxt;
		lft = dfssz(rt);
	}
	return {rt, dist[nod] - dist[rt]};
}
void find_roads(int n, int Q, int A[], int B[], int W[])
{
	dist[1] = 0;
	for(int i = 2; i <= n; ++i)
		dist[i] = get_distance(1, i);	
	int nr[1002];
	for(int i = 1; i <= n; ++i)
		nr[i] = i;
	sort(nr + 1, nr + n + 1, cmp);
	for(int i = 2; i <= n; ++i)
	{
		A[i-2] = nr[i];
		if(i != 2)
		{
			pair<int, int> ans = solve(nr[i], i-1);
			B[i-2] = ans.first;
			W[i-2] = ans.second;
		}
		else
		{
			B[i-2] = 1;
			W[i-2] = dist[nr[i]];
		}
		v[A[i-2]].push_back(B[i-2]);
		v[B[i-2]].push_back(A[i-2]);
		dfs(0, 1);
		memset(nu, 0, sizeof(nu));
	}
	return;
}
