// XML_DS_Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include "XML_Tree.h"

using namespace std;

void formatting_xml(Node *N);

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
	
	inFile.close();
	formatting_xml(Main.GetHead());
    return 0;
}




void formatting_xml(Node *N)
{

	string tab = " ";

	string TN;
	//print opening tag
	if (N->Attribute == "" && N->Data == "")
	{
		TN = "<" + N->TagName + ">";
	}

	else if (N->Attribute != "" && N->Data == "")
	{
		TN = "<" + N->TagName + N->Attribute + ">";
	}

	else if (N->Attribute == "" && N->Data != "")
	{
		TN = "<" + N->TagName + ">" + N->Data;
	}

	else
	{
		TN = "<" + N->TagName + N->Attribute + ">" + N->Data;
	}
	cout << tab << TN << endl;

	tab += " ";
	for (int i = 0; i<N->Children.size(); ++i)
	{
		if (N->Children[i] != NULL)
			formatting_xml(N->Children[i]);
	}

	tab += " ";
	tab.erase(0, 1);

	TN = "</" + N->TagName + ">";
	cout << tab << TN << endl;

}