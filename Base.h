#pragma once

#include <locale>
#include "MyList.h"

/*Класс Фамильное дерево хранит данные о семье. Каждый член семьи имеет:
ФИО, знания о родителях, знания о супруге, знания о своих детях, дату
рождения, дату смерти (если есть), возраст.*/

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

