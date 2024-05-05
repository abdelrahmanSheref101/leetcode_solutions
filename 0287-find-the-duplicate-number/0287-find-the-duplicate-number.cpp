class Solution {
public:


    int findDuplicate(vector<int>& nums) {
        unordered_set<int>st;

        for(auto& elm:nums)
            if(!st.insert(elm).second)
                return elm;
        return -1;
    }
/*
    int findDuplicate(vector<int>& nums) {
        vector<int>vec (nums);
        sort(vec.begin(),vec.end());
        for (int i = 1; i < nums.size(); i++)
            if(vec[i]==vec[i-1])
                return vec[i];
        return -1; 
    }
*/
};