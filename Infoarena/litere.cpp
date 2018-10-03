#include <fstream>
using namespace std;
ifstream in("litere.in");
ofstream out("litere.out");
int n, ans, v[26];
int main(){
    in>>n;
    char c;
    for(int i=1;i<=n;i++)
    {
        in>>c;
        v[c-'a']++;
        for(int j=25;j>=c-'a'+1;j--)
            ans=ans+v[j];
    }
    out<<ans;
    return 0;
}
