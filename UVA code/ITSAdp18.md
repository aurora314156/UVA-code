---
title: ITSAdp18
date: 2017-07-25 13:01:59
tags:
- Other
- Algorithm
categories:
- Other
---


 <br /> <br /> <br />

<!-- more -->


	問題描述： 
	在沙漠中有一個村落，村落旁邊有一個綠洲，村民所有的水都要從綠洲取得，村長發給每一戶人家一個水桶，以及家中每個人一個水瓢，
	年齡愈大的人拿到的水瓢容積愈大，並且規定每戶人家每天只能只能裝一桶水，取水時必須排隊，
	每個人一次只能舀一瓢水，而且水瓢必須裝滿。今天小明全家出動，要去裝水，
	知道水桶可裝 M 公升的水， 請幫小明算算全家人如何在排最少舀水幾次能將水桶裝滿，而綠洲的水相當珍貴，所以不能讓水滿出水桶。


	輸入說明： 
	第一行有一個正整數 N ，表示共有 N 筆測試資料，之後有 N 行，
	每行為一筆測試資料。每筆測資第一個數為一個正整數 K (1 <= K <= 100) ，代表家中人口數 ( 即水瓢的數量 ) ，
	之後有 K +1 個正整數，前面 K 個數字分別代表各水瓢的容積，最後一個則代表水桶的容積 (M <= 10000)，每個整數間均有一個空格隔開。


	輸出說明： 每筆測試資料 輸出最少舀水次數 於一行，若無法在不溢出的情況下 將水桶裝滿則輸出 0 。



	Sample Input
	2
	3 2 3 4 5
	4 2 4 6 8 21

	Sample Output
	2
	0


	解法:動態規劃





	import java.util.Scanner;

	public class ITSA_C_DP18 {

	 public static void main(String[] args) {
	  // TODO Auto-generated method stub
	  Scanner sc = new Scanner(System.in);

	  int N = sc.nextInt();

	  for (int n = 0; n < N; n++) {

	   int K = sc.nextInt();

	   int volume[] = new int[K + 1];

	   for (int v = 1; v <= K; v++)
		volume[v] = sc.nextInt();

	   int M = sc.nextInt();

	   int dp[] = new int[M + 1];

	   for (int d = 1; d <= M; d++)
		dp[d] = Integer.MAX_VALUE;

	   dp[0] = 0;
	   
	   for (int i = 1; i <= K; i++)
		for (int j = volume[i]; j <= M; j++) {
		 if (dp[j - volume[i]] != Integer.MAX_VALUE && dp[j - volume[i]] + 1 < dp[j])
		  dp[j] = dp[j - volume[i]] + 1;
		}

	   System.out.println(dp[M] == Integer.MAX_VALUE ? 0 : dp[M]);

	  }
	  sc.close();
	 }
	}
</br>
