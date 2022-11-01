#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>

#ifndef elevator
#define elevator

#define TRUE 1
#define FALSE 0
#define MAXCHAR 99

#define MAX_USERS 3
#define MAX_FLOORS 10
#define MAX_REQUESTS 1000

typedef enum DIRECTION Direction;
enum DIRECTION {UP, DOWN};

typedef struct REQUEST Request;
struct REQUEST {
    int request_id;
    int orig_flr;
    int dest_flr;
    int time;
};

typedef struct NODE Node;
struct NODE {
    int floor;
    REQUEST waiting[MAX_REQUESTS];
    Node* next;
    Node* prev;
};

//typedef struct QNODE Queue;
//struct QNODE {
//    Request data;
//    Queue* next;
//};

void append(Node**, int);
void printAllFloors(Node*);
Node* traverseUpward(Node*);
Node* traverseDownward(Node*);

char* showQueue(int qFront, int qRear, Request* arr);

Request generateRequest(int&, int);
Node* inputRequest(int&, int&, int&, int&, int, int, int, Node*);

int incrementBase(int base);
#endif