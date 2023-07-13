#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>

using std::vector;
using std::swap;



int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m = partition2(a, l, r);

  randomized_quick_sort(a, l, m - 1);
  randomized_quick_sort(a, m + 1, r);
}



uint32_t partition(vector<uint32_t> &a, int32_t mid_idx, int32_t right_idx)
{
    int32_t l = mid_idx + 1; 
    int32_t r = right_idx;
    

    while(l < r)
    {
      if(a[mid_idx] > a[l]) l++; //l - right place
      else if(a[mid_idx] < a[l] && a[mid_idx] > a[r]) //l, r - both wrong places
      {
        swap(a[l], a[r]);
        l++;
        r--;
      }
      else if(a[mid_idx] < a[r]) r--; //r - right place
    }

    swap(a[mid_idx], a[(l-1)/*end of left side*/]);
    
    return l-1; 
}

void quick_sort(vector<uint32_t> &a, int32_t left_idx, int32_t right_idx)
{
  if(left_idx >= right_idx) return;

  int32_t point = left_idx + rand() % ( (right_idx - left_idx) + 1); // left_idx <= point < right_idx + 1    

  swap(a[left_idx], a[point]);
  int32_t mid_idx = partition(a, left_idx, right_idx);

  quick_sort(a, left_idx, mid_idx - 1); //mid_idx value is on the
  quick_sort(a, mid_idx + 1, right_idx);
}


vector<uint32_t> naive_sort(const vector<uint32_t> &array)
{
  vector<uint32_t> sorted_array(array);
  uint32_t min_idx = 0;
  for(size_t i = 0; i < sorted_array.size(); i++)
  {
    min_idx = i;
    for(size_t j = i; j < sorted_array.size(); j++)
    {
      if(sorted_array[min_idx] > sorted_array[j])
      {
        min_idx = j;
      }
    }
    std::swap(sorted_array[i], sorted_array[min_idx]);
  }
  return sorted_array;
}

vector<uint32_t>& sort_copy(const vector<uint32_t>& array)
{
  vector<uint32_t> array_copy(array);
  quick_sort(array_copy, 0, array_copy.size() - 1);
  return array_copy;
}

void test(uint n) 
{
  for(uint i = 2; i < n; i+= rand()%(n/2))
  {
      vector<uint32_t> array(i);
      for(uint j = 0; j < i; j++)
      {
        array[j] = rand()%10000;
      }
      
      vector<uint32_t> sorted_arr_quick = sort_copy(array);
      vector<uint32_t> sorted_arr_naive = naive_sort(array);
      for(uint j = 0; j < i; j++)
      {
        assert(sorted_arr_quick[i] == sorted_arr_naive[i]);
      }
  }
}

int input() {
  int n;
  std::cin >> n;
  vector<uint32_t> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }

  vector<uint32_t> sorted_array(a);
  quick_sort(sorted_array, 0, sorted_array.size() - 1);
  
  // randomized_quick_sort(a, 0, a.size() - 1);
  // for (size_t i = 0; i < a.size(); ++i) {
  //   std::cout << a[i] << ' ';
  // }
  std::cout << "brrrrr" << "\n";
}


int main() {
  int n;
  std::cin >> n;
  test(n);
}
