#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>

int cup[4], len;
char seq[202];
std::pair<int, int> p[6] = { {0,1}, {0,2}, {0,3}, {1,2}, {1,3}, {2,3} };

int main() {
    scanf("%s", seq); len = strlen(seq);
    cup[0] = 1; cup[3] = 2;
    
    for(int i = 0; i < len; ++i)
        std::swap(cup[p[seq[i] - 'A'].first], cup[p[seq[i] - 'A'].second]);
    
    for(int i = 0; i < 4; ++i) if(cup[i] == 1) printf("%d\n", i+1);
    for(int i = 0; i < 4; ++i) if(cup[i] == 2) printf("%d\n", i+1);
}