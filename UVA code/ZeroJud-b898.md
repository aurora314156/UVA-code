---
title: ZeroJud.b898
date: 2017-07-25 13:05:19
tags:
- ZeroJudge
- Algorithm
categories:
- ZeroJudge
---



 <br /> <br /> <br />

<!-- more -->


	/*large number*/





	#include <iostream>
	#include <string>
	using namespace std;

	int main(int argc, const char * argv[]) {
	   
		// your code goes here
		int count = 0;
		cin>>count;
		while(count--)
		{
			/*initial*/
			string fir,sec,thi;
		   
			cin>>fir>>sec>>thi;
			string temp[3];
			temp[0]=fir;
			temp[1]=sec;
			temp[2]=thi;
		   
			string ans =temp[0];
		   
			for(int i =1;i<3;i++)
			{
				if(ans.size()>temp[i].size()){
					continue;
				}else if(ans.size()<temp[i].size()||ans.compare(temp[i])<0){
					ans=temp[i];
				}
			}
			cout<<ans<<endl;
		   
		}
	   
		return 0;
	}
</br>
