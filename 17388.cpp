#include <cstdio>
#include <algorithm>
using std::min;

int main() {
    int s,k,h;
    scanf("%d%d%d", &s, &k, &h);
    if(s+k+h >= 100) printf("OK");
    else{
        int m = min(s, min(k, h));
        if(m == s) printf("Soongsil");
        else if(m == k) printf("Korea");
        else printf("Hanyang");
    }
}