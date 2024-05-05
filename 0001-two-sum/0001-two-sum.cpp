class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        multimap<int,int>mp;
        for (int i = 0; i < nums.size(); i++)
            mp.insert(pair<int,int>(nums[i],i));
        for (int i = 0; i < nums.size(); i++)
        {
            if(mp.count(target-nums[i]))
            {
                if(mp.lower_bound(target-nums[i])->second==i)
                    continue;
                return {i,mp.lower_bound(target-nums[i])->second};
            }
        }

        return {-1,-1};
        
    }


};