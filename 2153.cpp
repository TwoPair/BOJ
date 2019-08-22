#include <cstdio>

int net[1200], sum;
char s[22];

void make_PrimeNet() {
    for(int i = 2; i < 1040; ++i) {
    	net[0] = 1;
        if(net[i] == 0)
            for(int j = i+i; j <= 1040; j += i)
                net[j] = 1;
    }
}

int main() {
    make_PrimeNet();
    scanf("%s", s);
    
    for(int i = 0; s[i]; ++i) {
        if('a' <= s[i] && s[i] <= 'z') sum += (s[i] - 'a' + 1);
        else sum += (s[i] - 'A' + 27);
    }
    
    printf("%s", net[sum] ? "It is not a prime word." : "It is a prime word.");
}