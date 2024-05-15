//2我做#include <iostream>
#include <algorithm>

int main() {
    long long P, Q, x;
    std::cin >> P >> Q >> x;
    long long a = 0, b = 0, c = 0;

    if (P < Q) {
        if (x > (Q - P) * 5) {
            x -= (Q - P) * 5;
            P = Q;
        } else {
            P += x / 5;
            x %= 5;
        }
        b = std::min(P, Q);
        c = x / 12;
        std::cout << b + c << std::endl;
    } else {
        if (x >= (P - Q - 1) * 7) {
            x -= (P - Q - 1) * 7;
            Q = P - 1;
        } else {
            Q += x / 7;
            x %= 7;
        }

        b = std::min(P, Q);
        c = x / 12;
        if (x % 12 >= 7) {
            b++;
        }
        std::cout << b + c << std::endl;
    }

    return 0;
}