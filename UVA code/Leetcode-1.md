---
title: 'Leetcode#1'
date: 2017-07-25 14:19:37
tags:
- Leetcode
- Algorithm
categories:
- Leetcode
---



 <br /> <br /> <br />

<!-- more -->

	// LeetCode #1 
	// Difficulty:Easy
	// Time:O(n)
	// Space:O(n)
	// Ds: HASH
	// Stl: MAP, ITERATOR, VECTOR
	// UVA 156 practice	
	 
	#include <iostream>
	#include <map>
	#include <vector>
	using namespace std;

	int main() {

		int nums[] = { 3,2,4 };

		int target = 6;

		map<int, int> map;
		vector<int> vt;

		//將map視為一個hash 若hash中已經有target - nums儲存的結果 則代表兩數相加為解
		for (int i = 0; i < 3; i++)
		{

			if (!map.count(target - nums[i])) {

				//cout << map.count(target - nums[i]) << endl;

				map.insert(pair<int, int>(nums[i], i));

				//cout << nums[i] << " " << i << endl;
			}
			else {

				vt.push_back(map[target - nums[i]]);
				vt.push_back(i);
			}
		}

		//or  for() auto it = vt.begin(); it != vt.end(); ++it)  After c++11
		for (vector<int>::iterator it = vt.begin(); it != vt.end(); ++it)
		{
			cout << *it << endl;
		}

		system("PAUSE");
	}



	//SOLUTION

	class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {

			map<int, int> map;
			vector<int> vt;

			for (int i = 0; i < nums.size(); i++)
			{
				if (!map.count(target - nums[i])) {
					map.insert(pair<int, int>(nums[i], i));
				}
				else {
					vt.push_back(map[target - nums[i]]);
					vt.push_back(i);
				}
			}

			return vt;
		}
	};

</br>
