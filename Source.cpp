#include "Keeper.h"

void start_menu()
{
	system("cls");
	cout << "1.�������� ��������\n2.������� ��������\n3.������������� ������ ��������\n4.������/�������\n5.������ ����������\n6.�����\n";
}

void encode(char* filename)
{
	FILE* file1 = fopen(filename, "rt");
	char* buffer = (char*)calloc(strlen(filename), strlen(filename) * sizeof(char*));
	for (int i = 0; i != strlen(filename); i++)
	{
		if (*(filename + i) == '.')
		{
			break;
		}
		buffer[i] = filename[i];
	}
	char* filename2 = strcat(buffer, ".y0dv");
	FILE* file2 = fopen(filename2, "wt");


	char* stroka = (char*)calloc(MAXLINE2, MAXLINE2 * sizeof(char*));
	memset(stroka, 0, MAXLINE2);
	while (fgets(stroka, MAXLINE2, file1))
	{
		for (int i = 0; i != strlen(stroka); i++)
		{

			stroka[i] ++;

		}
		cout << stroka << endl;;
		fputs(stroka, file2);
	}
	fclose(file1);
	fclose(file2);


}

void decode(char* filename)
{
	FILE* file1 = fopen(filename, "rt");
	char* buffer = (char*)calloc(strlen(filename), strlen(filename) * sizeof(char*));
	for (int i = 0; i != strlen(filename); i++)
	{
		if (*(filename + i) == '.')
		{
			break;
		}
		buffer[i] = filename[i];
	}
	char* filename2 = strcat(buffer, "RAZ.txt");

	FILE* file2 = fopen(filename2, "wt");
	char* stroka = (char*)calloc(MAXLINE2, MAXLINE2 * sizeof(char*));
	memset(stroka, 0, MAXLINE2);
	while (fgets(stroka, MAXLINE2, file1))
	{
		for (int i = 0; i != strlen(stroka); i++)
		{

			stroka[i]--;

		}
		cout << stroka << endl;
		fputs(stroka, file2);
	}
	fclose(file1);
	fclose(file2);
}






int main(void)
{

	setlocale(LC_ALL, "Russian");
	int a;
	cout << "������� ��������� ������ �������\n";
	do
	{
		
		cin >> a;
		if (a < 0)
		{

			cout << "������� �������� ��������\n";
		}
	}
		while (a < 0);
	//Keeper* mas = (Keeper*)calloc(a, a*sizeof(Keeper*));
	Keeper mas(a);

	int select = 0;
	do
	{
		start_menu();
		cin >> select;
		if (select == 1)
		{
			system("cls");
			cout << "�������� ������ ������������\n";
			if (mas.get_size() == 0)
			{
				mas.resize(1);
			}
			Base_People buffer(1);
			cout << "�������� ������� ���� �������� � ��������� 0-" << mas.get_size()-1 << endl;
			int position;
			do
			{
				cin >> position;
			} while (position > mas.get_size() - 1);
		
			mas.add(buffer, position);

			
		}
		if (select == 2)
		{
			if (mas.get_size() == 0)
			{
				cout << "������ ����\n";
				system("pause");
			}
			else
			{
				cout << "� ������� ������ " << mas.get_size()-1 << "���������.����� ����� �������?\n";

				for (int i = 0; i != mas.get_size(); i++)
				{

					cout << i << ". " << mas[i];
				}
				int select2;
				do
				{
					
					cin >> select2;
					if (select2 > mas.get_size())
					{
						cout << "������� �������� �������\n";
					}
				}
					while (select2 > mas.get_size());

				mas.remove(select2);
				cout << "������ ������!\n";
				system("pause");
			}
			
		}
		if (select == 3)
		{

			if (mas.get_size() == 0)
			{
				cout << "������ ����\n";
				system("pause");
			}
			else
			{
				cout << "� ������� ������ " << mas.get_size() << "���������.����� ����� �������������?\n";

				for (int i = 0; i != mas.get_size(); i++)
				{

					cout << i << ". " << mas[i];
				}
				int select3;
				do
				{

					cin >> select3;
					if (select3 > mas.get_size()-1)
					{
						cout << "������� �������� �������\n";
					}
				} while (select3 > mas.get_size()-1);

				system("cls");
				cout << "������ ������!\n";
				cout << mas[select3];
				cout << "��� ����� ��������?\1.��� ���������� ������\n2.�������\n3.���\n4.��������\n5.�������\n6.���� ��������\n;7.������ � �������\n8.������ � ����\n9.������ � ������\n10.������ � �����\n11.���� ������\n";
				int select31;
				do
				{
					cin >> select31;
					Base_People buffer_red = mas[select3];
					if (select31 == 1)
					{
						buffer_red.set_Family_name();
						
					}
					if (select31 == 2)
					{
						buffer_red.set_last_name();
					}
					if (select31 == 3)
					{
						buffer_red.set_name();
					}
					if (select31 == 4)
					{
						buffer_red.set_middle_name();
					}
					if (select31 == 5)
					{
						buffer_red.set_age();
					}
					if (select31 == 6)
					{
						buffer_red.set_day();
						buffer_red.set_month();
						buffer_red.set_year();
						buffer_red.set_birthday();
					}
					if (select31 == 7)
					{
						buffer_red.set_spouse();
					}
					if (select31 == 8)
					{
						buffer_red.set_father();

					}
					if (select31 == 9)
					{
						buffer_red.set_mother();
					}
					if (select31 == 10)
					{
						cout << "��� ����� ������?\n1.��������� �������\n2.������� �������\n3.������������� �������\n";
						int select32;
						do
						{
							cin >> select32;
							if (select32 == 1)
							{
								buffer_red.set_children();
							}
							if (select32 == 2)
							{
								cout << "� �������� ��� ����� ������ �����" << endl;
								mas[select3].show_children();
								cout << "������ ����� �������?" << endl;
								int select33;
								do
								{
									cin >> select33;
									if (select33 > mas[select3].get_count_children())
									{
										cout << "������� �������� �������!\n";
									}
								}
									while (select33 > mas[select3].get_count_children());
								mas[select3].Base_People_remove_children(select33);
								
							}
							if (select32 == 3)
							{
								cout << "� �������� ��� ����� ������ �����" << endl;
								mas[select3].show_children();
								cout << "������ ����� �������?" << endl;
								int select34;
								do
								{
									cin >> select34;
									if (select34 > mas[select3].get_count_children())
									{
										cout << "������� �������� �������!\n";
									}
								} while (select34 > mas[select3].get_count_children());
								mas[select3].Base_People_edit_children(select34);
							}
							if (select32 != 1 && select32 != 2 && select32 != 3)
							{
								cout << "������ �������� �����!\n";
							}

						}
							while (select32 != 1 && select32 != 2 && select32 != 3);
					}
					if (select31 == 11)
					{
						buffer_red.set_day_s();
						buffer_red.set_month_s();
						buffer_red.set_year_s();
						buffer_red.set_deadday();

					}
					if (select31 != 1 && select31 != 2 && select31 != 3 && select31 != 4 && select31 != 5 && select31 != 6 && select31 != 7 && select31 != 8 && select31 != 9 && select31 != 10 && select31 != 11)
					{
						cout << "������ �������� �����!\n";
					}
					mas[select3] = buffer_red;
				}
					while (select31 != 1 && select31 != 2 && select31 != 3 && select31 != 4 && select31 != 5 && select31 != 6 && select31 != 7 && select31 != 8 && select31 != 9 && select31 != 10 && select31 != 11);
				
				cout << "������ ��������������!\n";
				system("pause");
			}
		}
		if (select == 4)
		{
			system("cls");
			cout << "�������� ����������� ��������:\n1.������\n2.�������\n";
			int select4;
			do
			{
				cin >> select4;
				if (select4 == 1)
				{
					system("cls");
					cout << "�������� ������ �������\n1.txt\n2.doc\n3.xml";
					int select41;
					do
					{
						cin >> select41;
						if (select41 != 1 && select41 != 2 && select41 != 3)
						{
							cout << "������ �������� �����\n";
						}
					} while (select41 != 1 && select41 != 2 && select41 != 3);
					char* filename = (char*)calloc(200, 200 * sizeof(char*));
					cout << "������� ������ ���� � ����� ������� ����������:\n";
					cin >> filename;
					char* mystrchr = strrchr(filename, '.');
					
					char razshirenie[4];
					memset(razshirenie, 0, 4);
					for (int i = 0, j = 1; i != 4; i++, j++)
					{
						razshirenie[i] = *(mystrchr + j);
					}
					

					if (strcmp(razshirenie, "txt") == 0 || strcmp(razshirenie, "doc") == 0 || strcmp(razshirenie, "xml") == 0)
					{
						if (select41 == 1)
						{
							mas.load_from_txt_file(filename);
						}
						if (select41 == 2)
						{
							mas.load_from_txt_file(filename);
						}
						if (select41 == 3)
						{
							mas.load_from_XML_file(filename);
						}
						cout << "���� ������� �������� � �������� � ���������!\n";
						system("pause");
						
					}
					else
					{
						
						cout << "������ �������� ������ �����\n������ ������ �� ��������������\n";
						system("pause");

					}
					free(filename);
				}
				if (select4 == 2)
				{
					system("cls");
					cout << "�������� ������ ��������\n1.txt\n2.doc\n3.xml";
					int select42;
					do
					{
						cin >> select42;
						if (select42 != 1 && select42 != 2 && select42 != 3)
						{
							cout << "������ �������� �����\n";
						}
					} while (select42 != 1 && select42 != 2 && select42 != 3);
					char* filename = (char*)calloc(200, 200 * sizeof(char*));
					cout << "������� ������ ���� � ����� ������� ����������:\n";
					cin >> filename;
					char* mystrchr = strrchr(filename, '.');

					char razshirenie[4];
					memset(razshirenie, 0, 4);
					for (int i = 0, j = 1; i != 4; i++, j++)
					{
						razshirenie[i] = *(mystrchr + j);
					}
				

					if (strcmp(razshirenie, "txt") == 0 || strcmp(razshirenie, "doc") == 0 || strcmp(razshirenie, "xml") == 0)
					{
						
						if (select42 == 1)
						{
							mas.save_in_txt_file(filename);
						}
						if (select42 == 2)
						{
							mas.save_in_txt_file(filename);
						}
						if (select42 == 3)
						{
							mas.save_in_XML_file(filename);
						}
						cout << "��������� ������� �������� � ����!\n";
						system("pause");
					}
					else
					{
						cout << "������ �������� ������ �����\n������ ������ �� ��������������\n";
						system("pause");

					}
					free(filename);
				}

				if (select4 != 1 && select4 != 2)
				{
					cout << "������ �������� �����\n";
				}
			}
				while (select4 != 1 && select4 != 2);
		}
		if (select == 5)
		{
			cout << "�������� ����������� ��������:\n1.��������\n2.�����������\n";
			int select5;
			do
			{
				cin >> select5;
				if (select5 != 1 && select5 != 2)
				{
					cout << "������ �������� �����!\n";
				}
			}
				while (select5 != 1 && select5 != 2);

			char* filename = (char*)calloc(200, 200 * sizeof(char*));
			cout << "������� ������ ���� � ����� ������� ����������:\n";
			cin >> filename;
			char* mystrchr = strrchr(filename, '.');

			char razshirenie[4];
			memset(razshirenie, 0, 4);
			for (int i = 0, j = 1; i != 4; i++, j++)
			{
				razshirenie[i] = *(mystrchr + j);
			}
			if (strcmp(razshirenie, "txt") == 0 || strcmp(razshirenie, "doc") == 0 || strcmp(razshirenie, "xml") == 0 || strcmp(razshirenie, "y0dv") == 0)
			{
				if (select5 == 1)
				{
					encode(filename);
					cout << "���� ������� ����������!\n";
				}
				if (select5 == 2)
				{
					decode(filename);
					cout << "���� ������� �����������!\n";
				}
				
			}
			else
			{
				cout << "������ �������� ������ �����\n������ ������ �� ��������������\n";
				system("pause");
			}
		}


		if (select != 1 && select != 2 && select != 3 && select != 4 && select != 5 && select != 6)
		{
			cout << "������ �������� �����!\n";
		}
	}
		while (select != 6);


	return 0;
}