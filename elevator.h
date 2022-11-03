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
    int orig_flr, dest_flr;
    int time;
};

typedef struct NODE Node;
struct NODE {
    int floor;
    int wFront, wRear;
    REQUEST waiting[MAX_REQUESTS];
    Node* next;
    Node* prev;
};

// DLL functions
void append(Node**, int);
void printAllFloors(Node*);
Node* traverseUpward(Node*, int& dir);
Node* traverseDownward(Node*, int& dir);

// Queue Functions
int isQueueEmpty(int qFront, int qRear);
void dequeue(int& qFront, int qRear, Request* arr);
int isQueueFull(int qRear);
void enqueue(int& qRear, Request* arr, Request val);
char* showQueue(int qFront, int qRear, Request* arr);

Request generateRequest(int&, int, int);
Node* traverseToRequester(Node* n, int& dir, int& base);
Node* inputRequest(int&, int&, int&, int&, int&, int, int, Node*);
Node* elevatorOperation(Node* node); // wapani nahuman
#endif