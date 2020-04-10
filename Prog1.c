
#include <stdio.h>




#define max 1000


char stack[max],top = -1;


char pop(){







	if(top == -1)


		return '0';


	char res = stack[top];


	top--;


	return res;







}


void push(char data){


	if(top != max-1)


		printf("overflow\n");


	top++;


	stack[top] = data;


}


int main(){


	char string[max];


	scanf("%[^\n]%*c",string);


	int i ;


	for(i = 0;string[i] !='\0';i++){


		push(string[i]);


	}


	for(i=0;i<max;i++){


		int c = pop();


		if(c == '0')


			break;


		string[i] = c;


		


	}


	printf("%s",string);


	return 0;


}
