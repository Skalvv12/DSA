#include <iostream>
#include <cassert>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

uint8_t get_fibonacci_sum(uint64_t n)
{
    if(n <= 1) return n;
    uint8_t previous = 0;
    uint8_t current = 1;
    uint8_t sum = 1;

    for(uint64_t i = 0; i < n-1; i++)
    {
        uint8_t tmp = current;
        current = (current + previous) % 10;
        previous = tmp;
        sum = (sum + current) % 10;
    }
    return sum;
}

void test(uint64_t n) {
    for (uint64_t i = 0; i < n; i++)
    {
        assert(fibonacci_sum_naive(i) == (int) get_fibonacci_sum(i));
    }
}
int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << (int) get_fibonacci_sum(n);
    // test(n);
}
