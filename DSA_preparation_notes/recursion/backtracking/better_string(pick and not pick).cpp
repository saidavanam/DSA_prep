// https://www.geeksforgeeks.org/problems/better-string/1

class Solution {
  public:
    void recurse(string str,set<string>&st,string temp,int index)
    {
        if(index==str.size())
        {
            if(temp.size())
            {
                st.insert(temp);
            }
            return;
        }
        temp.push_back(str[index]);
        recurse(str,st,temp,index+1);
        temp.pop_back();
        recurse(str,st,temp,index+1);
        
    }
    string betterString(string str1, string str2) {
        // code here
        set<string> st1;
        string temp = "";
        recurse(str1,st1,temp,0);
        
        temp = "";
        set<string>st2;
        recurse(str2,st2,temp,0);
        
        return st1.size()>=st2.size()?str1:str2;
    }
};