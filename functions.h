#include<string>
#include<vector>
using namespace std;
void load_vector();
void write_history(char s[100]);
void show_history();
void command_parsing(char string1[],int count);
int parse(char input[],int k[]);
void execute(int i, int count);
void echo_show(char *sub[],int j);
extern vector<vector<string> > svector;

