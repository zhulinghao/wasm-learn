//mem.cc
#include "emport.h"
#include <stdio.h>
#include <cstdlib>



// int g_int = 42;
// double g_double = 3.1415926;

int * int_addr = nullptr;
int * int_addr2 = nullptr;

EM_PORT_API(int*) get_int_ptr2() {
  if(int_addr2 == nullptr) {
    int_addr2 = new int[100];
    for(int i = 0; i < 100; i++) {
      int_addr2[i] = (i + 1) * 10000;
    }
  }
  return int_addr2;
	// return &g_int;
}

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


EM_PORT_API(int *) release_int() {
  if(int_addr == nullptr) {
    return int_addr;
  }
  for(int i = 0; i < 100; i++) {
    int_addr[i] = 0;
  }
  delete[] int_addr;
  // int_addr = nullptr;
  return get_int_ptr2();
	// return &g_int;
}

// EM_PORT_API(int *) get_xx() {
//   int a = 123;
//   return &a;
// 	// return &g_int;
// }

// EM_PORT_API(double*) get_double_ptr() {
// 	return &g_double;
// }

// EM_PORT_API(void) print_data() {
// 	printf("C{g_int:%d}\n", g_int);
// 	printf("C{g_double:%lf}\n", g_double);
// }


