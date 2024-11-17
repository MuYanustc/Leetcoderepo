/*
 * @lc app=leetcode.cn id=825 lang=cpp
 * @lcpr version=30204
 *
 * [825] 适龄的朋友
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
    int numFriendRequests(vector<int>& ages) {
        int n = ages.size();
        std::sort(ages.begin(),ages.end());
    }
};
// @lc code=end



/*
// @lcpr case=start
// [16,16]\n
// @lcpr case=end

// @lcpr case=start
// [16,17,18]\n
// @lcpr case=end

// @lcpr case=start
// [20,30,100,110,120]\n
// @lcpr case=end

 */

