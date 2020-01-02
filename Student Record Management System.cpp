#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
class Student{
	public:
	int roll_no;
	char name[20] ;
};
class Node{
	public:
	Student data;
	Node *next;
};
class operations{
	private:
		Node * list1_head;
		Node * list2_head;
	public:
		list_Entry1();
		list_Entry2();
		printlist1();
		printlist2();
		deletenode1(int roll_no);
		deletenode2(int roll_no);
		unionlist();
		intersectionlist();
		mergesort();
};
operations::mergesort(){
	
}
operations::intersectionlist(){
	Node *new_list1=new Node;
	Node *new_list2=new Node;
	new_list1=list1_head;
	new_list2=list2_head;
	if(new_list1==NULL || new_list2==NULL){
		cout<<"No Intersection can be done because one of the list is empty"<<endl;
	}
	while(new_list1!=NULL){
		while(new_list2!=NULL){
			if(new_list1->data.roll_no == new_list2->data.roll_no){
				cout<<new_list1->data.roll_no<<" "<<new_list1->data.name<<endl;
			}
			new_list2=new_list2->next;
		}
		new_list1=new_list1->next;
	}
}
operations::unionlist(){
		Node *new_list1=new Node;
	Node *new_list2=new Node;
	new_list1=list1_head;
	new_list2=list2_head;
	printlist1();
	if(new_list1==NULL || new_list2==NULL){
		cout<<"No Intersection can be done because one of the list is empty"<<endl;
	}
	while(new_list1!=NULL){
		while(new_list2!=NULL){
			if(new_list1->data.roll_no == new_list2->data.roll_no){
				cout<<new_list1->data.roll_no<<" "<<new_list1->data.name<<endl;
			}
			new_list2=new_list2->next;
		}
		new_list1=new_list1->next;
	}	
}
operations::list_Entry1(){
	
	int roll_number;
	char character1[10];
	Node *new_node = new Node();
	Node *last = list1_head;
	cin>>roll_number>>character1;
		
	new_node->data.roll_no = roll_number;
	strcpy(new_node->data.name,character1);
	new_node->next=NULL;
	
	if(last == NULL){
		last = new_node;
		list1_head = new_node;
	}
	else{
		while(last->next!=NULL){
			last=last->next;
		}
		last->next = new_node;
		
	}
}
operations::list_Entry2()
{
	Node *new_node=new Node();
	Node *last = list2_head;
	int integer2;
	char character2[10];
	cin>>integer2>>character2;	
	new_node->data.roll_no=integer2;
	strcpy(new_node->data.name,character2);
	new_node->next=NULL;
	if(last == NULL){
		last = new_node;
		list2_head = new_node;
	}
	else{
		while(last->next!=NULL){
			last=last->next;
		}
		last->next = new_node;
		
	}
}
operations::printlist1()
{
	Node *new_node=list1_head;
	if(new_node==NULL)
		cout<<"list is empty";
	while(new_node!=NULL)
	{
		cout<<new_node->data.roll_no<<" "<<new_node->data.name<<"\n";
		new_node=new_node->next;
	}
}
operations::printlist2()
{
	Node *new_node=list2_head;
	if(new_node==NULL)
		cout<<"list is empty";
	while(new_node!=NULL)
	{
		cout<<new_node->data.roll_no<<" "<<new_node->data.name<<endl;
		new_node=new_node->next;
	}
}
operations::deletenode1(int roll_no)
{
	Node *new_node=list1_head;
	Node *last=list1_head;
	if(new_node==NULL)
		cout<<"List is Empty";
	while(last!=NULL)
	{
		if(last->data.roll_no==roll_no)
		{
			new_node->next=last->next;
			cout<<roll_no<<"Deleted"<<endl;
		}
		new_node=last;
		last=last->next;
	}
}
operations::deletenode2(int roll_no)
{
	Node *new_node=list2_head;
	Node *last=list2_head;
	if(new_node==NULL)
		cout<<"List is Empty";
	while(last!=NULL)
	{	
		if(last->data.roll_no==roll_no)
		{
			new_node->next=last->next;
			cout<<roll_no<<"Deleted"<<endl;
		}
		new_node=last;
		last=last->next;
	}
}
int main()
{
	int size1, size2, choice_1, choice_2,roll_no;
	operations * op= new operations(); 
	while(1)
	{
		cout<< "\nEnter\n1.Insert\n2.Delete\n3.print\n4.Union\n5.Intersection\n6.MergeSort\n7.Exit\nEnter your choice:";
		cin>> choice_1;
		switch(choice_1)
		{
			case 1: cout<<"\nEnter \n1.To create First List \n2.to create Second List\nEnter your choice:";
				cin>> choice_2;
				switch(choice_2)
				{
					case 1: cout<<"Enter the size of list 1:";
						cin>>size1;
						for(int i=0;i<size1;i++)
						{
							cout<<"Enter the roll no and data for the Student "<<i+1<<":\n";
							op->list_Entry1();
						}
						break;
					case 2: cout<<"Enter the size of list 2:";
						cin>>size2;
						for(int i=0;i<size2;i++)
						{
							cout<<"Enter the roll no and data for the Student "<<i+1<<":\n";
							op->list_Entry2();
						}	
						break;
					default:
						cout<<"Invalid Choice";
						break;
				}
				break;
			case 2:	cout<<"Enter \n1.To delete node in First List \n2.To delete node in Second List\nEnter your choice:";
				cin>> choice_2;
				switch(choice_2)
				{
					case 1:cout<<"Enter roll no which is to deleted";
						cin>>roll_no;
						op->deletenode1(roll_no);
						break;
					case 2:cout<<"Enter roll no which is to deleted";
						cin>>roll_no;
						op->deletenode2(roll_no);
						break;
					default:
						cout<<"Invalid Choice";
						break;
				}
				break;
			case 3: cout<<"Enter \n1.To print First List \n2.To print Second List\nEnter your choice:";
				cin>> choice_2;
				switch(choice_2)
				{
					case 1:op->printlist1();
						break;
					case 2:	op->printlist2();
						break;
					default:
						cout<<"Invalid Choice";
						break;
				}
				break;
			case 4:
				op->unionlist();
				break;
			case 5:	
				op->intersectionlist();
				break;
			case 6:
				op->mergesort();
				break;
			case 7:exit(0);
				break; 
			default:
				cout<<"Entered Invalid choice";
				break;
		}
	}
}
