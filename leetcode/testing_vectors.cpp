#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int main() 
{

    vector<vector<int>> image = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}

        };

    int numRows = image.size();                   // Number of rows

    int numCols = image.empty() ? 0 : image[0].size();  // Number of columns (assuming all rows have the same size)

    cout <<numRows<<"\n";
    cout << numCols<< "\n";

    int numRows1 = 3;    // Number of rows
    int numCols1 = 4;    // Number of columns

    std::vector<std::vector<int>> image1(numRows, std::vector<int>(numCols));
    cout << numCols1;
}
