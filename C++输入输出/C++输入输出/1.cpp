#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#pragma warning(disable:4996)

//.h�Ķ�ΪCͷ�ļ�
// C++��ͷ�ļ�û�� ".h" ��׺, 
// ����C++ͷ�ļ��ж�������г�Ա������std��������ռ�

/*
C++�������:
	����cin: ֧����������--> cin >> ���� >> ����...;
	���cout: ֧��������� --> cout << ���� << ����...;
	����Ҫָ���������ĸ�ʽ, ��ʶ��, ���������������ͬ�ĸ�ʽ

*/
using std::cout;
using std::cin;

void testInput(){
	int a = 10;
	printf("%d\n", a);
	printf("C++ ���:\n");
	std::cout << a << "\n"; // ���, �������Ϊa ��������Ļ��
	cout << a << "\n"; // ֧�������������

	float b = 0;
	scanf("%d", &a);
	scanf("%f", &b);

	cout << a << " " << b << "\n";

	cin >> a >> b; // ���� �������� + ��������� + ����
	cout << a << " " << b << "\n";
}

// ȱʡ����: ���庯������������ʱ������һ��Ĭ��ֵ ���û�б������ ��ֱ��ִ��Ĭ��ֵ(�ֻ��ײ�)
// void fun4(int a = 100); ����
// �������������ֻ��ѡһ����Ĭ��ֵ �������ͬʱ���־����ض���
using std::endl; // endl �൱�� "\n"
void fun4(int a = 100){
	cout << a << endl;
}
// ȫȱʡ
void fun5(int a = 1, int b = 2, int c = 3){
	cout << a << b << c << endl;
}
// ��ȱʡ : ���ҵ����˳�������Ĭ��ֵ, ���ֲ���û������Ĭ��ֵ
void fun6(int a, int b = 1, int c = 2){
	cout << a << b << c << endl;
}
// ��ȱʡ���ҵ����Ĭ��ֵ, �м䲻���м��(������û��������), ������ߵ�(��������)ȫ��û��ֵ, 
void fun7(int a, int b, int c, int d){
	cout << a << b << c << d << endl;
}

int main1(){
	testInput();
	fun4(); // ���� ���100
	fun4(5); // ѡ�� ���Ի� ���5

	fun5();
	fun5(10);
	fun5(10, 20);
	fun5(10, 20, 30);

	// ���ٴ�һ������
	fun6(0);
	fun6(10, 20);
	fun6(10, 20, 30);

	fun7(100, 200, 300, 400);

	system("pause");
	return 0;
}

// ��������: ǰ��: ���������ͬһ����������(ͬһ��ϵ�еĲ�ͬ�汾���ֻ�, ����iphone)
// ��������ͬ ���Բ�����Ϣ(����, ��������, ����˳��)��ͬ, 

void fun7(int a, float b, char c){
	cout << "fun7(int a, float b, char c)" << endl;
}
// ����������ͬ
void fun7(int a){
	cout << "fun7(int a)" << endl;
}
// �������Ͳ�ͬ
void fun7(char a, char b, char c){
	cout << "fun7(char a, char b, char c)" << endl;
}
// ����˳��ͬ
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
// ���������������� (��������һ��)
int addInt(int a, int b){
	return a + b;
}
char addChar(char a, char b){
	return a + b;
}
float addFloat(float a, float b){
	return a + b;
}
//���������ɺ������� (���Ͳ�һ��Ҳ���� ֻҪ��������ͬ)
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

// ��������
// C++���� C������
// C������: int sub(int,int)   �ײ�ĺ�����Ϊ_sub
// C++������: int sub(int, int)  �ײ�ĺ�����Ϊ...(����ʶ)
// g++������: int sub(int, int)  �ײ�ĺ�����Ϊ _Z3subii, 3Ϊ����������, �����iiΪ��������(i,f,c)
// C�����������������ι���: ֻ����������
// C++�����������������ι���Ϊ: ������+������Ϣ(˳��, ����, ����) 
// ����C++֧�ֺ�������, C��֧��
extern "C" int sub(int a, int b);
int main(){
	test();
	test2();
	system("pause");
	return 0;

}

// ����:
// �ļ�֮��Ľ���, ���׶β����������ű��δ������ű�(����������ʼ��λ��) ���ӵ�ʱ��ȥ�����ļ�����
// Ԥ����: ͷ�ļ�չ��, ȥע��, ��������, ���滻
// ����: �﷨���, ��Դ�������ɻ�����
// ���: �ѻ��������ɻ����� --> Ŀ���ļ�(.o, .obj), --> �������ű� ,δ������ű�
// ����: �����еĻ�����ת����һ����ִ���ļ�, --> �ҵ�����ָ��ĵ�ַ

/*a.cpp
int funa(int a, int b){}
// ����.obj�ļ�, ���е������ű�: funa, 0X45(��ַ)
// δ������ű�: ��

#include "a.h"
b.cpp
int funb(int a){}
int main(){
	funa(1, 2);
	funb(3);
}
// ����b.obj
//�������ű�: funb 0X63(��ַ)
// δ������ű�: funa?(ȥ��funa�ĵ�ַ, �Ӷ��ҵ�funa������
*/