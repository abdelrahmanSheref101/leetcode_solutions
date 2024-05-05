class Solution {
    class trie{
        private:
            const static int max_char= 26;
            trie * child[max_char];
            bool isLeaf=0;
        public:
            trie(){
                for(int i=0;i<max_char;++i)
                    child[i]=nullptr;
            }

            void insert(string str){
                trie *curT=this;
                for (int  i = 0,curPos=str[i]-'a'; i < str.size(); i++,curPos=str[i]-'a')
                {
                    if(i==str.size()-1)
                    {
                        if(!curT->child[curPos])
                            curT->child[curPos]=new trie();
                        curT->child[curPos]->isLeaf=1;
                    }
                    else if(!curT->child[curPos]) 
                        curT->child[curPos]=new trie();
                    curT=curT->child[curPos];
                    
                }
            }
            bool prefixExist(string str){
                int curPos=str[0]-'a';
                trie *curT=this;
                for (int  i = 0; i < str.size();curT=curT->child[curPos], i++,curPos=str[i]-'a')
                {
                    if(!curT->child[curPos])    
                        return 0;
                    if(i==str.size())
                        return (curT->child[curPos]);
                }
                return 1;
            }
        pair<bool,string> is_prefixed(string str)
        {
            string res="";
            int curPos=str[0]-'a';
            trie *curT=this;

            if(!child[curPos])
                return make_pair(0,"");

            for (int  i = 0; i < str.size();curT=curT->child[curPos], i++,curPos=str[i]-'a')
            {
                if(!curT->child[curPos])
                    return make_pair(0,"");
                   
                res+=str[i];

                if(curT->child[curPos]->isLeaf)
                    return make_pair(1,res);
            } 
            return make_pair(0,"");
        }
    };
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string word,res;
        trie T;
        for(auto &prefixes:dictionary)
            T.insert(prefixes);
        istringstream iss(sentence);
        iss>>word;
        while(true)
        {
            pair<bool,string>output=T.is_prefixed(word);
            if(output.first)
                res+=output.second;
            else        
                res+=word;
            if(iss>>word)
                res+=" ";
            else
                break;
        }
    return res;
    }

};