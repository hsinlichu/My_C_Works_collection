#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<process.h>
#include<string>
#include<sstream>

#define Max 80

void inToPostfix(char*, char*);
int priority(char);
int result(char*);
int calculate(char, int, int);

int main() {
	char infix[Max] = { '\0' };
	while (~scanf("%s",&infix)) {
		printf("%s", infix);
		printf("%d", result(infix));
	}
	system("pause");
	return 0;
}

void inToPostfix(char* infix, char* postfix) {
	char stack[Max] = { '\0' };
	int i, j, top;
	for (i = 0, j = 0, top = 0;infix[i] != '\0';i++) {
		switch (infix[i]) {
		case '(':
			stack[++top] = infix[i];
			break;
		case'+':case'-':case'*':case'/':case'%':
			while (priority(stack[top]) >= priority(infix[i])) {
				postfix[j++] = stack[top--]; //let the high priority more close to the number to calculate first
			}
			stack[++top] = infix[i];
			break;
		case')':
			while (stack[top] != '(') {
				postfix[j++] = stack[top--];
			}
			top--;
			break;
		default:
			postfix[j++] = infix[i];
		}

	}
	while (top > 0) {
		postfix[j++] = stack[top--]; //pure number directly output
	}

}

int priority(char oper) {
	switch (oper) {
	case'+':case'-':return 1;
	case'*':case'/':case'%':return 2;
	default: return 0;
	}
}

int result(char* infix) {
	char postfix[Max] = { '\0' };
	char opnd[2] = { '\0' };
	int stack[Max] = { 0 };

	inToPostfix(infix, postfix);

	int top, i;
	for (top = 0, i = 0;postfix[i] != '\0';i++) {
		switch (postfix[i]) {
		case'+':case'-':case'*':case'/':case'%':
			stack[top - 1] = calculate(postfix[i], stack[top - 1], stack[top]);
			top--;
			break;
		default:
			opnd[0] = postfix[i];
			stack[++top] = (int)atof(opnd);
		}
	}

	return stack[top];
}

int calculate(char op, int p1, int p2) {
	switch (op) {
	case'+': return p1 + p2;
	case'-': return p1 - p2;
	case'*': return p1 * p2;
	case'/': return p1 / p2;
	case'%': return p1 % p2;
	}


}
