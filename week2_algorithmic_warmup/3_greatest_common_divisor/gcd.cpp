#include <iostream>
#include <cassert>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b) {
  if (b == 0) return a;
  a = a % b;
  return gcd_fast(b, a);
}

void test(uint a, uint b) {
  for(int n = 1; n < b; n++)
  {
    for(int m = 1; m < b; m++)
    {
      assert(gcd_naive(n, m) == gcd_fast(n, m));
    }
  }

}

int main() {
  uint a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  std::cout << 6%7;
  // test(a,b);
  return 0;
}
