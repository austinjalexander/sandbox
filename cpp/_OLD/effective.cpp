// 1: prefer const and inline to #define
// 2: prefer <iostream> to <stdio.h>
// use << and >> instead of printf and scanf
// 3: prefer new and delete to malloc and free
// 4: prefer c++-style comments
// 5: use the same form in corresponding uses of new and delete
// if: string *stringPtr2 = new string[100];
// then: delete [] stringPtr2;
// 6: use delete on pointer members in destructors
// 7: be prepared for out-of-memory conditions