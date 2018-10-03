#include <bits/stdc++.h>
using namespace std;
int a[20000], n, k;
void Produs(int x)
{
    int i, y, t = 0;
    for (i = 1; i <= k; i++)
    {
        y = a[i] * x + t;
        a[i] = y % 10;
        t = y / 10;
    }
    while (t > 0)
    {
        a[++k] = t % 10;
        t /= 10;
    }
}
int main()
{
    ifstream fin("culori3.in");
    ofstream fout("culori3.out");
    fin >> n;
    if (n == 1)
        fout << "5\n";
    else
        if (n == 2)
            fout << "8\n";
    else
        if (n == 3)
            fout << "14\n";
    else
    {
        if (n % 2 == 0) {a[1] = 8; k = 1;}
        else {a[1] = 4; a[2] = 1; k = 2;}
        n = n / 2 - 1;
        while (n >= 10)
        {
            Produs(59049);
            n -= 10;
        }
        while (n > 0)
        {
            Produs(3);
            n--;
        }
        for (int i = k; i >= 1; --i)
            fout << a[i];
    }
    return 0;
}
