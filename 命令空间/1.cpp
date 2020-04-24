#include "head1.h"
#include <stdio.h>
#include <stdlib.h>
/*
命名空间就是为了避免命名冲突 (当多个变量定义了相同的名字, 但又想让他们共存, 就用命名空间, 
	就像不同班级不同学校有相同名字的人一样, 需要在姓名前加标签, 消防1701XXX, 只是给成员加了个标签而已, 定义在了不同的地方而已)
命名空间定义: 
	1. namespace + 命名空间名称 + {成员定义的地方}
	2. 嵌套定义: namespace + 名称 + {namespace + 名称 + {}..)
	3. 同一个命名空间可以定义多个片段
命名空间内成员的使用方式
	1. 完整的作用域 + 成员: 命名空间名称::(如果有嵌套,加嵌套的命名空间名称)::成员名称
	2. 引进成员: using + 命名空间名称::成员名称
	3. 展开命名空间: using namespace 命名空间名称 --> 不建议使用(所有变量都暴露在全局域中, 可能会导致成员重定义)

	tip: 命名空间可以定义别名, 也支持嵌套命名空间的别名定义
		namespace 别名 = 完整命名空间(支持嵌套)

*/
// 全局域
int global = 10;

int fun(){
	// 局部域
	int a = 1;

}
// 文件域
static void fun2(){

}

// 命名空间具体使用
// 1. 命名空间 + ::(作用域限定符) + 成员(变量/函数)  命名空间相当于姓, 后面的成员相当于名
// 全局域, 没有名字
void testNamespace(){
	
	::global = 10;
	head1::global = 20;
	head1::val2 = 10;
	head1::internal::val = 1;// 嵌套的作用域也要写上

}

// 成员使用方式:
// 2. using + 完整作用域的变量
using head1::internal::val;

// 可以给命名空间起别名, 简化命名空间的书写
namespace hi = head1::internal;

void testNamespace2(){
	val = 1;// 全局不需要加作用域
	// 新的变量需要加作用域
	head1::val2 = 2;
	head1::fun2();
	head1::fun3();
	head1::global = 1;
	hi::val = 2;
}

// 成员的使用方式
// 3. using + namespace + 命名空间名称
// 相当于把命名空间 的所有成员暴露在全局域中
// 不建议使用
//using namespace head1;
//void testNamespace(){
//	va12 = 1;
//	fun2(); // 命名冲突
//	fun3();
//	global = 1;// 和全局域中的global造成命名冲突
//}
int main(){

	system("pause");
	return 0;
}