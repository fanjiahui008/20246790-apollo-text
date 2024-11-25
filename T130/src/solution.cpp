// src/solution.cpp
#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>>& board, int x, int y, vector<vector<bool>>& visited) 
{
    // 将当前的 'O' 标记为 'A'
    board[x][y] = 'A';
    visited[x][y] = true;
    
    // 方向数组，表示四个方向（上、下、左、右）
    int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};
    
    // 向四个方向遍历
    for (int i = 0; i < 4; i++) 
    {
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        
        // 检查是否超出边界
        if (nextx < 0 || nextx >= board.size() || nexty < 0 || nexty >= board[0].size()) continue;
        
        // 如果是 'O' 且未被访问过，继续深度优先搜索
        if (board[nextx][nexty] == 'O' && !visited[nextx][nexty]) 
        {
            dfs(board, nextx, nexty, visited);
        }
    }
}

void solve(vector<vector<char>>& board) 
{
    // 如果 board 为空，直接返回
    if (board.empty() || board[0].empty()) return;
    
    int n = board.size(), m = board[0].size();
    
    // 创建一个二维数组，记录每个位置是否已经被访问过
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    // 步骤一：从边界进行 DFS，标记所有与边界相连的 'O'
    for (int i = 0; i < n; ++i) 
    {
        if (board[i][0] == 'O' && !visited[i][0]) dfs(board, i, 0, visited);  // 左边
        if (board[i][m - 1] == 'O' && !visited[i][m - 1]) dfs(board, i, m - 1, visited);  // 右边
    }

    for (int j = 0; j < m; ++j) 
    {
        if (board[0][j] == 'O' && !visited[0][j]) dfs(board, 0, j, visited);  // 上边
        if (board[n - 1][j] == 'O' && !visited[n - 1][j]) dfs(board, n - 1, j, visited);  // 下边
    }

    // 步骤二：遍历整个 board，替换被包围的 'O' 为 'X'，并将标记的 'A' 恢复为 'O'
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            if (board[i][j] == 'O') board[i][j] = 'X';  // 被包围的 'O' 变为 'X'
            if (board[i][j] == 'A') board[i][j] = 'O';  // 与边界相连的 'O' 恢复为 'O'
        }
    }
}

