#include <iostream>
#include <stack>
using namespace std;

int postfixEvaluation(string inflix);
int prefixEvaluation(string inflix);
bool isDigit(char ch);
bool isOperator(char ch);

int main()
{
    string postflix;
    cout << "Enter postflix Expression: " << endl;
    cin >> postflix;
    cout << "Output: " << postfixEvaluation(postflix) << endl;
}

int postfixEvaluation(string postflix)
{
	int output = 0;
	int number1 = 0;
	int number2 = 0;
	int idx = 0;
	stack<int> st;
	while (postflix[idx] != '\0') 
	{
		if(isDigit(postflix[idx]))
		{
			st.push((int)postflix[idx] - 48);
		}

		else if (isOperator(postflix[idx])) 
		{
			number2 = st.top();
			st.pop();
			number1 = st.top();
			st.pop();

			if (postflix[idx] == '+')
			{
				output = number1 + number2;
			}

			else if (postflix[idx] == '-')
			{
				output = number1 - number2;
			}

			else if (postflix[idx] == '*')
			{
				output = number1 * number2;
			}

			else if (postflix[idx] == '/')
			{
				output = number1 / number2;
			}
			st.push(output);
		}
		idx++;
	}
	return output;
}

int prefixEvaluation(string prefix)
{
	int output = 0;
	int number1 = 0;
	int number2 = 0;
	stack<int> numbers;
	for (int i = prefix.size() - 1; i >= 0; i--)
	{
		if (isDigit(prefix[i]))
		{
			numbers.push((int)prefix[i] - 48);
		}

		else if (isOperator(prefix[i]))
		{
			number1 = numbers.top();
			numbers.pop();
			number2 = numbers.top();
			numbers.pop();

			if (prefix[i] == '+')
			{
				output = number1 + number2;
			}

			else if (prefix[i] == '-')
			{
				output = number1 - number2;
			}

			else if (prefix[i] == '*')
			{
				output = number1 * number2;
			}

			else if (prefix[i] == '/')
			{
				output = number1 / number2;
			}
			numbers.push(output);
		}
	}
	output = numbers.top();
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