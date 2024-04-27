#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 50

int top = -1;
char postfix[MAX];

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
		postfix[top] = c;
	}
}

int pop(){
	if(isEmpty()) {
		printf("Stack Underflow!");
        return 0;
    }
    char c=postfix[top];
	top--;
	return c;
}

int postEvaluate(){
    int i, a, b;
    for(i=0; i<strlen(postfix); i++){
        if(postfix[i] >= '0' && postfix[i] <= '9'){
            push(postfix[i] - '0');
        } else {
            a = pop();
            b = pop();

            switch(postfix[i]){
                case '+':
                    push(b+a);
                    break;
                case '-':
                    push(b-a);
                    break;
                case '*':
                    push(b*a);
                    break;
                case '/':
                    push(b/a);
                    break;
                case '^':
                    push(pow(b,a));
                    break;
                case '%':
                    push(b%a);
                    break;
            }
        }
    }
    return pop();
}

int main(){

    printf("Enter a postfix expression:");
    scanf("%s", postfix);

    printf("%d",postEvaluate());

    return 0;
}
