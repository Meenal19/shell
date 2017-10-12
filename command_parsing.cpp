#include<iostream>
#include<cstring>
#include<vector>
#include<bits/stdc++.h>
#include<fstream>
#include<iterator>
#include<algorithm>
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include "functions.h"
using namespace std;
/*********************converting strings to tokens******************/
vector<vector<string> > svector;
void convert(string line ,int k[],int j,int count){
	int i=0,t;
	vector<string> v;
	string sub[1000];
	string command_entry[1000];	
	while(i<j){
		sub[i]=line.substr(k[i],k[i+1]-k[i]);
			i++;
		}
	string sub3;
	for(i=0;i<j;i++){
	 size_t first = sub[i].find_first_not_of(' ');
    size_t last = sub[i].find_last_not_of(' ');
   	command_entry[i]=sub[i].substr(first, (last-first+1));
		v.push_back(command_entry[i]);
		}
		svector.push_back(v);
		if(svector.size()==(count+1)){
			execute(j,count);	
			}	
}
/*********************parsing with spaces*******************/
void command_parsing(char string1[],int count){
	string sub1=(string1);
int i=0,j=1,flag=0,flag2=0,l,k[100];
	k[0]=0;
	l=sub1.size();
	while(sub1[i++]!='\0'){
		if(sub1[i]=='"'){
			if(flag==1)
				flag=0;
			else
				flag=1;
			}
		if(sub1[i]=='\''){
			if(flag2==1)
				flag2=0;
			else
				flag2=1;
			}
		if(sub1[i]==' '&&flag==0&&flag2==0){
			while(sub1[++i]==' ');
				if(sub1[i]=='"')
					flag=1;
				if(sub1[i]=='\'')
					flag2=1;
				k[j++]=i;
			}
		}
		k[j]=l;
	convert(sub1,k,j,count);
}

