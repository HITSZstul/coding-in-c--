#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

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
            for(int j = i + skip;j < s.length(); j++){
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

int main(){
    Solution sol;
    string s = "anviaj";
    cout<<sol.lengthOfLongestSubstring(s)<<endl;
}
