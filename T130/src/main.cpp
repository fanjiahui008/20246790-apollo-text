#include <iostream>
#include <vector>
#include "solution.h"
#include <clocale> 
using namespace std;


int main() 
{
    // 设置语言环境为中文
    setlocale(LC_ALL, "zh_CN.UTF-8");
    
    vector<vector<char>> board = 
    {
        {'X', 'O', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    solve(board);

    cout << "处理后的棋盘：" << endl;
    for (auto& row : board) 
    {
        for (auto& cell : row) 
        {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
