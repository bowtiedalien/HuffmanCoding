#include <fstream>
#include "HuffmanCoding.h"
#include <iomanip>
#include <math.h>

int main()
{
	ifstream myfile;

	/*Printing the text */

	myfile.open("text1.txt");
	if (!myfile.is_open())
		cout << "There was an error opening the file." << endl;
	string line;
	cout << "Printing text ..." << endl;
	for (int i = 0; !myfile.eof(); i++)
	{
		getline(myfile, line);
		cout << line << endl;
	}
	myfile.clear();
	

	/* Reading text file and creating array of frequencies */

	myfile.seekg(0, std::ios::beg);			//reset file pointer to beginning of file to read again
	char letter;

	int freqArr[26] = { 0 };		//huffman frequency table initialised to all zeros
	for (int i=0;!myfile.eof();i++)
	{
		myfile >> letter; 
		if (notAlphabet(letter)) 
			continue;
		else
			freqArr[mapLetterstoNums(letter)-1]++; 
	}

	cout << endl;
	myfile.clear();

	/*Print frequencies array*/

	myfile.seekg(0, std::ios::beg);
	cout << "Printing array .. " << endl;
	for (int i = 0; i < 26; i++)
	{
		cout << freqArr[i] << "|";
	}
	cout << endl;
	myfile.clear();

	/* Constructing priority queue of nodes */
	priority_queue<nodeType, vector<nodeType>, comp> pq;

	nodeType inputNode;
	for (int i = 0; i < 26; i++)
	{
		inputNode.data = mapNumstoLetters(i);		//stores the character
		inputNode.freq = freqArr[i];			
		pq.emplace(inputNode);
	}


	/* Building Huffman tree */

	nodeType* sumNode = nullptr;		//basically my root node
	while(pq.size()>=2)
	{
		sumNode = new nodeType;

		nodeType* holder = new nodeType;
		*holder = pq.top();
 		pq.pop();
		nodeType* holder2 = new nodeType;
		*holder2 = pq.top();
		pq.pop();

		sumNode->data = '*';
		sumNode->freq = holder->freq + holder2->freq;
		sumNode->lLink = holder;
		sumNode->rLink = holder2;

		pq.push(*sumNode);
	}

	/* ---------------------- SHOWING RESULTS ----------------------*/

	/*Printing uncompressed codes*/

	cout << "\nprinting uncompressed file... " << endl;	
	float TotalsizeOfUncompressed = 0;		
	letter = '\0';			//reusing letter

		int j = 1;			//for organising output only
		while(!myfile.eof())
		{
			myfile >> letter;
			if (notAlphabet(letter))
				continue;
			else {
				cout << chartobin(letter);		//convert the char into binary
				cout << " ";
				TotalsizeOfUncompressed += 8;	//since each char takes 1 byte = 8 bits always
				if (j % 12 == 0)
					cout << endl;
				j++;
			}
		}
		myfile.clear();

	cout << "\nNumber of bits: " << TotalsizeOfUncompressed << " bits";
	string sizeofBinaryString;		//number of bits used to code a letter
	cout << endl;
	
	/*Printing compressed codes*/

	vector<string> CodesArray(26);  //array to store huffman codes
	string s = "";
	getCodes(sumNode, s, CodesArray);		//computing codes from tree
	float TotalsizeOfCompressed = 0;
	cout << "\nprinting compressed file..." << endl;
	
		myfile.seekg(0, std::ios::beg);
		int k = 1;				//organising output only
		letter = '\0';			//reusing input variable
		while(!myfile.eof())
		{
			myfile >> letter;
			if (notAlphabet(letter))
				continue;
			else {
				cout << CodesArray[mapLetterstoNums(letter) - 1] << " ";
				for (char c : CodesArray[mapLetterstoNums(letter) - 1])
					TotalsizeOfCompressed++;
				cout << " ";
				if (k % 17 == 0)			//just for organising output
					cout << endl;
				k++;
			}
		
		}
		myfile.close();

	/* Comparing normal encoding and Huffman encoding */

	cout << "\nNumber of bits: " << TotalsizeOfCompressed << " bits";
	cout << "\nPercentage of space saved: " << 100 - (TotalsizeOfCompressed / TotalsizeOfUncompressed) * 100.0 << " %";
	cout << endl;

	system("pause");
	return 0;
}

/*
	Concepts from this code I did not absorb well: 
		1. recursive functions. How does getCodes() work under the hood?
		2. chartobin() - go back over it and understand carefully
*/
