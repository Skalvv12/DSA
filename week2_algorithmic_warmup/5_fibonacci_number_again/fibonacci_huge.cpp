#include <iostream>
#include <cassert>
#include <chrono>

using namespace std;
using namespace std::chrono;

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

uint16_t get_fibonacci_huge(uint64_t n, uint16_t m)
{
    if(n <= 1) return n;
    uint16_t previous = 0;
    uint16_t current = 1;
    uint16_t tmp = current;

    for (uint64_t i = 0; i < n - 1; i++)
    {
        tmp = current;
        current = (current + previous) % m;
        previous = tmp;
    }
    return current;
}

uint16_t get_fibonacci_mod_2(uint64_t n, uint16_t m)
{
    if(n % 3 == 0) return 0;
    return 1;
}

void test(uint64_t n, uint64_t m) {
    for(uint64_t i = 0; i < n; i++)
    {
        assert(get_fibonacci_mod_2(i, m) == get_fibonacci_huge(i, m));
    }
}
int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << "got it" << '\n';
    auto start = high_resolution_clock::now();

    std::cout << get_fibonacci_huge(n, m) << '\n';
    //test(n, m);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time: " <<duration.count() <<" microseconds"<< "\n";
    test(n, m);
    return 0;
}
