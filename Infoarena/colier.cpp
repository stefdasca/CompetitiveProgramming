#include<fstream>
using namespace std;
ifstream f("colier.in");
ofstream g("colier.out");
int n,i,t,ok;
char s[100005];
int main(){
    f>>t;
    for(int o=1;o<=t;o++){
        f>>n>>s;
        ok=0;
        for(i=0;i<n;i++)
            if(s[i]=='0')
                ok++;
        if(n==1&&s[0]=='1'){
            g<<"DA"<<"\n";
            continue;
        }
        if(ok==n || ok%2==0){
            g<<"NU"<<"\n";
            continue;
        }
        g<<"DA"<<"\n";
    }
    return 0;
}
