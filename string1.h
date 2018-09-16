#pragma once
#ifndef STRING_H_
#define STRING_H_
#include <iostream>
using std::ostream;
using std::istream;

class String {
private :
	char *str;//���ڿ� ����������
	int len;//���ڿ� ����
	static int num_strings;//��ü�� ��
	static const int CINLIM = 80;//�Է� �Ѱ�
public :
	String(const char *s);//������
	String();//����Ʈ ������
	String(const String &st);//���� ������
	~String();//�ı���
	int length() const { return len; }

	String &operator=(const String &st);
	String &operator=(const char *s);
	char &operator[](int i);
	const char &operator[](int i) const;

	friend bool operator<(const String &st1, const String &str2);
	friend bool operator>(const String &st1, const String &str2);
	friend bool operator==(const String &st1, const String &str2);
	friend ostream &operator<<(ostream &os, const String &st);
	friend istream &operator>>(istream &is, String &st);

	static int HowMany();
};
#endif