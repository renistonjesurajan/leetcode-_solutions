#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isValid(char* s) {
    int len = strlen(s);
    
    // An odd length string can never be valid
    if (len % 2 != 0) {
        return false;
    }
    
    // Allocate memory for the stack (worst case size is len)
    char* stack = (char*)malloc(len * sizeof(char));
    int top = -1; // Index tracker for the top of the stack
    
    for (int i = 0; i < len; i++) {
        char current = s[i];
        
        // If it's an opening bracket, push to stack
        if (current == '(' || current == '{' || current == '[') {
            stack[++top] = current;
        } 
        // If it's a closing bracket
        else {
            // Stack is empty means no matching opening bracket
            if (top == -1) {
                free(stack);
                return false;
            }
            
            // Pop the top element and check for a match
            char topChar = stack[top--];
            if ((current == ')' && topChar != '(') ||
                (current == '}' && topChar != '{') ||
                (current == ']' && topChar != '[')) {
                free(stack);
                return false;
            }
        }
    }
    
    // If top is -1, all brackets were successfully matched and popped
    bool result = (top == -1);
    free(stack); // Always clean up allocated memory
    return result;
}
