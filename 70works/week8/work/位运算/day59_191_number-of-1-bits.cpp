#include<string>
#include<vector>
#include<unordered_set>
#include<iostream>
using namespace std;
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n != 0) {
            cout<<"n1:"<<bitset<32>(n << 2) <<endl;
            count++;
            n = n & (n-1);
            cout<<"n :"<<bitset<32>(n << 2)<<endl;
        }
        return count;
    }
};

int main() {

    Solution s;
    int res;
    res = s.hammingWeight(3);
    cout<<res<<endl;
    return 0;
}