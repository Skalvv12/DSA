#include <cassert>
#include <iostream>
#include <vector>

using namespace std;






class Solution {
public:
    vector<int> dirs = {1, 0, 0, 1, -1, 0, 0, -1};
    void floodFillRecursive(vector<vector<int>>& image, int sr, int sc, int color, int oldcolor)
    {
        if(color == image[sr][sc] || oldcolor != image[sr][sc]) return;
        
        image[sr][sc] = color;
        
        for(int i = 0, j = 1; j < dirs.size(); i+=2, j+=2)
        {
            int v = dirs[i]+sr;
            int h = dirs[j]+sc;
            if(v < 0 || v >= image.size() || h < 0 || h >= image[0].size()) continue;

            floodFillRecursive(image, v, h, color, oldcolor);
        }
    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        floodFillRecursive(image, sr, sc, color, image[sr][sc]);
        return image;
    }

};


int main()
{
    
    Solution solution;

    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}, {1, 1, 1}};
    int sr = 1, sc = 1, newColor = 2;

    vector<vector<int>> result = solution.floodFill(image, sr, sc, newColor);
    cout << 1 << "\n";
    return 0;
}