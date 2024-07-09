#include "emport.h"
#include <emscripten.h>
#include <stdio.h>
#include <iostream>

int main(){
	double now = EM_ASM_DOUBLE_V(return performance.now());
  printf("NOW: %lf\n", now);
	return 0;
}
