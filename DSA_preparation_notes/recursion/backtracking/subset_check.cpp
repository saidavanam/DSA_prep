// https://www.naukri.com/code360/problems/subset-sum_630213?leftPanelTabValue=PROBLEM&count=25&page=1&search=&sort_entity=order&sort_order=ASC

bool subset_check(vector<int> &a,vector<int> temp,int n,int sum,int p)
{
    if(sum==0)
    {
        return true;
    }
    if(sum<0)
    {
        return false;
    }
    for(int i=p;i<n;i++)
    {
        temp.push_back(a[i]);
        bool check = subset_check(a,temp,n,sum-a[i],i+1);
        if(check == true)
        {
            return true;
        }
        temp.pop_back();
    }

    return false;

}



bool isSubsetPresent(int n, int k, vector<int> &a)
{
    // Write your code here
    vector<int> temp;
    return subset_check(a,temp,n,k,0);

}