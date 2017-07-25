---
title: 'Leetcode#4'
date: 2017-07-25 14:20:04
tags:
- Leetcode
- Algorithm
categories:
- Leetcode
---



 <br /> <br /> <br />

<!-- more -->

	// Leetcode #4
	// Difficulty: Hard
	// Time: O(m+n) // let set1 be m size and set2 be n size, easy to distinguish
	// Space: O(m+n)
	// Stl: vector 
	// Algorithm: merge sort


	// It can be considered a merge stage of merge sort to deal, and it will be finished on O(m+n)
	// Comparing to the same array size have some differ to unequal length 


	#include <iostream>
	#include <cstdio>
	#include <algorithm>
	#include <vector>
	using namespace std;
	#define array_size(ary) sizeof(ary) / sizeof(*ary)
	vector<int> vc;

	void Median(int s1[], int s2[], int s1_length, int s2_length)
	{
		int i = 0, j = 0;

		while (i < s1_length && j < s2_length)
		{
			if (s1[i] > s2[j])
			{
				//cout << "i :" << i << " j: " << j << " push: " << s2[j] << endl;
				vc.push_back(s2[j]);
				++j;
			}
			else if (s1[i] < s2[j])
			{
				//cout << "i :" << i << " j: " << j << " push: " << s1[i] << endl;
				vc.push_back(s1[i]);
				++i;
			}
			else
			{
				//cout << "i :" << i << " j: " << j << " push: " << s1[i] <<" "<< s2[j] << endl;
				vc.push_back(s1[i]);
				vc.push_back(s2[j]);
				++i;
				++j;
			}
		}

		if (i >= s1_length)
		{
			for (; j < s2_length; ++j)
				vc.push_back(s2[j]);
		}
		if (j >= s2_length)
		{
			for (; i < s1_length; ++i)
				vc.push_back(s1[i]);
		}
	}


	int main() {

		int s1[] = { 11,13,15,17,18 };
		int s2[] = { 1,2,3,4,5,10 };

		int s1_length = array_size(s1);
		int s2_length = array_size(s2);

		s1_length > s2_length ? Median(s2, s1, s2_length, s1_length) : Median(s1, s2, s1_length, s2_length);

		/*for (vector<int>::iterator iter=vc.begin(); iter != vc.end(); ++iter)
		{
			printf("%d ", *iter);
		}*/

		double ans_index;

		if (vc.size() & 1)
		{
			int ans_index = vc.size() / 2;

			printf("%d\n", vc.at(ans_index));
		}
		else {

			ans_index = vc.size() / 2;

			double ans = (vc.at(ans_index) + vc.at(ans_index - 1)) / 2.0;

			printf("%.1f\n", ans);
		}

		system("PAUSE");
	}



	/*
	class Solution {
		vector<int>vc;
	public:
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

			int s1_length = nums1.size();

			int s2_length = nums2.size();

			s1_length > s2_length ? Median(nums2, nums1, s2_length, s1_length) : Median(nums1, nums2, s1_length, s2_length);

			double ans_index;

			if (vc.size() & 1)
			{
				int ans_index = vc.size() / 2;
				
				return vc.at(ans_index);
				
			}
			else {

				ans_index = vc.size() / 2;

				double ans = (vc.at(ans_index) + vc.at(ans_index - 1)) / 2.0;

				return ans;

				
			}
		}
		void Median(vector<int>& nums1, vector<int>& nums2, int s1_length, int s2_length)
		{

			int i = 0, j = 0;

			while (i < s1_length && j < s2_length)
			{
				if (nums1.at(i) > nums2.at(j))
				{
					vc.push_back(nums2.at(j));
					++j;
				}
				else if (nums1.at(i) < nums2.at(j))
				{
					vc.push_back(nums1.at(i));
					++i;
				}
				else
				{
					vc.push_back(nums1.at(i));
					vc.push_back(nums2.at(j));
					++i;
					++j;
				}
			}

			if (i >= s1_length)
			{
				for (; j < s2_length; ++j)
					vc.push_back(nums2.at(j));
			}
			if (j >= s2_length)
			{
				for (; i < s1_length; ++i)
					vc.push_back(nums1.at(i));
			}

		}
	};*/
</br>
