#include <fstream>
using namespace std;
ifstream fin("trompeta.in");
ofstream fout("trompeta.out");
int n,c,k,i;
char x,s[1000002];
int main()
{
    fin>>n>>c;
    c=n-c;
    for(i=1;i<=n;i++){
        fin>>x;
        while(k!=0 && c!=0 && x>s[k]){
            --c;
            --k;
        }
        ++k;
        s[k]=x;
    }
    fout<<s+1;
    return 0;
}
