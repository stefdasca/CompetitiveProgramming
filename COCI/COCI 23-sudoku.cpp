/*
  First, we process the grid and find the digits, then we process for each digit whether there is another equal digit on the same line, column or 3x3 square
*/
#include <bits/stdc++.h>
using namespace std;

char grid[13][13];
int table[9][9];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    for(int i = 0; i <= 12; i++)
        cin >> grid[i];
    
    int cnt = 0;
    for(int i = 0; i <= 12; i++)
    {
        if(i % 4 == 0)
            continue;
        int cntC = 0;
        for(int j = 0; j <= 12; j++)
        {
            if(grid[i][j] == '|')
                continue;
            if(grid[i][j] == '.')
                table[cnt][cntC++] = 0;
            else
                table[cnt][cntC++] = (grid[i][j] - '0');
        }
        cnt++;
    }
    
    bool ok = 1;
    for(int i = 0; i <= 8; i++)
        for(int j = 0; j <= 8; j++)
        {
            if(table[i][j] == 0)
                continue;
            bool ok2 = 1;
            for(int x = 0; x <= 8; x++)
            {
                if(x != j && table[i][x] == table[i][j])
                    ok2 = 0;
                if(x != i && table[x][j] == table[i][j])
                    ok2 = 0;
            }
            for(int st = i-i%3; st <= 2+i-i%3; st++)
                for(int stc = j-j%3; stc <= 2+j-j%3; stc++)
                    if((st != i || stc != j) && table[st][stc] == table[i][j])
                        ok2 = 0;
            if(ok2 == 0)
                ok = 0;
        }
    
    cout << (ok == 1 ? "OK" : "GRESKA") << '\n';
    return 0;
}
