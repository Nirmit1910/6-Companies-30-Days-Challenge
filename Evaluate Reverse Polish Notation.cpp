class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;


        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+")
            {
                long ele1=st.top();
                st.pop();
                long ele2=st.top();
                st.pop();
                st.push(ele1+ele2);
            }
            else if(tokens[i]=="-")
            {
                long ele1=st.top();
                st.pop();
                long ele2=st.top();
                st.pop();
                st.push(ele2-ele1);
            }
            else if(tokens[i]=="*")
            {
                long ele1=st.top();
                st.pop();
                long ele2=st.top();
                st.pop();
                st.push(ele1*ele2);
            }
            else if(tokens[i]=="/")
            {
                long ele1=st.top();
                st.pop();
                long ele2=st.top();
                st.pop();
                st.push(ele2/ele1);
            }
            else
            {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
