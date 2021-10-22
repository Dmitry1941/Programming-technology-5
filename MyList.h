#pragma once
#include "Node.h"
class MyList
{
private:
	Node* head;
	int count;
public:
	MyList();


		~MyList();

		void add_list(char* children);
		int getCount();
		char* get_element(int i);
		void show();
		void children_from_txt_save(char** spisok_children);
		void edit_element(int i);
		void remove_element(int i);
	

};

