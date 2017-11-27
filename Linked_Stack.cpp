#include<iostream>
using namespace std;

typedef char Stack_entry;
typedef Stack_entry Node_entry;

struct Node{
	Node_entry entry;
	Node* next;
	Node();
	Node(Node_entry item, Node *add_on=NULL);
};
Node::Node()
{
	next=NULL;
}
Node::Node(Node_entry item, Node *add_on)
{
	entry=item;
	next=add_on;
}
class Stack{
public:
	   bool empty() const{return top_node==NULL;}
	   int push(const Stack_entry &item);
	   int pop();
	   int top();
	   Stack operator=(const Stack &original);
	   Stack(){top_node=NULL;}
protected:
	Node* top_node;
	
};

int Stack::pop()
{
	Node*old_top=top_node;
	if(top_node==NULL)return 0;
	top_node=old_top->next;
	delete old_top;
	return 1;
}

int Stack::push(const Stack_entry&item)
{
	Node*new_top=new Node(item,top_node);
	if (new_top==NULL)return 0;
	top_node=new_top;
	return 1;
}

int Stack::top()
{
	if(top_node==NULL)return 0;
	cout<<top_node->entry<<" ";
	return 1;
}

Stack Stack::operator=(const Stack &original)
{
	Node *new_top,*new_copy,*original_node=original.top_node;
	if(original_node==NULL)new_top=NULL;
	else{
		new_copy=new_top=new Node(original_node->entry);
		while(original_node->next!=NULL)
		{
			original_node=original_node->next;
			new_copy->next=new Node(original_node->entry); 
			new_copy=new_copy->next;
		}
		while(!empty())
			pop();
			top_node=new_top;
	}
	return *this;
}

int main()
{
	Stack x,y,z;
	int i=0;
	char item;
	cout<<"ÇëÊäÈëz"<<endl;
	for(i=0;i<5;i++)
	{
			cin>>item;
			z.push(item);
	}
	cout<<"ÇëÊäÈëy"<<endl;
	for(i=0;i<5;i++)
	{
			cin>>item;
			y.push(item);
	}
	cout<<"ÇëÊäÈëx"<<endl;
	for(i=0;i<5;i++)
	{
		    cin>>item;
			x.push(item);
	}
	x=y=z;
	for(i=4;i>=0;i--)
	{
		cout<<"y."<<i<<"=";
		y.top();
		y.pop();
	}
	cout<<endl;
	for(i=4;i>=0;i--)
	{
		cout<<"x."<<i<<"=";
		x.top();
		x.pop();
	}
	system("pause");
	return 0;
}
