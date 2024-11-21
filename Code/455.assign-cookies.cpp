/*
 * @lc app=leetcode.cn id=455 lang=cpp
 * @lcpr version=30204
 *
 * [455] 分发饼干
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
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // sort g and s first
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        // go through g and s, if s[i] >= g[j], then count++
        int count = 0;
        for (int i = 0, j = 0; i < s.size() && j < g.size();) {
            if (s[i] >= g[j]) {
                count++;
                j++;
            }
            i++;
        }
        return count;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n[1,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[1,2,3]\n
// @lcpr case=end

 */

