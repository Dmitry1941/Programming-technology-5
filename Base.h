#pragma once

#include <locale>
#include "MyList.h"

/*����� ��������� ������ ������ ������ � �����. ������ ���� ����� �����:
���, ������ � ���������, ������ � �������, ������ � ����� �����, ����
��������, ���� ������ (���� ����), �������.*/

class Base
{
private:
	string Family_name;
public:
	void set_Family_name();
	
	string get_Family_name();
	
	void set_Family_name(char* line);
	virtual string say_Family_name() = 0;
	virtual string save_from_txt() = 0;
	virtual string AboutMe() = 0;
	virtual string convert_from_XML() = 0;
	Base();
	virtual ~Base();

};

