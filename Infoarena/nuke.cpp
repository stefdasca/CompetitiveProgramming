/*
                    infoarena nuke

    "Given n <= 2e5 points and m <= 1e5 circles, find for each of the circles how many points has inside or on the circle. The surfaces covered by any pair
of two circles don't have common points".

    Let's define a circle as a range [a, b], where a = x - r and b = x + r, where x is the Ox coordinate and r is the radius of the circle.
Given that there is no pair of overlapping circles, we can observe that if the current point is on the circle,
it can only be in the circle which has the closest Oy coordinate to the point's Oy coordinate.

    Therefore, there are three types of events which are important for us, and we're going to sort them in the ascending order of Ox coordinate,
and in case of two events with the same coordinate, by the following tiebreaker
    1. A circle is inserted in the list of possible circles - this happens when the current Ox coordinate is (Ox coordinate of the circus - its radius)
    2. We need to find for a point whether it is situated on any of the circles.
    3. A circle is erased from the list of possible circles - this happens when the current Ox coordinate is (Ox coordinate of the circus + its radius)

    When we have a event of type 2, we are going to use the observation described above in order to find the suitable circle(s) in which the point may
be inside of. This can be done easily using set-like data structure.

    Overall, our complexity will be O((m + n) log (n + m)).


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

ifstream f("nuke.in");
ofstream g("nuke.out");
int n, m, x, ans[100002];

pair<int, int> points[200002];
pair<pair<int, int>, int> circle[100002], events[600002];

int verif(int a, int b)
{
    long long dist = 1LL * (points[a].fi - circle[b].fi.fi) * (points[a].fi - circle[b].fi.fi);
    dist += 1LL * (points[a].se - circle[b].fi.se) * (points[a].se - circle[b].fi.se);
    if(dist <= 1LL * circle[b].se * circle[b].se)
        return 1;
    return 0;
}
int main()
{
    f >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        f >> points[i].fi >> points[i].se;
        events[++x] = {{points[i].fi, 0}, i};
    }
    for(int i = 1; i <= m; ++i)
    {
        f >> circle[i].fi.fi >> circle[i].fi.se >> circle[i].se;
        events[++x] = {{circle[i].fi.fi - circle[i].se, -1}, i};
        events[++x] = {{circle[i].fi.fi + circle[i].se, 1}, i};
    }
    sort(events + 1, events + x + 1);
    set<pair<int, int> >cerc;
    for(int i = 1; i <= x; ++i)
    {
        if(events[i].fi.se == -1)
            cerc.insert({circle[events[i].se].fi.se, events[i].se});
        else
            if(events[i].fi.se == 1)
                cerc.erase({circle[events[i].se].fi.se, events[i].se});
            else
            {
                set<pair<int, int> > :: iterator it = cerc.lower_bound({points[events[i].se].se, 0});
                if(it != cerc.end() && verif(events[i].se, (*it).se))
                    ++ans[(*it).se];
                else
                    if(it != cerc.begin())
                    {
                        --it;
                        if(verif(events[i].se, (*it).se))
                            ++ans[(*it).se];
                    }
            }
    }
    for(int i = 1; i <= m; ++i)
        g << ans[i] << '\n';
    return 0;
}
