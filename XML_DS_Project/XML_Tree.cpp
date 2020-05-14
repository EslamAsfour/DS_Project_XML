#include "stdafx.h"
#include "XML_Tree.h"
#include <iostream>
#include <string>

XML_Tree::XML_Tree()
{
	Head = NULL;
}

XML_Tree::XML_Tree(Node* Head)
{
	this->Head = Head;
}


XML_Tree::~XML_Tree()
{
}

void XML_Tree::insertChild(Node* child)
{
	//FirstNode
	if (Head == NULL)
	{
		Head = child;
		MostRecent = child;
		Head->Parent = NULL;
		return;
	}
	if (MostRecent->done == false)
	{	
		child->Parent = MostRecent;
		MostRecent->Children.push_back(child);
		MostRecent = child;
	}
	else if (MostRecent->done == true)
	{
		MostRecent = MostRecent->Parent;
		insertChild(child);
	}

}

Node * XML_Tree::returnRecentNode()
{
	return MostRecent;
}

void XML_Tree::DoneNode()
{
	MostRecent->done = true;
	MostRecent = MostRecent->Parent;
}

void XML_Tree::print( Node* head ,int level = 0)
{
	std::string tab = "";
	for (int i = 0; i < level; i++)
		tab += "\t";
	if (head->Attribute == "")
	{
		std::cout <<  tab +  "<" + head->TagName + head->Attribute + ">" << std::endl;
	}
	else
		std::cout << tab +"<" + head->TagName + " "+head->Attribute + ">" << std::endl;
	
	if (head->Children.size() != 0)
	{
		for (int i = 0; i < head->Children.size(); i++)
		{
			print(head->Children[i], level + 1);
		}
	}
	if (head->Data != "")
	{
		
		std::cout <<  tab + "\t"+ head->Data << std::endl;
		
	}
	if (head->Attribute != "")
		if (head->Attribute[head->Attribute.length() - 1] == '/')
			return;
	std::cout << tab + "</" + head->TagName + ">" << std::endl;
}
