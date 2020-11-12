#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct key
{
    char c[1];
    int a;
    struct key *next;
    struct key *prev;
    
}key;

key *head,*tail;
int n=0;

int menu(int ch)
{
    printf(" 1: insert begin \n 2: insert end \n 3:insert middle \n 4: delete character \n 5: search \n 6: display \n -1: exit \n Enter your choice: ");
    scanf("%d",&ch);
    return ch;
}

key * search (key * head , char e[1])
{
    key * sptr=head;
    if(head==NULL)
    {
        return NULL;
    }
    while(strcmp(sptr->c,e)!=0)
    {
        sptr= sptr->next;
        if(sptr==NULL)
        {
            return NULL;
        }
    }
    return sptr;
}

key * create (key * prev , key * next  )
{
    key * new = (key *)malloc(sizeof(key)) ;
    printf("Enter character : ");
    scanf("%s", new->c);
    printf("Enter value : ");
    scanf("%d", &new->a);
    new->prev=prev;
    new->next=next;
    return new;
}

key * insertbegin(key* head )
{
    key * new = create ( NULL, head);
    head=new;
    n++;
    return head;
    
}

key * insertend(key * tail)
{
    
    key * new = create (tail,NULL);
    if(tail!=NULL)
    {
        tail->next=new;
        
    }
    tail=new;
    n++;
    return tail;
}

key * insertbefore(key * head)
{
    char e[1];
    key * sptr;
    printf("Enter character BEFORE which you want to insert: ");
    scanf("%s", e);
    sptr= search(head,e);
    if(sptr==NULL)
    {
        printf("Character %s not present",e);
    }
    else if(sptr==head)
    {
        head= insertbegin(head);
    }
    else
    {
        key * new = create(sptr->prev , sptr);
        sptr->prev=new;
        sptr->prev->next = new;
        n++;
        
    }
    return head;
}

key * insertafter(key * tail)
{
    char e[1];
    key * sptr;
    printf("Enter character AFTER which you want to insert: ");
    scanf("%s", e);
    sptr= search(head,e);
    if(sptr==NULL)
    {
        printf("Character %s not present",e);
    }
    else if(sptr==tail)
    {
        tail= insertend(tail);
    }
    else
    {
        key * new = create(sptr , sptr->next);
        sptr->next=new;
        sptr->next->prev = new;
        n++;
        
    }
    return tail;
    
}

void display(key * head)
{
    if(head==NULL)
    {
        printf("No elements to display\n");
    
    }
    else
    {
        printf("No. of elements : %d \n ",n);
        while(head!=NULL)
        {
            printf("%s : %d \n", head->c , head->a);
            head=head->next;
        }
        
    }
    
}
int main()
{
    head=NULL;
    tail=NULL;
    int ch=0;
    key * sptr;
    char e[1];
    
    while(1)
    {
        ch=menu(ch);
        switch (ch)
        {
            case 1:  head=insertbegin(head);
            if(n==1)
            {
                tail=head;
            }
            break;
            
            case 2: tail=insertend(tail);
            if(n==1)
            {
                head=tail;
            }
            break;
            
            case 3: if(head==NULL)
            {
                printf("No elements present\n");
            }
            else 
            {
                int p=0;
                printf("0 : Enter BEFORE a character\n 1: Enter AFTER a character \n enter your choice :");
                scanf("%d",&p);
                if(p==0)
                {
                    head=insertbefore(head);
                }
                else if(p==1)
                {
                    tail=insertafter(tail);
                }
                else
                {
                    printf("invalid choice\n");
                }
            }
            break;
            
            case 4:if(head==NULL)
            {
                printf("No items to be deleted\n");
            }
            else
            {
                printf("Enter character to be deleted : ");
                scanf("%s",e);
                sptr= search(head , e);
                if(sptr==NULL)
                {
                    printf("Element not present \n");
                }
                
                
                else
                {
                    printf("Character %s deleted\n",sptr->c);
                    
                    if(sptr==head)
                    {
                        head=head->next;
                        head->prev=NULL;
                        free(sptr);
                        n--;
                    }
                    else if(sptr==tail)
                    {
                        tail=tail->prev;
                        tail->next =NULL;
                        free(sptr);
                        n--;
                    }
                    else
                    {
                        sptr->prev->next = sptr->next;
                        sptr->next->prev = sptr->prev;
                        free(sptr);
                        n--;
                    }
                }
            }
            break;
            
            case 5: if(head==NULL)
            {
                printf("No elements to search for \n");
            }
            else
            {
                printf("Enter character to be searched : ");
                scanf("%s",e);
                sptr=search(head, e);
                if(sptr==NULL)
                {
                    printf("Character not present\n");
                }
                else
                {
                    printf("Character %s has value %d \n", sptr->c, sptr->a);
                }
            }
                
            
            break;
            
            
            case 6: display(head);
            break;
            
            case -1 : return 0;
            
            default : printf("invalid choice \n");
            break;
            
        }
        
    }
    
    
    
    
    return 0;
}
