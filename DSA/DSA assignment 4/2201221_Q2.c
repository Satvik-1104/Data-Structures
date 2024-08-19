#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>

#define MAX 100

int top = -1;
char stack[MAX];

int isFull ()
{
  return top == MAX - 1;
}

int isEmpty ()
{
  return top == -1;
}

void push (char item)
{
  if (isFull ())
    printf("OVERFLOW\n");
  top++;
  stack[top] = item;
}
 
int pop ()
{
  if (isEmpty ())
    printf("UNDERFLOW\n");   
  return stack[top--];
}

int peek ()
{
  if (isEmpty ())
    printf("the stack is empty");
  return stack[top];
}
 
int checkIfOperand (char ch)
{
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// In this function larger value means higher precedence 
int precedence (char ch)
{
  switch (ch)
    {
    case '+':
    case '-':
      return 1;

    case '*':
    case '/':
      return 2;

    case '^':
      return 3;
    }
  return -1;
}

int getPostfix (char *expression)
{
  int i, j;

  for (i = 0, j = -1; expression[i]; ++i)
    {
      
      if (checkIfOperand (expression[i]))
	expression[++j] = expression[i];

      else if (expression[i] == ')')
	push (expression[i]);
 
      else if (expression[i] == '(')
	{
	  while (!isEmpty (stack) && peek (stack) != ')')
	    expression[++j] = pop (stack);
	  if (!isEmpty (stack) && peek (stack) != ')')
	    return -1;		// Invalid expression              
	  else
	    pop (stack);
	}
      else
	{
	  while (!isEmpty (stack)
		 && precedence (expression[i]) < precedence (peek (stack)))
	    expression[++j] = pop (stack);
	  push (expression[i]);
	}

    }

  // adding all the elements of the stack to the expressions after all the operands are passed
  while (!isEmpty (stack))
    expression[++j] = pop (stack);
  expression[++j] = '\0';
}

void reverse (char *exp)
{

  int size = strlen (exp);
  int j = size-1, i = 0;
  while (i<j)
    {
      int temp = exp[j];
      exp[j] = exp[i];
      exp[i] = temp;
      j--;
      i++;
    }
}

void InfixtoPrefix (char *exp)
{

  int size = strlen (exp);
  reverse (exp);
  printf("The infix expression in reverse is\n");
  printf("%s\n", exp);
  // when deriving the prefix expression, the law of associativity reverses i.e, if it is from L to R, the operator gets pushed into stack
  getPostfix (exp);
  reverse (exp);
}

int main ()
{
  printf ("Enter the infix expression: ");
  char expression[MAX];
  gets(expression);
  printf ("%s\n", expression);
  InfixtoPrefix (expression);
  printf ("The prefix expression is: ");
  printf ("%s\n", expression);
  return 0;
}