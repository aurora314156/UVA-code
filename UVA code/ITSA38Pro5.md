---
title: ITSA38Pro5
date: 2017-07-25 13:04:17
tags:
- Other
- Algorithm
categories:
- Other
---



 <br /> <br /> <br />

<!-- more -->


※使用 hashMap不重複計數的特性






	import java.util.HashMap;
	import java.util.Map;
	import java.util.Scanner;

	public class Main {

	 public static void main(String[] args) {

	  Scanner sc=  new Scanner(System.in);

	  int count = 0;

	  count  = Integer.parseInt(sc.nextLine().trim());

	  while(count-->0)
	  {
	   int a = sc.nextInt();
	 
	   int c = sc.nextInt();
	 
	   int m = sc.nextInt();
	 
	   int x = sc.nextInt();
	 
	   int counter = 0,ans = 0;
	 
	   HashMap<Integer,Integer>  hm = new HashMap<Integer,Integer>();
	 
	   while(counter<m)
	   {
		counter++;
	  
		x = (a * x + c) % m ;
	  
		if(!hm.containsKey(x))
		 hm.put(x, 1);
		else
		{
		 int temp = hm.get(x);
		 temp++;
		 hm.put(x, temp);
		}
	   }
</br>