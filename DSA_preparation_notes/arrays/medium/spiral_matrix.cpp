// leetcode problem no. 54

vector<int> spiralOrder_54(vector<vector<int>>& matrix) {
    int m=matrix.size();
    int n=matrix[0].size();

    vector<int>ans;
    int top=0,bottom=m-1,left=0,right=n-1;

    while(top<=bottom && left<=right)
    {
        for(int i=left;i<=right;i++)
    {
        ans.push_back(matrix[top][i]);

    }
    top++;
    for(int i=top;i<=bottom;i++)
    {
        ans.push_back(matrix[i][right]);
    }
    right--;
    if(top<=bottom)
    {
        for(int i=right;i>=left;i--)
        {
        ans.push_back(matrix[bottom][i]);
        }
        bottom--;
    }

    if(left<=right)
    {
        for(int i=bottom;i>=top;i--)
        {
            ans.push_back(matrix[i][left]);
        }
        left++;
    }

    }

    
    return ans;
    
}

//leetcode problem 59

vector<vector<int>> spiral_order_59(int n) {
        
    vector<vector<int>> matrix(n,vector<int>(n));

    int c=1;

    int left=0,right=n-1,top=0,bottom=n-1;

    while(top<=bottom && left<=right)
    {
        for(int i=left;i<=right;i++)
    {
        matrix[top][i]=c++;
    }
    top++;

    for(int i=top;i<=bottom;i++)
    {
        matrix[i][right]=c++;
    }
    right--;

    if(top<=bottom)
    {
        for(int i=right;i>=left;i--)
        {
        matrix[bottom][i]=c++;
        }
        bottom--;

    }

    if(left<=right)
    {
        for(int i=bottom;i>=top;i--)
        {
        matrix[i][left]=c++;
        }
        left++;

    }

    }

    

    return matrix;
    
}

//time complexity of both the problems are o(m*n). o(n*n) if m==n