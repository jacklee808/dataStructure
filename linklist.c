//
//  list.c
//  ds
//
//  Created by 李印臣 on 2019/3/28.
//  Copyright © 2019年 李印臣. All rights reserved.
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
    
    p = *L;
    while (p != NULL){
        q = p->next;
        free(p);
        p = q;
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
    while(n < index && p){
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
    while(p && compare(p->data, e) == false){
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

bool insertList(linkList L, int index, ElemType e){
    int n = 0;
    LNode *p, *q;
    
    if (!isExist(L) || index < 0) return false;
    
    p = L;
    if(L->data == INT_MIN){
        if(index == 0){
            L->data = e;
            return true;
        }else{
            return false;
        }
    }
    
    while(n < index && p != NULL){
        p = p->next;
        n++;
    }
    
    if(p == NULL) return false;
    else{
        q = (linkList)malloc(sizeof(LNode));
        q->data = e;
        q->next = p->next;
        p->next = q;
        return true;
    }
}

bool deleteList(linkList L, int index){
    int n = 0;
    LNode *p, *q;
    
    if (!isExist(L) || index < 0) return false;
    q = p = L;
    while(n < index && p != NULL){
        q = p;
        p = p->next;
        n++;
    }
    
    if(p == NULL) return false;
    else{
        q->next = p->next;
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
    LNode *p = NULL, *q = NULL, *q2 = NULL;
    
    if (!isExist(La)) return Lb;
    if (!isExist(Lb)) return La;
    
    p = Lb;
    while(p != NULL){
        q = La;
        while(q != NULL && compare(p->data, q->data) == false){
            q2 = q;
            q = q->next;
        }
        if (q == NULL){
            q2->next = p;
            q2->next->next = NULL;
            p = p->next;
        }
    }
    
    return La;
}

void mergeList(linkList La, linkList Lb, linkList *Lc){
    LNode *p = NULL, *q = NULL, *r = NULL;
    
    if (!isExist(La)) *Lc = Lb;
    if (!isExist(Lb)) *Lc = La;
    
    p = La;
    q = Lb;
    
    while(p != NULL && q != NULL){
        if(p->data > q->data){
            if(r == NULL){
                r = q;
                *Lc = r;
            }else{
                r->next = q;
                r = r ->next;
            }
            q = q->next;
            r->next = NULL;
        }else{
            if(r == NULL){
                r = p;
                *Lc = r;
            }else{
                r->next = p;
                r = r ->next;
            }
            p = p->next;
            r->next = NULL;
        }
    }
    
    while(p != NULL){
        if(r == NULL){
            r = p;
            *Lc = r;
        }else{
            r->next = p;
            r = r ->next;
        }
        p = p->next;
        r->next = NULL;
    }
    
    while (q != NULL) {
        
        if(r == NULL){
            r = q;
            *Lc = r;
        }else{
            r->next = q;
            r = r ->next;
        }
        q = q->next;
        r->next = NULL;
    }
}
