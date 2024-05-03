class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1=version1.size(),n2=version2.size();
        int num1=0,num2=0;
        for(int i=0,j=0;i<n1 || j<n2;++i,++j){
            while(i<n1&&version1[i]!='.')
                num1=10*num1+(version1[i++]-'0');
            while(j<n2&&version2[j]!='.')
                num2=10*num2+(version2[j++]-'0');

            if(num1<num2) return -1;
            else if(num1>num2) return 1;
            num1=0;
            num2=0;
        }
        return 0;
    }
};