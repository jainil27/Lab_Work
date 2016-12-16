#include<iostream>
#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<process.h>
using namespace std;

struct node
{
        int data;
        node* uplink;
        node* dwnlink;
};

class link_list
{
        node* head=NULL;

        public:

        void push(int);
        int pop();
        void display();
        void rev_disp();
};

main()
{

        int ch,temp;
        link_list l;
        while(1)
        {
                cout<<"\n\n\t\tDoubly Linked List"
                    <<"\n1) Push\n2) Pop \n3) Display\n4) Reverse Display\n5) Exit\n\nEnter your choice...";
                cin>>ch;
                switch(ch)
                {
                        case 1 : cout<<"Enter element to push : ";
                        cin>>temp;
                        l.push(temp);
                        break;
                        case 2 : cout<<"Element popped is "<<l.pop();
                        break;
                        case 3 :cout<<"\n\n\t";
                                cout<<"The Link list is : ";
                        l.display();
                        break;
                        case 4 : cout<<"\n\n\t";
                                cout<<"The Link list is : ";
                                l.rev_disp();
                                break;
                        case 5 : exit(0);
                        default: cout<<"Invalid Choice";

                }

        }
}

void link_list::push(int d)
{
        node* p=new node;
        p->data=d;
        p->uplink=NULL;
        p->dwnlink=NULL;
        if(head==NULL)
        {
                head=p;
        }
        else
        {

                node* ptr=head,*parent;
                while(ptr!=NULL)
                {
                        parent=ptr;
                        ptr=ptr->dwnlink;
                }
                parent->dwnlink=p;
                p->uplink=parent;
        }
}

int link_list::pop()
{
        int temp;
        temp=head->data;
        head=head->dwnlink;
        return temp;
}

void link_list::display()
{
        node* ptr=head;

        while(ptr!=NULL)
        {
                cout<<ptr->data<<" ";
                ptr=ptr->dwnlink;
        }
}

void link_list::rev_disp()
{
        node* ptr=head,*parent;
        while(ptr!=NULL)
        {
                parent=ptr;
                ptr=ptr->dwnlink;
        }
        while(parent!=NULL)
        {
                cout<<parent->data<<" ";
                parent=parent->uplink;
        }
}
