#include<vector>
#include<iostream>
using namespace std;
/*
如果数组的每一对相邻元素都是两个奇偶性不同的数字，则该数组被认为是一个 特殊数组 。

你有一个整数数组 nums 和一个二维整数矩阵 queries，对于 queries[i] = [fromi, toi]，请你帮助你检查 
子数组
 nums[fromi..toi] 是不是一个 特殊数组 。

返回布尔数组 answer，如果 nums[fromi..toi] 是特殊数组，则 answer[i] 为 true ，否则，answer[i] 为 false 。
*/
class Solution{
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();//get num of subarray
        vector<int> dp(n,1);//creat a vector with n element in 1 value
        for(int i=1; i<n; i++){
            if(nums[i]^nums[i-1]&1){
                dp[i] = dp[i-1] + 1;
            }
        }
        
        vector<bool> res;
        for(auto &q:queries){//ergodic the queries element
            int x = q[0], y = q[1];//get the length of subarray
            res.emplace_back(dp[y] >= y-x+1);// if dp[y] the longest subarray of special array
        }
        return res;
    }
};