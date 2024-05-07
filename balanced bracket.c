/*c program to check a balanced brackets*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10
char stack[MAX];
int top=-1;
void push(char item){
	stack[++top]=item;
}
int ismatch(char ch1,char ch2){
	if(ch1=='['&&ch2==']')
		return 1;
	else if (ch1=='('&&ch2==')')
		return 1;
	else if(ch1=='{'&&ch2=='}')
		return 1;		
	else 
		return 0;
}
char pop(){
	char ch;
	if(top==-1){
		printf("not balanced\n");
		exit(0);
	}	
	ch=stack[top];
	top--;
	return ch;
}
int isempty(){
	if(top==-1)
		return 1;
	else
		return 0;
}
int main(){
	char exp[MAX],ch,temp;
	int i;
	printf("enter the expression\n");
	gets(exp);
	for(i=0;exp[i]!='\0';i++){
		ch=exp[i];
		if(ch=='('||ch=='['||ch=='{')
			push(ch);
		else{
			temp=pop();
			if(!ismatch(temp,ch)){
				printf("not balanced\n");
				exit(0);
			}		 
                }
        }
	if(isempty())
		printf("balanced\n");
	else
		printf("not balanced\n");
}	
