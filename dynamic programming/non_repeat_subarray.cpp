#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>

using namespace std;

/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串的长度。
*/ 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        int skip = 0;
        int count = 0;
        bool flag = false;
        if(s.length()==0){
            return 0;
        }
        if(s.length()==1){
            return 1;
        }
        for(int i = 0;i < s.length();i++){
            count = skip-1;
            flag = false;
            for(int j = i + skip;j < s.length(); j++){//这里的使用skip的用意是当前检查的子数组必然是不重复的，因此在下一次的检查只需跳转到上一次检查的位置
                count++;
                for(int z = i;z<j;z++){
                    if(s[z]==s[j]){
                        flag = true;
                        break;
                    }
                }
                if((j == s.length()-1)&&flag==false){
                    flag = true;
                    count++;
                }
                if(flag==true){
                    if(count>1){
                        skip = count - 1;
                    }
                    else{
                        skip = 1;
                    }
                    if(max<count){
                        max = count;
                    }
                    break;
                }
            }
        }
        return max;
    }
};

class Solution_official {
public:
    int lengthOfLongestSubstring_official(string s) {
        // 哈希集合，记录每个字符是否出现过
        unordered_set<char> occ;
        int n = s.size();
        // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
        int rk = -1, ans = 0;
        // 枚举左指针的位置，初始值隐性地表示为 -1
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                // 左指针向右移动一格，移除一个字符
                occ.erase(s[i - 1]);
            }
            while (rk + 1 < n && !occ.count(s[rk + 1])) {
                // 不断地移动右指针
                occ.insert(s[rk + 1]);
                ++rk;
            }
            // 第 i 到 rk 个字符是一个极长的无重复字符子串
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }
};

// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/longest-substring-without-repeating-characters/solutions/227999/wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-by-leetc-2/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

/*
合理使用哈希集合，可以降低时间复杂度。
unordered_set 是一个无序的集合，里面存放的是元素的值，元素的值不能重复。
*/

/*
因为我们已经保证了当前区间没有重复值，当右指针右移一个位置，只需要遍历区间，找出其中与右指针当前元素相同的元素即可(最多1个）。如果存在，这个元素以及其左侧的元素都可以舍弃掉， 左指针 = 相同元素位置+1。
时间复杂度O(N*∣Σ∣)。因为不重复子串区间长度不会超过ASCII 码字符集的长度∣Σ∣=128，当N足够大时，时间复杂度接近O(N)。
空间复杂度O(1)。跟官方解法相比，这个解法省去了哈希表占用的空间。
*/
class Solution_sec{
public: 
    int lengthOfLongestSubstring(string s) {
        int ss=0;
        for(int i=0,j=0;i<s.size();i++){//更加合理的方式
            for(int l=j;l<i;l++){
                if(s[i]==s[l]){
                    j=l+1;
                    break;
                }
            }ss=max(ss,i-j+1);
        }return ss;
    }
};

/*
滑动窗口格式
//外层循环扩展右边界，内层循环扩展左边界
for (int l = 0, r = 0 ; r < n ; r++) {
	//当前考虑的元素
	while (l <= r && check()) {//区间[left,right]不符合题意
        //扩展左边界
    }
    //区间[left,right]符合题意，统计相关信息
}

本题

class Solution {
    public int lengthOfLongestSubstring(String s) {
        //滑动窗口
        char[] ss = s.toCharArray();
        Set<Character> set = new HashSet<>();//去重
        int res = 0;//结果
        for(int left = 0, right = 0; right < s.length(); right++) {//每一轮右端点都扩一个。
            char ch = ss[right];//right指向的元素，也是当前要考虑的元素
            while(set.contains(ch)) {//set中有ch，则缩短左边界，同时从set集合出元素
                set.remove(ss[left]);
                left++;
            }
            set.add(ss[right]);//别忘。将当前元素加入。
            res = Math.max(res, right - left + 1);//计算当前不重复子串的长度。
        }
        return res;
    }
}
*/

/*
哈希表的使用
*/

#include <unordered_map>
#include <string>

using namespace std;

class HashTable_use{
public:
    void hash_table() {
        // unordered_map<string, int> my_map;
        // my_map["apple"] = 1;
        unordered_set<string> mySet;
        mySet.insert("apple");
            // 向 unordered_set 中插入元素
        mySet.insert("apple");
        mySet.insert("banana");
        mySet.insert("cherry");
        mySet.insert("apple"); // 这个插入操作不会生效，因为 apple 已经存在于集合中

        // 检查元素是否存在于 unordered_set 中
        if (mySet.find("banana") != mySet.end()) {
            std::cout << "Banana is in the set." << std::endl;
        } else {
            std::cout << "Banana is not in the set." << std::endl;
        }

        // 遍历 unordered_set 中的元素
        for (const auto& element : mySet) {
            std::cout << element << std::endl;
        }

        // 删除 unordered_set 中的元素 erase(key)
        mySet.erase("cherry");

        // 再次检查元素是否存在 find(key) 返回指向 key 的指针，如果找不到则返回 end()
        if (mySet.find("cherry") == mySet.end()) {
            std::cout << "Cherry has been removed from the set." << std::endl;
        }

        // 获取 unordered_set 的大小 size()
        std::cout << "Size of the set: " << mySet.size() << std::endl;
        }
};
int main(){
    Solution sol;
    string s = "anviaj";
    cout<<sol.lengthOfLongestSubstring(s)<<endl;
}
