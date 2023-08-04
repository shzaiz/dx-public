#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>

void printCallStack() {
    const int max_depth = 50;
    void* call_stack[max_depth];
    int num_frames = backtrace(call_stack, max_depth);
    char** symbols = backtrace_symbols(call_stack, num_frames);

    if (symbols == NULL) {
        perror("backtrace_symbols");
        return;
    }

    for (int i = 0; i < num_frames; i++) {
        printf("%s\n", symbols[i]);
    }

    free(symbols);
}


int fib(int n){
	printCallStack();
	if(n<=1) return n;
	return fib(n-1)+fib(n-2);
}

int main(){
	fib(5);	
	return 0;
}