/*
 * @lc app=leetcode.cn id=3248 lang=cpp
 * @lcpr version=30204
 *
 * [3248] 矩阵中的蛇
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int current_i = 0, current_j = 0;
        for (const auto& command : commands) {
            if (command == "RIGHT") {
                current_j++;
            } else if (command == "DOWN") {
                current_i++;
            } else if (command == "UP") {
                current_i--;
            } else if (command == "LEFT") {
                current_j--;
            }
        }
        return current_i * n + current_j;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n["RIGHT","DOWN"]\n
// @lcpr case=end

// @lcpr case=start
// 3\n["DOWN","RIGHT","UP"]\n
// @lcpr case=end

 */

