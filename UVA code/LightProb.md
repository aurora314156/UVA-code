---
title: LightProb
date: 2017-07-25 13:03:13
tags:
- Other
- Algorithm
categories:
- Other
---


 <br /> <br /> <br />

<!-- more -->


	題目描述 :

	有n盞燈，編號為1～n，第1個人把所有燈打開，第2個人按下所有編號為2的倍數的開關（這些燈將被關掉），第3個人按下所有編號為3的倍數的開關（其中關掉的燈被打開， 開著燈將被關閉），
	依此類推。一共有k個人，問最後有哪些燈開著？( k <=n <=1000)


	input

	7  3

	output

	1  5  6  7




	#include<stdio.h>
	#include<string.h>
	#define maxn 1010
	int a[maxn];

	int main()
	{
	 int n, k, first = 1;
	 memset(a, 0, sizeof(a));
	 scanf_s("%d%d", &n, &k);
	 for (int i = 1; i <= k; i++)
	  for (int j = 1; j <= n; j++)
	   if (j%i == 0)a[j] = !a[j];
	 
			for (int i = 1; i <= n; i++)
	  if (a[i]){ if (first)first = 0; else printf(" "); printf("%d", i); }
	 
			printf("\n");
	 return 0;
	}
</br>