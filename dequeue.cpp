#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iomanip>

using namespace std;

struct node
{
    int data;
    node* next;
};

class dequeue
{
    node* front;
    node* rear;
public:
    void ins_front(int);
    void ins_rear(int);
    void rem_front();
    void rem_rear();
    void display();
}dq;
main()
{
    int choice,d;
    cout<<"\t\tDouble Ended Queue.";
    cout<<"\n\n1) Input Restricted Doubly Ended QUEUE.";
    cout<<"\n2) Output Restricted Doubly Ended QUEUE.";
    cout<<"\n\nEnter Your Choice...";
    cin>>choice;
    switch(choice)
    {
    case 1: system("clear");
        label:
            cout<<"\t\tInput Restricted Doubly Ended Queue.";
            cout<<"\n\n1) Add Element to front.\n2) Remove from front.\n3) Remove from rear.\n4) Display.\n5)Exit.";
            cout<<"\n\nEnter your choice...";
            cin>>choice;
            switch(choice)
            {
                case 1: cout<<"Enter element to add : ";
                        cin>>d;
                        dq.ins_front(d);
                        break;
                case 2: dq.rem_front();
                        break;
                case 3: dq.rem_rear();
                        break;
                case 4: dq.display();
                        break;
                case 5: exit(0);
                default: cout<<"Invalid Choice.";
            }
            goto label;
            break;
    case 2: system("clear");
        tag:
            cout<<"\t\tOutput Restricted Doubly Ended Queue.";
            cout<<"\n\n1) Add Element to front.\n2) Add element to rear.\n3) Remove from rear.\n4) Display.\n5)Exit.";
            cout<<"\n\nEnter your choice...";
            cin>>choice;
            switch(choice)
            {
                case 1: cout<<"Enter element to add : ";
                        cin>>d;
                        dq.ins_front(d);
                        break;
                case 2: cout<<"Enter element to add : ";
                        cin>>d;
                        dq.ins_rear(d);
                        break;
                case 3: dq.rem_rear();
                        break;
                case 4: dq.display();
                        break;
                default: cout<<"Invalid Choice.";
            }
            goto tag;
            break;
        default: cout<<"Invalid choice. ";

    }
}

void dequeue::ins_front(int d)
{
    node* p=new node;
    p->data=d;
    p->next=NULL;
    if(front=NULL)
    {
        front=rear=p;
    }
    else
    {
        p->next=front;
        front=p;
    }
}

void dequeue::ins_rear(int d)
{
    node* p=new node;
    p->data=d;
    p->next=NULL;
    if(front=NULL)
    {
        front=rear=p;
    }
    else
    {
        rear->next=p;
        rear=p;
    }
}

void dequeue::rem_front()
{
    if(front==NULL)
    {
        cout<<"\nQueue is EMPTY.";
        return;
    }
    else
    {
        cout<<"\nElement Removed is : "<<front->data;
        dq.display();
    }
}

void dequeue::rem_rear()
{
    if(front==NULL)
    {
        cout<<"\nQueue is EMPTY.";
        return;
    }
    else
    {
        node* temp=front;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        cout<<"\nElement removed is : "<<temp->next->data;
        temp->next=NULL;
        rear=temp;
        dq.display();
    }
}

void dequeue::display()
{
    node* temp;
    temp=front;
    while(temp->next!=NULL)
    {
        cout<<" "<<temp->data;
        temp=temp->next;
    }
    cout<<" "<<temp->data;
}
