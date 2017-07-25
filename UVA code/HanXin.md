---
title: HanXin
date: 2017-07-25 13:02:43
tags:
- Other
- Algorithm
categories:
- Other
---


 <br /> <br /> <br />

<!-- more -->

	描述:

	相傳韓信才智過人，從不直接清點自己軍隊的人數，只要讓士兵先後以三人一排、五人一排、七人一排地變換隊形，而他每次只掠一眼隊伍的排尾就知道總人數了。
	輸入3個非負整數a,b,c ，表示每種隊形排尾的人數（a<3,b<5,c<7），輸出總人數的最小值（或報告無解）。已知總人數不小於10，不超過100 。


	輸入
	   
	2  1  6
	2  1  3


	輸出

	Case  1:  41
	Case  2:  No  answer




	#include<stdio.h>
	#include<math.h>

	int main()
	{
	 
	 int a = 0, b = 0, c = 0;

	 int Case = 0;

	 while (scanf("%d %d %d", &a, &b, &c) == 3 && a != 0 && b != 0 && c != 0)
	 {
	  int x1 = 5*7, x2 = 3*7, x3 = 3*5, N = 0;

	  for (; x1 % 3 != 1; x1 += x1);

	  for (; x2 % 5 != 1; x2 += x2);

	  for (; x3 % 7 != 1; x3 += x3);

	  N = (x1 * a + x2 * b + x3 * c) % 105;
	 
	  
	  printf("Case %d: ", ++Case);
	  10 <= N && N <= 100 ? printf("%d\n", N) : printf("No answer\n");
	  
	 }
	 return 0;
	}


	//加入0 0 0 作為中斷
</br>
