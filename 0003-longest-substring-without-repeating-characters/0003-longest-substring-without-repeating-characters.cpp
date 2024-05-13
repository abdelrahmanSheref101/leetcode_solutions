class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.size())
            return 0;
        bool *arr;
        //frequecy array
        arr=new bool[150]{false};

        int first=0;
        int last=0;

        int res=0;
        for(int i=0;i<s.size();++i)
        {
            if(arr[s[i]])
            {
                if(last) 
                    res=max(res,(last-first));
                else
                    res=max(res,(last-first)+1);

                
                while(arr[s[i]]){
                    arr[s[first]]=false;
                    ++first;
                }

                
           }
            arr[s[i]]=true;
            ++last;
        }
        if(last) 
            res=max(res,(last-first));
        else
            res=max(res,(last-first)+1);

       return res; 
    }
};