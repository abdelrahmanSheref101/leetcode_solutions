class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int boats=0;
        int i=0,j=people.size()-1;
        while(i<=j)
        {
            int sum=limit-people[j];
            j--;
            boats++;
            if(i<=j && sum>=people[i])
                ++i;

        }
        return boats;
    }
};
