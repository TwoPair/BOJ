#include <cstdio>
#include <algorithm>
using namespace std;

int a[4], b[2], sum;

int main() {
    for(int i = 0; i < 4; ++i) { scanf("%d", a+i); sum += a[i]; }
    scanf("%d%d", b, b+1); sum += (b[0] + b[1]);
    
    printf("%d", sum - *min_element(a, a+4) - min(b[0], b[1]));
}