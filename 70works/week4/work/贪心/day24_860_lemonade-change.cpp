class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int size = bills.size();
        int five = 0;
        int ten =0;
        for(int i = 0;　i<size;i++) {
            if(bills[i] == 5) {
                five ++;
            } else if(bills[i] == 10) {
                if (five == 0) {
                    return false;
                }
                five--;
                ten++;
            } else {
                if (five >0 && ten >0) {
                    five--;
                    ten--;
                } else if(five >= 3) {
                    five -=3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};