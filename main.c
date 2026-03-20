#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} circle;

circle *createCLL(int data)
{
    circle *newnode = (circle*) malloc(sizeof(circle));
    
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    
    return newnode;
}

circle *add(circle *head, int data)
{
    circle *newNode = createCLL(data);
    if(head == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }
    
    circle *temp = head;
    while(temp->next != head)
    {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = head;
    head->prev = newNode;
    
    return head;
}

void display(circle *head)
{
    if(head == NULL)
    {
        return;
    }
    
    circle *temp = head;
    
    do
    {
        printf("data -> %d\n", temp->data);
        temp = temp->next;
    }while(temp != head);
}

int listcheck(circle *head)
{
    if(head == NULL)
    {
        return 0;
    }
    
    circle *temp = head;
    int count = 0;
    
    do
    {
        if(temp->data == 0)
        {
            return 1;
        }
        
        temp = temp->next;
        count++;
    }while(count < 10 && temp != head);
    
    return 0;
}

int main()
{
    time_t start, end;
    start = time(NULL);
    circle *head = NULL;
    srand(time(NULL));
    
    int r, i = 2;
    head = add(head, 1);
    
    while(i <= 10)
    {
        head = add(head, 0);
        i++;
    }
    
    display(head);
    
    do
    {
        r = (rand() % 10) + 1;
        printf("Random seed -> %d\n", r);
        sleep(1);
        
        if(r <= 5 && r >= 1)
        {
            head = head->prev;
            if(head->data == 1)
            {
                printf("\n==========Continued==========");
                printf("\nData -> %d\n", head->data);
                printf("Next -> %p : %d\n", head->next, head->next);
                printf("Previous -> %p : %d\n\n", head->prev, head->prev);
                continue;
            }
            else
            {
                head->data = 1;
            }
            printf("\nData -> %d\n", head->data);
            printf("Next -> %p : %d\n", head->next, head->next);
            printf("Previous -> %p : %d\n\n", head->prev, head->prev);
        }
        else if(r >= 6 && r <= 10)
        {
            head = head->next;
            if(head->data == 1)
            {
                printf("\n==========Continued==========");
                printf("\nData -> %d\n", head->data);
                printf("Next -> %p : %d\n", head->next, head->next);
                printf("Previous -> %p : %d\n\n", head->prev, head->prev);
                continue;
            }
            else
            {
                head->data = 1;
            }
            printf("\nData -> %d\n", head->data);
            printf("Next -> %p : %d\n", head->next, head->next);
            printf("Previous -> %p : %d\n\n", head->prev, head->prev);
        }
    }while(listcheck(head));
    
    display(head);
    end = time(NULL);
    printf("\nTime: %ld seconds", end - start);
    
    return 0;
}