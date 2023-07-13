#include <iostream>

int get_change(int amount) {
  uint8_t coins[3] = {10, 5, 1};
  uint8_t coins_iter = 0;
  uint16_t n = 0;

  while(amount != 0)
  {
    int frac = amount / coins[coins_iter];
    if(frac > 0)
    {
      n += frac;
      amount -= frac*coins[coins_iter];
    }
    else
    {
      coins_iter++;
    }
  }
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';

}
