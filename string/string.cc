#ifndef EM_PORT_API
#	if defined(__EMSCRIPTEN__)
#		include <emscripten.h>
#include <stdio.h>
#		if defined(__cplusplus)
#			define EM_PORT_API(rettype) extern "C" rettype EMSCRIPTEN_KEEPALIVE
#		else
#			define EM_PORT_API(rettype) rettype EMSCRIPTEN_KEEPALIVE
#		endif
#	else
#		if defined(__cplusplus)
#			define EM_PORT_API(rettype) extern "C" rettype
#		else
#			define EM_PORT_API(rettype) rettype
#		endif
#	endif
#endif
#include <stdio.h>
#include <cstdlib>

EM_PORT_API(void*) xmalloc(int len) {
  // if(int_addr == nullptr) {
  //   int_addr = new int[100];
  //   for(int i = 0; i < 100; i++) {
  //     int_addr[i] = (i + 1) * 10000;
  //   }
  // }

  return malloc(len);
  
	// return &g_int;
}

EM_PORT_API(void) xfree(void *p) {
  free(p);
	// return &g_int;
}


EM_PORT_API(const char*) get_string() {
	static const char str[] = "Hello, wolrd! 你好，世界！";
	return str;
}

EM_PORT_API(void) print_string(char* str) {
	printf("%s\n", str);
}