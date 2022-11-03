#include "elevator.h"


// A linked list node methods
void append(Node** head_ref, int floor)
{
    /* 1. allocate node */
    Node* new_node = (Node*)malloc(sizeof(Node));

    Node* last = *head_ref; /* used in step 5*/

    /* 2. put in the data  */
    new_node->floor = floor;
    new_node->wFront = 0;
    new_node->wRear = 0;


    /* 3. This new node is going to be the last node, so
          make next of it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new
          node as head */
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = new_node;

    /* 7. Make last node as previous of new node */
    new_node->prev = last;

    return;
}

void printAllFloors(Node* node)
{
    while (node != NULL) {
        printf(" %d ", node->floor);
        node = node->next;
    }
}

Node* traverseUpward(Node* node, int& dir)
{   
    if (node == NULL)
    {
        printf("\nNode not available\n");
        return node;
    }
    else if (node->floor == MAX_FLOORS) {
        printf("\nReached the top!!\n");
        dir = DOWN;
        return node;
    }
    
    return node->next;
    printf(" \n%d ", node->floor);
}

Node* traverseDownward(Node* node, int& dir)
{
    if (node == NULL)
    {
        printf("\nNode not available\n");
        return node;
    }
    else if (node->floor == MAX_FLOORS) {
        printf("\nReached the bottom!!\n");
        dir = UP;
        return node;
    }
    return node->prev;
    printf(" \n%d ", node->floor);
}
//----------Queue-----------//

int isQueueEmpty(int qFront, int qRear)
{
    if (qFront == qRear)
        return TRUE;
    return FALSE;
}

// delete head element
void dequeue(int& qFront, int qRear, Request* arr)
{
    if (isQueueEmpty(qFront, qRear) == TRUE)
        printf("Queue is Empty.\n");
    else
    {
        printf("Dequeued element = %d\n", arr[qFront]);
        qFront++;
    }
}

int isQueueFull(int qRear)
{
    if (qRear == MAX_REQUESTS)
        return TRUE;
    return FALSE;
}

//add element
void enqueue(int &qRear, Request* arr, Request val)
{
    if (isQueueFull(qRear) == TRUE)
        printf("Queue is Full\n");
    else
    {
        arr[qRear] = val;
        qRear++;
    }
}

char* showQueue(int qFront, int qRear, Request *arr)
{
    char* buffer = (char*)malloc(MAXCHAR * sizeof(char));
    char* stemp = (char*)malloc(MAXCHAR * sizeof(char));

    if (isQueueEmpty(qFront, qRear) == TRUE || arr[qFront].dest_flr < 0) {
        sprintf_s(stemp, sizeof(char) * MAXCHAR, "\nEmpty Queue");

        //free(buffer);
        return stemp;
    }
    else
    {
        // ERROR HERE KAPOY GARBAGE COLLECTION T_T
        sprintf_s(stemp, sizeof(char) * MAXCHAR, "\nQueue: ");
        sprintf_s(buffer, sizeof(char)*MAXCHAR, "%d ", arr[qFront].dest_flr);
        strcat_s(stemp, sizeof(char) * MAXCHAR, buffer);

        for (int i = qFront + 1; i < qRear; i++) {
            sprintf_s(buffer, sizeof(char) * MAXCHAR, "%d ", arr[i].dest_flr);
            strcat_s(stemp, sizeof(char) * MAXCHAR, buffer);
        }
        
        //free(buffer);
        return stemp;
    }

}

//--------------------------------------------------//

Request generateRequest(int& totalReq, int min, int base) {
    int max_n = MAX_FLOORS, min_n = 1;
    Request new_R;
    totalReq++;
    new_R.request_id = totalReq;
    new_R.orig_flr = base;
    new_R.dest_flr = rand() % max_n + new_R.orig_flr;
    new_R.time = min;
    return new_R;
}

Node* traverseToRequester(Node* n, int& dir, int& base) {
    Node* temp = n;
    if (dir == UP) {
        while (temp->floor != base) {
            temp = traverseUpward(temp, dir);
        }
    }
    else {
        while (temp->floor != base) {
            temp = traverseDownward(temp, dir);
        }
    }

    return temp;
}

Node* inputRequest(int& totalReq, int& qF, int& qR, int& base, int &direction, int min, int dest, Node* node) {
    Node* tempNode = node;
    Request new_R;
    totalReq++;
    new_R.request_id = totalReq;
    new_R.orig_flr = base;
    new_R.dest_flr = dest;
    new_R.time = min;


    if (dest > MAX_FLOORS) {
        printf("\nFloor doesn't exist! Please try again...\n");
        return node;
    }
    else if (dest > 0 && dest <= MAX_FLOORS) {
        node = traverseToRequester(node, direction, base);
        enqueue(node->wRear, node->waiting, new_R);
        //base = incrementBase(base);
        return tempNode;
    }
    else {
        printf("\nFloor doesn't exist! Please try again...\n");
        return node;
    }
}


// pickup riders of elevator per floor
Node* elevatorOperation(Node* node) {
    Node* tempNode = node;
    int i = 0;

    while (node->waiting[i].request_id > 0) {
        


        i++;
    }

    /*if ((node->waiting < dest && direction == UP) || (base < dest && isQueueEmpty(qF, qR) == TRUE)) {
        
    }
    else if ((base > dest && direction == DOWN) || (base > dest && isQueueEmpty(qF, qR) == TRUE)) {
        
    }
    printf("\nElevator going on opposite direction, please try again later...\n");*/
    return tempNode;
}
