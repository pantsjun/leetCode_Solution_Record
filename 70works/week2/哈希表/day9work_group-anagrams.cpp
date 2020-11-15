/*
自己没有做出来的原因:1. 对容器的相关函数不了解，没有想到用容器封装好的函数来做题
                   2.对STL的相关知识不熟悉，比如如何去排序字符串也是没想到用sort来做
                   也不清楚sort可以排序字符串的字符;
解题思路： 首先就是排序了,然后用一个unorder_map存储键值对<str, int> ,str作为键，int作为值,
          异位词排序完的字符串是一样的，所以只要排序完的字符串作为键存入map中，后面遍历到的元素只要排序完得到的
          结果也和map存的键一样，那么就说明它们是异位词，就送入res
           利用unorder_map的count可以判断键所对应的值是否存在(unorder_map不存储重复的元素),若存在则直接送进结果，
           否则表示res当前还不存在str,把str送进res中。接着unorder_map键所对应的值(也就是用来表示res下标)自增
 */
#include<iostream>
#include<vector>
#include<unorder_map>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int sub =0;
        string tmp;
        vector<vector<string>>res = NULL;
        unordered_map<string, int> work;
        for(auto str: strs) {
            tmp = str;
            sort(tmp.begin(), tmp.end());
            if(work.count(tmp)) {
                res[work[tmp]].push_back(str);
            }else {
                vector<string> vec(1, str);
                res.push_back(vec);
                work[tmp] = sub++;
            }
        }
        return res
    }
};
int main() {
    Solution s;
    vector<string> s = {"eat","tea","tan","ate","nat","bat"}
    vector<vector<string>> res;
    res = s.groupAnagrams(s);
    return 0;
}