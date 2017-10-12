#include<iostream>
#include<cstring>
#include<vector>
#include<fstream>
#include<iterator>
#include<algorithm>
#include<stdio.h>
#include "functions.h"
using namespace std;
#define LIMIT 100
vector<string> history;
/******************************load vector****************************/
void load_vector(){
	history.clear();
	string line1;
	ifstream file("history.txt");
	while(getline(file,line1)){
		history.push_back(line1);
		}
}
/**************************display history******************************/
void show_history(){
	int i,j;
	int size=history.size()-1;
	if(svector[0][1][0]>='0'&&svector[0][1][0]<='9'){
		int value;
		value=atoi(svector[0][1].c_str());
		for(i=size-value+1;i<=size;i++)
			cout<<history[i]<<"\n";
			}
	else{
	if(size<=LIMIT)
		for(i=1,j=1;i<=size;i++,j++){
			cout<<j<<" "<<history[i]<<"\n";
		}
	else
		for(i=size-LIMIT+1,j=1;i<=size;i++,j++){
			cout<<j<<" "<<history[i]<<"\n";
			}
		}
	}
/*******************writing content in file*************************/
void exit(){
	int i;
	ofstream output_file;
		output_file.open("./history.txt");
		for(i=0;i<history.size();i++)
			output_file<<history[i]<<"\n";
}
/*********************bang operator*********************************/
void bang(string line,int l){
	int a;
	string value;
	int i;
	if((line[0]=='-')||(line[0]>='0'&&line[0]<='9')||(line[0]=='!')){
		if(line[0]=='-'){
			string line1=line.substr(1,l-1);
			a=stoi(line1,nullptr);
			value=history[history.size()-a];
			}
		else if(line[0]>='0'&&line[0]<='9'){
			a=stoi(line,nullptr);
	 		value=history[a-1];
			}
		else if(line[0]=='!'){
			value=history[history.size()-1];
			}
			int k[100];
			char command[100];
			strcpy(command,value.c_str());
			int j=parse(command,k);
		}
	else
		cout<<"error\n";
	if(!value.empty())
		history.push_back(value);
	}
/***************************identifying bang operator********************/	
void write_history(char s[100]){
	int i;
	string line=string(s);
	if(history.size()==0&&line[0]!='!'&&!line.empty()){
		history.push_back(line);
		}
	else{
		if(history[history.size()-1].compare(line)!=0&&line[0]!='!'&&!line.empty()){
			history.push_back(line);
		}
	}
	if(line.compare("exit")==0){
		exit();
		}
	if(line[0]=='!'){
		int length=line.length()-1;
		string line1=line.substr(1,length);
		bang(line1,length);
		}
}

