// 自动机
#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
class  Atoi {
    string state = "start";
    unordered_map< string, vector<string> > table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end","end", "in_number", "end"}},
        {"end" , {"end", "end", "end", "end"}},
    };
    // unordered_map<string, vector<string>> table = {
    //     {"start", {"start", "signed", "in_number", "end"}},
    //     {"signed", {"end", "end", "in_number", "end"}},
    //     {"in_number", {"end", "end", "in_number", "end"}},
    //     {"end", {"end", "end", "end", "end"}}
    // };
    public:
    int sign = 1;
    long long ans = 0;
    int get_loc(char ch) {
        if (isspace(ch)) return 0;
        if (ch == '+' || ch == '-') return 1;
        if (isdigit(ch)) return 2;
        return 3;
    }
    void get(char ch) {
        state = table[state][get_loc(ch)];
        if (state == "in_number") {
            ans = ans * 10 + ch -'0';
            ans = sign == 1 ? std::min(ans, (long long)INT_MAX) : std::min(ans, -(long long)INT_MIN);  
        } else if (state == "signed") {
            sign = ch == '+' ? 1: -1;
        }
    }
};
class Solution {
public:
    int myAtoi(string s) {
        Atoi atoi; 
        for(auto ch : s) 
            atoi.get(ch);
        return atoi.sign * atoi.ans;
    }
};
int main () {
    string str = "-42";
    Solution s;
    s.myAtoi(str);
    return 0;
}