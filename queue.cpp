#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
#include<string.h>
#include<math.h>

using namespace std;

struct node
{
    int data;
    node* next;
}*start;

class queuee
{
    node* front=NULL;   // Try without assignment
    node* rear=NULL;
public:
    void add(int);
    void display();
    void removee();
}q;

main()
{
    int ch,temp;
//        queuee q;
        while(1)
        {
                cout<<"\n\n\t\tQueue"
                    <<"\n1) Add Element\n2) Remove Element \n3) Display\n4) Exit\n\nEnter your choice...";
                cin>>ch;
                switch(ch)
                {
                        case 1 : cout<<"Enter element to insert : ";
                        cin>>temp;
                        q.add(temp);
                        break;
                        case 2 : q.removee();
                        break;
                        case 3 :cout<<"\n\n\t";

                        q.display();
                        break;
                        case 4 : exit(0);
                        default: cout<<"Invalid Choice";

                }

        }
}

void queuee::add(int d)
{
    node*p = new node;
    p->data=d;
    p->next=NULL;
    if(front==NULL)
    {
        front=rear=p;
    }
    else
    {
        rear->next=p;
        rear=p;
    }
}

void queuee::display()
{
    if (front==NULL)
    {
        cout<<"\nQueue is Empty !";
        return;
    }
    node* p=front;
//    cout<<p->data;
 cout<<"\nThe Queue is : >>";
    while(p->next!=NULL)
    {
        cout<<" "<<p->data;
        p=p->next;
    }
    cout<<" "<<p->data;
}

void queuee::removee()
{
    if(front==NULL)
    {
        cout<<"Queue is Empty !!";
    }
    else{
    cout<<"Element removed is : "<<front->data;
    front=front->next;
    q.display();
    }
}
