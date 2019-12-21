#ifndef local_library_h
#define local_library_h
#include <stdio.h>
#include "books.h"
extern int N;
extern Book books[];
const Book* firstinlibrary(void);
const Book* lastinlibrary(void);
char* findnamebynumber(int booknum);
#endif /* local_library_h */
