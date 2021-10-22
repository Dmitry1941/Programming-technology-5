#include "Base_People.h"
Base_People::Base_People()  : Base()
{
	
	last_name = "NULL";
	name = "NULL";
	middle_name = "NULL";
	father = "NULL";
	mother =  "NULL";
	birthday = "NULL";
	age = -1;
	day = -1;
	month = -1;
	year = -1;
	spouse = "NULL";
	day_s = -1;
	month_s = -1;
	year_s = -1;
	deadday = "NULL";
	cout << "Человек создан!\n";
}
Base_People::Base_People(int a = 0) : Base()
{
	set_Family_name();
	set_last_name();
	set_name();
	set_middle_name();
	set_age();
	set_day();
	set_month();
	set_year();
	set_birthday();
	set_spouse();
	cout << "Сколько у вас детей?\n";
	int number = 0;
	do
	{
		cin.ignore(32767, '\n');
		cin >> number;
		if(number < 0 || number > 20)
		{
			cout << "Введите еще раз!\n";
		}
	}
		while (number < 0 || number > 20);
	for (int i = 0; i != number; i++)
	{
		set_children();
	}
	set_father();
	set_mother();
	cout << "Человек живой?\n1.Да\n2.Нет\n";
	int flag = 0;
	do
	{
		cin.ignore(32767, '\n');
		cin >> flag;
		if (flag != 1 && flag != 2)
		{
			cout << "Введите еще раз!\n";
		}
	}
		while (flag != 1 && flag !=2);
	if (flag == 2)
	{
		set_day_s();
		set_month_s();
		set_year_s();
		set_deadday();
	}
	
}
string Base_People::get_name()
{
	return this->name;
}
void Base_People::set_name()
{
	cin.ignore(32767, '\n');
	cout << "Введите имя\n";
	cin >> this->name;

}

string Base_People::get_last_name()
{
	return this->last_name;
}
void Base_People::set_last_name()
{
	//cin.ignore();
	cin.ignore(32767, '\n');
	cout << "Введите фамилию\n";
	cin >> this->last_name;
}

string Base_People::get_middle_name()
{
	return this->middle_name;
}
void Base_People::set_middle_name()
{
	cin.ignore(32767, '\n');
	cout << "Введите отчество\n";
	cin >> this->middle_name;
}

void Base_People::set_day()
{
	//cout << "Введите день рождения в формате ХХ:\n";
	cout << "Введите день рождения\n";

	do
	{
		cin.ignore(32767, '\n');
		cin >> this->day;
		if (day < 1 || day > 31 && day!= -1)
		{
			cout << "Введите корректное значение!" << endl;

		}
	} while (day < 1 || day > 31 && day != -1);

}
int Base_People::get_day()
{
	return this->day;

}

void Base_People::set_month()
{
	cout << "Введите месяц рождения\n";
	do
	{
		cin.ignore(32767, '\n');
		cin >> this->month;
		if (month < 1 || month > 12 && month != -1)
		{
			cout << "Введите корректное значение!" << endl;
		}
	} while (month < 1 || month > 12 && month != -1);

}
int Base_People::get_month()
{
	return this->month;
}
void Base_People::set_year()
{
	cout << "Введите год рождения\n";
	do
	{
		
		cin.ignore(32767, '\n');
		cin >> year;
		if (year < 1 && year != -1)
		{
			cout << "Введите корректное значение!" << endl;
		}
	} while (year < 1 && year != -1);
}
int Base_People::get_year()
{
	return this->year;
}
void Base_People::set_father()
{
	int flag = 0;
	cout << "Вам известны данные отца человека?\n1.Да\n2.Нет\n";
	do
	{
		cin.ignore(32767, '\n');
		cin >> flag;
		if(flag != 1 && flag !=2)
		{
			cout << "Введите еще раз!\n";
		}
	}while (flag != 1 && flag != 2);
	if (flag == 1)
	{
		string buffer_last_name;
		string buffer_name;
		string buffer_middle_name;

		cout << "Введите фамилию отца:\n";
		cin.ignore(32767, '\n');
		cin >> buffer_last_name;
		cout << "Введите имя отца:\n";
		//cin.ignore(32767, '\n');
		cin >> buffer_name;
		cout << "Введите отчество отца:\n";
		cin.ignore(32767, '\n');
		cin >> buffer_middle_name;
		this->father = buffer_last_name + buffer_name + buffer_middle_name;
	}
	if (flag == 2)
	{
		this->father = "NULL";
	}
}
string Base_People::get_father()
{
	return this->father;
}
void Base_People::set_mother()
{
	int flag = 0;
	cout << "Вам известны данные матери человека?\n1.Да\n2.Нет\n";
	do
	{
		cin.ignore(32767, '\n');
		cin >> flag;
		if (flag != 1 && flag != 2)
		{
			cout << "Введите еще раз!\n";
		}
	} while (flag != 1 && flag != 2);
	if (flag == 1)
	{
		string buffer_last_name;
		string buffer_name;
		string buffer_middle_name;

		cout << "Введите фамилию матери:\n";

		cin >> buffer_last_name;
		cout << "Введите имя матери:\n";

		cin >> buffer_name;
		cout << "Введите отчество матери:\n";

		cin >> buffer_middle_name;
		this->mother = buffer_last_name + buffer_name + buffer_middle_name;
	}
	if (flag == 2)
	{
		this->mother = "NULL";
	}
}
string Base_People::get_mother()
{
	return this->mother;
}

void Base_People::set_day_s()
{
	//cout << "Введите день рождения в формате ХХ:\n";

	cout << "Введите день смерти\n";
	do
	{
		cin.ignore(32767, '\n');
		cin >> this->day_s;
		if (day_s < 1 || day_s > 31 && day_s != -1)
		{
			cout << "Введите корректное значение!" << endl;

		}
	} while (day_s < 1 || day_s > 31 && day_s != -1);

}
int Base_People::get_day_s()
{
	return this->day_s;

}

void Base_People::set_month_s()
{
	cout << "Введите месяц смерти\n";
	do
	{
		cin.ignore(32767, '\n');
		cin >> this->month_s;
		if (month_s < 1 || month_s > 12 && month_s != -1)
		{
			cout << "Введите корректное значение!" << endl;
		}
	} while (month_s < 1 || month_s > 12 && month_s != -1);

}
int Base_People::get_month_s()
{
	return this->month_s;
}
void Base_People::set_year_s()
{
	cout << "Введите год смерти\n";
	do
	{
		cin.ignore(32767, '\n');
		cin >> year_s;
		if (year_s < 1 && year_s != -1)
		{
			cout << "Введите корректное значение!" << endl;
		}
	} while (year_s < 1 && year_s != -1);
}
int Base_People::get_year_s()
{
	return this->year_s;
}

int Base_People::get_age()
{
	return this->age;
}
void Base_People::set_age()
{

	cout << "Введите возраст\n";
	do
	{
		cin.ignore(32767, '\n');
		cin >> this->age;
		if (age < 0 || age > 200)
		{
			cout << "Введите еще раз!\n";
		}
	} while (age < 0 || age > 200);
}

void Base_People::set_birthday()
{
	if (day == -1 || month == -1 || year == -1)
	{
		birthday = "NULL";
	}

	else
	{

		if (day < 10)
		{
			birthday = string("0") + to_string(day) + string(".");
		}
		else
		{
			birthday = to_string(day) + string(".");
		}

		if (month < 10)
		{
			birthday = birthday + string("0") + to_string(month) + string(".");
		}
		else
		{
			birthday = birthday + to_string(month) + string(".");
		}

		birthday = birthday + to_string(year);
	}
}
string Base_People::get_birthday()
{
	return birthday;
}

void Base_People::set_deadday()
{
	if (day_s == -1 || month_s == -1 || year_s == -1)
	{
		deadday = "NULL";
	}
	else
	{

		if (day_s < 10)
		{
			deadday = string("0") + to_string(day_s) + string(".");
		}
		else
		{
			deadday = to_string(day_s) + string(".");
		}

		if (month_s < 10)
		{
			deadday = deadday + string("0") + to_string(month_s) + string(".");
		}
		else
		{
			deadday = deadday + to_string(month_s) + string(".");
		}
		deadday = deadday + to_string(year_s);
	}
}
string Base_People::get_deadday()
{
	return deadday;
}

void  Base_People::set_name(char* line)
{
	name = (string)line;
}
void  Base_People::set_last_name(char* line)
{
	last_name = (string)line;
}

void  Base_People::set_middle_name(char* line)
{
	middle_name = (string)line;
}
void  Base_People::set_day(char* line)
{
	day = atoi(line);
}
void  Base_People::set_month(char* line)
{
	month = atoi(line);
}
void  Base_People::set_year(char* line)
{
	year = atoi(line);
}
void  Base_People::set_age(char* line)
{
	age = atoi(line);
}

void  Base_People::set_father(char* line)
{
	father = (string)line;
}

void  Base_People::set_mother(char* line)
{
	mother = (string)line;
}
void  Base_People::set_birthday(char* line)
{
	birthday = (string)line;
}
void  Base_People::set_day_s(char* line)
{
	day_s = atoi(line);
}
void  Base_People::set_month_s(char* line)
{
	month_s = atoi(line);
}
void  Base_People::set_year_s(char* line)
{
	year_s = atoi(line);
}
void  Base_People::set_deadday(char* line)
{
	deadday = (string)line;
}

void Base_People::set_children()
{
	char* buffer_children = (char*)calloc(MAXLINE, MAXLINE * sizeof(char*));
	cout << "Введите данные о ребенке\n";
	cin.ignore(32767, '\n');
	cin >> buffer_children;
	children_list.add_list(buffer_children);
}
void Base_People::set_children(char* line)
{
	children_list.add_list(line);
}
char* Base_People::get_children()
{
	cout << "У данного объекта " << children_list.getCount() << " детей\nКакого хотите выбрать?\n";
	children_list.show();
	int position = 0;
	do
	{
		cin >> position;
		if (position < 0 || position > children_list.getCount())
		{
			cout << "Выбран неверный объект!\n";
		}
	}
		while (position < 0 || position > children_list.getCount());
	return children_list.get_element(position);


}

void Base_People::show_children()
{
	children_list.show();
}

int Base_People::get_count_children()
{
	return children_list.getCount();
}

void Base_People::Base_People_remove_children(int i)
{
	this->children_list.remove_element(i);
}

void Base_People::Base_People_edit_children(int i)
{
	this->children_list.edit_element(i);
}

void Base_People::set_spouse()
{
	int flag = 0;
	cout << "У человека есть супруг?\n1.Да\n2.Нет";
	do
	{
		cin.ignore(32767, '\n');
		cin >> flag;
		if (flag != 1 && flag != 2)
		{
			cout << "Введите еще раз!\n";
		}
	}
		while (flag != 1 && flag != 2);
	if (flag == 1)
	{
		//cin.ignore(32767, '\n');
		string buffer_last_name;
		string buffer_name;
		string buffer_middle_name;
		cout << "Введите фамилию супруга:\n";
		cin.ignore(32767, '\n');
		cin >> buffer_last_name;
		cout << "Введите имя супруга:\n";
		cin.ignore(32767, '\n');
		cin >> buffer_name;
		cout << "Введите отчество супруга:\n";
		cin.ignore(32767, '\n');
		cin >> buffer_middle_name;
		spouse = buffer_last_name + " " + buffer_name + " " + buffer_middle_name;
	}
	if (flag == 2)
	{
		spouse = "NULL";
	}
}

void Base_People::set_spouse(char*line)
{
	spouse = string(line);
}

string Base_People::get_spouse()
{
	return spouse;

}

string Base_People::say_Family_name()
{
	return this->get_Family_name() ;

}

string Base_People::AboutMe()
{
	return this->get_Family_name() + " " + this->last_name + " " + this->name + " " + this->middle_name + " " + this->birthday + " " + to_string(this->age) + " " + this->spouse + " " + this->get_All_name_children_in_string() +  " " + this->father + " " + this->mother + " "  + " " + this->deadday + "|" + to_string(day) + "@" + to_string(month) + "@" + to_string(year) + "|" + to_string(day_s) + "#" + to_string(month_s) + "#" + to_string(year_s) + "\n";
}

string Base_People::get_All_name_children_in_string()
{

	if (children_list.getCount() > 0)
	{
		char** spisok_children = (char**)calloc(children_list.getCount(), children_list.getCount() * sizeof(char**));
		for (int i = 0; i != children_list.getCount(); i++)
		{
			spisok_children[i] = (char*)calloc(MAXLINE, MAXLINE * sizeof(char*));
		}
		children_list.children_from_txt_save(spisok_children);
		string SuperStroka;

		for (int i = 0; i != children_list.getCount(); i++)
		{
			SuperStroka = SuperStroka + (string)spisok_children[i] + ",";
		}

		for (int i = 0; i != children_list.getCount(); i++)
		{
			free(spisok_children[i]);
		}
		free(spisok_children);
		return SuperStroka;
	}
	else
	{
		return "NULL";
	}
}

ostream& operator << (ostream& out, Base_People& example)
{
	out << example.AboutMe();
	return out;
}

string Base_People::save_from_txt()
{

		

	string SuperStroka = this->get_All_name_children_in_string();

	return  this->get_Family_name() + "!" + this->last_name + "|" + this->name  + "|" + this->middle_name + "|" + this->birthday + "|" + to_string(this->age) + "|" + this->spouse + "|" + this->father + "|" + this->mother + "|" + SuperStroka + "|" + this->deadday + "|" + to_string(day) + "@" + to_string(month) + "@" + to_string(year) + "|" + to_string(day_s) + "#" + to_string(month_s) + "#" + to_string(year_s) +"\n" ;
	
	
}

string Base_People::convert_from_XML()
{
	string tag_family_tree1 = "<familytree>";
	string tag_family_tree2 = "</familytree>";

	string tag_last_name1 = "<lastname>";
	string tag_last_name2 = "</lastname>";

	string tag_name1 = "<name>";
	string tag_name2 = "</name>";

	string tag_middle_name1 = "<middlename>";
	string tag_middle_name2 = "</middlename>";

	string tag_birthday1 = "<birthday>";
	string tag_birthday2 = "</birthday>";

	string tag_age1 = "<age>";
	string tag_age2 = "</age>";

	string tag_spouse1 = "<spouse>";
	string tag_spouse2 = "</spouse>";

	string tag_father1 = "<father>";
	string tag_father2 = "</father>";

	string tag_mother1 = "<mother>";
	string tag_mother2 = "</mother>";

	string tag_children1 = "<children>";
	string tag_children2 = "</children>";

	string tag_deadday1 = "<deadday>";
	string tag_deadday2 = "</deadday>";

	string tag_day1 = "<day>";
	string tag_day2 = "</day>";

	string tag_month1 = "<month>";
	string tag_month2 = "</month>";

	string tag_year1 = "<year>";
	string tag_year2 = "</year>";

	string tag_day_s1 = "<dayS>";
	string tag_day_s2 = "</dayS>";

	string tag_month_s1 = "<monthS>";
	string tag_month_s2 = "</monthS>";

	string tag_year_s1 = "<yearS>";
	string tag_year_s2 = "</yearS>";

	string family_tree = tag_family_tree1  + this->get_Family_name()  + tag_family_tree2 + '\n';
	string last_name = tag_last_name1  + this->last_name  + tag_last_name2 + '\n';
	string name = tag_name1 +  this->name +  tag_name2 + '\n';
	string middle_name = tag_middle_name1  + this->middle_name + tag_middle_name2 + '\n';
	string birthday = tag_birthday1  + this->birthday  + tag_birthday2 + '\n';
	string age = tag_age1  + to_string(this->age)  + tag_age2 + '\n';
	string spouse = tag_spouse1  + this->spouse  + tag_spouse2 + '\n';
	string father = tag_father1  + this->father  + tag_father2 + '\n';
	string mother = tag_mother1  + this->mother  + tag_mother2 + '\n';
	string SuperStroka = this->get_All_name_children_in_string();
	string children = tag_children1   + SuperStroka  + tag_children2 + '\n';
	string deadday = tag_deadday1  + this->deadday  + tag_deadday2 + '\n';
	string day = tag_day1  + to_string(this->day)  + tag_day2 + '\n';
	string month = tag_month1  + to_string(this->month)  + tag_month2 + '\n';
	string year = tag_year1  + to_string(this->year)  + tag_year2 + '\n';
	string day_s = tag_day_s1  + to_string(this->day_s)  + tag_day_s2 + '\n';
	string month_s = tag_month_s1  + to_string(this->month_s)  + tag_month_s2 + '\n';
	string year_s = tag_year_s1 + to_string(this->year_s)  + tag_year_s2 + '\n';

	return family_tree + last_name + name + middle_name + birthday + age + spouse + father + mother  + children + deadday + day + month + year + day_s + month_s + year_s + "\n" + "\n";






}

Base_People::~Base_People()
{
	cout << "Производный класс удален!\n";
}