#include<bits/stdc++.h>
using namespace std;

int getweight(char op)

{
	int wgt;
	if(op == '+' || op == '-')
		wgt = 1;
	else if(op == '*' || op == '/')
		wgt = 2;
	return wgt;
}

int morepreference(char op1, char op2)

{
	int op1w = getweight(op1);
	int op2w = getweight(op2);
	if(op1w >= op2w)
		return true;
	else
		return false;
}

string intopost(string st2)		//converting the infix expression to postfix

{	
	string::iterator i;
	string::iterator j;
	int pref;			//preference
	stack<char> stk;
	string post = "";
	int k;	
	
	for(k = 0; k < st2.length(); k++)
	{
		if((st2[k] == '+') || (st2[k] == '-') || (st2[k] == '*') || (st2[k] == '/'))
		{
			//post = post + " ";
			while(!stk.empty() && morepreference(stk.top(),st2[k]))
			{		
				post = post + stk.top() + " ";
				stk.pop();
//				cout<<"Hello\n";
			}
			stk.push(st2[k]); 
			//post = post + " ";
		}
		
		else if((st2[k] >= 'a' && st2[k] <= 'z') || (st2[k] >= 'A' && st2[k] <= 'Z') || (st2[k] >= '0' && st2[k] <= '9'))
		{	
			post = post + st2[k];
			if((st2[k+1] == '+') || (st2[k+1] == '-') || (st2[k+1] == '*') || (st2[k+1] == '/'))
			{	post = post + " ";	
				continue;
			}
			else
			{	k++;
				post = post + st2[k];	
			}
			post = post + " ";
		} 		
				
		//cout<<st2<<'\n';
		
	}
	while(!stk.empty()) 
	{
		post = post + stk.top();
		stk.pop();
	}
	return post;
} 

int evaluate(char op, int op1, int op2)

{	if(op == '+') 
		return op1 +op2;
	else if(op == '-') 
		return op1 - op2;
	else if(op == '*') 
		return op1 * op2;
	else if(op == '/') 
		return op1 / op2;

}

int evalpost(string st)

{		
	stack<int> stk;
	int i;	
	for(i=0;i<st.length();i++)
	{	if(st[i] == ' ')
			continue;	
		else if((st[i] == '+') || (st[i] == '-') || (st[i] == '*') || (st[i] == '/'))
		{	int op2 = stk.top();
			stk.pop();
			int op1 = stk.top();
			stk.pop();
			int res = evaluate(st[i],op1,op2);
			stk.push(res); 
		}
		else if(st[i] >= '0' && st[i] <='9')
		{
			int op = 0;
			while(i < st.length() && st[i] >= '0' && st[i] <='9')
			{	op = (op * 10) + (st[i] - '0');
				i++;			
			}	
			i--;
			stk.push(op);
						
		}

	}
	return stk.top();
}

string int2str (int num)

{
     ostringstream strng;
     strng << num;
     return strng.str();
}

int main()

{
	cout<<"Python Interpreter\nEnter quit() or exit() to Exit\n";
	string::iterator i;
	string::iterator j;
	string st;
	string st2;
	string st3;
	int exp;
	int k;
	int pos;
	char names [100];
	int vals [100];	
	do
	{	
		cout<<">>> ";	
		getline(cin,st);

		st.erase(std::remove(st.begin(), st.end(), ' '), st.end());	//removes all the whitespace from the entered sentence
		//cout<<st<<'\n';
		if(st.find("=") != string::npos)
		{
			size_t equal = st.find("=");
			st2 = st.substr(equal+1);
			if(st2.find_first_not_of("0123456789+-*/") == string::npos)			
			{	st2 = intopost(st2);
				exp = evalpost(st2);
//				names[st[0] - 'a'] = st[0];
				vals[st[0] - 'a'] = exp;
			}			
			else
			{	
				st3 = "";
				for(k = 0;k < st2.length();k++)
				{	if(st2[k] >= 'a' && st2[k] <= 'z')
					{	pos = st2[k] - 'a';
						//string st_tmp = int2str(vals[pos]);	
						st3 = st3 + int2str(vals[pos]);	
					}
					else
					{	st3 = st3 + st2[k];
					}					
				}			
				st3 = intopost(st3);
				exp = evalpost(st3);
				vals[st[0] - 'a'] = exp;
			}	
			
		}
		else if(st.find("print") !=string::npos)
		{	size_t prnt = st.find("print");
			st2 = st.substr(prnt+5);
			if(st2.find_first_not_of("0123456789+-*/") == string::npos)
			{	st2 = intopost(st2);
				exp = evalpost(st2);
				cout<<exp<<'\n';
			}
			else
			{
				st3 = "";
				for(k = 0;k < st2.length();k++)
				{	if(st2[k] >= 'a' && st2[k] <= 'z')
					{	pos = st2[k] - 'a';
						//string st_tmp = int2str(vals[pos]);	
						st3 = st3 + int2str(vals[pos]);	
					}
					else
					{	st3 = st3 + st2[k];
					}					
				}			
				st3 = intopost(st3);
				exp = evalpost(st3);
				cout<<exp<<'\n';
			}
	
		}
		
				
	}while((st.compare("quit()") != 0) && (st.compare("exit()") != 0));
	
	//cout<<st;
	return 0;
}
