/*
            AtCoder010-AGC-D

    Let's consider some cases:

    1) If the array has odd number of even integers, the player whose turn is now
can win by performing the operation on one of the even integers(thus, GCD won't change the parities)

    2) If 1) doesn't happen and there are at least two odd numbers, the player whose turn will come next will win,
since no matter what the player whose turn is now will do, the other player can undo it.

    3) If 1) and 2) don't happen and we have at least an one, the player whose turn will come next will win, because the sum of
the possible drops is even and the player currently at turn won't have any remaining move.

    If none of the cases above happen, we have only 1 odd integer and (n-1) even integers, so we need to perform the operation
on the odd integer, and we will solve the game recursively for the next player.

    Since the GCD will be at least 2, the complexity will therefore be O(n log valmax).

*/
#include<bits/stdc++.h>
using namespace std;
int n, v[100002];
int winn(int turn)
{
    int odd = 0, even = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(v[i] % 2 == 0)
            ++even;
        else
            if(v[i] == 1)
                ++odd;
    }
    if(even % 2 == 1)
        return turn;
    if(even < n - 1)
        return 3 - turn;
    if(odd)
        return 3 - turn;
    for(int i = 1; i <= n; ++i)
        if(v[i] % 2 == 1)
            --v[i];
    int cmm = v[1];
    for(int i = 1; i <= n; ++i)
        cmm = __gcd(cmm, v[i]);
    for(int i = 1; i <= n; ++i)
        v[i] /= cmm;
    return winn(3 - turn);
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    int tu = winn(1);
    if(tu == 1)
        cout << "First";
    else
        cout << "Second";
    return 0;
}
