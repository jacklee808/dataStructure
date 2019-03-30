//
//  slinklist.c
//  ds
//
//  Created by 李名韬 on 2019/3/30.
//  Copyright © 2019年 李名韬. All rights reserved.
//

#include "slinklist.h"

void initSLinklist(SLinklist *L){
    int i;
    if(isExistSLinklist(*L)) {
        printstr("This list is not empty. If you want reset it, please destroy it first.");
        return;
    }
    *L = (SLinklist) malloc(MAXSIZE * sizeof(Elem));
    if(*L == NULL)exit(EXIT_FAILURE);
    (*L)[0].cur = -1;
    (*L)[0].data = MAXSIZE - 1;
    
    for(i = MAXSIZE - 1; i > 1; i--){
        (*L)[i].cur = i - 1;
    }
    (*L)[1].cur = -1;
}

isExist(SLinklist, SLinklist)

bool isEmptySLinklist(SLinklist L){
    return !isExistSLinklist(L) || L[0].cur == -1;
}

void destroySLinklist(SLinklist *L){
    if(!isExistSLinklist(*L)) return;
    free((*L));
    (*L) = NULL;
}

void clearSLinklist(SLinklist *L){
    int i;
    if (isEmptySLinklist(*L)) return;
    (*L)[0].cur = -1;
    (*L)[0].data = MAXSIZE - 1;
    
    for(i = MAXSIZE - 1; i > 1; i--){
        (*L)[i].cur = i - 1;
    }
    (*L)[1].cur = -1;
}


bool insertSLinklist(SLinklist L, int index, ElemType e){
    int p, q, n = 0;
    
    if(!isExistSLinklist(L) || index < 0) return false;
    
    p = L[0].cur;
    while(n < index && L[p].cur != -1){
        p = L[p].cur;
        n++;
    }
    
    if(p == -1 && index != 0) return false;
    else{
        q = L[MAXSIZE - 1].cur;
        if(q != -1) {
            L[MAXSIZE - 1].cur = L[q].cur;
            L[q].data = e;
            
            if(index == 0){
                L[q].cur = -1;
                L[0].cur = q;
            }else{
               L[q].cur = L[p].cur;
                L[p].cur = q;
            }
            return true;
        }else return false;
    }
}

bool deleteSLinklist(SLinklist *L, int index){
    int p, q, n = 0;
    if(isEmptySLinklist(*L) || index < 0) return false;
    
    q  = 0;
    p = (*L)[0].cur;
    while (p != -1 && n < index) {
        q = p;
        p = (*L)[p].cur;
        n++;
    }
    
    if(p == -1) return false;
    else{
        (*L)[q].cur = (*L)[p].cur;
        (*L)[p].cur = (*L)[MAXSIZE - 1].cur;
        (*L)[MAXSIZE - 1].cur = p;
        return true;
    }
}
