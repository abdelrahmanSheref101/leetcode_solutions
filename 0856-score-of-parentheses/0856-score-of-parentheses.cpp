class Solution{
    public:
int scoreOfParentheses(string s) {
    stack <int> intStk;
    intStk.push(0);
    for(auto &chr:s){
        if(chr=='(')
            intStk.push(0);
        else{
            int last=intStk.top();
            intStk.pop();
            if(last==0)
                last=1; 
            else
                last *= 2;
            
            int parent_par = intStk.top()+ last;
            intStk.pop();
            intStk.push(parent_par);
        }
    }
    return intStk.top();

}
};