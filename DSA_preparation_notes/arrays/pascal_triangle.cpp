//Leetcode problem no.119

//Optimal solution

vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex+1,1);

        int n=rowIndex;

        long long ans=1;
        row[0]=1;
        for(int i=1;i<n;i++)
        {
            ans=ans*(n-(i-1));
            ans/=i;
            row[i]=ans;
        }
        return row;
        
}

//Leetcode problem no.118

//optimal solution

vector<vector<int>> generate(int numRows) 
{

        vector<vector<int>>matrix(numRows);

        for(int i=0;i<numRows;i++)
        {
            vector<int> row(i+1,1);

            int n=i;

            long long ans=1;
            row[0]=1;
            for(int j=1;j<n;j++)
            {
                ans=ans*(n-(j-1));
                ans/=j;
                row[j]=ans;
            }
            matrix[i]=row;
            
        }

        return matrix;
        
}