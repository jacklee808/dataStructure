//
//  hlinkList.c
//  ds
//
//  Created by 李印臣 on 2019/3/29.
//  Copyright © 2019年 李印臣. All rights reserved.
//

#include "hlinklist.h"

void initHList(linkList *L){
    initList(L);
    (*L)->data = 0;
}

void destroyHList(linkList *L){
    destroyList(L);
}

void clearHList(linkList *L){
    if(isExistHList(*L)) destroyHList(&(*L)->next);

    (*L)->data = 0;
}

bool isEmptyHList(linkList L){
    if(isExistHList(L) && L->next == NULL) return true;
    else return false;
}

bool isExistHList(linkList L){
    return isExist(L);
}

int getLenHList(linkList L){
    if (isExistHList(L)) return L->data;
    else return -1;
}

ElemType getElemHList(linkList L, int index){
    if (!isExistHList(L) || L->data < index) return INT_MIN;
    else return getElem(L->next, index);
}

int locateELemHList(linkList L, ElemType e, bool (* compare)(ElemType a, ElemType b)){
    if (!isExistHList(L)) return -1;
    
    return locateELem(L->next, e, compare);
}

ElemType priorElemHList(linkList L, ElemType cur_e){
    if (!isExistHList(L)) return INT_MIN;
    else return priorElem(L->next, cur_e);
}

ElemType nextELemHList(linkList L, ElemType cur_e){
    if (!isExistHList(L)) return INT_MIN;
    else return nextELem(L->next, cur_e);
}

bool insertHL(linkList *L, int index, ElemType e, bool isAfter){
    int n = 0;
    LNode *p, *q;
    
    if (!isExistHList(*L) || index < 0 || index > (*L)->data) return false;
    
    p = (*L)->next;
    if(!isAfter){
        index--;
    }
    while (n < index) {
        p = p->next;
    }
    
    q = (LNode *)malloc(sizeof(LNode));
    q->data = e;
    
    if(!isAfter && index == -1){
        q->next = p;
        (*L)->next = q;
    }else{
        q->next = p->next;
        p->next = q;
    }
    (*L)->data++;
    return true;
}

bool insertHList(linkList L, int index, ElemType e){
    return insertHL(&L, index, e, true);
}

bool bInsertHList(linkList *L, int index, ElemType e){
    return insertHL(L, index, e, false);
}

bool deleteHList(linkList *L, int index){
    int n = 0;
    LNode *p, *q;
    
    if (!isExistHList(*L) || index < 0 || index > (*L)->data) return false;
    
    p = (*L)->next;
    
    while (p != NULL && n < index - 1) {
        p = p->next;
        n++;
    }
    
    q = p->next;
    p->next = p->next->next;
    (*L)->data--;
    free(q);
    return true;
}

void traverseHList(linkList L, void (* visit)(ElemType e)){
    traverseList(L, visit);
}

linkList unionHList(linkList La, linkList Lb){
    LNode *p, *q;
    if(!isExistHList(La)) return Lb;
    if(!isExistHList(Lb)) return La;
    
    p = Lb->next;
    while (p != NULL && -1 == locateELem(La, p->data, compare)) {
        q = p->next;
        p->next = La->next;
        La->next = p;
        p = q;
        La->data++;
    }
    
    return La;
}

void insertHNode(LNode **p, LNode **q){
    (*q)->next = *p;
    (*p) = (*p)->next;
    (*q) = (*q)->next;
    (*q)->next = NULL;
}

void mergeHList(linkList La, linkList Lb, linkList *Lc){
    LNode *p = NULL, *q = NULL, *r = NULL;
    
    if(!isExistHList(La)){
        *Lc = Lb;
        return;
    }
    if(!isExistHList(Lb)){
        *Lc = La;
        return;
    }
    
    p = La->next;
    q = Lb->next;
    r = *Lc = La;
    
    while(p != NULL && q != NULL){
        if(p->data > q->data){
            insertHNode(&q, &r);
        }else{
            insertHNode(&p, &r);
        }
    }
    
    while (p != NULL) {
        insertHNode(&p, &r);
    }
    
    while (q != NULL) {
        insertHNode(&q, &r);
    }
}
