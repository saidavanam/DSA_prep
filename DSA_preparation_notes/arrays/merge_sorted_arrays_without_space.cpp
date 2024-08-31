#include<vector>

void optimalmergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	// Write your code here.
	int i = a.size() -1;
	int j = 0;

	while(i>=0 && j<b.size())
	{
		if(a[i]>b[j])
		{
			swap(a[i],b[j]);
			i--;
			j++;
		}
		else{
			break;
		}
	}

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	
}

//time complexity is o(mlogm) + o(nlogn) + o(min(m,n)) and space complexity is o(1)