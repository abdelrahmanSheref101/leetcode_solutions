class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
     vector<vector<int>>res;   
     if(nums.size()<3)
        return res;

        sort(nums.begin(),nums.end());

        for (int i = 0; i < nums.size()-2; i++)
        {
            int front=i+1,rear=nums.size()-1;
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }
            
            while(front<rear){
                int sum=(nums[front]+nums[rear]+nums[i]);
                if(sum>0)
                    --rear;
                else if(sum<0)
                    ++front;
                else{
                    res.push_back({nums[i],nums[front],nums[rear]});
                    while (front < rear && nums[front] == nums[front + 1]) {
                        front++;
                    }
                    front++;
                    
                    while (front < rear && nums[rear - 1] == nums[rear]) {
                        rear--;
                    }
                    rear--;
                }
            }
        }
        
        return res;
    }
};