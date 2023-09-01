// Header Files
#include<iostream>
#include<string>
#include<vector>
#include<bits/stdc++.h>
using namespace std;


/*
 * 
 */
 
bool check(int mid, vector<int>& nums, int p, int q)
{
	int n = nums.size();
	for(int i=0;i<n;i++)
	{
		int val = max(0, nums[i] - mid);
		int op = (val + p-1)/p;
		mid -= op;
	}
	if(mid < 0)
		return false;
	return true;
}
 
int minProject (vector<int> nums, int p, int q)
{
    sort(nums.begin(), nums.end());
	int low = 0;
	int high = 2e9;
	int ans = low;
	while(low <= high)
	{
		int mid = low + (high - low)/2;
		if(check(mid, nums, p ,q))
		{
			ans = mid;
			high = mid-1;
		}
		else{
			low = mid+1;
		}
	}
    return ans;
}

int main()
{
    
	//input for errorScore
	int errorScore_size;
	cin >> errorScore_size;
	vector<int> errorScore;
	for ( int idx = 0; idx < errorScore_size; idx++ )
	{
		int temp;
		cin >> temp;
		errorScore.push_back(temp);
	}
	//input for compP
	int compP;
	cin >> compP;
	
	//input for othQ
	int othQ;
	cin >> othQ;
	
	
    int result = minProject(errorScore, compP, othQ);
	cout << result;
	
	
    return 0;
}
