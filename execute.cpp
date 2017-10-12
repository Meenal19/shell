#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iterator>
#include<algorithm>
#include<stdio.h>
#include<unistd.h>
#include<cstring>
#include <sys/types.h> 
#include <sys/wait.h>
#include<stdlib.h>
#include<istream>
#include <sstream>
#include "functions.h"
using namespace std;
/***********************executing pipes***********************/
void spawn_proc (int in, int out,char* command[]){
pid_t pid;
int status;
if ((pid = fork ()) == 0){
      if(in != 0){
          dup2 (in, 0);
          close (in);
        }
	if(out!= 1){
          dup2(out, 1);
          close(out);
        }
	execvp(command[0],command);
	}
	while(wait(&status)!=pid);
		return;
	
}
/********************execute function**************************/
void execute(int i, int count){
	int j,k;
	char *command[1000];	
	int in,fd[2];
	pid_t pid,pid1;
	int status;
	vector< vector< string > >::iterator row;
	vector< string >::iterator col;
		if((svector[0][0].compare("history")==0)||(svector[0][0].compare("echo")==0)||(svector[0][0].compare("pwd")==0)||(svector[0][0].compare("cd")==0||svector[0][0].compare("export")==0)){		
		if(svector[0][0].compare("history")==0){
			show_history();
			}
		if(svector[0][0].compare("echo")==0){
				char *sub2[100];
				for(j=0;j<100;j++)
					sub2[j]=(char*)malloc(100*sizeof(char));
				for(j=1;j<i;j++)
					strcpy(sub2[j],svector[0][j].c_str());
				echo_show(sub2,j);
				}
			if(svector[0][0].compare("pwd")==0){
				char cwd[1024];
				if(getcwd(cwd,sizeof(cwd))!=NULL)
					cout<<cwd<<"\n";
				else
					perror("getcwd() error");
			}
			if(svector[0][0].compare("cd")==0){
			int rc=0;
					if((svector[0][1].compare("#")==0)||(svector[0][1].compare("~")==0)||(svector[0][1].compare("-")==0)){
						rc=chdir(getenv("HOME"));
						}
					else
						rc=chdir(svector[0][1].c_str());
					if(rc<0)
				perror("chdir() error");
					}
			if(svector[0][0].compare("export")==0){
				string s1,s2;
				char *value1,*value2;
				s1=svector[0][1].substr(0,1);
				s2=svector[0][1].substr(2,(svector[0][1].length()-2));
				setenv(s1.c_str(),s2.c_str(),1);
				}
		}
 
		
		else {
			if(svector[0][0].compare("echo")!=0)
			for(row=svector.begin();row!=svector.end();++row){
				j=0;
			for(k=0;k<1000;k++)
				command[k]=(char *)malloc(1000*sizeof(char));
			for(col=row->begin();col!=row->end();++col){
				strcpy(command[j],(*col).c_str());
				j++;
			}
				command[j]=NULL;
				pipe(fd);
			if((row+1)==svector.end())
				break;
			spawn_proc (in, fd [1], command);
			close (fd [1]);
			in = fd [0];
			}
	pid1=fork();
	if(pid1==0){
		if (in != 0)
		dup2 (in, 0);
		pid=fork();
		if(pid<0){
			perror("fork");
			return;
			}
		if(pid==0){
			execvp(command[0],command);
			}
		while(wait(&status)!=pid);
		exit(1);
			}
		while(wait(&status)!=pid1);
		return;
		}
	}


