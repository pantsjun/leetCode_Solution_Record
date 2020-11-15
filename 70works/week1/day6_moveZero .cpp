// 两次遍历法：
// 一次遍历：只要不是非零元素都往前拷贝一份, 用j表示0元素开始存放的位置;
//  
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            /* code */
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }
        for(int i =j;i <nums.size();i++) {
            nums[i] = 0;
        }
    }
};