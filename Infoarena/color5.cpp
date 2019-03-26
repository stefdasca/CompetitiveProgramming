/*
        Infoarena color5(https://www.infoarena.ro/problema/color5)
       
   "Given an undirected graph with n+1 nodes which has 2n edges(there is edge between n and every other node and there is edge between
a and (a+1) mod n), color the edges with as few colors as possible such that for each pair of nodes, there is a path which crosses only 
through edges colored differently"

    After drawing some graphs on paper, one can observe that for each n, we can draw a 3-colorable graph. Also, for n = 3 we can use just 1
color because it's a complete graph, while for 4 <= n <= 6, we can make it 2-colorable using a rather simple pattern.
    
*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("color5.in");
ofstream g("color5.out");
int n;
int main()
{
    f >> n;
    int sol = 1 + (n >= 4) + (n >= 7);
    g << sol << '\n';
    for(int i = 0; i < n; ++i)
    {
        g << i << " " << (i + 1) % n << " " << i % sol + 1 << '\n';
        g << n << " " << i << " " << (i+1) % sol + 1 << '\n';
    }
    return 0;
}
