// XML_DS_Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include "XML_Tree.h"

using namespace std;



int main()
{
	string input;
	ifstream inFile;
	XML_Tree Main;
	int count = 0;
	inFile.open("test.txt");
	if (!inFile) {
		cout << "Unable to open file";
		exit(1); // terminate with error
	}
	while (std::getline(inFile,input)) 
	{
		
		
		//Opening Tag			// We can take Tag name and Attribute from this line
		if(input[0] == '<' && input[1] != '/' )
		{   
			
			count++;
			int index;
			// Searching for the space to get the tag name only from the line
			for (int i = 1; i < input.length(); i++)
			{
				index = i;
				if (input[i] == ' ')
				{
						//First white space in the tag
					break;
				}
			}
			string tag = input.substr(1, index-1);
			string att = input.substr(index + 1);
			// check if <tag attr/> "Opening and closing tag shortcut"
			if (input[input.length() - 2] == '/')
			{
				Node* In = new Node(att.substr(0, att.length() - 1), tag);
				Main.insertChild(In);
				Main.DoneNode();
			}
			else 
			{
				Node* In = new Node(att.substr(0, att.length() - 1), tag);
				Main.insertChild(In);
			}
			
			
		}
		//Closing tag
		else if (input[0] == '<' && input[1] == '/')
		{
			count--;
			Main.DoneNode();
		}
		//Data
		else
		{
			Node* mostRec = Main.returnRecentNode();
			mostRec->Data = input;
		}
	}
	Main.print(Main.GetHead() , 0);
	inFile.close();
	
    return 0;
}




