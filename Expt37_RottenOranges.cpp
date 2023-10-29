#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int freshOranges = 0;
    int time = 0;
    queue<pair<int, int>> rottenQueue;

    // Count fresh oranges and initialize the queue with rotten oranges
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 1) {
                freshOranges++;
            } else if (grid[i][j] == 2) {
                rottenQueue.push({i, j});
            }
        }
    }

    // Define directions (up, down, left, right)
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!rottenQueue.empty() && freshOranges > 0) {
        int queueSize = rottenQueue.size();
        for (int i = 0; i < queueSize; ++i) {
            int row = rottenQueue.front().first;
            int col = rottenQueue.front().second;
            rottenQueue.pop();

            for (const auto& dir : directions) {
                int newRow = row + dir.first;
                int newCol = col + dir.second;

                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols &&
                    grid[newRow][newCol] == 1) {
                    grid[newRow][newCol] = 2; // Mark as rotten
                    rottenQueue.push({newRow, newCol});
                    freshOranges--;
                }
            }
        }
        time++;
    }

    return (freshOranges == 0) ? time : -1;
}

int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    int result = orangesRotting(grid);

    if (result == -1) {
        cout << "It's impossible to rot all oranges." << endl;
    } else {
        cout << "Minimum time to rot all oranges: " << result << " minutes" << endl;
    }

    return 0;
}
