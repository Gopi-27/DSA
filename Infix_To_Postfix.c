#include <stdio.h>
#include <string.h>
#include<stdlib.h>
struct Node{
	struct Node* prev;
	char ch;
	struct Node* next;
};

struct Node* Top = NULL;
// Function to add operator at the  top of stack
void Push(char val){
	struct Node* nn = (struct Node*)malloc(sizeof(struct Node));
	nn->prev = NULL;
	nn->ch = val;
	nn->next = NULL;
	if(Top == NULL){
		Top = nn;
		return ;
	}
	nn->prev = Top;
	Top->next = nn;
	Top = nn;
	return ;
}
// Function To delete the operator at Top of the stack
void Pop(){
	Top = Top->prev;
	return;
}
// Function To Check Wheather The Stack is Empty or not
int IsEmpty(){
	if(Top == NULL)return 1;
	else return 0;
}
// Function to Assign the Values for operators in specific order
int Value(char c){
	if(c == '+' || c == '-')return 1;
	else if(c == '*' || c == '/' )return 2;
	else return 3;
	
}
// Function to convert infix expression to postfix expression
char* infixToPostfix(char* str) {
  int idx = 0;
	for(int i = 0; str[i] != '\0'; i++){
    // Checking Wheather the present str[i] is operator or '(' or ')'
		  if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '^' || str[i] == '/' || str[i] == '(' || str[i] == ')'){
                // Checking for  '(', if it is true Just push to  stack
          			if(str[i] == '('){
          				Push(str[i]);
                  // Cheking for ')' if it is true Just add the operators to answer form here to the open bracket
          			}else if(str[i] == ')'){
            				while( Top->ch != '('){
            					str[idx++] = Top->ch;
            					Pop();
            				}
                  // and finally pop the open bracket
            				Pop();
          			}else {
                  // if it is an operator ,  add the opearators  to answer until , the  value of Top operator is lessthan or equal to the present operator  and before the open bracket
            				while( !IsEmpty()  && Top->ch != '(' && Value(str[i]) <= Value(Top->ch) ){
            					str[idx++] = Top->ch;
            					Pop();
            				}
                  // Finally Push The present operator
            				Push(str[i]);					
          			}
          					
		}else {
        // if str[i] is other than operator just adding it to our answer
  			str[idx++] = str[i];
		}
    
	}
  // Finally adding all the operator that are left in our stack to answer
	while(!IsEmpty()){
		str[idx++] = Top->ch;
		Pop();
	}
  // Terminating the answer 
	str[idx] = '\0';
	return str;
    
}

int main() {
      char exp[1000];
      scanf("%s", exp); // Read the expression as a string
      // Call the infixToPostfix function and print the result
      printf("%s\n", infixToPostfix(exp));
      return 0;
}



