#pragma once
#include <string>
#include <vector>
struct Node
{
	std::string Data;
	std::string Attribute;
	std::string TagName;
	std::vector<Node*>Children;
	Node* Parent;
	bool done;
	
	//Constructor
	Node( std::string Attr , std::string Name , std::string DataIn = "")
	{
		Data = DataIn;
		Attribute = Attr;
		TagName = Name;
		done = false;
		Parent = NULL;
	}
};


class XML_Tree
{
private:
	Node* Head;
	Node* MostRecent;
public:
	XML_Tree();
	XML_Tree(Node* Head);
	~XML_Tree();
	void insertChild(Node *child);
	Node* returnRecentNode();
	void DoneNode();
};

