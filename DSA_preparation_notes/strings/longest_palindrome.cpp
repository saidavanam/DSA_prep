// leetcode problem no.5

/*
Brute force solution :-
  retriving all substrings (o(n**2)) and palin check o(n)

*/

class Solution {
public:
    string longestPalindrome(string s) {

        string max_str = "";
        int max_len = 0;
        int n = s.length();

        for(int i=0;i<n;i++)
        {
            for(int j=i+max_len-1;j<n;j++) //only focusing on solutions which are atleast as big as max_len. j = i+max_len
            {
                if(j-i+1>max_len && ispalin(i,j,s))
                {
                    max_str = s.substr(i,j-i+1); //s.substr(i,length) not s.substr(i,j)
                    max_len = j-i+1;
                }
            }
        }

        return max_str;


        
    }
private:
    bool ispalin(int i,int j,const string &s) //pass memory address instead of string to prevent memory addresss exceeded error.
    {
        int left = i;
        int right = j;
        while(left<=right)
        {
            if(s[left]!=s[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

/*
Time Complexity is o(n**3),space complexity is o(1).
*/

/*
Optimal solution :-
solutions expanding from center.

We observe that a palindrome mirrors around its center. 
Therefore, a palindrome can be expanded from its center, and there are only 2n - 1 such centers.
You might be asking why there are 2n - 1(both odd and even centers) but not n centers? The reason is the center of a palindrome can be in between two letters. 
Such palindromes have even number of letters (such as "abba") and its center are between the two 'b's.'
Since expanding a palindrome around its center could take O(n) time, the overall complexity is O(n^2).
*/

class Solution {
public:
    string longestPalindrome(string s) {

        if(s.length()<=1)
        {
            return s;
        }

        string max_str = "";

        //lambda function
        auto expand = [&](int left,int right)
        {
            while(left>=0 && right<s.length() && s[left]==s[right])
            {
                left--,right++;
            }
            return s.substr(left+1,right-left-1);
        };

        for(int i=0;i<s.length();i++)
        {
            string odd = expand(i,i); //retriving odd len string
            string even = expand(i,i+1); //retrieving even len string

            if(odd.length()>max_str.length())
            {
                max_str = odd;
            }

            if(even.length()>max_str.length())
            {
                max_str = even;
            }
        }

        return max_str;
    }
};