#include<iostream>
#include<string.h>
using namespace std;

class book{
    char *name;
    char *author;
    char *publisher;
    int price;
    int stock;
    public:
        book(){}
        ~book(){
            delete(name);
            delete(author);
            delete(publisher);
        }
        void set(char *n,char *a,char *p,int pr,int s){
            int size=strlen(n);
            name=new char[size+1];
            strcpy(name,n);
            size=strlen(a);
            author=new char[size+1];
            strcpy(author,a);
            size=strlen(a);
            publisher=new char[size+1];
            strcpy(publisher,p);
            price=pr;
            stock=s;
        }
    
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Author: "<<author<<endl;
        cout<<"Publisher: "<<publisher<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Stock: "<<stock<<endl;

    }

    void searchbook(book b[],char *n,char *a,int no){
        int i;
        for(i=0;i<no;i++){
            if(strcmp(b[i].name,n)&&(strcmp(b[i].author,a))){
                if(b[i].stock>0){
                    b[i].display();
                    cout<<"Enter the no. of books you want"<<endl;
                    int c;
                    cin>>c;
                    if(c>b[i].stock){
                        cout<<"Invalid quantity"<<endl;    
                    }
                    else{
                        cout<<"Total cost"<<c*b[i].price<<endl;
                        b[i].stock=b[i].stock-c;
                    }
                }
                else{
                    cout<<"Stock Not Avaliable"<<endl;
                }
            }
        }
    }
};

int main(){
    int ch;int i=0;
    char name[50];
    char author[50];
    char publisher[50];
    int price;
    int stock;
    cout<<"\n How many books data u want to enter";
    int n;
    cin>>n;
    book b[n];
    do{
        cout<<"\nBook Store";
        cout<<"\n 1.Insert Details of book \n 2.Display \n 3.search \n 4.exit";
        cout<<"\n Enter Your Choice:";
        cin>>ch;
        switch(ch)
        {
        case 1:
        for(i=0;i<n;i++)
        {
            cout<<"\n Enter the name of Book:";
            cin>>name;
            cout<<"\n Enter The Name Of Author:";
            cin>>author;
            cout<<"\n Enter The name of Publisher:";
            cin>>publisher;
            cout<<"\n Enter the Price of book:";
            cin>>price;
            cout<<"\n Enter Stock of book:";
            cin>>stock;
            b[i].set(name,author,publisher,price,stock);
        }
        break;
        case 2:
        for(int j=0;j<n;j++)
        {
            cout<<"\n";
            b[j].display();   
        }
        break;
        case 3:
        cout<<"\n Enter title of required book";
        cin>>name;
        cout<<"\n Enter author of required book";
        cin>>author;
        b[0].searchbook(b,name,author,i);         
        break;
        case 4: exit(EXIT_SUCCESS);
        break;
        default :
        cout<<"\n Wrong Choice";
        break;
     } 
    }while(ch!=5);
    return 0;
}