#pragma once
#include <vector>
#include <queue>
#include <iostream>
#include <string>
using namespace std;

struct nodeType {
public:
	int freq;
	nodeType* rLink = nullptr;
	nodeType* lLink = nullptr;
	char data;
};

struct comp {
	bool operator()(const nodeType lhs, const nodeType rhs)
	{
		if (lhs.freq > rhs.freq)
			return true;
		else if (lhs.freq == rhs.freq && rhs.data > lhs.data)
			return false;
		else if (lhs.freq == rhs.freq && lhs.data > rhs.data)
			return true;
		else
			return false;
	}
};

/* Function that takes a letter and maps it to an int index for the frequencies array */
int mapLetterstoNums(char a)
{
	int num;

	switch (a) {
	case 'A':
	case 'a':
		num = 1;
		break;
	case 'B':
	case 'b':
		num = 2;
		break;
	case 'C':
	case 'c':
		num = 3;
		break;
	case 'D':
	case 'd':
		num = 4;
		break;
	case 'E':
	case 'e':
		num = 5;
		break;
	case 'F':
	case 'f':
		num = 6;
		break;
	case 'G':
	case 'g':
		num = 7;
		break;
	case 'H':
	case 'h':
		num = 8;
		break;
	case 'I':
	case 'i':
		num = 9;
		break;
	case 'J':
	case 'j':
		num = 10;
		break;
	case 'K':
	case 'k':
		num = 11;
		break;
	case 'L':
	case 'l':
		num = 12;
		break;
	case 'M':
	case 'm':
		num = 13;
		break;
	case 'N':
	case 'n':
		num = 14;
		break;
	case 'O':
	case 'o':
		num = 15;
		break;
	case 'P':
	case 'p':
		num = 16;
		break;
	case 'Q':
	case 'q':
		num = 17;
		break;
	case 'R':
	case 'r':
		num = 18;
		break;
	case 'S':
	case 's':
		num = 19;
		break;
	case 'T':
	case 't':
		num = 20;
		break;
	case 'U':
	case 'u':
		num = 21;
		break;
	case 'V':
	case 'v':
		num = 22;
		break;
	case 'W':
	case 'w':
		num = 23;
		break;
	case 'X':
	case 'x':
		num = 24;
		break;
	case 'Y':
	case 'y':
		num = 25;
		break;
	case 'Z':
	case 'z':
		num = 26;
		break;
	}

	return num;
}

/* Function that takes array int index and maps it to its corresponding letter */
char mapNumstoLetters(int a)
{
	char c;
	c = a + 97;
	return c;
}

/* Function that removes commas, dots, and others non-letter characters from the input file*/
bool notAlphabet(char a)
{
	if (a > 90 && a < 97)
		return true;
	if (a > 122)
		return true;
	if (a < 65)
		return true;
	return false;
}

/* Function that converts characters to binary strings - source used is mentioned at the end of HuffmanCoding.h*/
char* chartobin(unsigned char c)  //function that converts char to binary
{
	static char bin[CHAR_BIT + 1] = { 0 };
	int i;

	for (i = CHAR_BIT - 1; i >= 0; i--)
	{
		bin[i] = (c % 2) + '0';		
		c /= 2;
	}

	return bin;
}

/* Function that traverses Huffman tree and extracts compressed codes for each letter*/
void getCodes(nodeType* root, string str, vector<string>& arr) 
{
	//str argument is the code that will be computed by the function and placed in arr
	//I send it as an argument because this is a recursive function, calling it repeatedly changes any variables
	//defined inside it. 
	
	if (root == nullptr)
		return;

	if (root->data == '*')
	{
		 getCodes(root->lLink, str + "0", arr);
		 getCodes(root->rLink, str + "1",arr);
	}

	if (root->data != '*')
	{
		arr[mapLetterstoNums(root->data)-1] = str;
		str = "";
		//std::cout << root->data << " : " << str << "\n";
		 getCodes(root->lLink, str + "0",arr);
		 getCodes(root->rLink, str + "1",arr);
	}
};

/*
sources:
	1. https://snipplr.com/view/43723/ - chartobin() function
	2. https://codereview.stackexchange.com/questions/175193/huffman-coding-in-c - getCodes() function
*/

