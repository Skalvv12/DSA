#include <iostream>
#include <cassert>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

uint8_t get_fibonacci_last_digit(uint64_t n){
    if (n <= 1) return n;
    
    uint8_t previous = 0;
    uint8_t current = 1;

    for(uint64_t i = 0; i < n-1; i++)
    {
        uint8_t tmp = current;
        current = (current + previous) % 10;
        previous = tmp;
        
    }
    
    return current;
}

void test(uint n) {
    for(uint i = 0; i < n; i++)
    {
        assert(get_fibonacci_last_digit_naive(i) == (int) get_fibonacci_last_digit(i));
    }
}

int main() {
    long long n;
    std::cin >> n;
    int c = get_fibonacci_last_digit(n);
    std::cout << c << '\n';

}
