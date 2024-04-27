#include<stdio.h>
#include<string.h>
#define MAX 50

char infix[MAX], postfix[MAX];
int top = -1;
char stack[MAX];

int isFull(){
	if (top == MAX - 1){
		return 1;
	} else {
		return 0;
	}
}

int isEmpty(){
	if (top == -1){
		return 1;
	} else {
		return 0;
	}
}

void push(char c){
	if(isFull()) {
		printf("Stack Overflow!");
	} else {
		top++;
		stack[top] = c;
	}
}

int pop(){
	if(isEmpty()) {
		printf("Stack Underflow!");
        return 0;
    }
    char c=stack[top];
	top--;
	return c;
}

int priority(char a){
	if(a == "^") {
		return 3;
	} else if(a == "*" || a == "/") {
		return 2;
	} else if(a == "+" || a == "-") {
		return 1;
	} else
		return 0;
}

void inToPost() {
    int i,j=0;
    char symbol,next;
    for(i=0; i<strlen(infix);i++){
        symbol = infix[i];
        switch(symbol){
            case '(':
                push(symbol);
                break;
            case ')':
                while((next = pop())!='('){
                    postfix[j++] = next;
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while(!isEmpty() && priority(stack[top]) >= priority(symbol)){
                    postfix[j++] = pop();
                }
                push(symbol);
                break;
            default:
                postfix[j++] = symbol;

        }
    }

    while(!isEmpty()){
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main(){
	printf("INFIX TO POSTFIX CONVERTOR \n");
	printf("Enter a infix expression: \n");
	gets(infix);
    inToPost();

    int i=0;
    printf("Equivalent postfix expression is:\n");
    while(postfix[i]){
        printf("%c", postfix[i++]);
    }
    return 0;
}
