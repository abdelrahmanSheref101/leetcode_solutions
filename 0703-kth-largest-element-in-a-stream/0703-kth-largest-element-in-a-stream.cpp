class KthLargest {
    int num;
    priority_queue <int> pq;
public:
    KthLargest(int k, vector<int>& nums):num(k) {
        for(int i=0;i<nums.size();++i)
            this->add(nums[i]);
    }
    
    int add(int val) {
        if(pq.empty()||pq.size()<num)    
            pq.push(-val);
        else if(-pq.top()<val)
            pq.pop(),pq.push(-val);
        return -pq.top();
    }
};
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */