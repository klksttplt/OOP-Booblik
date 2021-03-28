#pragma once

#include <ostream>
using namespace std;
//�������������� ���� ��� ������ � ��������� �������.

//

//��������� ����� ������������ �������

//maxHeigh � maxWidth

//

class Screen

{

public:

	//����� ������������ ������ pc,

	//���� �� �������, ������ �� ������������

	//������������ _filler

	Screen(int, int, char* pc = 0);

	~Screen();

	//����������������������

	//��������� ������ �� ������� ������

	const Screen& home() const;

	Screen& home();

	//�������� ������ �� ���� ������ ������

	const Screen& move() const;

	Screen& move();

	//�������� ������ �� ���� ������ ����

	const Screen& back() const;

	Screen& back();

	//������������������

	const Screen& show() const;

	Screen& show();

	//��������� ������ �� ������ �������

	const Screen& move(int, int) const;

	Screen& move(int, int);

	//�������������

	Screen& clear();

	//�������� ������, �� ����� ����������� ������

	const Screen& showCurrent() const;

	//��������

	char get() const;

	//�����������

	Screen& set(char);

private:

	//�����������������������

	static const int maxHeight;

	//�����������������������

	static const int maxWidth;

	//����������

	static const char _filler;

	//�������� ������ ������

	int _height;

	//�������� ������ ������

	int _width;

	//���������� ������

	char* _wContent;

	//������

	mutable int _cursor;

	//����������������������������

	Screen(const Screen&);

	Screen& operator= (const Screen&);

};

ostream& operator<<(ostream&, const Screen&);

typedef const Screen& (Screen::* const ConstAction) () const;

typedef Screen& (Screen::* const NonConstAction) ();

void doActionConst(const Screen& s, ConstAction act, int n);

void doActionNonConst(Screen& s, NonConstAction act, int n);