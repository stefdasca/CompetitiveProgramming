/*
                                TOKI2018-TileCovering

    It is obvious that we will place the tiles starting from points which are not covered by a tile
Based on this observation, you can build a tree where for each i from 0 to (M - 2), we will draw an edge from i
to the leftmost element such that distance to the ith uncovered tie is bigger than length of a tile.
After we have built the tree, we will do binary lifting in the tree, in order to find in O(log n) the kth ancestor of each
node. For each query of type (L, R), we will firstly find the first uncovered tile which is right of L and left of R. If there
is such a tile, we will binary search the number of tiles needed using the array already constructed during the binary lifting phase

*/

#include <vector>
std::vector<int>v[300002];
int anc[300002][22];
int lvl[300002];
std::vector<int>AA;
void dfs(int nod, int prev)

    anc[nod][0] = prev;
    int z = 1;
    while(prev)
    {
        anc[nod][z] = anc[prev][z-1];
        prev = anc[nod][z];
        ++z;
    }
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        lvl[vecin] = lvl[nod] + 1;
        dfs(vecin, nod);
    }
}
void init(int N, int K, int Q, int M, std::vector<int> A) {
    A.push_back(2000000002);
    for(int i = 0; i < A.size(); ++i)
    {
        int b = i+1;
        int e = A.size() - 1;
        int ans = 0;
        while(b <= e)
        {
            int mid = (b + e) / 2;
            if(A[mid] - K >= A[i])
                ans = mid, e = mid - 1;
            else
                b = mid + 1;
        }
        if(ans != 0)
            v[ans].push_back(i);
        AA.push_back(A[i]);
    }
    dfs(A.size() - 1, 0);
}
bool check(int startpos, int lvl, int mx)
{
    for(int i = 18; i >= 0; --i)
        if(lvl & (1<<i))
        {
            startpos = anc[startpos][i], lvl ^= (1<<i);
            if(AA[startpos] > mx)
                return 1;
        }
    return 0;
}
int cb(int startpos, int mx)
{
    int b = 0;
    int e = lvl[startpos];
    int ans = 0;
    while(b <= e)
    {
        int mid = (b + e) / 2;
        if(check(startpos, mid, mx))
            ans = mid, e = mid - 1;
        else
            b = mid + 1;
    }
    return ans;
}
int cbb(int st)
{
    int b = 0;
    int e = AA.size() - 1;
    int ans = 0;
    while(b <= e)
    {
        int mid = (b + e) / 2;
        if(AA[mid] >= st)
            ans = mid, e = mid - 1;
        else
            b = mid + 1;
    }
    return ans;
}
int getNumberOfSpecialTiles(int L, int R)
{
   int NL = cbb(L);
   if(AA[NL] > R)
      return 0;
   int sol = cb(NL, R);
   return sol;
}
