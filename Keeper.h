#pragma once
#include "Base.h"
#include "Base_People.h"
#include <cassert>
#define MAXLINE2 2000
#define MAXLINE3 3000
#define MAXLINE1000 1000
#pragma warning(disable: 4996)
class Keeper
{
private:
	int length;
	
	Base_People* data;
public:
	Keeper();

	Keeper(int length);
	~Keeper();
	void set_length(int v);
	int get_size();
	void erase();


	Base_People& operator[](int index);
	

	void reallocate(int newlength);

	void resize(int newlength);

	void add(Base_People value, int index);

	void remove(int index);

	void save_in_txt_file(char* filename);
	
	void load_from_txt_file(char* filename);


	void save_in_XML_file(char* filename);

	void load_from_XML_file(char* filename);

	
	
};

