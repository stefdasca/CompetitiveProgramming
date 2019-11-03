/*
        SPOX XXXXXXXX

    Classical problem, this problem can be solved using 2D segment tree after reading the solution given
here - https://codeforces.com/blog/entry/10508?#comment-158835

    * Firstly, let's normalize the input data in order to avoid using an extra container like set or map.

    * For every position we will keep the next position with a value equal to the value on the current position, or n+1
if there is no such position.

    * We are going to perform the updates and queries using 2D segment tree as follows:

    For the queries, we are going to run the queries like one usually does when writing segment tree, except that we will call the query
function for the segment tree included in our node from the outer segment tree, and we will add to the answer the values such that NextPos
is bigger than the rightmost value of the queryed interval.

    For the updates, we need to modify several values, because when we change the value of the element on position i to some other value,
the previous position which was equal to previous value of position i has to get new next position, while also the previous position with value equal
to the new value of position i has to get new value.

    The total runtime will be O((n + q) * log^2 (n + q)).

*/

#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

const int MAX = 150005;
int TREE_SIZE;

struct query
{
    char type;
    int x;
    int y;
};
query queries[MAX];
struct tree
{
    long long sum;
    tree* l;
    tree* r;
};
typedef tree* ptree;

ptree segTree[MAX * 4];

long long get(ptree &p)
{
    if(p)
        return p -> sum;
    return 0;
}
ptree initialize(long long value)
{
    ptree p = (ptree)malloc(sizeof(tree));
    p->sum = value;
    p->l = NULL;
    p->r = NULL;
    return p;
}
void update(ptree &p, int low, int high, int position, int value)
{
    if (!p)
        p = initialize(0);
    if (low == high)
    {
        p->sum += value;
        return;
    }
    int middle = (low + high) >> 1;
    if(position <= middle)
        update(p->l, low, middle, position, value);
    else
        update(p->r, middle + 1, high, position, value);
    p->sum = get(p->l) + get(p->r);
}
long long get(ptree &p, int low, int high, int l, int r) {
    if (!p)
        return 0;
    if (low > r || high < l)
        return 0;
    if (low >= l && high <= r)
        return p->sum;
    int middle = (low + high) >> 1;
    return get(p->l, low, middle, l, r)
    + get(p->r, middle + 1, high, l, r);
}

int N, M, Q;
int data[MAX], realValue[MAX];

set<int> occurrences[MAX];

void update(int I, int low, int high, int position, int treePosition, int value)
{
    update(segTree[I], 1, TREE_SIZE, treePosition, value);
    if(low == high)
        return;
    int middle = (low + high) >> 1;
    if (position <= middle)
        update(I << 1, low, middle, position, treePosition, value);
    else
        update(I << 1 | 1, middle + 1, high, position, treePosition, value);
}
long long get(int I, int low, int high, int l, int r, int treeLow, int treeHigh)
{
    if (low > r || high < l)
        return 0;
    if (low >= l && high <= r)
        return get(segTree[I], 1, TREE_SIZE, treeLow, treeHigh);
    int middle = (low + high) >> 1;
    return get(I << 1, low, middle, l, r, treeLow, treeHigh)
    + get(I << 1 | 1, middle + 1, high, l, r, treeLow, treeHigh);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i ++)
        cin >> data[i];
    cin >> Q;
    for (int i = 0; i < Q; i ++)
        cin >> queries[i].type >> queries[i].x >> queries[i].y;

    // we normalize the input in order to avoid using an extra container, like map or set
    vector<int> values = vector<int>(data + 1, data + N + 1);
    for (int i = 0; i < Q; i ++)
        if (queries[i].type == 'U')
            values.push_back(queries[i].y);
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    for(int i = 1; i <= N; i ++)
    {
        int oldValue = data[i];
        data[i] = (int)(lower_bound(values.begin(), values.end(), data[i]) - values.begin()) + 1;
        realValue[data[i]] = oldValue;
    }
    for(int i = 0; i < Q; i ++)
        if(queries[i].type == 'U')
        {
            int oldValue = queries[i].y;
            queries[i].y = (int)(lower_bound(values.begin(), values.end(), queries[i].y) - values.begin()) + 1;
            realValue[queries[i].y] = oldValue;
        }

    TREE_SIZE = N + 1;
    for(int i = 1; i <= N; i++)
        occurrences[data[i]].insert(i);
    for (int i = 1; i <= (int)values.size(); i++)
    {
        occurrences[i].insert(0);
        occurrences[i].insert(TREE_SIZE);
    }
    for (int i = 1; i <= N; i ++)
    {
        auto nextIterator = occurrences[data[i]].upper_bound(i);
        update(1, 1, N, i, *nextIterator, realValue[data[i]]);
    }
    for (int i = 0; i < Q; i ++)
    {
        if(queries[i].type == 'Q')
            cout << get(1, 1, N, queries[i].x, queries[i].y, queries[i].y + 1, TREE_SIZE) << '\n';
        else
        {
            if(data[queries[i].x] == queries[i].y)
            {
                // no update needed
                continue;
            }
            auto currentIterator = occurrences[data[queries[i].x]].lower_bound(queries[i].x);
            auto previousIterator = currentIterator; --previousIterator;
            auto nextIterator = currentIterator; ++nextIterator;
            // removing old element
            if (*previousIterator > 0)
            {
                update(1, 1, N, *previousIterator, queries[i].x, -realValue[data[*previousIterator]]);
                update(1, 1, N, *previousIterator, *nextIterator, +realValue[data[*previousIterator]]);
            }
            update(1, 1, N, queries[i].x, *nextIterator, -realValue[data[queries[i].x]]);
            occurrences[data[queries[i].x]].erase(currentIterator);

            // adding new element
            data[queries[i].x] = queries[i].y;
            occurrences[data[queries[i].x]].insert(queries[i].x);
            currentIterator = occurrences[data[queries[i].x]].lower_bound(queries[i].x);
            previousIterator = currentIterator; --previousIterator;
            nextIterator = currentIterator; ++nextIterator;
            if (*previousIterator > 0)
            {
                update(1, 1, N, *previousIterator, queries[i].x, +realValue[data[*previousIterator]]);
                update(1, 1, N, *previousIterator, *nextIterator, -realValue[data[*previousIterator]]);
            }
            update(1, 1, N, queries[i].x, *nextIterator, +realValue[data[queries[i].x]]);
        }
    }
    return 0;
}
