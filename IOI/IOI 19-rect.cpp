/*
        IOI 19-rect

    editorial: https://ioinformatics.org/page/ioi-2019/51

    Basically, we compute using stacks the closest value to each square (i, j) such that it's bigger than value on (i, j) on up, down, left and right.

    Then we will use the values computed at the previous step to turn the valid squares into valid lines/columns and we are going to check each pair
using brute force(there are about O(n^2) possible pairs).

*/
#include "rect.h"
#include<bits/stdc++.h>
using namespace std;
int maxst[2502][2502], maxdr[2502][2502], maxup[2502][2502], maxdwn[2502][2502];
int upleft[2502][2502], downleft[2502][2502], leftup[2502][2502], rightup[2502][2502];

vector<long long> v;
void check(int xa, int xb, int ya, int yb)
{
	if(xb < xa || yb < ya)
        return;
	if(!((maxdr[xb][ya-1]-1 == yb && rightup[xb][ya-1] <= xa) || (maxst[xb][yb+1]+1 == ya && leftup[xb][yb+1] <= xa)))
        return;
	if(!((maxdwn[xa-1][yb]-1 == xb && downleft[xa-1][yb] <= ya) || (maxup[xb+1][yb]+1 == xa && upleft[xb+1][yb] <= ya)))
        return;
	v.push_back(((1LL * xa * 3010 + xb) * 3010 + ya) * 3010 + yb);
}
long long count_rectangles(vector<vector<int> > a)
{
    int n = a.size();
    int m = a[0].size();
    long long ans = 0;
    deque<int> d;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            while(!d.empty() && a[i][j] > a[i][d.back()])
                d.pop_back();
            if(d.empty())
                maxst[i][j] = -1;
            else
                maxst[i][j] = d.back();
            d.push_back(j);
        }
        d.clear();
        for(int j = m - 1; j >= 0; --j)
        {
            while(!d.empty() && a[i][j] > a[i][d.back()])
                d.pop_back();
            if(d.empty())
                maxdr[i][j] = -1;
            else
                maxdr[i][j] = d.back();
            d.push_back(j);
        }
        d.clear();
    }
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            while(!d.empty() && a[j][i] > a[d.back()][i])
                d.pop_back();
            if(d.empty())
                maxup[j][i] = -1;
            else
                maxup[j][i] = d.back();
            d.push_back(j);
        }
        d.clear();
        for(int j = n-1; j >= 0; --j)
        {
            while(!d.empty() && a[j][i] > a[d.back()][i])
                d.pop_back();
            if(d.empty())
                maxdwn[j][i] = -1;
            else
                maxdwn[j][i] = d.back();
            d.push_back(j);
        }
        d.clear();
    }
    for(int j = 0; j < m; ++j)
    {
        for(int i = 0; i < n; ++i)
        {
            if(maxup[i][j] != -1)
            {
                if(j > 0 && maxup[i][j] == maxup[i][j-1])
                    upleft[i][j] = upleft[i][j-1];
                else
                    if(j > 0 && i == maxdwn[maxup[i][j]][j-1])
                        upleft[i][j] = downleft[maxup[i][j]][j-1];
                    else
                        upleft[i][j] = j;
            }
            if(maxdwn[i][j] != -1)
            {
                if(j > 0 && maxdwn[i][j] == maxdwn[i][j-1])
                    downleft[i][j] = downleft[i][j-1];
                else
                    if(j > 0 && i == maxup[maxdwn[i][j]][j-1])
                        downleft[i][j] = upleft[maxdwn[i][j]][j-1];
                    else
                        downleft[i][j] = j;
            }
        }
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(maxst[i][j] != -1)
            {
                if(i > 0 && maxst[i][j] == maxst[i-1][j])
                    leftup[i][j] = leftup[i-1][j];
                else
                    if(i > 0 && j == maxdr[i-1][maxst[i][j]])
                        leftup[i][j] = rightup[i-1][maxst[i][j]];
                    else
                        leftup[i][j] = i;
            }
            if(maxdr[i][j] != -1)
            {
                if(i > 0 && maxdr[i][j] == maxdr[i-1][j])
                    rightup[i][j] = rightup[i-1][j];
                else
                    if(i > 0 && j == maxst[i-1][maxdr[i][j]])
                        rightup[i][j] = leftup[i-1][maxdr[i][j]];
                    else
                        rightup[i][j] = i;
            }
        }
    }
    for(int i = 1; i + 1 < n; ++i)
        for(int j = 1; j + 1 < m; ++j)
        {
            if(maxup[i+1][j] != -1 && maxst[i][j+1] != -1)
                check(maxup[i+1][j]+1, i, maxst[i][j+1]+1, j);
            if(maxup[i+1][j] != -1 && maxdr[i][j-1] != -1)
                check(maxup[i+1][j]+1, i, j, maxdr[i][j-1]-1);
            if(maxdwn[i-1][j] != -1 && maxst[i][j+1] != -1)
                check(i, maxdwn[i-1][j]-1, maxst[i][j+1]+1, j);
            if(maxdwn[i-1][j] != -1 && maxdr[i][j-1] != -1)
                check(i, maxdwn[i-1][j]-1, j, maxdr[i][j-1]-1);
            if(maxdwn[i-1][j] != -1 && maxdr[maxdwn[i-1][j]-1][j-1] != -1)
                check(i, maxdwn[i-1][j]-1, j, maxdr[maxdwn[i-1][j]-1][j-1]-1);
            if(maxdwn[i-1][j] != -1 && maxst[maxdwn[i-1][j]-1][j+1] != -1)
                check(i, maxdwn[i-1][j]-1, maxst[maxdwn[i-1][j]-1][j+1]+1, j);
        }
    sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
    return v.size();
}
