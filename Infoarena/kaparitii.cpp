#include<fstream>
using namespace std;
ifstream cin("aparitii.in");
ofstream cout("aparitii.out");
int n,k,i,x,biti[32],res;
int main()
{
    cin>>n>>k;
    while (n--) {
        cin>>x;
        for (i=0;i<32;i++)
            if (x&(1<<i)) ++biti[i];
    }
   for (i=0;i<32;++i)
        if (biti[i]%k)
            res+=1<<i;
   cout<<res;
   return 0;
}
