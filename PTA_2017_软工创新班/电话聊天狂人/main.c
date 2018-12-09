#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int count;
    long number;
    struct Node* Next;
}Node;
Node numbers[200000];
int count = 1;
int max = 0;
long min_number = 99999999999;

Node* Find(long n) {
    int t = 0;
    long m = n;
    if(n % 10 == 1 || n % 10 == 3) {
        t += 100000;
    }
    n /= 10;
    n %= 100000;
    t += n;
    Node* pos = &numbers[t];
    if(pos->number == -1){
        pos->number = m;
        return pos;
    }
    while(pos->number != m){
        if(pos->Next == NULL) {
            pos->Next = (Node*)malloc(sizeof(Node));
            pos = pos->Next;
            pos->number = m;
            pos->count = 0;
            pos->Next = NULL;
            break;
        } else {
            pos = pos->Next;
        }
    }
    return pos;
}
void insert(long t) {
    Node* s = Find(t);
    s->count++;
    if(s->count > max){
        max++;
        min_number = t;
        count = 1;
    } else if(s->count == max) {
        count++;
        if(t < min_number) {
            min_number = t;
        }
    }
}

int main(int argc,char* args[]){
    int n;
    scanf("%d",&n);
    long telp1,telp2;
    for(int i = 0; i < 200000; i++){
        numbers[i].count = 0;
        numbers[i].Next = NULL;
        numbers[i].number = -1;
    }
    for(int i = 0; i < n; i++) {
        scanf("%ld %ld",&telp1,&telp2);
        insert(telp1);
        insert(telp2);
    }
    printf("%ld %d",min_number,max);
    if(count > 1) {
        printf(" %d",count);
    }
}

