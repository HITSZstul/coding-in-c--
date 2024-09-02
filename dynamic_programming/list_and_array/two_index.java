package dynamic_programming.list_and_array;

public class two_index {
    
}
class Solution {
    public int[] sortedSquares(int[] nums) {
        int index = 0;
        int length = nums.length;
        int[] res = new int[nums.length];
        if(nums[length-1]<0){
            index = length-1;
        }else{
            for(int i=0;i<length-1;i++){
                if(nums[i]>0&&nums[i+1]>=0){
                    index = i;
                }
            }
        }
        for(int i =0;i<length;i++){
            nums[i] = nums[i]*nums[i];
        }
        int right = index+1;
        int i=0;
        while(index>=0||right<length){
            if(index<0){
                res[i++]=nums[right++];
            }
            else if(right==length){
                res[i++]=nums[index--];
            }else{
                if(nums[index]>nums[right]){
                    res[i++]=nums[right++];
                }else{
                    res[i++]=nums[index--];
            }
            }
            
        }
        return res;
    }
}
class Solution_2{
    public int[] sortedSquares(int[] nums) {
        int length = nums.length;
        int[] res = new int[length];
        
        for(int i=0, j=length-1,index = length-1;i<=j;){
            if(nums[i]*nums[i]>nums[j]*nums[j]){
                res[index--] = nums[i]*nums[i];
                ++i;
            }else{
                res[index--] = nums[j]*nums[j];
                --j;
            }
        }
        for (int i = 0; i < nums.length; ++i) {
            nums[i] *= nums[i];
        }
        
        return res;
    }
};