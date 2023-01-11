#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};

struct Stack
{
    int top;
    struct Node *array[100];
};

struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

int isOperand(char ch)
{
    return isdigit(ch);
}

int isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int toDigit(char ch)
{
    return ch - '0';
}

void push(struct Stack *stack, struct Node *t)
{
    stack->array[++stack->top] = t;
}

struct Node *pop(struct Stack *stack)
{
    if (stack->top == -1)
        return NULL;
    return stack->array[stack->top--];
}

struct Node *newNode(char data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
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
            push(stack, t);
        }
        else if (isOperator(postfix[i]))
        {
            t = newNode(postfix[i]);
            t1 = pop(stack);
            t2 = pop(stack);
            if (t1 == NULL || t2 == NULL)
            {
                printf("Invalid postfix expression");
                exit(0);
            }
            t->right = t1;
            t->left = t2;
            push(stack, t);
        }
        else
        {
            printf("Invalid character encountered: %c", postfix[i]);
            exit(0);
        }
    }

    t = pop(stack);
    if (stack->top > -1)
    {
        printf("Invalid postfix expression");
        exit(0);
    }

    return t;
}

int evaluate(struct Node *root)
{
    if (root == NULL)
        return 0;
    if (!isOperator(root->data))
        return toDigit(root->data);

    int left = evaluate(root->left);
    int right = evaluate(root->right);
    switch (root->data)
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
    }
}

int main()
{
    char postfix[] = "231*+9-";
    struct Node *root = buildTree(postfix);
    printf("Value of %s is %d\n", postfix, evaluate(root));

    char test2[] = "a-b";
    struct Node *test = buildTree(test2);
    printf("Value of %s is %d\n", test2, evaluate(test));
    return 0;
}