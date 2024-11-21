/*
 * @lc app=leetcode.cn id=452 lang=cpp
 * @lcpr version=30204
 *
 * [452] 用最少数量的箭引爆气球
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
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0]; // 这里a[0]<b[0]也能ac
        });
        // 这种线段覆盖感觉很经典，按左端排序还是右端排序有点迷糊
        int start = points[0][0];
        int end = points[0][1];
        int sum = 1;
        for (int i = 1; i < points.size(); i++) {
            if (points[i][1] < start||points[i][0]>end) {
                sum++;
                start = points[i][0];
                end = points[i][1];
            } else {
                start = max(start, points[i][0]);
                end = min(end, points[i][1]);
            }
        }

        return sum;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[10,16],[2,8],[1,6],[7,12]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[3,4],[5,6],[7,8]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[2,3],[3,4],[4,5]]\n
// @lcpr case=end

 */

