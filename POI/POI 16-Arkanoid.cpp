/*
            POI 16-Arkanoid

    (solution based on the second approach from the editorial)

    * We are going to simulate the required algorithm in a smart way.

    * Firstly, we can observe that all the possible ball positions lie on one cycle.
For all the possible tuples of type (x, y, dx, dy), where dx and dy is the direction we are coming
towards (x, y) we will keep the time we are going to firstly reach that state.

    * However, this is not fast enough so we need to speed up the process. We are going to keep the times
only for the positions where the ball bounces off the wall. For this we need a function that for a given ball position
( x, y, dx, dy) will calculate how many time units the ball will bounce off the wall.

    * Using this observation, finding the times will be simple. At the beginning we findpart of the diagonal on which the position is ( x, y, dx, dy ).
For this purpose from ( x, y )we go back (- dx, - dy ) to the first reflection with the wall.
The result is the sum of the numbers assigned to the beginning of the diagonal and the number of steps we needed undone.

    * The reverse function is equally simple. We find a binary search hexagonal beginning with the highest number is not greater than t
(let it be and -ta over-diagonal with the beginning number t ). This is easy to do with the upper_bound function
from the C ++ standard library called on the reverse table . We go this diagonalt - t steps:

    * Since there are 2 ( m + n ) diagonals , the preliminary calculations will take time O ( m + n) and each function will work in O(log(n + m)),
thus getting a total runtime of O ( m + n + k log ( m + n + k )), which is fast enough.

*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

int m, n, k;
int xk[100001], yk[100001];
int x, y, dx, dy;
long long answer;

tuple<int, int> field_center(int x, int y, int dx, int dy)
{
    int sx, sy;
    if (x % 2 == 0)
    {
        sx = x + dx;
        sy = y;
    }
    else
    {
        sx = x;
        sy = y + dy;
    }
    return make_tuple(sx, sy);
}

bool wall(int x, int y, int dx, int dy)
{
    int sx, sy;
    tie(sx, sy) = field_center(x, y, dx, dy);
    return (sx < 0 || sx > 2*m || sy < 0 || sy > 2*n);
}

void bounce()
{
    if(x % 2 == 0)
        dx = -dx;
    else
        dy = -dy;
}

int go_to_wall(int x, int y, int dx, int dy)
{
    int len = 200001;
    int candidate[] = {-x/dx, (2*m-x)/dx, -y/dy, (2*n-y)/dy};
    for (int i = 0; i < 4; ++i)
        if (candidate[i] >= 0 && wall(x + candidate[i]*dx, y + candidate[i]*dy, dx, dy))
            len = min(len, candidate[i]);
    return len;
}

map<tuple<int, int, int, int>, int> gear;
tuple<int, int, int, int> gear_poz[400005];
long long gear_num[400005];
set<long long> numberset;

long long number(int x, int y, int dx, int dy)
{
    int len = go_to_wall(x, y, -dx, -dy);
    tuple<int, int, int, int> key = make_tuple(x - dx*len, y - dy*len, dx, dy);
    return gear_num[gear[key]] + len;
}


tuple<int, int, int, int> position(long long t)
{
    int index = upper_bound(gear_num, gear_num + 2*(m+n), t) - gear_num;
    index--;
    int x, y, dx, dy;
    tie(x, y, dx, dy) = gear_poz[index];
    long long len = t - gear_num[index];
    return make_tuple(x + dx*len, y + dy*len, dx, dy);
}

set<long long> numberblocks(int sx, int sy)
{
    set<long long> collection;
    tuple<int, int, int, int> keys[] =
    {
        make_tuple(sx-1, sy, 1, 1),
        make_tuple(sx-1, sy, 1, -1),
        make_tuple(sx+1, sy, -1, -1),
        make_tuple(sx+1, sy, -1, 1),
        make_tuple(sx, sy-1, -1, 1),
        make_tuple(sx, sy-1, 1, 1),
        make_tuple(sx, sy+1, 1, -1),
        make_tuple(sx, sy+1, -1, -1)
    };
    int turn = ((sx/2) ^ (sy/2) ^ (m/2)) & 1;
    for (int i = turn; i < 8; i += 2)
    {
        int x, y, dx, dy;
        tie(x, y, dx, dy) = keys[i];
        long long num = number(x, y, dx, dy);
        collection.insert(num);
    }
    return collection;
}

void BlockRemove(int x, int y, int dx, int dy)
{
    int sx, sy;
    tie(sx, sy) = field_center(x, y, dx, dy);

    set<long long> collection = numberblocks(sx, sy);
    for (set<long long>::iterator it = collection.begin(); it != collection.end(); ++it)
        numberset.erase(*it);
}

void go()
{
    long long t = number(x, y, dx, dy);
    set<long long>::iterator it = numberset.lower_bound(t);
    long long nast_t;
    if (it != numberset.end())
    {
        nast_t = *it;
        answer += nast_t - t;
    }
    else
    {
        nast_t = *numberset.begin();
        answer += 4LL*n*m - (t - nast_t);
    }
    tie(x, y, dx, dy) = position(nast_t);
    BlockRemove(x, y, dx, dy);
    k--;
    bounce();
}

void init()
{
    x = m;
    y = 0;
    dx = -1;
    dy = 1;
    long long t = 0;

    for (int i = 0; i < 2*(m+n); ++i)
    {
        tuple<int, int, int, int> key = make_tuple(x, y, dx, dy);
        gear[key] = i;
        gear_poz[i] = make_tuple(x, y, dx, dy);
        gear_num[i] = t;
        int len = go_to_wall(x, y, dx, dy);
        t += len;
        x += dx * len;
        y += dy * len;
        bounce();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n >> k;
    for (int i = 1; i <= k; i++)
        cin >> xk[i] >> yk[i];
    init();
    for (int i = 1; i <= k; i++)
    {
        set<long long> collection = numberblocks(2*xk[i] - 1, 2*yk[i] - 1);
        numberset.insert(collection.begin(), collection.end());
    }
    answer = 0;
    x = m;
    y = 0;
    dx = -1;
    dy = 1;
    while(k)
        go();
    cout << answer;
    return 0;
}
