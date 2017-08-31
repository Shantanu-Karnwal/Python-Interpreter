#include<bits/stdc++.h>
using namespace std;

struct node

{	char symb;	
	int num;
	bool ischar;
	bool isint;
	node * lptr;
	node * rptr;
};

void input(node * &exp)

{	cin>>exp->symb;
	cin>>exp->num;
	cin>>exp->ischar;
	cin>>exp->isint;

	exp->lptr = NULL;
	exp->rptr = NULL;

	string left,right;
	cin>>left;
	if(left == "true")
		input(exp->lptr);
	cin>>right;
	if(right == "true")
		input(exp->rptr);	

}

void tobinary(int x)

{	int mask = 1 << (sizeof(x) * 8 - 1);

	for(int i = 0; i < sizeof(x) * 8; i++)
	{
		if((x & mask) == 0)
			cout << '0' ;
		else
			cout << '1' ;
		mask  >>= 1;
	}
	cout<<"\n";
}

void inorder(node* exp)

{	if(exp == NULL)
		return;
	inorder(exp->lptr);
	if(exp->ischar == true)
		cout<<exp->symb<<" ";
	else if(exp->isint == true)
		cout<<exp->num<<" ";
	else if(exp->isint == false)
		tobinary(exp->num);
	inorder(exp->rptr);
}

int typecheck(node * &exp)

{	if(exp == NULL)
		return 0;
	int b1,b2;	
	if(exp->ischar == '+')
	{	b1 = typecheck(exp->lptr);
		b2 = typecheck(exp->rptr);
		if(b1 == b2 && b1 == 1 && b2 == 1)
			return 1;
		else 
			return 0;
	}
	else if(exp->ischar == '>')
	{	b1 = typecheck(exp->lptr);
		b2 = typecheck(exp->rptr);
		if(b1 == b2 && b1 == 1 && b2 == 1)
			return 1;
		else if(b1 == b2 && b1 == 2 && b2 == 2)
			return 2;
		else
			return 0;
	}
	else if(exp->ischar == '!')
	{	b2 = typecheck(exp->rptr);
		if(b2 == '2')
			return 2;
		else 
			return 0; 
	}
	else if(exp->isint == true)
	{	return 1;
	}
	else if(exp->isint == false)
	{	return 2;
	}
	else
	{	return 0;
	}
}

int main()

{	node * exp;
	input(exp);
	int type;
	type = typecheck(exp);
	if(type == 0)
		cout<<"Type mismatch!! Error !!";
	else if(type == 1)
		cout<"Type Matches -> Integer type expressiom";
	else if(type == 2)
		cout<<"Type Matches -> Binary type expression";		
	return 0;
}
