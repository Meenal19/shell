#include<iostream>
#include<cstring>  
#include<stdio.h>
#include<unistd.h> 
#include<vector>
#include<signal.h>
#include "functions.h"
using namespace std;
char cwd[1024];
void sigint(int a){
    	cout.flush();
		}
/****************substring passing******************************/
void command(string sub,int count){
	char substring[1000];
	if(sub[0]=='|'){
		sub.erase(0,1);
		}	
    size_t first = sub.find_first_not_of(' ');
    size_t last = sub.find_last_not_of(' ');
   	string sub1=sub.substr(first, (last-first+1));
		strcpy(substring,sub1.c_str());
	command_parsing(substring,count);
	}
/*********************function to parse the string********************/
int substring(string line ,int k[],int j,int count){
	int i=0;
	string sub[100];	
	while(i<j){
		sub[i]=line.substr(k[i],k[i+1]-k[i]);
			i++;
		}
	for(i=0;i<j;i++){
	command(sub[i],count);
		}
	return 0;
	}
/************************parsing substrings*****************************/
int parse(char input[],int k[]){
	int i=0,j=1,flag=0,flag2=0,l;
	k[0]=0;
	int count=0;
	string line=(input);
	l=line.size();
	while(line[i++]!='\0'){
		if(line[i]=='"'){
			if(flag==1)
				flag=0;
			else
				flag=1;
			}
		if(line[i]=='\''){
			if(flag2==1)
				flag2=0;
			else
				flag2=1;
			}
		if(line[i]=='|'&&flag==0&&flag2==0){
			k[j++]=i;
			count++;
			}
		}
		k[j]=l;
		substring(line,k,j,count);
	return j;
}
/*************************driver function******************************/
int main(){
	load_vector();
	char input[1000];
	string line;
	char ch;
	signal(SIGINT,sigint);
	while(1){
		int i,j,count=0,flag=0,k[100];
		chdir("/path/to/change/directory/to");
		getcwd(cwd,sizeof(cwd));
		cout<<"my-shell:~"<<cwd<<"$";
		getline(cin,line);
		if(!line.empty()){
			svector.clear();
			strcpy(input,line.c_str());
			write_history(input);
		if(strcmp("exit",input)==0){
			printf("bubye...\n");
			break;
			}
		j=parse(input,k);
		}
	}
	return 0;
}
