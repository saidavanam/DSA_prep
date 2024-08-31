//leetcode problem no.560

//Optimal solution

int subarraySum(vector<int>& nums, int k) {
        int sum=0,rem=0,count=0,n=nums.size();
        std::map<int,int> mpp; //map sum value as keys and their counts as values.

        mpp[0]=1; //used to increment count when rem is zero.

        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            rem=sum-k;
            if(mpp.find(rem)!=mpp.end())
            {
                count+=mpp[rem];
            }
            if(mpp.find(sum)!=mpp.end())
            {
                mpp[sum]+=1;
            }
            else
            {
                mpp[sum]=1;
            }
        }

        return count;
        
    }

/*
   Dry run:- [1,2,3,-3,1,1,1,4,2,-3] count=8
*/

/*
Time complexity is o(n)(unordered map)
o(nlogn)(ordered map)
space complexity is o(n)
*/
