/*
        Balkan 18-Popa

    One can observe that if query(i, i, x, y) = 1, i is the root of the subsequence [x, y], where x <= i <= y.
    So, we can start from 0 to n-1, and we are going to try to insert the current node in the chain between the rightmost
node and the root, on the highest possible position.

*/
#include <bits/stdc++.h>
#include "popa.h"

int parent[1005];
int solve(int n, int *left, int *right)
{
	for(int i = 0; i < n; i++)
    {
		left[i] = -1;
		right[i] = -1;
		parent[i] = -1;
	}
	int root = -1;
	for(int i = 0; i < n; i++)
	{
		int curr = i - 1;
		while(curr != -1 && query(i, i, curr, i))
		{
			right[curr] = left[i];
			parent[left[i]] = curr;
			left[i] = curr;
			int nxt = parent[curr];
			parent[curr] = i;
			curr = nxt;
		}
		if(curr == -1)
        {
			left[i] = root;
			if(root != -1)
				parent[root] = i;
			root = i;
		}
		else
        {
			right[curr] = i;
			parent[i] = curr;
		}
	}
	return root;
}
