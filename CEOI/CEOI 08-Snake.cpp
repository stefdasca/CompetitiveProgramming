/*
        CEOI 08-Snake

    We are going to use binary search to find the estimate of the left and the right ends of the snake.
Since ceil(log2(12122)) = 14, we need to split the snake in three pieces using the first query, so we will eventually get a worst case of 13 queries.

    Based on the answers given by the interactor, we are going to modify the left and the right ends of the query range, and at the end, take the median of all
the possible lengths of the snake.

*/
#include "snakelib.h"
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k = get_speed();
    int Lst = -1, Ldr = 12122;
    int Rst = -1, Rdr = 12122;
    char a1, a2;
    for(int i = 1; i <= 13; ++i)
    {
        Ldr += k;
        Rdr += k;
        int startMid = (Lst + Ldr - 1)/2;
        int endMid = (Rst + Rdr)/2;
        if(Lst == Rst && Ldr == Rdr)
        {
            startMid = Lst + (Ldr-Lst)/3;
            endMid = Rst + (Rdr-Rst)*2/3;
        }
        ask_snake(startMid, endMid, &a1, &a2);
        if(a1 == 's')
        {
            Ldr = startMid + 1;
            Rst = max(Rst, startMid);
        }
        else
            if(a1 == 'f')
            {
                Ldr = startMid;
                Rdr = min(Rdr, startMid);
            }
            else
            {
                Lst = startMid + 1;
                Rst = max(Rst, startMid + 1);
            }

        if(a2 == 's')
        {
            Rst = endMid;
            Ldr = min(Ldr, Rst + 1);
        }
        else
            if(a2 == 'f')
            {
                Rdr = endMid;
                Ldr = min(Ldr, Rdr);
            }
            else
            {
                Rst = endMid + 1;
                Lst = max(Lst, Rst);
            }
    }
    int maxAns = Rdr - Lst + 1;
    int minAns = Rst - Ldr + 1;
    int guess = (maxAns + minAns) / 2;
    tell_length(guess);
}
