#include<iostream>
#include<string.h>
using namespace std;

struct node{
    string label;
    int count;
    struct node *child[10];
}*root;

class GT{
    public:
    int i,j,tchapters;
    GT(){
        root = NULL;
    }
    void create()
    {
        root = new node;
        cout<<"enter name of a book:";
        cin>>root->label;
        cout<<"enter number of chapters:";
        cin>>root->count;
        for(i=0;i<root->count;i++)
        {
            root->child[i] = new node;
            cout<<"enter name of chapter"<<" "<<i+1<<":";
            cin>>root->child[i]->label;
            cout<<"enter number of section in chapter"<<" "<<i+1<<":";
            cin>>root->child[i]->count;
            for(j=0;j<root->child[i]->count;j++)
            {
                root->child[i]->child[j] = new node;
                cout<<"enter name of section"<<" "<<i+1<<"."<<j+1<<":";
                cin>>root->child[i]->child[j]->label;
            }
        }
    }
    
    void display(node *r1){
        if(r1 != NULL)
        {
            cout<<"Book Title:"<<r1->label<<endl;
            tchapters = r1->count;
            for(i=0;i<r1->count;i++)
            {
                cout<<"name of chapter"<<" "<<i+1<<":"<<r1->child[i]->label<<endl;
                for(j=0;j<r1->child[i]->count;j++)
                {
                    cout<<"section"<<" "<<i+1<<"."<<j+1<<":"<<r1->child[i]->child[j]->label<<endl;
                }
            }
        }
        
    }
};

int main(){
    int ch;
    GT g;
    while(1)
    {
        cout<<"1.create"<<endl;
        cout<<"2.display"<<endl;
        cout<<"3.exit"<<endl;
        cout<<"enter your choice:"<<endl;
        cin>>ch;
    
    switch(ch)
      {
        case 1:
        cout<<"Tree is creating!"<<endl;
        g.create();
        break;
        
        case 2:
        cout<<"Displaying the tree!"<<endl;
        g.display(root);
        break;
        
        case 3:
        cout<<"program is exited!";
        break;
       }
    }
    return 0;
}
