#include <iostream>
#include <cassert>


long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

uint32_t gcd(uint32_t a, uint32_t b) {
  if (b == 0) return a;
  a = a % b;
  return gcd(b, a);
}

uint64_t lcm(uint32_t a, uint32_t b)
{
  return static_cast<uint64_t> ((a / gcd(a, b)) * b);
}

void test(uint32_t a, uint32_t b)
{
  for(uint32_t i = 1; i < a; i++)
  {
    for(uint32_t j = 1; j < b; j++)
    {
      assert(lcm_naive(a, b) == lcm(a, b));
    }
  }
}
int main() {
  uint32_t a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;
  // test(a, b);

  return 0;
}
