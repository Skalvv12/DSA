#include <iostream>
#include <vector>
#include <cassert>

using std::vector;

struct merge_data
{
  vector<uint32_t>& array;
  uint64_t inversions = 0;
};

class SortArrayCountInversions
{
  uint64_t inversions = 0;
  vector<uint32_t> sorted_array;
  vector<uint32_t> merge(const vector<uint32_t>& left,const vector<uint32_t>& right);
  vector<uint32_t> mergesort(const vector<uint32_t>& array);
  public:
    SortArrayCountInversions(const vector<uint32_t>& array)
    {
      sorted_array = mergesort(array);
    }
    vector<uint32_t> get_sorted_array()
    {
      return sorted_array;
    }
    uint64_t get_inversions()
    {
      return inversions;
    }  
};

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  //write your code here
  return number_of_inversions;
}


uint64_t get_number_of_inversions_naive(const vector<uint32_t>& array)
{
  uint64_t inversions = 0;
  for(int i = 0; i < array.size() - 1; i++)
  {
    for(int j = i + 1; j < array.size(); j++)
    {
      if(array[i] > array[j])
      {
        inversions++;
      }
    }
  }
  return inversions;
}

vector<uint32_t> SortArrayCountInversions::merge(const vector<uint32_t>& left,const vector<uint32_t>& right)
{
  uint32_t left_min_idx = 0;
  uint32_t right_min_idx = 0;
  uint64_t inversions = 0;

  vector<uint32_t> merged(left.size() + right.size());
   
  for(uint i = 0; i < merged.size(); i++)
  {
    if(left_min_idx >= left.size())
    {
      merged[i] = right[right_min_idx];
      right_min_idx++;
    }
    else if(right_min_idx >= right.size())
    {
      merged[i] = left[left_min_idx];
      // SortArrayCountInversions::inversions += left.size() - left_min_idx;
      left_min_idx++;
    }
    //order of ifs is important 
    else if(left[left_min_idx] < right[right_min_idx])
    {
      merged[i] = left[left_min_idx];
      left_min_idx++;
    }
    else if(left[left_min_idx] > right[right_min_idx])
    {
      merged[i] = right[right_min_idx];
      SortArrayCountInversions::inversions += left.size() - left_min_idx;
      right_min_idx++;
    }
  }

  return merged;
}


vector<uint32_t> SortArrayCountInversions::mergesort(const vector<uint32_t> &array)
{
  if(array.size() <= 1)
  {
    return array;
  }
  size_t const half_size = array.size() / 2;

  //read only copies and this sheet
  vector<uint32_t> left(array.begin(), array.begin() + half_size);
  vector<uint32_t> right(array.begin() + half_size, array.end());
  left = mergesort(left);
  right = mergesort(right);

  return merge(left, right);
}

void test(const vector<uint32_t>& array)
{
  uint64_t inversions = SortArrayCountInversions(array).get_inversions();
  uint64_t alternative_inversions = get_number_of_inversions_naive(array);
  assert(inversions == alternative_inversions);
}
int main() 
{
  int n;
  std::cin >> n;
  vector<uint32_t> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }

  vector<uint32_t> b = {6};
  vector<uint32_t> c = {5};

  uint64_t alternative_inversions = get_number_of_inversions_naive(a);


  // vector<int> b(a.size());
  std::cout << alternative_inversions << '\n';
}
