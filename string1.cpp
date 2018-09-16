#include <cstring>
#include "string1.h"
using std::cin;
using std::cout;

int String::num_strings = 0;

int String::HowMany() {
	return num_strings;
}
//Ŭ���� �ż���

String::String(const char *s) {//C��Ÿ���� ���ڿ��κ��� String�� ����
	len = std::strlen(s);//���ڿ��� ũ�⸦ ����
	str = new char[len + 1];//��� ������ ����
	std::strcpy(str, s);//�����͸� �ʱ�ȭ
	num_strings++;//��ü ī��Ʈ ����
}

String::String() {//����Ʈ ������
	len = 4;
	str = new char[1];
	str[0] = '\0';//����Ʈ ���ڿ�
	num_strings++;
}

String::String(const String &st) {
	num_strings++;//static��� ������ ó��
	len = st.len;//���� ũ��� ����
	str = new char[len + 1];//�������� ����
	std::strcpy(str, st.str);//���ڿ��� �� ��ġ�� ����
}

String::~String() {
	--num_strings;
	delete[] str;
}
//�����ε� ������ �޼���

String &String::operator=(const String &st) {//String�� String�� ����
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

String &String::operator=(const char *s) {//C��Ÿ���� ���ڿ��� String�� ����
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

char &String::operator[](int i) {//const�� �ƴ� String�� �б� �� ���� �������� ����
	return str[i];
}

const char &String::operator[](int i)const {//const String�� �б� ���� ���� ���� ����
	return str[i];
}
//�����ε� ������ ������

bool operator<(const String &st1, const String &st2) {
	return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2) {
	return st1.str>st2.str;
}

bool operator==(const String &st1, const String &st2) {
	return (std::strcmp(st1.str, st2.str) == 0);
}

ostream &operator<<(ostream &os, const String &st) {
	os << st.str;
	return os;
}

istream &operator>>(istream &is, String &st) {
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}

