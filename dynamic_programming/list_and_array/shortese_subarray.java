package dynamic_programming.list_and_array;

import java.util.Arrays;

public class shortese_subarray {
    public static void main(String[] args) {
        Solution s = new Solution();
        int k=s.minSubArrayLen(213, new int[] {12,28,83,4,25,26,25,2,25,25,25,12});
        System.out.println(k);
     }
    

}
class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        Arrays.sort(nums);
        int res=0;
        while(target>0){
            res++;
            if(nums.length<res){
                res = 0;
                break;
            }
            target-=nums[nums.length-res];
        }
        return res;
    }
}
