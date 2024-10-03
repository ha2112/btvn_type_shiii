#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<pair<int, int> >s;
    int maxArea = 0;
    heights.push_back(0);
    
    for (int i = 0; i < heights.size(); ++i) {
        int start = i;
        while (!s.empty() && s.top().second > heights[i]) {
            int index = s.top().first;
            int height = s.top().second;
            s.pop();
            maxArea = max(maxArea, height * (i - index));
            start = index;
        }
        s.push(make_pair(start, heights[i]));
    }
    
    return maxArea;
}

int maxRectangle(vector<vector<int> >& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    
    int n = matrix.size(), m = matrix[0].size();
    vector<int> heights(m, 0);
    int maxArea = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == 1) {
                heights[j]++;
            } else {
                heights[j] = 0;
            }
        }
        maxArea = max(maxArea, largestRectangleArea(heights));
    }
    
    return maxArea;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int> > matrix(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }
    
    cout << maxRectangle(matrix) << endl;
    
    return 0;
}