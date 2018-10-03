#include <fstream>
#include <vector>
using namespace std;
ifstream f("euro2.in");
ofstream g("euro2.out");
int n,nrc;
int sclms[10002],sclmd[10002];
vector<float>v;
int CeilIndex(vector<float> &v, int l, int r, float key) {
    while (r-l > 1) {
    int m = l + (r-l)/2;
    if (v[m] >= key)
        r = m;
    else
        l = m;
    }

    return r;
}

void LongestIncreasingSubsequenceLength(vector<float> &v) {
    vector<float> tail(n, 0);
    int length = 1;
    tail[0] = v[0];
    ++nrc;
    for (size_t i = 1; i < n; i++) {
        if (v[i] < tail[0])
            tail[0] = v[i];
        else if (v[i] > tail[length-1])
            tail[length++] = v[i];
        else
            tail[CeilIndex(tail, -1, length-1, v[i])] = v[i];
        if(nrc==1)
            sclms[i]=length;
        else
            sclmd[n-i-1]=length;
    }
}

int main() {
    f>>n;
    sclms[0]=sclmd[n-1]=1;
    float nr;
    for(int i=0;i<n;++i)
        f>>nr,v.push_back(nr);
    LongestIncreasingSubsequenceLength(v);
    for(int i=0;i<n/2;++i)
        swap(v[i],v[n-i-1]);
    LongestIncreasingSubsequenceLength(v);
    int sol=1;
    for(int i=0;i<n;++i)
        if(sclms[i]>=2 && sclmd[i]>=2)
        sol=max(sol,sclms[i]+sclmd[i]);
    g<<sol-1;
   return 0;
}
