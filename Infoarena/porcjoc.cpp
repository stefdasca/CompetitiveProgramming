/*
                Infoarena porcjoc(https://www.infoarena.ro/problema/porcjoc)
    "Given n paper sheets, such that each of the sheets has a value written on them and a size,
find the probability that by choosing two sheets of paper, the numbers written on them will be coprime. At first,
the first sheet will be taken, then it will be put back in the list of sheets, then the other sheet will be taken. Probability
for a sheet to be taken is (size of that sheet) / (sum of all sizes of all sheets)"


    Given that all the numbers written on the sheets are <= 500000, we can basically try all the possibilities in a smart way.
We will find for each number from 2 to 500000 its multiples and we will make some kind of frequencies sums. At some step, we will
find the probability to have gcd of 2 sheets = i, by dropping the probabilities to have gcd = to some multiple of i.


*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("porcjoc.in");
ofstream g("porcjoc.out");
long long n, sum, frq[500002], frq2[500002], ans[500002];
long long gcd(long long a, long long b)
{
    long long c;
    while(b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main()
{
    f >> n;
    for(int i = 1; i <= n; ++i)
    {
        int val, s;
        f >> val >> s;
        sum += s;
        frq[val] += s;
    }
    for(int i = 2; i <= 500000; ++i)
        for(int j = i; j <= 500000; j += i)
            frq2[i] += frq[j];
    long long numitor = sum * sum;
    long long sol = 0;
    for(int i = 500000; i >= 2; --i)
    {
        ans[i] += frq2[i] * frq2[i];
        for(int j = 2 * i; j <= 500000; j += i)
            ans[i] -= ans[j];
        sol += ans[i];
    }
    sol = numitor - sol;
    long long cmmdc = gcd(sol, numitor);
    g << sol / cmmdc << "/" << numitor / cmmdc;
    return 0;
}
