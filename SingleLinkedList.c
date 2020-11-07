#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct store
{
    
    char n[20];
    int a;
    
    struct store * next;
    
}store;
store *head,*tail;
int c=0;


store * create(store *next)
{
    store * node=(store *) malloc(sizeof(store));
    printf("enter name:");
    scanf("%s",node->n);
    printf("enter price: ");
    scanf("%d",&node->a);
    node->next = next;
    return node;
}


store * insertbegin(store * head)
{
    store * new=create(head);
    new->next=head;
    
    head=new;
    c++;
    return head;
    
   
}
store * insertend(store *tail)
{
    store * new = create (NULL);
    if(tail!=NULL)
    {
        tail->next=new;
    }
    
    tail=new;
    c++;
    return tail;
}
store * search (store * head , char name[] )
{
    
    if(head==NULL)
    {
        printf("no items to search for\n");
        return NULL;
    }
    else
    {
        
        store *sptr;
        sptr=head;
        while(strcmp(sptr->n,name)!=0)
        {
            sptr=sptr->next;
            if(sptr==NULL)
            {
                return NULL;
            }
        }
        return sptr;
    }
    
}
store * insertbefore(store * head)
{
    char name[20];
    store *sptr,*before;
    printf("enter name of element before which u want to insert : ");
    scanf("%s", name);
    sptr=search(head,name);
    if(sptr==head)
    {
        head=insertbegin(head);
        
    }
    else if(sptr==NULL)
    {
        printf("Item %s not present",name);
    }
    else
    {
        
        before=head;
        while(before->next != sptr)
        {
            before=before->next;
        }
        store * new = create (sptr);
        
        before->next = new ;
        c++;
        
    }
    
    
    return head;
    
}
store * insertafter(store * head, store *tail)
{
    char name[20];
    store *sptr;
    printf("enter name of element after which u want to insert : ");
    scanf("%s", name);
    sptr=search(head,name);
    if(sptr==tail)
    {
        tail=insertend(tail);
    }
    else if(sptr==NULL)
    {
        printf("Item %s not present",name);
    }
    else
    {
        store * new = create (sptr->next);
        sptr->next = new ;
        c++;
    }
    return tail;
}




int menu (int ch)
{
    printf("1 : insert begin \n 2: insert end \n 3: insert middle \n 4: delete \n  5: search \n 6: display  \n -1 : exit \n enter choice : ");
    scanf("%d",&ch);
    return ch;
}
void display(store *head)
{
    if(head==NULL)
    {
        printf("no items to display\n");
        
    }
    else
    {
        printf("Number of items: %d\n",c);
        
        while(head!=NULL)
        {
            printf("%s : %d rs.\n",head->n,head->a);
            head=head->next;
        }
    }
    
}

int main() {
    
    int ch;
    head=NULL;
    tail=NULL;
    char name[20];
    store * sptr;
    int d; /*creating anywhere is possible in modern compilers...write here to play safe*/
    
    
    while(1)
    {
        
        ch= menu(ch);
        switch(ch)
        {
            case 1 : head= insertbegin(head);
            if(c==1)
            {
                tail=head;
                
            }
            
            break;
            
            
            case 2 : tail= insertend(tail);
            if(c==1)
            {
                head=tail;
                
            }
            
            break;
            
            case 3 : if(head==NULL)
            {
                printf("no items in store\n");
            }
            else
            {
                
                
                
                printf(" 0 : enter before an item \n 1 : enter after an item \n enter choice : ");
                scanf("%d",&d);
                if(d==0)
                {
                   head=insertbefore(head); 
                    
                }
                else if(d==1)
                {
                    
                    tail=insertafter(head,tail);
                }
                else 
                {
                    printf("Invalid choice\n");
                    
                }
            }
            break;
                            
            case 4 :if(head==NULL)
            printf("no items to delete\n");
            
    
            else
            {
                
                store *before;
                
                printf("enter item to be deleted : ");
                scanf("%s",name);
                sptr=search (head,name);
                
                if(sptr==NULL)
                {
                    printf("item not present\n");
                }
                
                else if(sptr==head)
                {
                    head=sptr->next;
                    printf("item %s deleted \n",sptr->n);
                    free(sptr);
                    c--;
                    
                }
                else
                {
                    before=head;
                    while(before->next != sptr)
                    {
                        before=before->next;
                    }
                    if(sptr==tail)
                    {
                        
                        
                        printf("item %s deleted\n",tail->n);
                        free(tail);
                        tail=before;
                        tail->next=NULL;
                        c--;
                    }
                    else
                    {
                        before->next=sptr->next;
                        printf("item %s deleted \n ",sptr->n);
                        free(sptr);
                        c--;
                    }
                    
                }
                
            
                
            }
            break;
            
            case 5 : if(head==NULL)
            {
                printf("no items to search for\n");
            }
            else
            {
                printf("enter element to be searched : ");
                scanf("%s", name );
                sptr=search(head,name);
                printf("price of %s is %d \n ", name , sptr->a);
                    
            }
                break;
            
            case 6 : display(head);break;
             
            case -1 : return 0;
            default: printf("invalid choice\n");
        }

        
    }
    
    
    
    return 0;
}
