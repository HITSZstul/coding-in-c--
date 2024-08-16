#include<vector>
#include<iostream>
#include <map>
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

class vector_test{
public:
    vector<int> v;//creat a vector,默认初始化一个空的 vector
    vector_test(){
        vector<int> v1(2,1);//creat a vector with 2 element in 1 value
        vector<int> v2 = {1,2};//creat a vector with 2 element in 2 value
    }
    //vector<int> v1(2,1);//creat a vector with 2 element in 1 value
    vector<int> v2 = {1,2};//creat a vector with 2 element in 2 value
    // std::vector<int> myVector1(5); // 创建一个包含 5 个整数的 vector，每个值都为默认值（0）
    // std::vector<int> myVector2(5, 10); // 创建一个包含 5 个整数的 vector，每个值都为 10
    // 在函数外定义 vector会报错，因为函数外定义 vector 属于全局变量

    // add element to vector

    void add_element(){
        v.push_back(1);// 添加一个元素到 vector 的末尾, 相当于 v[v.size()] = 1
    }
    // v.push_back(1);


    // v.emplace_back(2);//emplace_back is faster than push_back
    /**
     * @brief 在容器末尾就地构造元素
     *
     * 在容器的末尾就地构造一个元素，并将其添加到容器中。
     *
     * @note 此函数使用emplace_back方法，将元素2添加到容器v中。
     */
    void emplace_back(){
        v.emplace_back(2);
    }
    // v.insert(v.begin(), 3);//insert element to the begin of vector
    /**
     * @brief 插入元素到向量的开头
     * 
     * insert 函数将元素插入到给定位置之前。
     * 
     * 在向量的开头插入一个元素。
     */
    void insert_begin(){
        v.insert(v.begin(), 3);//insert element to the begin of vector
    }
    // v.insert(v.end()-1, 4);//insert element to the end of vector
    void insert_end(){
        v.insert(v.end()-1, 4);//insert element to the end of vector
    }
    // v.insert(v.begin()+1, 5);
    void insert_vector(){
        v.insert(v.begin()+1, 5);
    }
    
    // erase element from vector 删除元素
    void erase_element(){
        v.erase(v.begin() + 2); // 删除第三个元素
    }
    // v.pop_back();
    void pop_back(){
        v.pop_back();// 删除最后一个元素
    }
    // v.clear();
    void clear(){
        v.clear();// 清空 vector
    }

    // 迭代访问vector
    void iterator1(){
        for(auto &i:v){// 迭代访问 vector 中的元素
            cout << i << " ";
        }
    }
    void iterator2(){
        for(int i=0; i<v.size(); i++){// 迭代访问 vector 中的元素
            cout << v[i] << " ";
        }
    }
    void iterator3(){
        for(vector<int>::iterator it = v.begin(); it != v.end(); ++it){// 迭代访问 vector 中的元素，vector<int>::iterator 可以替换为auto
            cout << *it << " ";
        }
    }
};
class map_test{
public:
    map<int, int> m;//creat a map with key and value
    map_test(){
        m[1] = 2; // 添加一个键值对，key 为 1，value 为 2
        m.emplace(3,4);//emplace is faster than insert
    }
    // m.insert({5,6});//insert element to the end of vector
    /**
     * @brief 插入元素到向量的末尾
     * 
     * insert 函数将元素插入到给定位置之前。
     * 
     * 在向量的末尾插入一个元素。
     */
    void insert_end(){
        m.insert({5,6});//insert element to the end of vector
    }
    // m.erase(1);
    void erase_element(){
        m.erase(1);
    }
    // 迭代访问map
    void iterator(){
                for(auto &i:m){// 迭代访问 map 中的元素
            cout << i.first << " " << i.second << endl;
        }
    }


};
int main(){
    vector_test vt;
    vt.add_element();
    vt.iterator1();
    cout << endl;
    vt.add_element();
    vt.iterator2();
    vt.emplace_back();
    vt.insert_begin();
    vt.iterator1();
    cout << endl;
    vt.insert_end();
    vt.iterator1();
    cout << endl;
    vt.insert_vector();
    vt.iterator1();
    cout << endl;
    vt.erase_element();
    vt.pop_back();
    vt.clear();

    cout << endl;
    vt.iterator3();
}