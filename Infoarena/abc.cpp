#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;
class InputReader {
    public:
        InputReader() {}
        InputReader(const char *file_name) {
            input_file = fopen(file_name, "r");
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
        inline InputReader &operator >>(int &n) {
            while(buffer[cursor] < '0' || buffer[cursor] > '9') {
                advance();
            }
            n = 0;
            while('0' <= buffer[cursor] && buffer[cursor] <= '9') {
                n = n * 10 + buffer[cursor] - '0';
                advance();
            }
            return *this;
        }
    private:
        FILE *input_file;
        static const int SIZE = 1 << 17;
        int cursor;
        char buffer[SIZE];
        inline void advance() {
            ++ cursor;
            if(cursor == SIZE) {
                cursor = 0;
                fread(buffer, SIZE, 1, input_file);
            }
        }
}f("abc.in");
ofstream g("abc.out");
int n,b,c,i,sum,S,D[66000],Sol[66000];
pair <int,int> a[66000];
int main()
{
    f>>n>>b>>c;
    for(i=1;i<=n;++i)
    {
        f>>a[i].first;
        sum+=a[i].first;
        a[i].second=i;
    }
    sort(a+1,a+n+1);
    if(sum<c)
    {
        reverse(a+1,a+n+1);
        D[0]=b+1;
        S=c-sum;
        for(i=1;i<=n;++i)
        {
            int d=ceil((double)S/(double)(n-i+1));
            if(a[i].first+d>b) d=b-a[i].first;
            if(a[i].first+d>=D[i-1]) d=D[i-1]-a[i].first-1;
            D[i]=a[i].first+d;
            S-=d;
            Sol[a[i].second]=D[i];
        }
    }
    else
    {
        D[0]=0;
        S=sum-c;
        for(i=1;i<=n;++i)
        {
            int d=ceil((double)S/(double)(n-i+1));
            if(a[i].first-d<1) d=a[i].first-1;
            if(a[i].first-d<=D[i-1]) d=a[i].first-D[i-1]-1;
            D[i]=a[i].first-d;
            S-=d;
            Sol[a[i].second]=D[i];
        }
    }
    for(i=1;i<=n;++i) g<<Sol[i]<<' ';
    return 0;
}
