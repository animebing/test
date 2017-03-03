#include <iostream>

int f(int a) {
    static int *b = new int(0);
    *b += a;
    return *b;
}

int main() {
    int c = 5;
    std::cout << f(c) << std::endl;
    int d = 6;
    std::cout << f(d) << std::endl;
    return 0;
}
