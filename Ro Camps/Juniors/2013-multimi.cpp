#include <fstream>

using namespace std;

ifstream cin("multimi.in");
ofstream cout("multimi.out");

int n, m, ans[1001][1001];
int main()
{
    cin >> n >> m;
    
    int gauss = (3 * n) * (3 * n + 1) / 2;
    gauss /= n;
    int c = 1;
    int b = 2 * n;
    int a = gauss - b - c;
    
    // construct the first 3 columns
    for(int i = 0; i < n; i++)
    {
        ans[i][0] = a;
        ans[i][1] = b;
        ans[i][2] = c;
        --a;
        --b;
        c += 2;
        if(i >= n/2 && (i-1) < n/2)
        {
            c = 2;
            a = 3 * n;
            b = gauss - c - a;
        }
    }
    
    // alternate the remaining columns two by two
    for(int i = 3; i < m; i++)
    {
        if(i % 2 == 1)
            for(int j = 0; j < n; j++)
                ans[j][i] = i * n + j + 1;
        else
            for(int j = 0; j < n; j++)
                ans[n - j - 1][i] = i * n + j + 1;
    }
    
    for(int i = 0; i < n; cout << '\n', i++)
        for(int j = 0; j < m; j++)
            cout << ans[i][j] << " ";
    return 0;
}
