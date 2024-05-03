class Solution {
public:
    int trap(vector<int>& height) {
        int i=0,j=height.size()-1;
        //intialize maxL,R with heights of the far left and far right
        int maxL=height[i],maxR=height[j];
        int totalArea=0;
        while(i<j){
            if(maxL<=maxR)
            {
                ++i;
                maxL=max(maxL,height[i]);
                totalArea += maxL-height[i];
            }
            else 
            {
                --j;
                maxR=max(maxR,height[j]);
                totalArea += maxR-height[j];
            }
        }

        return totalArea;
    }
};