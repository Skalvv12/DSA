#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

using std::vector;
using namespace std;


int binary_search(const vector<uint32_t> &keys, uint32_t query) {
  uint16_t left_idx = 0, right_idx = (uint16_t)keys.size() - 1; 
  
 
  uint16_t mid_idx = 0;
   

  while(left_idx <= right_idx)
  {
    //midle, or left middle index (if left_idx + right_idx = 2k)
    // c++ floors the value
    mid_idx = left_idx + (right_idx - left_idx) / 2;
    if(query < keys[mid_idx]) right_idx = mid_idx - 1; //|0|1|r|mid|4|5|6| len = 7 
    else if(keys[mid_idx] > query) left_idx = mid_idx + 1; //|0|1|2|mid|l|5|6| len = 7 
    else return mid_idx;
  }

  return -1;

}

int linear_search(const vector<uint32_t> &a, uint32_t x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

void test()
{
  const int query = 1000;
  vector<uint32_t> keys(1000);
  for(uint16_t i = 0; i < keys.size(); i++)
  {
    if(i == 0) 
    {
      keys[i] = 1;
    }
    else
    {
      keys[i] += keys[i-1] + (std::rand()%2+1);
    } 
  }

  auto start = chrono::high_resolution_clock::now();

  for(uint32_t q = 1; q <= query; q++)
  {
    linear_search(keys, q);
  }

  auto stop = chrono::high_resolution_clock::now();

  auto duration = chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();

  start = chrono::high_resolution_clock::now();
  for(uint32_t q = 1; q <= query; q++)
  {
    binary_search(keys, q);
  }
  stop = chrono::high_resolution_clock::now();

  duration = chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();


  for(uint32_t q = 1; q <= query; q++)
  {
    int res_linear = linear_search(keys, q);
    int res_binary = binary_search(keys, q);
    assert(linear_search(keys, q) == binary_search(keys, q));
  }
}

void input()
{
  int n;
  // std::cout <<"number of elements in array: \n";
  std::cin >> n;
  vector<uint32_t> a(n);
  //std::cout << "array:\n";
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  // std::cout << "number of elements in query: \n";
  std::cin >> m;
  vector<uint32_t> b(m);
  //std::cout << "query:\n";
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }

  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << linear_search(a, b[i]) << ' ';
    
  }
}
int main() {
  input();
}

