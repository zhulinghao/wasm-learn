#include "emport.h"
#include <emscripten.h>
#include <stdio.h>

int main() {
	EM_ASM(console.log('你好，Emscripten！'));
  EM_ASM(var k = 0.22;console.log('The answer is:', k););

  int sum = EM_ASM_({return $0 + $1 + $2;}, 1, 0.1, 3);
	printf("sum(1, 2, 3): %d\n", sum);

	return 0;
}