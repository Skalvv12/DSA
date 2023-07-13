#include <iostream>
#include <vector>
#include <cassert>
using std::vector;
using namespace::std;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

uint8_t get_fibonacci_sum(uint64_t n)
{
    if(n <= 1) return n;
    uint8_t previous = 0;
    uint8_t current = 1;
    uint8_t sum = 1;

    for(uint64_t i = 2; i < n+1; i++)
    {
        uint8_t tmp = current;
        current = (current + previous) % 10;
        previous = tmp;
        sum = (sum + current) % 10;
    }
    return sum;
}

uint8_t get_fibonacci_partial_sum(uint64_t from, uint64_t to)
{
    if(from == 0) return get_fibonacci_sum(to);
    assert(from <= to);
    uint8_t sum_to = get_fibonacci_sum(to);
    uint8_t sum_from = get_fibonacci_sum(from - 1);
    int result = 10 + sum_to - sum_from; // -n % 10 = -(n % 10)
    
    result = result % 10;

    uint8_t tmp = (uint8_t) result;
    return (uint8_t) result;

}

void test(uint64_t from,uint64_t to)
{
    for (uint64_t i = 1; i < 90; i++)
    {
        for(uint64_t j = 0; j < i && j < from && j < 90; j++)
        {
            assert(get_fibonacci_partial_sum_naive(j, i) == (long long) get_fibonacci_partial_sum(j, i));
        }
    }
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    // std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << (int) get_fibonacci_partial_sum(from, to) << '\n';
    // test(from, to);
}
