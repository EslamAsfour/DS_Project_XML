#include "stdafx.h"
#include "XML_Tree.h"


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
