#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

int lcm(int arr[7],int n);
int gcd(int a,int b);


struct player
{
        char name[15];
        int pnts;
}*p1,*p2,p[2];

player& get_player(char []);

main()
{
        int N,i=0,itr=1;
        int num;
        int t[7];
        char c,name[15];
        cin>>N;
        if(N<=0||N>10)
        {
                cout<<"Invalid Input";
                exit(0);
        }
        while(N)
        {

                int ans;
                {
                        //Question line
                        i=0;
                        if(itr==1)
                        {
                                cin>>p[0].name;
                                p1= &p[0];
                        }
                        else
                        {
                                cin>>name;
                                p1=&get_player(name);
                        }
                        while(cin>>num)
                        {

                                if(num<1||num>100)
                                {
                                        cout<<"Invalid Input";
                                        exit(0);
                                }
                                t[i]=int(num);

                                c=getchar();


                                if(int(c)==44)
                                        {
                                                i++;
                                                continue;
                                        }
                                else
                                        break;


                        }
                        N-=2;

                        ans=lcm(t,i);
                }
                        if(i<1||i>6)
                        {
                                cout<<"Invalid Input";
                                exit(0);
                        }
                        char a[20];     // Max size of ans
                {
                        //Answer line
                        char tmp;
                        cin>>tmp;       //This must be 'A'
                        {
                                if(int(tmp)!=65)
                                {
                                        cout<<"Invalid Input";
                                        exit(0);
                                }
                        }
                        if(itr==1)
                        {
                                cin>>p[1].name;
                                p2=&p[1];
                        }
                        else
                        {
                                cin>>name;
                                p2=&get_player(name);
                        }
                        cin>>a;


                }
                {
                        //Output
                        cout<<p1->name<<"'s question is: "<<t[0];
                        for(int j=1;j<=i;j++)
                                cout<<","<<t[j];
                        if(atoi(a)==ans)
                        {
                                cout<<"\nCorrect Answer";
                                p2->pnts+=10;
                                cout<<"\n"<<p2->name<<": 10points\n";
                        }
                        else if(strcmp(a,"PASS")==0)
                        {
                                cout<<"\nQuestion is PASSed";
                                cout<<"\nAnswer is: "<<ans;
                                cout<<"\n"<<p2->name<<": 0points\n";
                        }
                        else
                        {
                                cout<<"\nWrong Answer";
                                cout<<"\n"<<p2->name<<": 0points\n";
                        }

                }

        itr++;
        }
        cout<<"Total Points:\n";
        cout<<p[0].name<<": "<<p[0].pnts<<"points\n";
        cout<<p[1].name<<": "<<p[1].pnts<<"points\n";
        if(p[0].pnts>p[1].pnts)
        {
                cout<<"Game Result: "<<p[0].name<<" is winner";
        }
        else if(p[0].pnts==p[1].pnts)
                 cout<<"Game Result: Draw";
        else
                 cout<<"Game Result: "<<p[1].name<<" is winner";

}



int lcm(int arr[7],int n)
{
   int result=1;
   for(int i=0;i<=n;i++)
      result=result*arr[i]/gcd(result,arr[i]);
   return result;
}

int gcd(int a,int b)
{
   if(b == 0)
      return a;
   else return gcd(b,a%b);
}

player& get_player(char pname[15])
{
        if(strcmp(p[0].name,pname)==0)
                return p[0];
        else if(strcmp(p[1].name,pname)==0)
                return p[1];
        else
               {
                       cout<<"Invalid Input";
                       exit(0);
               }

}
