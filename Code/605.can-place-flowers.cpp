/*
 * @lc app=leetcode.cn id=605 lang=cpp
 * @lcpr version=30204
 *
 * [605] 种花问题
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
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // solution 1
        // int count = 0;
        // for (int i = 0; i < flowerbed.size(); i++) {
        //     // 这个条件判断可以注意一下，写的很不错，利用||特性覆盖corner case
        //     if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
        //         flowerbed[i] = 1;
        //         count++;
        //     }
        // }
        // return count >= n;
        // solution 2
        // 在flowerbed前后插入0，这样就不用考虑边界问题, 会快一点
        flowerbed.insert(flowerbed.begin(),0);
        flowerbed.push_back(0);
        for(int i = 1;i<flowerbed.size()-1;i++){
            if(flowerbed[i-1]==0&&flowerbed[i]==0&&flowerbed[i+1]==0){
                flowerbed[i] = 1;
                n--;
            }
        }
        return n<=0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,0,0,0,1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,0,0,0,1]\n2\n
// @lcpr case=end

 */

