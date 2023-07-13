#include <iostream>
#include <cassert>
#include <vector>
#include <typeindex>
#include <typeinfo>
#include <chrono>

using namespace std;
using namespace std::chrono;

using std::vector;

int binary_search_duplicates(const vector<uint64_t> &keys, uint32_t query) {
  if(keys.size() == 0) return -1;

  uint32_t left_idx = 0;
  uint32_t right_idx = (uint16_t)keys.size() - 1; 
  
 
  uint32_t mid_idx = 0;
   

  while(left_idx <= right_idx)
  {
    //midle, or left middle index (if left_idx + right_idx = 2k)
    // c++ floors the value
    mid_idx = (left_idx + right_idx + 1) / 2;
    if(keys[left_idx] == query) return mid_idx;
    else if(query < keys[mid_idx]) right_idx = mid_idx - 1; //|0|1|l|mid|4|5|6| len = 7 
    else if(keys[mid_idx] < query) left_idx = mid_idx + 1; //|0|1|2|mid|2|5|6| len = 7 
    else if(right_idx - left_idx > 1) right_idx = mid_idx;
    else return mid_idx;
  }

  return -1;

}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "Vector (Type: " << std::type_index(typeid(T)).name() << ", Size: " << vec.size() << "): [";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i != vec.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}



int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}



void print_res_test(const vector<uint64_t>& a, const vector<uint64_t>& q) {
  
  std::cout <<"array"<< a << '\n';
  std::cout <<"query"<< q << '\n';
  for (int i = 0; i < q.size(); ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search_duplicates(a, q[i]) << ' ';
  }
  std::cout<< '\n';

}

void stress_test() {
    // Create a large vector of size 10^7
    vector<uint64_t> large_vector(1e7);

    // Fill the vector with ascending numbers
    for(int i = 0; i < large_vector.size(); i++) {
        large_vector[i] = i;
    }

    // Start time
    high_resolution_clock::time_point start = high_resolution_clock::now();

    // Test searching for several different numbers
    for(int i = 0; i < 1e6; i++) {
        int target = rand() % (int)large_vector.size();
        assert(binary_search_duplicates(large_vector, target) == target);
    }

    // End time
    high_resolution_clock::time_point end = high_resolution_clock::now();

    // Calculate and print the duration
    auto duration = duration_cast<microseconds>( end - start ).count();
    cout << "Stress test completed in " << duration << " microseconds." << endl;
}


void test(){
  print_res_test({}, {1});
  print_res_test({1}, {1});
  print_res_test({1}, {2});

  print_res_test({1, 2}, {1});
  print_res_test({1, 2}, {2});

  print_res_test({2,2}, {2});
  print_res_test({1, 2, 2}, {2});

  print_res_test({1, 3, 3}, {2});

}


int interface(){
    
    int n;
    std::cin >> n;

    vector<uint64_t> a(n);

    for (size_t i = 0; i < a.size(); i++) {
      std::cin >> a[i];
    }

    int m;
    std::cin >> m;

    vector<uint64_t> b(m);

    for (int i = 0; i < m; ++i) {
      std::cin >> b[i];
    }

    for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search_duplicates(a, b[i]) << ' ';
    
    }

    return 0;
}

int main() {
  test();
  stress_test();
}
