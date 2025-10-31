#include <stdio.h>
#include <stdint.h>
typedef long long ll;
typedef unsigned long long ull;

struct FastMod {
    ull b, m;
};
static inline void FastMod_init(struct FastMod *fm, ull b) {
    fm->b = b;
    fm->m = ~0ULL / b;
}
static inline ull FastMod_reduce(struct FastMod *fm, ull a) {
    __uint128_t tmp = (__uint128_t)fm->m * a;
    ull q = (ull)(tmp >> 64);
    ull pp = a - q * fm->b;
    return (pp >= fm->b ? pp - fm->b : pp);
}

int main() {
    int n, e;
    scanf("%d %d", &n, &e);

    struct FastMod mod;
    FastMod_init(&mod, (ull)n);

    int cur = e;
    ull pos = 0;

    if (!FastMod_reduce(&mod, (ull)cur) || !FastMod_reduce(&mod, (ull)cur + (ull)cur - 1)) {
        puts("infinity");
        return 0;
    }

    ll score = e*(e+1)/2;
    const int mx = 1800000005;
    int ct = mx;

    while (cur && ct--) {
        pos = FastMod_reduce(&mod, pos + (ull)cur);

        cur += 1 - 2 * (!!pos);

        if (!pos) {
            score += (cur << 1)-1;
        }

        if (!pos && !FastMod_reduce(&mod, (ull)cur)) {
            puts("infinity");
            return 0;
        }

        // score += cur;
    }

    if (ct == -1) puts("infinity");
    else printf("%lld\n", score);

    return 0;
}
