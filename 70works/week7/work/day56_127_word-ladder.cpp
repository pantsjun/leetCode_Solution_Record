#include<string>
#include<vector>
#include<unordered_set>
#include<iostream>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.count(endWord) == 0) return 0;
        unordered_set<string> upToDown({beginWord});
        unordered_set<string>downToUp({endWord});
        int list_size = wordList.size();
        int word_size = beginWord.size();
        vector<int>flag(list_size, 0);
        int res =2;
        while(!upToDown.empty()) {
            unordered_set<string>next;
            for( auto & word : upToDown) {
                for(int i =0; i < list_size; i++) {
                    int count = 0; // count是用来计算beginword和当前比较的string不同的字符个数
                    for(int j = 0; j < word_size; j++) {
                        if (word[j] != wordList[i][j]) {
                            count++;
                        }
                        if(count > 1) break; //如果不同的字符个数大于一个以上就跳出循环
                    }
                    if (count == 1) { // 题目要求每次只能变一个元素，所以不同字符的个数只能为一，满足条件，才能往下判断
                        if (downToUp.count(wordList[i]) != 0) return res;
                        if (flag[i] == 0)
                        next.insert(wordList[i]);
                        flag[i] = 1;
                    }
                }
            }
            res++;
            upToDown = next;
            if (upToDown.size() >  downToUp.size()) swap(upToDown, downToUp);
        }
        return 0;
    }
};

int main() {

    Solution s;
    int res;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string>wordlist = {"hot","dot","dog","lot","log","cog"};
    res = s.ladderLength(beginWord, endWord, wordlist);
    cout<<res<<endl;
    return 0;
}