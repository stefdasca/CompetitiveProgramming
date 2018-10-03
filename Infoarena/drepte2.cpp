#include<fstream>
using namespace std;
ifstream f("drepte2.in");
ofstream g("drepte2.out");
long long n,sol;
int main()
{
    f>>n;
    sol=(n+1)*n/2+1;
    g<<sol<<'\n';
}
