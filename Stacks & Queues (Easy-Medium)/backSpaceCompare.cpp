class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack <char> sStack, tStack;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '#'){
                if(!sStack.empty())
                sStack.pop();
            }
            else sStack.push(s[i]);
        }
        for(int i=0; i<t.size(); i++){
            if(t[i] == '#'){
                if(!tStack.empty())
                tStack.pop();
            }
            else tStack.push(t[i]);
        }
        while(!sStack.empty() && !tStack.empty()){
            if(sStack.top() != tStack.top())return false;
            sStack.pop();
            tStack.pop();
        }
        return !sStack.empty() || !tStack.empty() ? false : true;
        
    }
};
