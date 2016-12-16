#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>

using namespace std;

struct node
{
        int data;
        node* lnode;
        node* rnode;
};
class btree
{
 public:       node* root=NULL;

        void insert(int d)
        {
                node* p=new node;
                p->data=d;
                p->lnode=NULL;
                p->rnode=NULL;
                if(root==NULL)
                {
                       root=p;
                }
                else
                {
                        node* ptr=root,*parent;
                        while(ptr!=NULL)
                        {
                                parent=ptr;
                                if(d<=ptr->data)
                                        ptr=ptr->lnode;
                                else
                                        ptr=ptr->rnode;
                        }
                        if(d<=parent->data)
                                parent->lnode=p;
                        else
                                parent->rnode=p;
                }
        }
        void search(int d)
        {
                int level=0;
                node* ptr=root;
                while(ptr!=NULL)
                {
                        if(ptr->data==d)
                                {
                                        cout<<"Element found at level "<<level;
                                        break;
                                }

                        else{
                                level++;
                                if(d<ptr->data)
                                        ptr=ptr->lnode;
                                else
                                        ptr=ptr->rnode;

                        }
                }
        }
        void inorder(node *ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->lnode);
		cout<<"  "<<ptr->data<<"     ";
		inorder(ptr->rnode);
	}
}
};
//node* root=NULL;
main()
{
        char ch='y';
        btree b;
        while(ch=='y')
        {
                int num,d;
//                clrscr();
                system("cls");
                cout<<"\t\tBinary Tree";
                cout<<"\n\n1) Add Data";
                cout<<"\n\n2) Search";
                cout<<"\n\n3) Exit";
                cout<<"\n\nEnter choice : ";
                cin>>num;
                switch(num)
                {
                case 1 : cout<<"Enter number : ";
                        cin>>d;
                        b.insert(d);
                        break;

                case 2 :cout<<"Enter number : ";
                        cin>>d;
                        b.search(d);
                case 3 : exit(0);
                default : cout<<"Invalid choice";
                }
                b.inorder(b.root);
                cout<<"Do you want to continue ?";
                cin>>ch;
        }
}

