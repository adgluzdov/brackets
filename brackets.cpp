#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include "MyList.h"
using namespace std;

bool isCorrect(char*);
void printResult(char*);

void main()
{
	printResult("()");
	printResult(")(");
	printResult(")");
	printResult("");
	printResult("(){}[]");
	printResult("{}[()]");
	printResult("[({(}))]");
	printResult("(){}[({})]");
	printResult("()((())))");
	printResult("{(}[)]");
	printResult("{[())]}");
	getchar ();
}


bool isCorrect(char* brackets)
{
	MyList *myList=0;
	for(int i=0;i<strlen(brackets);i++)
	{
		if ((brackets[i]=='[') || (brackets[i]=='{') || (brackets[i]=='('))
			push(&myList,brackets[i]);
		else
		{	
			if(myList==0)
				return false;
			if (myList->s!='[' && brackets[i]==']')
					return false;
			if (myList->s!='{' && brackets[i]=='}')
				return false;
			if (myList->s!='(' && brackets[i]==')')
				return false;
			myList=myList->next;
		}
	}
	
	if (myList==0)
		return true;
	else
		return false;
}

void printResult(char *str)
{
		cout<< str << " - " << isCorrect(str) <<endl;
}