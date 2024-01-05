#include <iostream>
#include <stack>
using namespace std;

string postfixFn(string infix);
string prefixFn(string infix);
bool isOperator(char ch);
bool isDigit(char ch);
int precedence(char newOperator);

int main()
{
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;
    cout << "Postfix: " << postfixFn(infix) << endl;
    cout << "Prefix: " << prefixFn(infix) << endl;
    return 0;
}

string prefixFn(string infix)
{
	string output;
	stack<char> operands;
	stack<char> operators;

	for (int i = infix.size() - 1; i >= 0; i--)
	{
		if (isDigit(infix[i]))
		{
			operands.push(infix[i]);
		}

		else if (infix[i] == ')')
		{
			operators.push(infix[i]);
		}

		else if (infix[i] == '(')
		{
			while (!operators.empty() && operators.top() != ')')
			{
				operands.push(operators.top());
				operators.pop();
			}
			if (!operators.empty()) {
				operators.pop();
			}
		}

		else if (isOperator(infix[i]))
		{
			if (operators.empty())
			{
				operators.push(infix[i]);
			}

			else if (precedence(operators.top()) >= precedence(infix[i]))
			{
				operators.push(infix[i]);
			}

			else
			{
				while (!operators.empty() && precedence(operators.top()) < precedence(infix[i]))
				{
					operands.push(operators.top());
					operators.pop();
				}
				operators.push(infix[i]);
			}

		}
	}
	while (!operators.empty())
	{
		operands.push(operators.top());
		operators.pop();
	}
	while (!operands.empty())
	{
		output += operands.top();
		operands.pop();
	}
	return output;
}

string postfixFn(string infix)
{
	string output;
	stack<char> st;
	int idx = 0;
	while (infix[idx] != '\0')
	{
		if (isDigit(infix[idx]))
		{
			output += infix[idx];
		}

		else if (infix[idx] == '(')
		{
			st.push(infix[idx]);
		}

		else if (infix[idx] == ')')
		{
			while (!st.empty() && st.top() != '(')
			{
				output += st.top();
				st.pop();
			}
			st.pop();
		}


		else if (isOperator(infix[idx]))
		{
			if (st.empty())
			{
				st.push(infix[idx]);
			}

			else if (precedence(infix[idx]) > precedence(st.top()))
			{
				st.push(infix[idx]);
			}

			else
			{
				while (!st.empty() && (precedence(infix[idx]) >= precedence(st.top())))
				{
					output += st.top();
					st.pop();
				}
				st.push(infix[idx]);
			}
		}
		idx++;
	}
	while (!st.empty())
	{
		output += st.top();
		st.pop();
	}
	return output;
}

bool isDigit(char ch)
{
    if(ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7'
    || ch == '8' || ch == '9' )
    {
        return true;
    }
    return false;
}

bool isOperator(char ch)
{
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return true;
    }
    return false;
}

int precedence(char newOperator)
{
    if(newOperator == '+' || newOperator == '-')
    {
        return 1;
    }

    else if(newOperator == '*' || newOperator == '/')
    {
        return 2;
    }

	else if(newOperator == '(' || newOperator == ')')
	{
		return 3; 
	}
	return 0;
}
