#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *Create(int);
Node *insert_beg(Node*, int);
Node *insert_end(Node*, int);
Node *delete_beg();
Node *delete_end();
void display(Node *head);


Node * Create(int item)
{
    Node *nptr = new Node;
    nptr->data = item;
    nptr->next = NULL;
    return nptr;
}

Node *insert_beg(Node *head, int data)
{
    Node *np = Create(data);
    if(!head)
    {
        head = np;
        return head;
    }
    np->next = head;
    head = np;
    return head;
}

Node *insert_end(Node *head, int x)
{
    Node *fst = Create(x);
    Node *snd = head;
    if(head == NULL)
    {
        head = fst;
        return head;
    }
    while(snd->next != NULL)
    {
        snd = snd->next;
    }
    snd->next = fst;
    return head;
}

Node *delete_beg(Node *head)
{
    Node *fst=NULL;
    if(head==NULL)
    {
        cout<<"List is Empty, so nothing to delete";
        return head;
    }
    else
    {
        fst=head->next;
        delete(head);
    }
    return fst;
}
Node *delete_end(Node *head)
{
    Node *temp=head;
    if(head==NULL)
    {
        cout<<"List is Empty, so nothing to delete";
        return head;
    }
    if(head->next==NULL)
    {
        delete head;
        return NULL;
    }
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
    return head;
}

void display(Node *head)
{
    if(!head)
    {
        cout<<"\nThere are no values in the list"<<endl;
        return;
    }
    Node *snd = head;
    cout<<"\nList elements are:"<<endl;
    while(snd!=NULL)
    {
        cout<<snd->data<<" ";
        snd = snd->next;
    }
}


int main()
{
    Node *head = NULL;
    
    //delete_beg(head);
    
    cout<<"\nAdding values to list from begining"<<endl;
    head = insert_beg(head,10);
    head = insert_beg(head,20);
    head = insert_beg(head,30);
    display(head);
    cout<<"\nDeleting  value from begining"<<endl;
    head = delete_beg(head);
    display(head);
    cout<<"\nDeleting  value from begining"<<endl;
    head = delete_beg(head);
    display(head);
    cout<<"\nDeleting  value from begining"<<endl;
    head = delete_beg(head);
    display(head);

    cout<<"\nAdding values to list from end"<<endl;
    head = insert_end(head,10);
    head = insert_end(head,20);
    head = insert_end(head,30);
    display(head);
    cout<<"\nDeleting  value from end"<<endl;
    head = delete_end(head);
    display(head);
    cout<<"\nDeleting  value from end"<<endl;
    head = delete_end(head);
    display(head);
    cout<<"\nDeleting  value from end"<<endl;
    head = delete_end(head);
    display(head);
    return 0;
}
