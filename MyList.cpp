#include "MyList.h"
MyList::MyList()
{
	head = nullptr;
	count = 0;
}

MyList::~MyList()
{
	//while (head != nullptr)
	//{
	//	//Node* temp = head->ptr;
	//	//delete head;
	//	//head = temp;
	//}
	//count = 0;
	cout << "Список удален!\n";
}
void MyList::add_list(char* children)
{
	Node* temp = new Node;
	temp->children = children;
	temp->ptr = head;
	head = temp;
	count++;
}
void MyList::remove_element(int i)
{
	Node* temp = head;
	if (count == 0)
	{
		cout << "Список детей пуст" << endl;
	}
	else
	{
		int j = 0;
		while (j != i)
		{
			temp = temp->ptr;
			j++;
		}
		Node* temp1 = temp;
		temp1 = temp->ptr;
		free(temp);
		if (i == 0)
		{
			head = temp1;
		}
		if (i == 1)
		{
			head->ptr = temp1;
		}
		count--;
	}

}
void MyList::edit_element(int i)
{
	Node* temp = head;
	if (count == 0)
	{
		cout << "Список детей пуст" << endl;
	}
	else
	{
		int j = 0;
		while (j != i)
		{
			temp = temp->ptr;
			j++;
		}
		cout << "Введите имя ребенка, чтобы отредактировать" << endl;
		cin >> temp->children;
		cout << "Редактирование успешно закончено!" << endl;
	}
}
void MyList::show()
{
	Node* temp = head;
	int i = 0;
	while (i != count)
	{
		cout << i << ". " <<   temp->children << endl;
		
		temp = temp->ptr;
		i++;

	}
	
}

void MyList::children_from_txt_save(char** spisok_children)
{
	Node* temp = head;
	int i = 0;
	while (temp != nullptr)
	{
		//spisok_children[i] = temp->children;
		strcpy(spisok_children[i], temp->children);
		temp = temp->ptr;
		i++;
	}

}

char* MyList::get_element(int i)
{
	Node* temp = head;
	int j = 0;
	while (j != i)
	{
		
		temp = temp->ptr;
		j++;
	}
	return temp->children;
}
int MyList::getCount()
{
	return count;
}