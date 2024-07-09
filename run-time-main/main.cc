//main.cc
#include "emport.h"
#include <stdio.h>

EM_PORT_API(int) show_me_the_answer() {
	return 42;
}

int main() {
	printf("你好，世界！\n");
	return 1;
}