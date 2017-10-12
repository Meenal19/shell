#include<iostream>
#include<cstring>
#include<vector>
#include<fstream>
#include<iterator>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include "functions.h"
using namespace std;
/***********************echo command working***********************/
void echo_show(char *sub[],int j){
	int i=1,k;
	string line[100];
	string sub1="";
	char *path;
	for(i=1;i<j;i++)
		line[i]=string(sub[i]);
	for(i=1;i<j;i++)
	if(line[1][0]=='$'){
		for(k=1,i=0;line[1][k]!='\0';k++,i++){
			sub1+=line[1][k];
				}
			path=getenv(sub1.c_str());
			if(path!=NULL)
			printf("%s\n",path);

		}
	else{
		for(i=1;i<j;i++){
			if(line[i][0]=='"'||line[i][0]=='\'')
				for(k=1;line[i][k]!='"';k++)
				cout<<line[i][k];
			else
				cout<<line[i]<<" ";
			}
			cout<<'\n';
		}
	}
