class Solution {
public:
       vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp; 
        set<pair<int,int>>st;

        for(auto& elm:nums)
            mp[elm]++;

        for(auto it=mp.begin();it!=mp.end();++it)
            st.insert({it->second,it->first});    

        vector<int>ans;
        auto it=st.end();
        --it;

        for (int i = 0; i < k;--it,i++)
            ans.push_back(it->second);
        
        return ans;
    }
};