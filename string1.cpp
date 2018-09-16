#include <cstring>
#include "string1.h"
using std::cin;
using std::cout;

int String::num_strings = 0;

int String::HowMany() {
	return num_strings;
}
//클래스 매서드

String::String(const char *s) {//C스타일의 문자열로부터 String을 생성
	len = std::strlen(s);//문자열의 크기를 설정
	str = new char[len + 1];//기억 공간을 대입
	std::strcpy(str, s);//포인터를 초기화
	num_strings++;//객체 카운트 설정
}

String::String() {//디폴트 생성자
	len = 4;
	str = new char[1];
	str[0] = '\0';//디폴트 문자열
	num_strings++;
}

String::String(const String &st) {
	num_strings++;//static멤버 갱신을 처리
	len = st.len;//같은 크기로 설정
	str = new char[len + 1];//기억공간을 대입
	std::strcpy(str, st.str);//문자열을 새 위치에 복사
}

String::~String() {
	--num_strings;
	delete[] str;
}
//오버로드 연산자 메서드

String &String::operator=(const String &st) {//String을 String에 대입
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

String &String::operator=(const char *s) {//C스타일의 문자열을 String에 대입
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

char &String::operator[](int i) {//const가 아닌 String에 읽기 및 쓰기 개별문자 접근
	return str[i];
}

const char &String::operator[](int i)const {//const String에 읽기 전용 개별 문자 접근
	return str[i];
}
//오버로드 연산자 프렌드

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

