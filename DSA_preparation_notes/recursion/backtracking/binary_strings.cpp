// https://www.geeksforgeeks.org/problems/generate-all-binary-strings/0

class Solution{
public:
    void generate_strings(map<char,int>&freq,vector<string>&ans,string temp,int num)
    {
        if(temp.size()==num)
        {
            ans.push_back(temp);
            return;
        }
        
        for(auto it=freq.begin();it!=freq.end();it++)
        {
            if(it->second)
            {
                if(!(it->first=='1' && temp.back()=='1'))
                {
                    temp += it->first;
                    it->second--;
                    generate_strings(freq,ans,temp,num);
                    it->second++;
                    temp.pop_back();
                    
                }
            }
        }
    }
    vector<string> generateBinaryStrings(int num){
        //Write your code
        map<char,int> freq;
        freq['0'] = num;
        freq['1'] = num;
        
        vector<string> ans;
        string temp = "";
        
        generate_strings(freq,ans,temp,num);
        return ans;
        
    }
};