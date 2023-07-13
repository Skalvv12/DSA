#include <iostream>
#include <vector>
#include <algorithm>

int MaxPairwiseProduct(const std::vector<int>& numbers) {
    int max_product = 0;
    int n = numbers.size();
   
    for(int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }

    return max_product;
}

unsigned long long less_naive_solution(const std::vector<unsigned int>& numbers){
    unsigned int n = numbers.size();
    unsigned int max_vals [] = {0,0};

    for(unsigned int i = 0; i < n; i++)
    {
        if (max_vals[1] < numbers[i]){
            max_vals[0] = max_vals[1];
            max_vals[1] = numbers[i];
        }
        else if(max_vals[0] < numbers[i])
        {
            max_vals[0] = numbers[i];
        } 
    }
    return (unsigned long long) max_vals[0] * (unsigned long long) max_vals[1];

}
int main() {
    unsigned int n;
    std::cin >> n;
    std::vector<unsigned int> numbers(n);
    for (unsigned int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << less_naive_solution(numbers) << "\n";
    return 0;
}
