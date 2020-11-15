//解题思路：三指针法，每个数组从后往前遍历
// p从m+n-1开始 
// p1为Nums1元素的下标;p2为Nums2元素的下标
// 遍历结束后将Nums2的剩余元素加进Nums1

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p1 = m-1;
    int p2  = n-1;
    int p = m+n-1;
    
    while(p1 >=0 && p2>=0) {
        if (nums1[p1] > nums2[p2]){
            nums1[p--] = nums1[p1--];
        } else {
            nums1[p--] = nums2[p2--];
        }
    }
    while (p2 >= 0)
    {
        /* code */
        nums1[p--] = nums2[p2--];
    }
    
    }
};