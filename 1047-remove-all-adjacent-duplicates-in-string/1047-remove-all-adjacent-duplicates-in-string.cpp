class Solution {
public:
    string removeDuplicates(string S){
    string res;
    stack <char> st;

    st.push(S[0]);

    for (int i = 1; i < S.size(); i++){
        if(!st.empty()&&S[i]==st.top())
            st.pop();
        else
            st.push(S[i]);
    }

    while(!st.empty())
        res+=st.top(),st.pop();

    reverse(res.begin(),res.end());

    return res;
}
};