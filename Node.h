#pragma once
#include <string>
#include <iostream>
using namespace std;
#pragma warning(disable : 4996)
class Node
{
public:
	char* children;
	Node* ptr;
	Node()
	{
		
		children = nullptr;
		ptr = nullptr;
	}

  };

