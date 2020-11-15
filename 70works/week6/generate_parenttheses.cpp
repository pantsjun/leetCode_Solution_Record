#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n == 0) return res;
        dfs(" ",0,0,n,res);
        return res;
    }
    void dfs(string curStr, int left, int right, int n , vector<string> &res){
        if(left == n && right == n ) {
            cout<<curStr<<endl;
            cout<<"size1:"<<res.size()<<endl;
            res.push_back(curStr);
            cout<<"size2:"<<res.size()<<endl;

            return;
        }
        if( left < right ) {
            return;
        }
        if(left < n) {
            dfs(curStr+"(", left+1, right, n, res);
        }
        if(right < n) {
            dfs(curStr+")",left, right+1,n,res);
        }
    }
};
int main() {
Solution s;
vector<string>res;
res = s.generateParenthesis(3);
for(int i =0; i < res.size(); i++) {
    cout<<"res:"<<res[i]<<endl;
}
    return 0;
}