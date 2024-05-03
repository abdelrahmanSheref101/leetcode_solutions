class Solution {
private:
    bool is_prime(int number) {
    if (number % 2 == 0) {
        return number == 2;
    }

    // Loop from 3 to square root (n)
    for (int test_factor = 3; test_factor <= number / test_factor; test_factor +=
        2) {
        if (number % test_factor == 0) {
        return false;
        }
    }
    return number > 1;
    }
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int minidx=0,maxidx=-1;
        bool first=true;

        for (int i = 0; i < nums.size(); i++)
        {
            if(is_prime(nums[i])){
                if(first){
                    minidx=i;
                    maxidx=i;
                    first=false;
                    continue;
                }
                if(minidx>=i)
                   minidx=i; 
                else if(maxidx<i)
                    maxidx=i;
            }
        }
        return maxidx-minidx;
    }
};