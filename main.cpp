#include <iostream>

struct node{
    int data;
    node* next = NULL;
};

void add_at_start(node*&h, node*&t, int d)
{
    node* newnode = new node;
    newnode->data = d;
    newnode->next = h;
    if(t == NULL) {t = newnode;}
    h = newnode;
}

void add_at_end(node*&h, node*&t, int d)
{
    if(t==NULL)
    {
        add_at_start(h, t, d);
        return;
    }
    
    node* newnode = new node;
    newnode->data = d;
    newnode->next = t->next;
    t->next = newnode;
    t = newnode;
}

void add_in_order(node*&h, node*&t, int d)
{
    node *temp1 = h;
    node *temp2 = h;
    node* newnode = new node;
    newnode->data = d;
    
    if(h==NULL)
    {
        h = newnode;
        t = newnode;
    }
    else
    {
        temp2 = temp2->next;
        
        if(temp1->data > d)
        {
            newnode->next = h;
            h = newnode;
        }
        else
        {
            while(temp2 != NULL)
            {
                if(temp2->data > d)
                {
                    break;
                }
                temp2 = temp2->next;
                temp1 = temp1->next;
            }
            
            if(t->data < d)
            {
                t = newnode;
            }
            newnode->next = temp1->next;
            temp1->next = newnode;
        }
    }
}

void remove_at_beginning(node*&h, node*&t)
{
    if(h == NULL)
    {
        return;
    }
    
    if(h->next == NULL)
    {
        delete h;
        h = NULL;
        t = NULL;
        return;
    }
    node *temp = h;
    h = h->next;
    delete temp;
}

void remove_at_end(node*&h, node*&t)
{
    if(h == NULL)
    {
        return;
    }
    
    if(h->next == NULL)
    {
        delete h;
        h = NULL;
        t = NULL;
        return;
    }
    
    node *temp = h;
    
    while(temp->next != t)
    {
        temp = temp->next;
    }
    
    t = temp;
    delete temp->next;
    temp->next = NULL;
}

void remove_data(node*&h, node*&t, int d)
{
    if(h->data == d)
    {
        remove_at_beginning(h, t);
    }
    
    else if(t->data == d)
    {
        remove_at_end(h, t);
    }
    
    else
    {
        node *before_data = h;
        node *after_data = NULL;
        
        while((before_data->next)->data != d && before_data->next != t)
        {
            before_data = before_data->next;
        }
        
        if(before_data->next->data == d)
        {
            after_data = before_data->next->next;
            delete before_data->next;
            before_data->next = after_data;
        }
    }
}

void traverse(node* h)
{
    node* i = new node;
    for(i = h; i != NULL; i = i->next) {
        std::cout << i->data << std::endl;}
}

int main()
{
    int numbers[5];
    node* h = NULL;
    node* t = NULL;
    for(int i = 0; i<5; i++) {
        std::cout<<"Enter a number:";
        std::cin >> numbers[i];
    }
    for(int i = 0; i<5; i++) {
        //add_at_start(h, t, numbers[i]);
        //add_at_end(h, t, numbers[i]);
        add_in_order(h, t, numbers[i]);
    }
    //remove_at_beginning(h, t);
    //remove_at_end(h, t);
    remove_data(h, t, 5);
    traverse(h);
}
