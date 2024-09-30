#include <iostream>  
#include <unordered_map>  
#include <vector>
  
int main() {  
    std::unordered_map<std::string, int> hashtable;  
  
    // 向哈希表中添加一些元素  
    hashtable["apple"] = 1;  
    hashtable["banana"] = 2;  
    hashtable["cherry"] = 3;  
  
    // 使用迭代器遍历哈希表  
    for (std::unordered_map<std::string, int>::iterator it = hashtable.begin();  
         it != hashtable.end(); // 使用end()作为循环的结束条件  
         ++it) {  
        std::cout << it->first << ": " << it->second << std::endl;  
    }  
  
    // 使用C++11的范围for循环遍历哈希表（更简洁）  
    for (const auto& pair : hashtable) {  
        std::cout << pair.first << ": " << pair.second << std::endl;  
    }  
  
    return 0;  
}
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>hashtable;
        for(int i=0;i<nums.size();i++){
            auto it = hashtable.find(target-nums[i]);
            if(it!=hashtable.end()){
                return {it->second,i};
            }
            hashtable[nums[i]]=i;
        }
        return {};
    }
};