// leetcode problem no.56 merge intervals

/*
Optimal solution
sort the array first
create a temp vector which stores first element in array.
iterate from second element
if(arr[i][0]<=temp[1])
            {
                if(temp[1]<=arr[i][1])
                {
                    ans.back()[1]=arr[i][1];
                }
            }
            else
            {
                ans.push_back(arr[i]);
            }

*/
vector<vector<int>> merge(vector<vector<int>>& arr) {

        vector<vector<int>> ans;
        vector<int> temp;
        sort(arr.begin(),arr.end());
        ans.push_back(arr[0]);
        int n = arr.size();

        for(int i=1;i<n;i++)
        {
            temp = ans.back();
            if(arr[i][0]<=temp[1])
            {
                if(temp[1]<=arr[i][1])
                {
                    ans.back()[1]=arr[i][1];
                }
            }
            else
            {
                ans.push_back(arr[i]);
            }

        }
        return ans;
    }

