/**
 * 一次哈希遍历
 * 解题思路:数值作为map的键，下标作为map的值;
 * 每次遍历时，如果target-nums[i]在map中能找到值，
 * 说明target的两个数已经找到,就返回
*/
#include <iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>res;
        map<int, int> hashmap;
        for(int i=0; i< nums.size();i++) {
            if(hashmap[target-nums[i]] && hashmap[target-nums[i]] != i+1) {
                res.push_back(i);
                res.push_back(hashmap[target-nums[i]]-1);
                return res;
            }

            //不让hash的下标为负
            hashmap[nums[i]] = i+1;
        }
        return res;
    }
};
int main() {
    Solution s;
    vector<int> test= {-2,11, 4, 15, 7,5};
   
    for(int i =0; i< s.twoSum(test, 9).size();i++) {
        cout<< s.twoSum(test, 9)[i]<<endl;
    }
    return 0;
}