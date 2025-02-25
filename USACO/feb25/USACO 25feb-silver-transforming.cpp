/*
    solution code by Stefan Dascalescu

    This problem has a relatively standard math part (instead of going forwards, you go backwards and you can observe that the operations resemble those made during the GCD algorithm).

    At a given point, we want to subtract from the bigger number as much as possible and then make sure that we can actually reach (a, b) from (c. d).
    
    There are a few cases which have to be handled as well, as shown in the source code by the comments attached below.
    video link: https://www.youtube.com/watch?v=NuSVH45kxac

*/

#include <iostream>
using namespace std;
 
long long gcd (long long a, long long b) {
    while (b > 0) {
        long long c = a%b;
        a = b;
        b = c;
    }
    return a;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while (t--) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
 
        // target must not be larger than the start, also the gcd is invariant under these subtraction operations.
        if (a > c || b > d || gcd(c, d) != gcd(a, b)) {
            cout << -1 << "\n";
            continue;
        }
 
        long long ops = 0;
        bool possible = true;
 
        // process until we exactly reach (a, b)
        while (c != a || d != b) {
            if (c < a || d < b) { // overshot the target in one coordinate
                possible = false;
                break;
            }
            if (c < d) {
                swap(c, d);
                swap(a, b);
            }
            if (c > a){
                // we must subtract d from c, check that even one subtraction does not drop c below a.
                if (c - d < a) {
                    possible = false;
                    break;
                }
                // k = maximum number of subtractions so that c - k*d >= a.
                long long k = (c - a) / d;
                if (k == 0) { // at least one subtraction must be done
                    k = 1; 
                }
                // c - k*d is always >= a.
                c -= k * d;
                ops += k;
            } 
            else { 
                // c == a, so we must operate on d.
                if (d - c < b) {
                    possible = false;
                    break;
                }
                long long k = (d - b) / c;
                if (k == 0) {
                    k = 1;
                }
                d -= k * c;
                ops += k;
            } 
        }
 
        cout << ((possible && c == a && d == b) ? ops : -1) << "\n";
    }
    return 0;
}
