#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Node
{
	char info;
	struct Node *left;
	struct Node *right;
};

struct Stack
{
	int top;
	unsigned capacity;
	int *array;
	struct Node *arrayStack[100];
};

struct Stack *createStack(unsigned capacity)
{
	struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));

	if (!stack)
		return NULL;

	stack->top = -1;
	stack->capacity = capacity;

	stack->array = (int *)malloc(stack->capacity * sizeof(int));

	return stack;
}

int isEmpty(struct Stack *stack)
{
	return stack->top == -1;
}

char peek(struct Stack *stack)
{
	return stack->array[stack->top];
}

char pop(struct Stack *stack)
{
	if (!isEmpty(stack))
		return stack->array[stack->top--];
	return '$';
}
struct Node *popNode(struct Stack *stack)
{
	if (stack->top == -1)
	{
		return NULL;
	}

	return stack->arrayStack[stack->top--];
}

void push(struct Stack *stack, char op)
{
	stack->array[++stack->top] = op;
}

void pushStS(struct Stack *stack, struct Node *node)
{
	stack->arrayStack[++stack->top] = node;
}

int isOperand(char ch)
{
	return (ch >= 'a' && ch <= 'z') ||
		   (ch >= 'A' && ch <= 'Z') ||
		   (ch >= '0' && ch <= '9') ||
		   (ch >= '[' && ch <= ']');
}

int isNumber(char ch)
{
	return (ch >= '0' && ch <= '9');
}

int isSign(char ch)
{
	return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int toDigit(char ch)
{
	return ch - '0';
}

int Prec(char ch)
{
	switch (ch)
	{
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;
	}
	return -1;
}

char *infixToPostfix(char *exp)
{
	int i, k;

	struct Stack *stack = createStack(strlen(exp));
	if (!stack)
		return "Error";

	for (i = 0, k = -1; exp[i]; ++i)
	{

		if (isOperand(exp[i]))
			exp[++k] = exp[i];
		else if (exp[i] == '(')
			push(stack, exp[i]);

		else if (exp[i] == ')')
		{
			while (!isEmpty(stack) && peek(stack) != '(')
				exp[++k] = pop(stack);
			if (!isEmpty(stack) && peek(stack) != '(')
				return "Error";
			else
				pop(stack);
		}

		else
		{
			while (!isEmpty(stack) && Prec(exp[i]) <= Prec(peek(stack)))
				exp[++k] = pop(stack);
			push(stack, exp[i]);
		}
	}

	while (!isEmpty(stack))
		exp[++k] = pop(stack);

	exp[++k] = '\0';

	return exp;
}

struct Node *newNode(char data)
{
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

	temp->info = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

struct Node *buildTree(char postfix[])
{
	struct Stack *stack = createStack(strlen(postfix));

	struct Node *t, *t1, *t2;

	for (int i = 0; i < strlen(postfix); i++)
	{
		if (isOperand(postfix[i]))
		{
			t = newNode(postfix[i]);
			pushStS(stack, t);
		}
		else if (isSign(postfix[i]))
		{
			t = newNode(postfix[i]);
			t1 = popNode(stack);
			t2 = popNode(stack);

			t->right = t1;
			t->left = t2;
			pushStS(stack, t);
		}
		else
		{
			printf("Invalid character: %c", postfix[i]);
		}
	}

	t = popNode(stack);

	return t;
}

int evaluate(struct Node *root)
{
	if (root == NULL)
		return 0;
	if (!isSign(root->info))
		return toDigit(root->info);

	int left = evaluate(root->left);
	int right = evaluate(root->right);
	switch (root->info)
	{
	case '+':
		return left + right;
	case '-':
		return left - right;
	case '*':
		return left * right;
	case '/':
		if (right == 0)
		{
			printf("Divide by zero error.");
			exit(0);
		}
		return left / right;
	case isOperand(root->info):
		return root->info;
	}

	return -1;
}
