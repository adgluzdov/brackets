struct MyList
{
	char s;
	MyList *next;
};

void push( MyList **l, char s)
{
		MyList *a=new MyList;
		a->next=*l;
		a->s=s;
		*l=a;
}