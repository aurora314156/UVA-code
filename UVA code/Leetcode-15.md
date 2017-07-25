---
title: 'Leetcode#15'
date: 2017-07-25 14:19:41
tags:
- Leetcode
- Algorithm
categories:
- Leetcode
---



 <br /> <br /> <br />

<!-- more -->

	// LeetCode #15
	// Difficulty: Medium
	// For test
	// Time:O(n^2)
	// Space:O(n^2)
	// Stl: SORT, ITERATOR, VECTOR


	#include <iostream>
	#include <vector>
	#include <algorithm>
	using namespace std;
	int i, j, k, n;

	//有點類似排序演算法的作法
	//每一個輪使用一個index先固定一個數 而剩下的陣列內容 分別使用兩個不同的index左右逼近 
	//過程中要注意避開重複的數字

	int main() {

		int nums[] = { -1, 0, 1, 2, -1, -4 };
		//convenient to stores result by using two-dimensional vector
		vector<vector<int> > res;
		vector<int> temp;
		n = sizeof(nums) / sizeof(nums[0]);
		sort(nums, nums + n);

		for (int i = 0; i < 6; i++) {

			//jump over duplicate
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			//two indices on each for loop
			k = n - 1; j = i + 1;
			while (j < k) {
				if (nums[i] + nums[j] + nums[k] == 0)
				{
					temp.push_back(nums[i]);
					temp.push_back(nums[j]);
					temp.push_back(nums[k]);
					res.push_back(temp);
					while (j < k && nums[k] == nums[k - 1])k--;
					while (j < k && nums[j] == nums[j + 1])j++;
					k--; j++;
					temp.clear();
				}
				else if (nums[i] + nums[j] + nums[k] > 0)k--;
				else j++;
			}
		}

		for (int v = 0; v < res.size(); ++v) {

			for (vector<int>::iterator it = res[v].begin(); it != res[v].end(); ++it)
			{
				cout << *it << " ";
			}
			cout << endl;
		}

		system("PAUSE");
	}



	//SOLUTION

	class Solution {
	public:
		vector<vector<int>> threeSum(vector<int>& nums) {
			int i, j, k,n = nums.size();

			vector<vector<int> > res;
			vector<int> temp;
			
			sort(nums.begin(),nums.begin()+n);

			for (int i = 0; i < n; i++) {

				//jump over duplicate
				if (i > 0 && nums[i] == nums[i - 1])
					continue;
				//two indices on each for loop
				k = n - 1; j = i + 1;
				while (j < k) {
					if (nums[i] + nums[j] + nums[k] == 0)
					{
						temp.push_back(nums[i]);
						temp.push_back(nums[j]);
						temp.push_back(nums[k]);
						res.push_back(temp);
						while (j < k && nums[k] == nums[k - 1])k--;
						while (j < k && nums[j] == nums[j + 1])j++;
						k--; j++;
						temp.clear();
					}
					else if (nums[i] + nums[j] + nums[k] > 0)k--;
					else j++;
				}
			}
			return res;
		}
	};
</br>
