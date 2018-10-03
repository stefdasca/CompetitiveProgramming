#include<fstream>
using namespace std;
ifstream f("adunare.in");
ofstream g("adunare.out");
int a,b,s;
int main()
{
    f>>a;
    f>>b;
    g<<a+b;
    return 0;
}
