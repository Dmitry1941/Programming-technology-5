#include "Keeper.h"
Keeper::Keeper()
{
	length = 0;

	data = nullptr;
	cout << "Контейнер создан!\n";
}

Keeper::Keeper(int length)
{
	this->length = length;
	if (length >= 0)
	{
		data = new Base_People[length];
		cout << "Контейнер создан!\n";
	}
	else
	{
		data = nullptr;
		cout << "Контейнер не может быть отрицательной длины!\n";
		system("pause");
		exit(1);
	}
}
Keeper::~Keeper()
{
	erase();
	length = 0;
	free(data);
	cout << "Контейнер удален!\n";
}
void Keeper::set_length(int v)
{
	length = v;
}
int Keeper::get_size()
{
	return length;
}
void Keeper::erase() // очистка контейнера
{
	delete[] data;
	data = nullptr;
	length = 0;
}

Base_People& Keeper::operator[](int index)
{
	assert(index >= 0 && index < length);
	return data[index];
}

void Keeper::reallocate(int newlength)
{
	erase();
	if (newlength <= 0)
	{
		return;
	}
	data = new Base_People[newlength];
	length = newlength;

}

void Keeper::resize(int newlength)
{
	if (newlength == length)
	{
		return;
	}
	if (newlength < 0)
	{
		erase();
		return;
	}
	Base_People* buffer_data = new Base_People[newlength];
	if (length >= 0)
	{
		int count_copy = 0;
		if (newlength > length)
		{
			count_copy = length;
		}
		else
		{
			count_copy = newlength;
		}
		for (int index = 0; index < count_copy; index++)
		{
			buffer_data[index] = data[index];
		}
		delete[] data;
		data = buffer_data;
		length = newlength;

	}
}

void Keeper::add(Base_People value, int index)
{
	assert(index >= 0 && index <= length);

	Base_People* buffer = new Base_People[length + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = data[i];
	}
	buffer[index] = value;
	for (int j = index; j < length; j++)
	{
		buffer[j + 1] = data[j];
	}
	delete[] data;
	data = buffer;
	length++;

}

void Keeper::remove(int index)
{
	assert(index >= 0 && index < length);

	if (length == 1)
	{
		erase();
		return;
	}
	Base_People* buffer = new Base_People[length - 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = data[i];
	}
	for (int j = index + 1; j < length; j++)
	{
		buffer[j - 1] = data[j];
	}
	delete[] data;
	data = buffer;
	length--;
}

void Keeper::save_in_txt_file(char* filename)
{
	try
	{
		FILE* file = fopen(filename, "w");
		for (int i = 0; i < length; i++)
		{
			string buffer_stroka = data[i].save_from_txt();
			//int length_stroka = buffer_stroka.length();


			fputs(buffer_stroka.c_str(), file);
		}
		fclose(file);
	}
	catch (exception ex)
	{
		cout << "File dont save!\n";
		return;
	}
}

void Keeper::load_from_txt_file(char* filename)
{
	int size = 0;

	try
	{
		FILE* file = fopen(filename, "r");

		char* buffer = (char*)calloc(MAXLINE2, MAXLINE2 * sizeof(char*));
		while (!feof(file))
		{
			int cnt_raz = 0;
			int cnt_vosk = 0;
			int cnt_zap = 0;
			int cnt_void = 0;
			try
			{//FIX
				fgets(buffer, MAXLINE2, file);
				if (strlen(buffer) == 1)
				{
					cnt_void++;
					cnt_raz = 11;
					cnt_vosk = 11;
					cout << strlen(buffer) << endl;
					system("pause");
				}

				for (int i = 0; i != strlen(buffer); i++)
				{
					if (buffer[i] == '|')
					{
						cnt_raz++;
					}
					if (buffer[i] == '!')
					{
						cnt_vosk++;

					}
					if (buffer[i] == ',')
					{
						cnt_zap++;
					}
				}
				if (cnt_raz == 11 && cnt_vosk == 1 && cnt_void < 2)
				{
					Base_People people_buffer;
					char* istr_fam_house = strtok(buffer, "!");
					people_buffer.set_Family_name(istr_fam_house);
					//cout << istr_fam_house;
					char* istr = istr_fam_house;

					istr = strtok(NULL, "|");
					//cout << istr << endl;
					people_buffer.set_last_name(istr);
					istr = strtok(NULL, "|");
					//cout << istr << endl;
					people_buffer.set_name(istr);
					istr = strtok(NULL, "|");
					//cout << istr << endl;
					people_buffer.set_middle_name(istr);
					istr = strtok(NULL, "|");
					//cout << istr << endl;
					people_buffer.set_birthday(istr);
					istr = strtok(NULL, "|");
					//cout << istr << endl;
					people_buffer.set_age(istr);
					istr = strtok(NULL, "|");
					//cout << istr << endl;
					people_buffer.set_spouse(istr);
					istr = strtok(NULL, "|");
					//cout << istr << endl;
					people_buffer.set_father(istr);
					istr = strtok(NULL, "|");
					//cout << istr << endl;
					people_buffer.set_mother(istr);
					//cout << istr << endl;



					//cout << cnt_zap << endl;

					for (int i = 0; i != cnt_zap; i++)
					{
						istr = strtok(NULL, "|,");

						char* buffer_children = (char*)calloc(strlen(istr), strlen(istr) * sizeof(char*));
						strcpy(buffer_children, istr);

						people_buffer.set_children(buffer_children);

					}

					istr = strtok(NULL, "|@#,");
					//cout << istr << endl;
					people_buffer.set_deadday(istr);
					istr = strtok(NULL, "|@#,");
					//cout << istr << endl;
					people_buffer.set_day(istr);
					istr = strtok(NULL, "|@#,");
					//cout << istr << endl;
					people_buffer.set_month(istr);
					istr = strtok(NULL, "|@#,");
					//cout << istr << endl;
					people_buffer.set_year(istr);
					istr = strtok(NULL, "|@#,");
					//cout << istr << endl;
					people_buffer.set_day_s(istr);
					istr = strtok(NULL, "|@#,");
					//cout << istr << endl;
					people_buffer.set_month_s(istr);
					istr = strtok(NULL, "|@#,");
					//cout << istr << endl;
					people_buffer.set_year_s(istr);
					//istr = strtok(NULL, "|@#");
					this->add(people_buffer, size);
					size++;
					if (size >= length)
					{
						this->resize(length + 1);
					}
					
				}
				else
				{
					throw - 1;
				}


			}
			catch (exception ex1)
			{
				cout << "File empty!\n";
				return;
			}
			catch (int a)
			{
				cout << "File soderjit lisnuu info!\n";
				return;
			}
		}

	}
	catch (exception ex)
	{
		cout << "File TXT dont open!\n";
		return;
	}
}


void Keeper::save_in_XML_file(char* filename)
{
	FILE* file = fopen(filename, "w");
	fputs("<?xml version=""1.0"" encoding = ""UTF-8""?>\n", file);
	fputs("<Keeper>\n\n", file);
	for (int i = 0; i != length; i++)
	{
		fputs(data[i].convert_from_XML().c_str(), file);
	}
	fputs("</Keeper>\n", file);
	fclose(file);

}

void Keeper:: load_from_XML_file(char* filename)
{

	int size = 0;
	int count_massiv = 0;

	int starter_tag = 0;
	int end_tag = 0;
	try
	{
		FILE* file = fopen(filename, "r");
		char* buffer_XML = (char*)calloc(MAXLINE2, MAXLINE2 * sizeof(char*));

		while (!feof(file))
		{

			fgets(buffer_XML, MAXLINE2, file);
			if (strstr(buffer_XML, "<Keeper>") != NULL)
			{
				starter_tag++;
			}
			if ((strstr(buffer_XML, "<familytree>") != NULL) && strstr(buffer_XML, "</familytree>") != NULL)
			{
				//ЗДЕСЬ ДОДЕЛАТЬ
				Base_People people;
				int start = 0;
				int end = 0;
				int flag = 0;
				for (int i = 0; i != strlen(buffer_XML); i++)
				{
					if (*(buffer_XML + i) == '>' && flag == 0)
					{
						start = i + 1;
						flag++;
					}
					if (*(buffer_XML + i) == 60)
					{
						end = i;
					}


				}
				char* buffer2 = (char*)calloc(end - start, (end - start) * sizeof(char*));
				for (int i = 0, j = start; j != end; i++, j++)
				{
					*(buffer2 + i) = *(buffer_XML + j);
				}

				people.set_Family_name(buffer2);
				//cout << people.get_Family_name() << endl;



				if (fgets(buffer_XML, MAXLINE2, file))
				{
					if ((strstr(buffer_XML, "<lastname>") != NULL) && strstr(buffer_XML, "/lastname") != NULL)
					{
						start = 0;
						end = 0;
						flag = 0;
						for (int i = 0; i != strlen(buffer_XML); i++)
						{
							if (*(buffer_XML + i) == '>' && flag == 0)
							{
								start = i + 1;
								flag++;
							}
							if (*(buffer_XML + i) == '<')
							{
								end = i;
							}
						}
						free(buffer2);
						buffer2 = (char*)calloc(end - start, (end - start) * sizeof(char*));
						for (int i = 0, j = start; j != end; i++, j++)
						{
							*(buffer2 + i) = *(buffer_XML + j);
						}
						people.set_last_name(buffer2);
						//cout << people.get_last_name() << endl;

						if (fgets(buffer_XML, MAXLINE2, file))
						{
							if ((strstr(buffer_XML, "<name>") != NULL && strstr(buffer_XML, "</name>") != NULL))
							{

								start = 0;
								end = 0;
								flag = 0;
								for (int i = 0; i != strlen(buffer_XML); i++)
								{
									if (*(buffer_XML + i) == '>' && flag == 0)
									{
										start = i + 1;
										flag++;
									}
									if (*(buffer_XML + i) == '<')
									{
										end = i;
									}
								}
								free(buffer2);
								buffer2 = (char*)calloc(end - start, (end - start) * sizeof(char*));
								for (int i = 0, j = start; j != end; i++, j++)
								{
									*(buffer2 + i) = *(buffer_XML + j);
								}
								people.set_name(buffer2);
								//cout << people.get_name() << endl;

								if (fgets(buffer_XML, MAXLINE2, file))
								{
									if ((strstr(buffer_XML, "<middlename>") != NULL && strstr(buffer_XML, "</middlename>") != NULL))
									{

										start = 0;
										end = 0;
										flag = 0;
										for (int i = 0; i != strlen(buffer_XML); i++)
										{
											if (*(buffer_XML + i) == '>' && flag == 0)
											{
												start = i + 1;
												flag++;
											}
											if (*(buffer_XML + i) == '<')
											{
												end = i;
											}
										}
										free(buffer2);
										buffer2 = (char*)calloc(end - start, (end - start) * sizeof(char*));
										for (int i = 0, j = start; j != end; i++, j++)
										{
											*(buffer2 + i) = *(buffer_XML + j);
										}
										people.set_middle_name(buffer2);
										//cout << people.get_middle_name() << endl;

										if (fgets(buffer_XML, MAXLINE2, file))
										{
											if ((strstr(buffer_XML, "<birthday>") != NULL && strstr(buffer_XML, "</birthday>") != NULL))
											{

												start = 0;
												end = 0;
												flag = 0;
												for (int i = 0; i != strlen(buffer_XML); i++)
												{
													if (*(buffer_XML + i) == '>' && flag == 0)
													{
														start = i + 1;
														flag++;
													}
													if (*(buffer_XML + i) == '<')
													{
														end = i;
													}
												}
												free(buffer2);
												buffer2 = (char*)calloc(end - start, (end - start) * sizeof(char*));
												for (int i = 0, j = start; j != end; i++, j++)
												{
													*(buffer2 + i) = *(buffer_XML + j);
												}
												people.set_birthday(buffer2);
												//cout << people.get_birthday() << endl;

												if (fgets(buffer_XML, MAXLINE2, file))
												{
													if ((strstr(buffer_XML, "<age>") != NULL && strstr(buffer_XML, "</age>") != NULL))
													{

														start = 0;
														end = 0;
														flag = 0;
														for (int i = 0; i != strlen(buffer_XML); i++)
														{
															if (*(buffer_XML + i) == '>' && flag == 0)
															{
																start = i + 1;
																flag++;
															}
															if (*(buffer_XML + i) == '<')
															{
																end = i;
															}
														}
														free(buffer2);
														buffer2 = (char*)calloc(end - start, (end - start) * sizeof(char*));
														for (int i = 0, j = start; j != end; i++, j++)
														{
															*(buffer2 + i) = *(buffer_XML + j);
														}
														people.set_age(buffer2);
														//cout << people.get_birthday() << endl;

														if (fgets(buffer_XML, MAXLINE2, file))
														{
															if ((strstr(buffer_XML, "<spouse>") != NULL && strstr(buffer_XML, "</spouse>") != NULL))
															{

																start = 0;
																end = 0;
																flag = 0;
																for (int i = 0; i != strlen(buffer_XML); i++)
																{
																	if (*(buffer_XML + i) == '>' && flag == 0)
																	{
																		start = i + 1;
																		flag++;
																	}
																	if (*(buffer_XML + i) == '<')
																	{
																		end = i;
																	}
																}
																free(buffer2);
																buffer2 = (char*)calloc(end - start, (end - start) * sizeof(char*));
																for (int i = 0, j = start; j != end; i++, j++)
																{
																	*(buffer2 + i) = *(buffer_XML + j);
																}
																people.set_spouse(buffer2);
																//cout << people.get_spouse() << endl;

																if (fgets(buffer_XML, MAXLINE2, file))
																{

																	if ((strstr(buffer_XML, "<father>") != NULL && strstr(buffer_XML, "</father>") != NULL))
																	{

																		start = 0;
																		end = 0;
																		flag = 0;
																		for (int i = 0; i != strlen(buffer_XML); i++)
																		{
																			if (*(buffer_XML + i) == '>' && flag == 0)
																			{
																				start = i + 1;
																				flag++;
																			}
																			if (*(buffer_XML + i) == '<')
																			{
																				end = i;
																			}
																		}
																		free(buffer2);
																		buffer2 = (char*)calloc(end - start, (end - start) * sizeof(char*));
																		for (int i = 0, j = start; j != end; i++, j++)
																		{
																			*(buffer2 + i) = *(buffer_XML + j);
																		}
																		cout << buffer2 << endl;
																		people.set_father(buffer2);
																		//cout << people.get_father() << endl;

																		if (fgets(buffer_XML, MAXLINE2, file))
																		{
																			if ((strstr(buffer_XML, "<mother>") != NULL && strstr(buffer_XML, "</mother>") != NULL))
																			{

																				start = 0;
																				end = 0;
																				flag = 0;
																				for (int i = 0; i != strlen(buffer_XML); i++)
																				{
																					if (*(buffer_XML + i) == '>' && flag == 0)
																					{
																						start = i + 1;
																						flag++;
																					}
																					if (*(buffer_XML + i) == '<')
																					{
																						end = i;
																					}
																				}
																				free(buffer2);
																				buffer2 = (char*)calloc(end - start, (end - start) * sizeof(char*));
																				for (int i = 0, j = start; j != end; i++, j++)
																				{
																					*(buffer2 + i) = *(buffer_XML + j);
																				}
																				people.set_mother(buffer2);
																				//cout << people.get_mother() << endl;

																				if (fgets(buffer_XML, MAXLINE2, file))
																				{
																					if ((strstr(buffer_XML, "<children>") != NULL && strstr(buffer_XML, "</children>") != NULL))
																					{
																						//Лезть сюда, если пропадают дети
																						start = 0;
																						end = 0;
																						flag = 0;
																						for (int i = 0; i != strlen(buffer_XML); i++)
																						{
																							if (*(buffer_XML + i) == '>' && flag == 0)
																							{
																								start = i + 1;
																								flag++;
																							}
																							if (*(buffer_XML + i) == '<')
																							{
																								end = i;
																							}
																						}
																						free(buffer2);
																						buffer2 = (char*)calloc(end - start, (end - start) * sizeof(char*));
																						for (int i = 0, j = start; j != end; i++, j++)
																						{
																							*(buffer2 + i) = *(buffer_XML + j);
																						}
																						if (buffer2 != "NULL")
																						{
																							int cnt_zap = 0;
																							for (int i = 0; i != strlen(buffer2); i++)
																							{
																								if (buffer2[i] == ',')
																								{
																									cnt_zap++;
																								}

																							}
																							char* istr_child = strtok(buffer2, ",");

																							for (int i = 0; i != cnt_zap; i++)
																							{
																								cout << istr_child << endl;

																								char* buffer_children = (char*)calloc(strlen(istr_child), strlen(istr_child) * sizeof(char*));
																								strcpy(buffer_children, istr_child);
																								people.set_children(buffer_children);
																								istr_child = strtok(NULL, ",");
																							}

																						}

																						//cout << people.get_All_name_children_in_string() << endl;

																						if (fgets(buffer_XML, MAXLINE2, file))
																						{
																							if ((strstr(buffer_XML, "<deadday>") != NULL && strstr(buffer_XML, "</deadday>") != NULL))
																							{

																								start = 0;
																								end = 0;
																								flag = 0;
																								for (int i = 0; i != strlen(buffer_XML); i++)
																								{
																									if (*(buffer_XML + i) == '>' && flag == 0)
																									{
																										start = i + 1;
																										flag++;
																									}
																									if (*(buffer_XML + i) == '<')
																									{
																										end = i;
																									}
																								}
																								free(buffer2);
																								buffer2 = (char*)calloc(end - start, (end - start) * sizeof(char*));
																								for (int i = 0, j = start; j != end; i++, j++)
																								{
																									*(buffer2 + i) = *(buffer_XML + j);
																								}
																								//cout << buffer2 << endl;
																								people.set_deadday(buffer2);

																								if (fgets(buffer_XML, MAXLINE2, file))
																								{
																									if ((strstr(buffer_XML, "<day>") != NULL && strstr(buffer_XML, "</day>") != NULL))
																									{

																										start = 0;
																										end = 0;
																										flag = 0;
																										for (int i = 0; i != strlen(buffer_XML); i++)
																										{
																											if (*(buffer_XML + i) == '>' && flag == 0)
																											{
																												start = i + 1;
																												flag++;
																											}
																											if (*(buffer_XML + i) == '<')
																											{
																												end = i;
																											}
																										}
																										free(buffer2);
																										buffer2 = (char*)calloc(end - start, (end - start) * sizeof(char*));
																										for (int i = 0, j = start; j != end; i++, j++)
																										{
																											*(buffer2 + i) = *(buffer_XML + j);
																										}
																										people.set_day(buffer2);

																										if (fgets(buffer_XML, MAXLINE2, file))
																										{
																											if ((strstr(buffer_XML, "<month>") != NULL && strstr(buffer_XML, "</month>") != NULL))
																											{

																												start = 0;
																												end = 0;
																												flag = 0;
																												for (int i = 0; i != strlen(buffer_XML); i++)
																												{
																													if (*(buffer_XML + i) == '>' && flag == 0)
																													{
																														start = i + 1;
																														flag++;
																													}
																													if (*(buffer_XML + i) == '<')
																													{
																														end = i;
																													}
																												}
																												free(buffer2);
																												buffer2 = (char*)calloc(end - start, (end - start) * sizeof(char*));
																												for (int i = 0, j = start; j != end; i++, j++)
																												{
																													*(buffer2 + i) = *(buffer_XML + j);
																												}
																												people.set_month(buffer2);

																												if (fgets(buffer_XML, MAXLINE2, file))
																												{
																													if ((strstr(buffer_XML, "<year>") != NULL && strstr(buffer_XML, "</year>") != NULL))
																													{

																														start = 0;
																														end = 0;
																														flag = 0;
																														for (int i = 0; i != strlen(buffer_XML); i++)
																														{
																															if (*(buffer_XML + i) == '>' && flag == 0)
																															{
																																start = i + 1;
																																flag++;
																															}
																															if (*(buffer_XML + i) == '<')
																															{
																																end = i;
																															}
																														}
																														free(buffer2);
																														buffer2 = (char*)calloc(end - start, (end - start) * sizeof(char*));
																														for (int i = 0, j = start; j != end; i++, j++)
																														{
																															*(buffer2 + i) = *(buffer_XML + j);
																														}
																														people.set_year(buffer2);

																														if (fgets(buffer_XML, MAXLINE, file))
																														{
																															if ((strstr(buffer_XML, "<dayS>") != NULL && strstr(buffer_XML, "</dayS>") != NULL))
																															{

																																start = 0;
																																end = 0;
																																flag = 0;
																																for (int i = 0; i != strlen(buffer_XML); i++)
																																{
																																	if (*(buffer_XML + i) == '>' && flag == 0)
																																	{
																																		start = i + 1;
																																		flag++;
																																	}
																																	if (*(buffer_XML + i) == '<')
																																	{
																																		end = i;
																																	}
																																}
																																free(buffer2);
																																buffer2 = (char*)calloc(end - start, (end - start) * sizeof(char*));
																																for (int i = 0, j = start; j != end; i++, j++)
																																{
																																	*(buffer2 + i) = *(buffer_XML + j);
																																}
																																people.set_day_s(buffer2);

																																if (fgets(buffer_XML, MAXLINE, file))
																																{
																																	if ((strstr(buffer_XML, "<monthS>") != NULL && strstr(buffer_XML, "</monthS>") != NULL))
																																	{

																																		start = 0;
																																		end = 0;
																																		flag = 0;
																																		for (int i = 0; i != strlen(buffer_XML); i++)
																																		{
																																			if (*(buffer_XML + i) == '>' && flag == 0)
																																			{
																																				start = i + 1;
																																				flag++;
																																			}
																																			if (*(buffer_XML + i) == '<')
																																			{
																																				end = i;
																																			}
																																		}
																																		free(buffer2);
																																		buffer2 = (char*)calloc(end - start, (end - start) * sizeof(char*));
																																		for (int i = 0, j = start; j != end; i++, j++)
																																		{
																																			*(buffer2 + i) = *(buffer_XML + j);
																																		}
																																		people.set_month_s(buffer2);

																																		if (fgets(buffer_XML, MAXLINE, file))
																																		{
																																			if ((strstr(buffer_XML, "<yearS>") != NULL && strstr(buffer_XML, "</yearS>") != NULL))
																																			{

																																				start = 0;
																																				end = 0;
																																				flag = 0;
																																				for (int i = 0; i != strlen(buffer_XML); i++)
																																				{
																																					if (*(buffer_XML + i) == '>' && flag == 0)
																																					{
																																						start = i + 1;
																																						flag++;
																																					}
																																					if (*(buffer_XML + i) == '<')
																																					{
																																						end = i;
																																					}
																																				}
																																				free(buffer2);
																																				buffer2 = (char*)calloc(end - start, (end - start) * sizeof(char*));
																																				for (int i = 0, j = start; j != end; i++, j++)
																																				{
																																					*(buffer2 + i) = *(buffer_XML + j);
																																				}
																																				people.set_year_s(buffer2);
																																				free(buffer2);

																																				this->add(people, size);
																																				size++;
																																				if (size >= length)
																																				{
																																					this->resize(length + 2);
																																				}
																																			}
																																			else
																																			{
																																				throw - 1;
																																			}
																																		}
																																		else
																																		{
																																			throw - 1;
																																		}
																																	}
																																	else
																																	{
																																		throw - 1;
																																	}
																																}
																																else
																																{
																																	throw - 1;
																																}
																															}
																															else
																															{
																																throw - 1;
																															}
																														}
																														else
																														{
																															throw - 1;
																														}
																													}
																													else
																													{
																														throw - 1;
																													}
																												}
																												else
																												{
																													throw - 1;
																												}

																											}
																											else
																											{
																												throw - 1;
																											}
																										}
																										else
																										{
																											throw - 1;
																										}
																									}
																									else
																									{
																										throw - 1;
																									}
																								}
																								else
																								{
																									throw - 1;
																								}

																							}
																							else
																							{
																								throw - 1;
																							}
																						}
																						else
																						{
																							throw - 1;
																						}
																					}
																					else
																					{
																						throw - 1;
																					}
																				}
																				else
																				{
																					throw - 1;
																				}

																			}
																			else
																			{
																				throw - 1;
																			}
																		}
																		else
																		{
																			throw - 1;
																		}
																	}
																	else
																	{
																		throw - 1;
																	}


																}
																else
																{
																	throw - 1;
																}


															}
															else
															{
																throw - 1;
															}
														}
														else
														{
															throw - 1;
														}

													}
													else
													{
														throw - 1;
													}

												}
												else
												{
													throw - 1;
												}
											}
											else
											{
												throw - 1;
											}
										}
										else
										{
											throw - 1;
										}
									}
								}
								else
								{
									throw - 1;
								}

							}
							else
							{
								throw - 1;
							}
						}
						else
						{
							throw - 1;
						}

					}
					else
					{
						throw - 1;
					}
				}
				else
				{
					throw - 1;
				}










			}
			if (strstr(buffer_XML, "</Keeper>") != NULL)
			{
				end_tag++;
			}

		}




		if (starter_tag == 1 && end_tag == 2)
		{
			//this->erase();
		}
		else
		{
			this->erase();
			throw - 1;
		}

	}
	catch (int a)
	{
		cout << "Файл битый. Нету открывающего, либо закрывающего тега\n";
	}
	catch (exception ex1)
	{
		cout << "File XML dont open!\n";
		return;

	}

}
