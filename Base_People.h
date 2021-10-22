#pragma once
#include "Base.h"
#define MAXLINE 100
class Base_People : public Base
{
private:
	string name = "NULL";
	string last_name = "NULL";
	string middle_name = "NULL";
	int day = -1;
	int month = -1;
	int year = -1;
	int age = -1;
	string birthday = "NULL";
	string father = "NULL";
	string mother = "NULL";
	int day_s = -1;
	int month_s = -1;
	int year_s = -1;
	string deadday = "NULL";
	string spouse;
	MyList children_list;
	
public:
	Base_People();
	Base_People(int a);
	string get_name();

	void set_name();

	string get_last_name();

	void set_last_name();


	string get_middle_name();

	void set_middle_name();


	void set_day();

	int get_day();


	void set_month();

	int get_month();

	void set_year();

	int get_year();

	void set_father();
	string get_father();

	void set_mother();

	string get_mother();


	void set_day_s();

	int get_day_s();


	void set_month_s();

	int get_month_s();

	void set_year_s();

	int get_year_s();

	int get_age();

	void set_age();


	void set_birthday();

	string get_birthday();


	void set_deadday();

	string get_deadday();

	void set_children();
	char* get_children();
	
	void set_spouse();
	string get_spouse();
	string get_All_name_children_in_string();
	/*Выше для новых записей*/


	void set_name(char* line);

	void set_last_name(char* line);


	void set_middle_name(char* line);

	void set_spouse(char* line);

	void set_day(char* line);

	void set_month(char* line);

	void set_year(char* line);

	void set_age(char* line);


	void set_father(char* line);


	void set_mother(char* line);

	void set_birthday(char* line);

	void set_day_s(char* line);

	void set_month_s(char* line);

	void set_year_s(char* line);

	void set_deadday(char* line);

	void set_children(char* line);
	
	string AboutMe() override;
	void show_children();
	int get_count_children();
	void Base_People_remove_children(int i);
	void Base_People_edit_children(int i);
	/*Выше для извлечения из файла*/
	string say_Family_name() override;
	friend ostream& operator << (ostream& out, Base_People& example);
	string save_from_txt() override;
	string convert_from_XML() override;
	~Base_People();







	
};

