#ifndef LOG_FOR_HAN
#define LOG_FOR_HAN
#define SIZE 100
#include <stdio.h>
#if defined(_linux) || defined(_unix)
#define COLOR(msg,code) "\033[0;1;"#code"m" msg "\033[0m"
#define RED(msg)        COLOR(msg,31)
#define GREEN(msg)      COLOR(msg,32)
#define YELLOW(msg)     COLOR(msg,33)
#define BLUE(msg)       COLOR(msg,34)

//EXPECT define
#define EXPECT(a,cmp,b){\
    __typeof(a) __a = (a), __b = (b);\
	if(!((__a) cmp (__b))){\
		printf("%s:%d : Failure\n",__FILE__, __LINE__);\
		printf(YELLOW("Expect: (%s) %s (%s), actual: %d vs %d\n"),\
		#a, #cmp, #b, __a, __b);\
	}\
} 

#define EXPECT_EQ(a,b) EXPECT(a,==,b)
#define EXPECT_NE(a, b) EXPECT(a, !=, b)
#define EXPECT_LT(a, b) EXPECT(a, <, b)
#define EXPECT_LE(a, b) EXPECT(a, <=, b)
//poll all the func
struct Log4hanNode
{
    void (*func)();
    const char *funcname;
}func_arr[SIZE];
int func_cnt = 0

#define TEST(a,b)\
void a##_##b();\
__attribute__((constructor))\
void reg_##a##_##b(){\
    add_func(a##_##b,#a"."#b);\
}\
void a##_##b()
//TEST(a,b){}会被替换

//reg

void add_func(void (*func)(),const char* str_name){
    func_arr[func_cnt].func = func;
    func_arr[func_cnt].funcname = str_name;
    func_cnt++;
    return;
}

int RUN_ALL_TEST(){
    for(int i = 0; i < func_cnt; i++)
	{
		printf(GREEN("[  RUN   ] ") "%s\n", func_arr[i].funcname);
		func_arr[i].func();
    }
	return 0;
}

//usage
/*
TEST(test,funcname){
    EXPECT_XX(funcname(),arg)
    xxxxx
}
*/
#endif
// #endif
#endif