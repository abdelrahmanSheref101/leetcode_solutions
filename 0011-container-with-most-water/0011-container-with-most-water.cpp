class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxAr{0};
        int j=height.size()-1;
        int i=0;
        while(i<j){
            int area=min(height[j],height[i])*(j-i);
            maxAr=max(area,maxAr);
            //shift the first pointer as potenially you will find a bigger height ,
            // note that still all potenial max areas are examined
            if(height[i]<=height[j])
                ++i;
            else    
                --j;
        }
        return maxAr;
    }
};
