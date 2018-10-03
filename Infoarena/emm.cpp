#include <bits/stdc++.h>
using namespace std;
const long MAX = 100010;
char S[MAX], *p=S;
long termen();
long factor();
long eval() {
    long r = termen();
    while ( *p=='m' || *p=='M' ) {
        switch ( *p ) {
            case 'M':
                ++p;
                r=max(r,termen());
                break;
            case 'm':
                ++p;
                r=min(r,termen());
                break;
        }
    }
    return r;
}
long termen() {
    long r = factor();
    return r;
}
long factor() {
    long r=0;
    if ( *p == '(' ) {
        ++p;
        r = eval();
        ++p;
    } else {
        while ( *p>='0' && *p<='9' )  {
            r = r*10 + *p - '0';
            ++p;
        }
    }
    return r;
}
int main() {
    fgets(S, MAX, fopen("emm.in", "r"));
    fprintf(fopen("emm.out", "w"), "%ld\n", eval());
    return 0;
}
