#include<fstream>
#include<cstring>
#include<bitset>
#define DIM 30005
using namespace std;
int n, m, nr, nr1, i, j, ii, num1, x, num2, sol;
char sir[DIM], s[15002][22], a[15002][22];
int v[DIM], w[DIM];
bitset<DIM> ok, ff;
ifstream fin("mesaje.in");
ofstream fout("mesaje.out");
int main(){
    fin.get(sir + 1, DIM);
    m = strlen(sir + 1);
    nr = 1;
    v[1] = 1;
    ff[1] = 1;
    for(i = 1; i <= m; i++){
        if(sir[i] == ' '){
            nr++;
            v[nr] = nr;
            ff[nr] = 1;
        }
        else{
            a[nr][ ++a[nr][0] ] = sir[i];
        }
    }
    sol = nr;
    fin.get();
    while(fin.get(sir + 1, DIM)){
        n++;
        fin.get();
        m = strlen(sir + 1);
        nr1 = 1;
        ok.reset();
        x = num1 = num2 = 0;
        s[1][0] = 0;
        for(i = 1; i <= m; i++){
            if(sir[i] == ' '){
                nr1++;
                s[nr1][0] = 0;
            }
            else{
                s[nr1][ ++s[nr1][0] ] = sir[i];
            }
        }
        for(i = 1; i <= min(nr1, nr); i++){
            if(s[i][0] == a[i][0]){
                ok[i] = 1;
                for(j = 1; j <= s[i][0]; j++){
                    if(s[i][j] != a[i][j]){
                        ok[i] = 0;
                        break;
                    }
                }
                if(ok[i] == 1){
                    x++;
                }
            }
        }
        if(x != 0){
            sol = x;
        }
        for(i = 1; i <= nr; i++){
            if(ok[ v[i] ] == 0){
                num1++;
                w[x + num1] = v[i];
            }
            else{
                num2++;
                w[num2] = v[i];
            }
            if(x != 0){
                ff[i] = ok[i];
            }
        }
        for(i = 1; i <= nr; i++){
            v[i] = w[i];
        }
    }
    fout<< sol <<"\n";
    for(i = 1; i <= nr; i++){
        if(ff[ v[i] ] == 0){
            break;
        }
        for(j = a[ v[i] ][0]; j >= 1; j--){
            fout<< a[ v[i] ][j];
        }
        fout<<" ";
    }
    return 0;
}
