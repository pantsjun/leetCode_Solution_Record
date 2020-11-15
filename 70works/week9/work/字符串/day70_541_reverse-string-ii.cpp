class Solution {
public:
    string reverseStr(string s, int k) {
    // int length = s.size();
    
    // int curIndex = 0;
    // while (length > 0 && curIndex < s.size()) {
    //     if (length < k) {
    //         reverse(s.begin(), s.end());
    //     } else if (length < 2 * k && length >= k) {
    //         reverse(curIndex, curIndex + length - 1);
    //     } else {
    //         reverse(curIndex, curIndex + k -1);
    //     } 
    //     curIndex += 2 * k;
    //     length -= 2 * k;
    // }
    // return s;
    for(int i = 0; i < s.size(); i += (2*k)) {
        if (i + k < s.size()) {
            reverse(s.begin() + i, s.begin() + i + k);
            continue;
        }
        reverse(s.begin() + i, s.begin()+ s.size());
    }
    return s;
    }
};