//
//  linklist.c
//  ds
//
//  Created by 李名韬 on 2019/3/28.
//  Copyright © 2019年 李名韬. All rights reserved.
//

#include "linklist.h"

void initList(linkList *L){
    if(isExistList(*L)) {
        printstr("This list is not empty. If you want reset it, please destroy it first.");
        return;
    }
    *L = (linkList) malloc(sizeof(LNode));
    if(*L == NULL)exit(EXIT_FAILURE);
    (*L)->data = INT_MIN;
    (*L)->next = NULL;
}

destroy(List)

void clearList(linkList *L){
    destroyList(L);
}

bool isEmptyList(linkList L){
    return !isExistList(L) || L->data == INT_MIN;
}

bool isExistList(linkList L){
    if(L == NULL) return false;
    else return true;
}

int getLenList(linkList L){
    int n = 0;
    LNode *p;
    
    if (isEmptyList(L)) return -1;
    p = L;
    while(p){
        p = p->next;
        n++;
    }
    
    return n;
}

ElemType getElemList(linkList L, int index){
    int n = 0;
    LNode *p;
    
    if (isEmptyList(L) || index < 0) return INT_MIN;
    
    p = L;
    while(n < index && p != NULL){
        p = p->next;
        n++;
    }
    
    if(p == NULL) return INT_MIN;
    else return p->data;
}

int locateELemList(linkList L, ElemType e, bool (* compare)(ElemType a, ElemType b)){
    int index = 0;
    LNode *p;
    
    if (isEmptyList(L)) return -1;
    
    p = L;
    while(p != NULL && compare(p->data, e) == false){
        p = p->next;
        index++;
    }
    
    if(p == NULL) return -1;
    return index;
}

ElemType priorElemList(linkList L, ElemType cur_e){
    LNode *p, *q = NULL;
    
    if (isEmptyList(L) || getLenList(L) == 1) return INT_MIN;
    
    p = L;
    while(p != NULL && compare(cur_e, p->data) == false){
        q = p;
        p = p->next;
    }
    
    if(p == NULL) return INT_MIN;
    else return q->data;
}

ElemType nextELemList(linkList L, ElemType cur_e){
    LNode *p;
    
    if (isEmptyList(L) || getLenList(L) == 1) return INT_MIN;
    
    p = L;
    while(p != NULL && compare(cur_e, p->data) == false){
        p = p->next;
    }
    
    if(p == NULL || p->next == NULL) return INT_MIN;
    else return p->next->data;
}

bool insert(linkList *L, int index, ElemType e, bool isAfter){
    int n = 0;
    LNode *p, *q;
    
    if (!isExistList(*L) || index < 0) return false;
    
    p = *L;
    if((*L)->data == INT_MIN){
        if(index == 0){
            (*L)->data = e;
            return true;
        }else{
            return false;
        }
    }
    if(!isAfter){
        index--;
    }
    while(n < index && p != NULL){
        p = p->next;
        n++;
    }
    
    if(p == NULL) return false;
    else{
        q = (LNode *)malloc(sizeof(LNode));
        q->data = e;
        if(isAfter == false && index == -1){
            q->next = p;
            *L = q;
        }else{
            q->next = p->next;
            p->next = q;
        }
        return true;
    }
}

bool insertList(linkList L, int index, ElemType e){
    return insert(&L, index, e, true);
}

bool bInsertList(linkList *L, int index, ElemType e){
    return insert(L, index, e, false);
}

bool deleteList(linkList *L, int index){
    int n = 0;
    LNode *p, *q;
    //如果删除的是表头呢？
    if (isEmptyList(*L) || index < 0) return false;
    
    q = p = *L;
    while(n < index && p != NULL){
        q = p;
        p = p->next;
        n++;
    }
    
    if(p == NULL) return false;
    else{
        if(index == 0) *L = (*L)->next;
        else q->next = p->next;
        free(p);
        p = NULL;
        return true;
    }
}

void traverseList(linkList L, void (* visit)(ElemType e)){
    LNode *p;
    
    if (isEmptyList(L)) return;

    p = L;
    while (p != NULL) {
        visit(p->data);
        p = p->next;
    }
}

linkList unionList(linkList La, linkList Lb){
    LNode *p = NULL, *q = NULL;
    
    if (isEmptyList(La)) return Lb;
    if (isEmptyList(Lb)) return La;
    
    p = Lb;
    while(p != NULL && -1 == locateELemList(La, p->data, compare)){
        q = p->next;
        p->next = La->next;
        La->next = p;
        p = q;
    }
    
    return La;
}

void insertNode(LNode **Lc, LNode **p, LNode **r){
    if((*r) == NULL){
        (*r) = (*p);
        *Lc = (*r);
    }else{
        (*r)->next = (*p);
        (*r) = (*r) ->next;
    }
    (*p) = (*p)->next;
    (*r)->next = NULL;
}
void mergeList(linkList La, linkList Lb, linkList *Lc){
    LNode *p = NULL, *q = NULL, *r = NULL;
    
    if (isEmptyList(La)){
        *Lc = Lb;
        return;
    }
    if (isEmptyList(Lb)){
        *Lc = La;
        return;
    }
    
    p = La;
    q = Lb;
    
    while(p != NULL && q != NULL){
        if(p->data > q->data){
            insertNode(Lc, &q, &r);
        }else{
            insertNode(Lc, &p, &r);
        }
    }
    
    while(p != NULL){
        insertNode(Lc, &p, &r);
    }
    
    while (q != NULL) {
        insertNode(Lc, &q, &r);
    }
}
