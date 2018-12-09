#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define ERROR 1e5
typedef enum { push, pop, inject, eject, end } Operation;

typedef struct Node *PtrToNode;
struct Node {
    ElementType Element;
    PtrToNode Next, Last;
};
typedef struct DequeRecord *Deque;
struct DequeRecord {
    PtrToNode Front, Rear;
};
Deque CreateDeque();
int Push( ElementType X, Deque D );
ElementType Pop( Deque D );
int Inject( ElementType X, Deque D );
ElementType Eject( Deque D );

Operation GetOp();          /* details omitted */
void PrintDeque( Deque D ); /* details omitted */

int main()
{
    ElementType X;
    Deque D;
    int done = 0;

    D = CreateDeque();
    while (!done) {
        switch(GetOp()) {
        case push: 
            scanf("%d", &X);
            if (!Push(X, D)) printf("Memory is Full!\n");
            break;
        case pop:
            X = Pop(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            break;
        case inject: 
            scanf("%d", &X);
            if (!Inject(X, D)) printf("Memory is Full!\n");
            break;
        case eject:
            X = Eject(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            break;
        case end:
            PrintDeque(D);
            done = 1;
            break;
        }
    }
    return 0;
}

Deque CreateDeque () {
	Deque p;
	p = (Deque)malloc(sizeof(struct DequeRecord));
	p->Front = (PtrToNode)malloc(sizeof(struct Node));
	p->Front->Last = NULL;
	p->Rear = p->Front;
	p->Rear->Next = NULL;
	return p;
}

int Push ( ElementType X, Deque D ) {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	if(!temp) {
		return 0;
	}
	temp->Element = X;
	if (D->Front == D->Rear) {
		D->Front->Next = temp;
		temp->Last = D->Front;
		D->Rear = temp;
		temp->Next = NULL;
		return 1;
	}
	temp->Next = D->Front->Next;
	D->Front->Next->Last = temp;
	D->Front->Next = temp;
	temp->Last = D->Front;
	return 1;
}

ElementType Pop ( Deque D ) {
	if(D->Front == D->Rear) {
		return ERROR;
	}
	struct Node* t = D->Front->Next;
	ElementType temp = t->Element;
	if (D->Front->Next == D->Rear) {
		D->Rear = D->Front;
		D->Rear->Next = NULL;
		free(t);
		return temp;
	}
	D->Front->Next->Next->Last = D->Front;
	D->Front->Next = D->Front->Next->Next;
	free(t);
	return temp;
}

int Inject ( ElementType X, Deque D ) {
	struct Node* temp;
	temp=(struct Node*)malloc(sizeof(struct Node));
	if(!temp) {
		return 0;
	}
	temp->Element = X;
	if (D->Front == D->Rear) {
		D->Front->Next = temp;
		temp->Last = D->Front;
		D->Rear = temp;
		return 1;
	}
	D->Rear->Next = temp;
	temp->Last = D->Rear;
	temp->Next = NULL;
	D->Rear = temp;
	return 1;
}

ElementType Eject( Deque D ) {
	if (D->Front == D->Rear) {
		return ERROR;
	}
	ElementType temp = D->Rear->Element;
	struct Node* t = D->Rear;
	D->Rear = D->Rear->Last;
	D->Rear->Next = NULL;
	free(t);
	return temp;
}

