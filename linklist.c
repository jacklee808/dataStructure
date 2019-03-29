//
//  linklist.c
//  ds
//
//  Created by 李名韬 on 2019/3/28.
//  Copyright © 2019年 李名韬. All rights reserved.
//

#include "linklist.h"

void initList(linkList *L){
    *L = (linkList) malloc(sizeof(LNode));
    if(*L == NULL)exit(EXIT_FAILURE);
    (*L)->data = INT_MIN;
    (*L)->next = NULL;
}

void destroyList(linkList *L){
    LNode *p, *q;
    
    if(!isExist(*L)) return;
    
    p = *L;
    while (p != NULL){
        q = p;
        p = p->next;
        free(q);
    }
    //此处不能漏掉
    *L = NULL;
}

void clearList(linkList *L){
    destroyList(L);
}

bool isEmpty(linkList L){
    return isExist(L);
}

bool isExist(linkList L){
    if(L == NULL) return false;
    else return true;
}

int getLen(linkList L){
    int n = 0;
    LNode *p;
    
    if (!isExist(L)) return INT_MIN;
    p = L;
    while(p){
        p = p->next;
        n++;
    }
    
    return n;
}

ElemType getElem(linkList L, int index){
    int n = 0;
    LNode *p;
    
    if (!isExist(L)) return INT_MIN;
    
    p = L;
    while(n < index && p != NULL){
        p = p->next;
        n++;
    }
    
    if(p == NULL) return INT_MIN;
    else return p->data;
}

int locateELem(linkList L, ElemType e, bool (* compare)(ElemType a, ElemType b)){
    int index = 0;
    LNode *p;
    
    if (!isExist(L)) return -1;
    
    p = L;
    while(p != NULL && compare(p->data, e) == false){
        p = p->next;
        index++;
    }
    
    if(p == NULL) return -1;
    return index;
}

ElemType priorElem(linkList L, ElemType cur_e){
    LNode *p, *q = NULL;
    
    if (!isExist(L)) return INT_MIN;
    
    p = L;
    while(p != NULL && compare(cur_e, p->data) == false){
        q = p;
        p = p->next;
    }
    
    if(p == NULL || p == L) return INT_MIN;
    else return q->data;
}

ElemType nextELem(linkList L, ElemType cur_e){
    LNode *p;
    
    if (!isExist(L)) return INT_MIN;
    
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
    
    if (!isExist(*L) || index < 0) return false;
    
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
    if (!isExist(*L) || index < 0) return false;
    
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
    
    if (!isExist(L)) return;

    p = L;
    while (p != NULL) {
        visit(p->data);
        p = p->next;
    }
}

linkList unionList(linkList La, linkList Lb){
    LNode *p = NULL, *q = NULL;
    
    if (!isExist(La)) return Lb;
    if (!isExist(Lb)) return La;
    
    p = Lb;
    while(p != NULL && -1 == locateELem(La, p->data, compare)){
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
    
    if (!isExist(La)){
        *Lc = Lb;
        return;
    }
    if (!isExist(Lb)){
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
