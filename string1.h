#pragma once
#ifndef STRING_H_
#define STRING_H_
#include <iostream>
using std::ostream;
using std::istream;

class String {
private :
	char *str;//문자열 지시포인터
	int len;//문자열 길이
	static int num_strings;//객체의 수
	static const int CINLIM = 80;//입력 한계
public :
	String(const char *s);//생성자
	String();//디폴트 생성자
	String(const String &st);//복사 생성자
	~String();//파괴자
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