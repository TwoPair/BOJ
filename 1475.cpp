#include <cstdio>
#define max(a,b) (a>b?a:b)

int n[10];

void parse(int num) {
	if(num == 0) ++n[0];
    while(num != 0) {
        ++n[num % 10];
        num /= 10;
    }
}

int solve() {
    int ans = 0, sxnn;
    for(int i = 0; i < 10; ++i)
        if(i != 6 && i != 9) ans = max(ans, n[i]);
    sxnn = n[6] + n[9];
    return max(ans, sxnn / 2 + sxnn % 2);
}

int main() {
    int num;
    scanf("%d", &num);
    parse(num); printf("%d", solve());
}