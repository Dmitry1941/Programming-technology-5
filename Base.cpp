#include "Base.h"
void Base::set_Family_name()
{
	
	cout << "������� �������� ���������� ������\n";
	cin >> Family_name;
}
string Base::get_Family_name()
{
	return Family_name;
}
void Base::set_Family_name(char* line)
{
	Family_name = (string)line;
}

Base::Base()
{
	Family_name = "NULL";
	cout << "��������� ������ �������!\n";
}
Base::~Base()
{
	cout << "������� ����� ������!\n";
}