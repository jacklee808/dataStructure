//
//  slist.c
//  ds
//
//  Created by 李印臣 on 2019/3/27.
//  Copyright © 2019年 李印臣. All rights reserved.
//

#include "slist.h"

void initSList(SList **L){
    *L = (SList *)malloc(sizeof(SList));
    if(*L == NULL) exit(EXIT_FAILURE);
    
    (*L)->elem = (ElemType *)malloc(SList_INIT_SIZE *sizeof(ElemType));
    if((*L)->elem == NULL) exit(EXIT_FAILURE);
    
    (*L)->len = 0;
    (*L)->SListSize = SList_INIT_SIZE;
}

void destroySList(SList **L){
    if(!isExist(*L)) return;
    free((*L)->elem);
    (*L)->elem = NULL;
    free((*L));
    (*L) = NULL;
}

void clearSList(SList *L){
    int i;
    if(!isExist(L)) return;
    for (i = 0; i < L->len; i++) {
        L->elem[i] = 0;
    }
}

bool isEmpty(SList *L){
    if(!isExist(L) || L->len == 0) return true;
    return false;
}

bool isExist(SList *L){
    if(L == NULL) return false;
    return true;
}

int getLen(SList *L){
    if(!isExist(L)) return INT_MIN;
    return L->len;
}

ElemType getElem(SList *L, int index){
    if(!isExist(L) || index >= L->len || index < 0) return INT_MIN;
    return L->elem[index];
}

bool compare(ElemType a, ElemType b){
    if(a == b) return true;
    return false;
}

int locateELem(SList *L, ElemType e, bool (* compare)(ElemType a, ElemType b)){
    int i;
    
    if(!isExist(L)) return INT_MIN;
    
    for (i = 0; i < L->len; i++) {
        if((*compare)(e, L->elem[i]) == true) return i;
    }
    
    return INT_MIN;
}

ElemType priorElem(SList *L, ElemType cur_e){
    int i;
    
    if(!isExist(L)) return INT_MIN;
    
    for (i = 0; i < L->len; i++) {
        if((*compare)(cur_e, L->elem[i]) == true && i > 0) return L->elem[i - 1];
    }
    
    return INT_MIN;
}

ElemType nextELem(SList *L, ElemType cur_e){
    int i;
    
    if(!isExist(L)) return INT_MIN;
    
    for (i = 0; i < L->len; i++) {
        if((*compare)(cur_e, L->elem[i]) == true && i + 1 < L->len) return L->elem[i + 1];
    }
    
    return INT_MIN;
}

bool insertSList(SList *L, int index, ElemType e){
    int i;
    
    if(!isExist(L) && (index > L->len || index < 0)) return false;
    
    if(L->len > L->SListSize){
        L = realloc(L, (L->SListSize + SListINCREMENT) * sizeof(ElemType));
        if(L == NULL) exit(EXIT_FAILURE);
        L->SListSize += SListINCREMENT;
    }
    
    for (i = L->len; i > index; i--) {
        L->elem[i] = L->elem[i - 1];
    }
    L->elem[index] = e;
    L->len++;
    
    return true;
}

bool deleteSList(SList *L, int index){
    int i;
    
    if(!isExist(L) && (index > L->len || index < 0)) return false;
    for (i = index; i < L->len; i++) {
        L->elem[i] = L->elem[i + 1];
    }
    L->len--;
    
    return true;
}

void visit(ElemType e){
    printf("%d ", e);
}

void traverseSList(SList *L, void (* visit)(ElemType e)){
    int i;
    
    if(!isExist(L)) return;
    
    for (i = 0; i < L->len; i++) {
        (*visit)(L->elem[i]);
    }
}

SList * unionSList(SList *La, SList *Lb){
    int i, j;
    ElemType e;
    if (isEmpty(La)) return Lb;
    if(isEmpty(Lb)) return La;
    
    for (i = La->len, j = 0; j < Lb->len; j++) {
        e = getElem(Lb, j);
        if (locateELem(La, e, &compare) == INT_MIN) {
            insertSList(La, i++, Lb->elem[j]);
        }
    }
    
    return La;
}

void mergeSList(SList *La, SList *Lb, SList **Lc){
    int i = 0, j = 0, k = 0, aLen = 0, bLen = 0;
    ElemType e1, e2;
    initSList(Lc);
    
    if (!isEmpty(La)) aLen = getLen(La);
    if (!isEmpty(Lb)) bLen = getLen(Lb);
    
    while(aLen > i && bLen > j){
        e1 = getElem(La, i);
        e2 = getElem(Lb, j);
        if(e1 > e2){
            insertSList(*Lc, k++, e2);
            j++;
        }else{
            insertSList(*Lc, k++, e1);
            i++;
        }
    }
    
    while(aLen > i){
        e1 = getElem(La, i++);
        insertSList(*Lc, k++, e1);
    }
    
    while(bLen > j){
        e2 = getElem(Lb, j++);
        insertSList(*Lc, k++, e2);
        
    }
    
}
