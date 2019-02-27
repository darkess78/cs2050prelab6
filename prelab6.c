//some decoding left in the comments but can be removed if needed
#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int item;
    struct node *next;
} List;


List *initIntegerList();
List *insertInteger(List **head, int item);
void printList(List *lptr);
void freeList(List *list);


int main(){
    int newItem, nodes, i;
    //set the first node to head
    List *head;
    
    //# of nodes
    printf("Number of nodes to be made? (between 1 and 20)\n");
    scanf("%d",&nodes);
    
    //printf("Number to be inserted: \n");
    //scanf("%d", &newItem);
    
    //initialize list
    head = initIntegerList();

    //for each node ask value for the node from user
    for(i=1;i<=nodes;i++){
        printf("Number to be inserted: \n");
        scanf("%d", &newItem);
        insertInteger(&head, newItem);
    }
    
    printList(head);
    
    freeList(head);
    
    return 0;
}

List *initIntegerList(){
    /*possible to use dummy nodes
    List *start = NULL;
    List *tail=start->next;
    */
    
    //create a list pointer node
    List *lptr = malloc(sizeof(List));
    
    //check to make sure node was created
    if (lptr==NULL)
    {
        printf("The node was not successfully created.\n");
    }
    return lptr;
}

List * insertInteger(List **head, int item){
    //check that head has a valid address
    if (*head==NULL){
        printf("Cannot find head node.\n");
        return *head;
    }
    
    //make sure newNode was malloced
    List *newNode = malloc(sizeof(List));
    if (newNode == NULL){
        printf("New node failed to allocate,\n");
        return newNode;
    }
    /* if you want the head->item to have a value other than 0
    else
    {
        lptr->item = 0;//hardcoded value for testing
    }
    */
    
    
    
    //set newNode's value of item to the int passed into the function
    newNode->item = item;
    //printf("%d\n", head->item);//head is 99
    //printf("%d\n", newNode->item);//newNode is 4
    
    //put newNode at head 
    newNode->next= *head;
    //printf("%d\n", head->item);//head is 99
    
    *head = newNode;
    //printf("%d\n", head->item);//head is now 4
    //printf("%d\n", newNode->item);//newNode is 4

    //newNode = *head;
    return *head;
}

void printList(List *list){
    int i=1;
    List *p= list;
    while (p != NULL) {
        printf("Node %d integer stored is: %d\n", i, p->item);
        p = p->next;
        i++;
    }
    /*could be a for loop of 
        for(i=1; p!=NULL; i++){
            printf("%d integer stored is: %d\n", i, p->item);
            p=p->next;
        }
    */
}

void freeList(List *list){
    List *p = list;
    
    while(list != NULL){
        list=list->next;
        free(p);
        p=list;
    }
    
    list=NULL;
    p=NULL;
    
}
