#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#pragma warning(disable:4996)

//.h的都为C头文件
// C++的头文件没有 ".h" 后缀, 
// 并且C++头文件中定义的所有成员都属于std这个命名空间

/*
C++输入输出:
	输入cin: 支持连续输入--> cin >> 变量 >> 变量...;
	输出cout: 支持连续输出 --> cout << 变量 << 变量...;
	不需要指定输出输入的格式, 会识别, 还可以输入输出不同的格式

*/
using std::cout;
using std::cin;

void testInput(){
	int a = 10;
	printf("%d\n", a);
	printf("C++ 输出:\n");
	std::cout << a << "\n"; // 输出, 可以理解为a 流到了屏幕上
	cout << a << "\n"; // 支持连续输入输出

	float b = 0;
	scanf("%d", &a);
	scanf("%f", &b);

	cout << a << " " << b << "\n";

	cin >> a >> b; // 输入 函数重载 + 运算符重载 + 引用
	cout << a << " " << b << "\n";
}

// 缺省参数: 定义函数和声明函数时给参数一个默认值 如果没有别的需求 就直接执行默认值(手机套餐)
// void fun4(int a = 100); 声明
// 函数定义和声明只能选一个给默认值 如果两个同时出现就是重定义
using std::endl; // endl 相当于 "\n"
void fun4(int a = 100){
	cout << a << endl;
}
// 全缺省
void fun5(int a = 1, int b = 2, int c = 3){
	cout << a << b << c << endl;
}
// 半缺省 : 从右到左的顺序给参数默认值, 部分参数没有设置默认值
void fun6(int a, int b = 1, int c = 2){
	cout << a << b << c << endl;
}
// 半缺省从右到左给默认值, 中间不能有间隔(不能有没给参数的), 可以左边的(或者所有)全都没有值, 
void fun7(int a, int b, int c, int d){
	cout << a << b << c << d << endl;
}

int main1(){
	testInput();
	fun4(); // 标配 输出100
	fun4(5); // 选配 个性化 输出5

	fun5();
	fun5(10);
	fun5(10, 20);
	fun5(10, 20, 30);

	// 至少传一个参数
	fun6(0);
	fun6(10, 20);
	fun6(10, 20, 30);

	fun7(100, 200, 300, 400);

	system("pause");
	return 0;
}

// 函数重载: 前提: 多个函数在同一个作用域下(同一个系列的不同版本的手机, 都是iphone)
// 函数名相同 可以参数信息(个数, 参数类型, 参数顺序)不同, 

void fun7(int a, float b, char c){
	cout << "fun7(int a, float b, char c)" << endl;
}
// 参数个数不同
void fun7(int a){
	cout << "fun7(int a)" << endl;
}
// 参数类型不同
void fun7(char a, char b, char c){
	cout << "fun7(char a, char b, char c)" << endl;
}
// 参数顺序不同
void fun7(char c, float b, int a){
	cout << "fun7(char c, float b, int a)" << endl;
}

void test(){
	int a = 10;
	float b = 2.3;
	char c = 'c';
	fun7(a, b, c);
	fun7(a);
	fun7(c, c, c);
	fun7(c, b, a);
}
// 这三个不构成重载 (函数名不一样)
int addInt(int a, int b){
	return a + b;
}
char addChar(char a, char b){
	return a + b;
}
float addFloat(float a, float b){
	return a + b;
}
//这三个构成函数重载 (类型不一样也可以 只要函数名相同)
int add(int a, int b){
	return a + b;
}
char add(char a, char b){
	return a + b;
}
float add(float a, float b){
	return a + b;
}

void test2(){

}

// 函数重载
// C++允许 C不允许
// C编译器: int sub(int,int)   底层的函数名为_sub
// C++编译器: int sub(int, int)  底层的函数名为...(不认识)
// g++编译器: int sub(int, int)  底层的函数名为 _Z3subii, 3为函数名长度, 后面的ii为参数类型(i,f,c)
// C编译器函数名的修饰规则: 只包含函数名
// C++编译器函数名的修饰规则为: 函数名+参数信息(顺序, 个数, 类型) 
// 导致C++支持函数重载, C不支持
extern "C" int sub(int a, int b);
int main(){
	test();
	test2();
	system("pause");
	return 0;

}

// 链接:
// 文件之间的交互, 汇编阶段产生导出符号表和未解决符号表(函数名和起始的位置) 链接的时候去其他文件中找
// 预处理: 头文件展开, 去注释, 条件编译, 宏替换
// 编译: 语法检查, 把源代码编译成汇编代码
// 汇编: 把汇编代码编译成机器码 --> 目标文件(.o, .obj), --> 导出符号表 ,未解决符号表
// 链接: 把所有的机器码转换成一个可执行文件, --> 找到所有指令的地址

/*a.cpp
int funa(int a, int b){}
// 生成.obj文件, 还有导出符号表: funa, 0X45(地址)
// 未解决符号表: 空

#include "a.h"
b.cpp
int funb(int a){}
int main(){
	funa(1, 2);
	funb(3);
}
// 生成b.obj
//导出符号表: funb 0X63(地址)
// 未解决符号表: funa?(去找funa的地址, 从而找到funa的所有
*/