/*
 * @lc app=leetcode.cn id=763 lang=cpp
 * @lcpr version=30204
 *
 * [763] 划分字母区间
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
    vector<int> partitionLabels(string s) {
        vector<int> res;
        unordered_map<char,int> mp;
        for(int i = 0;i<s.size();i++){
            mp[s[i]] = i;
        }
        int start = 0;
        int end = mp[s[0]];
        for(int i = 1;i<s.size();i++){
            if(i>end){
                res.push_back(end-start+1);
                start = i;
                end = mp[s[i]];
            }
            else{
                end = max(end,mp[s[i]]);
            }
        }
        res.push_back(end-start+1);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "ababcbacadefegdehijhklij"\n
// @lcpr case=end

// @lcpr case=start
// "eccbbbbdec"\n
// @lcpr case=end

 */

