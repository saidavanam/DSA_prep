https://www.interviewbit.com/problems/subarray-with-given-xor/


// use this test case for dry run [4,2,2,6,4]


int Bettersolve(vector<int> &A, int B) {
    
    int count = 0;
    int n = A.size(); 
    
    for(int i=0;i<n;i++)
    {
        int xor_ = 0;
        for(int j=i;j<n;j++)
        {
            xor_ = xor_ ^ A[j];
            if(xor_ == B)
            {
                count++;
            }
            
        }
    }
    return count;
}

/* 
 Time complexity is o(n**2) and space complexity is o(1)
*/

int optimalsolve(vector<int> &A, int B) {
    
    int count = 0;
    int n = A.size(); 
    
    std::map<int,int> mpp;
    
    mpp[0] = 1; // very imp
    
    int xor_ = 0;
    int x = 0;
    
    for(int i=0;i<n;i++)
    {
        xor_ = xor_ ^ A[i];
        x = xor_ ^ B;
        
        if(mpp.find(x)!=mpp.end())
        {
            count += mpp[x];
        }
        mpp[xor_] +=1;
        
    }
    
    return count;
}

/*
 Time complexity is o(n) and space complexity is o(n)
*/