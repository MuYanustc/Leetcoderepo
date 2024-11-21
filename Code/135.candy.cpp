// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=135 lang=cpp
 * @lcpr version=30204
 *
 * [135] 分发糖果
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
#include <numeric>
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
    int candy(vector<int>& ratings)
    {
        // go through ratings
        bool flag = false;
        // condy
        vector<int> candies(ratings.size(), 1);
        if (ratings.size() == 1) {
            return 1;
        }
        // 标准解法
        // int n = ratings.size();
        // vector<int> candies(n, 1);
        // for (int i = 1; i < n; ++i) {
        //     if (ratings[i] > ratings[i - 1]) {
        //         candies[i] = candies[i - 1] + 1;
        //     }
        // }
        // for (int i = n - 1; i > 0; --i) {
        //     if (ratings[i] < ratings[i - 1]) {
        //         candies[i - 1] = max(candies[i - 1], candies[i] + 1);
        //     }
        // }
        // return accumulate(candies.begin(), candies.end(), 0);

        // int n = ratings.size(); vector<int> candies(n, 1); for (int i = 1; i < n;
        // ++i) { if (ratings[i] > ratings[i - 1]) { candies[i] = candies[i - 1] +
        // 1; } }  for (int i = n - 1; i > 0; --i) { if (ratings[i] < ratings[i -
        // 1]) { candies[i - 1] = max(candies[i - 1], candies[i] + 1); } }  return
        // accumulate(candies.begin(), candies.end(), 0); 漏一个case，
        // 以及丑陋的解法 上面的解法感觉可以，但仔细考量corner case 有点多。
        // 判断如果降序，则需要从后往前遍历
        bool is_descend = true;
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] >= ratings[i - 1]) {
                is_descend = false;
                break;
            }
        }
        if (is_descend) {
            for (int i = 0; i < ratings.size(); i++) {
                candies[i] = ratings.size() - i;
            }
            return ratings.size() * (ratings.size() + 1) / 2;
        }
        while (!flag) {
            flag = true;
            for (const auto& rating : ratings) {
                int index = &rating - &ratings[0];
                if (index == 0) {
                    if ((rating < ratings[1]) && (candies[0] >= candies[1])) {
                        candies[1] = candies[0] + 1;
                        flag = false;
                    } else if ((rating > ratings[1]) && (candies[0] <= candies[1])) {
                        candies[0] = candies[1] + 1;
                        flag = false;
                    }
                } else if (index == ratings.size() - 1) {
                    if ((rating < ratings[ratings.size() - 2]) && (candies[index] >= candies[index - 1])) {
                        candies[index - 1] = candies[index] + 1;
                        flag = false;
                    } else if ((rating > ratings[index - 1]) && (candies[index] <= candies[index - 1])) {
                        candies[index] = candies[index - 1] + 1;
                        flag = false;
                    }
                } else {
                    if ((rating > ratings[index + 1]) && (candies[index] <= candies[index + 1])) {
                        candies[index] = candies[index + 1] + 1;
                        flag = false;
                    } else if ((rating < ratings[index + 1]) && (candies[index] >= candies[index + 1])) {
                        candies[index + 1] = candies[index] + 1;
                        flag = false;
                    } else if ((rating > ratings[index - 1]) && (candies[index] <= candies[index - 1])) {
                        candies[index] = candies[index - 1] + 1;
                        flag = false;
                    } else if ((rating < ratings[index - 1]) && (candies[index] >= candies[index - 1])) {
                        candies[index - 1] = candies[index] + 1;
                        flag = false;
                    }
                }
            }
        }
        int sum = 0;
        for (const auto& candy : candies) {
            sum += candy;
        }
        // output candies
        for (const auto& candy : candies) {
            cout << candy << " ";
        }
        return sum;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,87,87,87,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2]\n
// @lcpr case=end

 */
