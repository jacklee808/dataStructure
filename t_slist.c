//
//  t_slist.c
//  ds
//
//  Created by 李名韬 on 2019/3/29.
//  Copyright © 2019年 李名韬. All rights reserved.
//

#include "t_slist.h"

#define CHECK(func, flag, num)                       \
void check_##func##_0(bool flag, int num){           \
    if(flag) println(#func" OK ", num);              \
    else println(#func" error ", num);               \
}

CHECK(initSList, flag, num)

void check_initSList(SList *L, bool N, int num){
    bool flag;
    flag = isExistSList(L);
    if(!N) flag = !flag;
    check_initSList_0(flag, num);
}

void t_initSList(){
    SList *L = NULL;
    SList *p = NULL;
    
    check_initSList(L, false, 1);
    initSList(&L);
    check_initSList(L, true, 2);
    p = L;
    initSList(&L);
    check_initSList(L, p == L, 3);
}

CHECK(destroySList, flag, num)

void check_destroySList(SList *L, bool N, int num){
    bool flag;
    flag = isExistSList(L);
    if(!N) flag = !flag;
    check_destroySList_0(flag, num);
}

void t_destroySList(){
    SList *L = NULL;
    
    destroySList(&L);
    check_destroySList(L, false, 1);
    initSList(&L);
    destroySList(&L);
    check_destroySList(L, false, 2);
    initSList(&L);
    insertSList(L, 0, 1);
    insertSList(L, 1, 2);
    destroySList(&L);
    check_destroySList(L, false, 3);
}

CHECK(clearSList, flag, num)

void check_clearSList(SList *L, bool N, int num){
    bool flag;
    clearSList(L);
    flag = !(!isExistSList(L) || (isExistSList(L) && isEmptySList(L)));
    if(!N) flag = !flag;
    check_clearSList_0(flag, num);
}

void t_clearSList(){
    SList *L = NULL;
    
    check_clearSList(L, false, 1);
    initSList(&L);
    check_clearSList(L, false, 2);
    insertSList(L, 0, 1);
    insertSList(L, 1, 2);
    check_clearSList(L, false, 2);
    insertSList(L, 0, 1);
    insertSList(L, 1, 2);
    destroySList(&L);
    check_clearSList(L, false, 4);
}

CHECK(isEmptySList, flag, num)

void check_isEmptySList(SList *L, bool N, int num){
    bool flag;
    flag = isEmptySList(L);
    if(!N) flag = !flag;
    check_isEmptySList_0(flag, num);
}

void t_isEmptySList(){
    SList *L = NULL;
   
    check_isEmptySList(L, true, 1);
    initSList(&L);
    check_isEmptySList(L, true, 2);
    insertSList(L, 0, 1);
    check_isEmptySList(L, false, 3);
    deleteSList(L, 0);
    check_isEmptySList(L, true, 4);
}

CHECK(isExistSList, flag, num)

void check_isExistSList(SList *L, bool N, int num){
    bool flag;
    flag = isExistSList(L);
    if(!N) flag = !flag;
    check_isExistSList_0(flag, num);
}

void t_isExistSList(){
    SList *L = NULL;
    
    check_isExistSList(L, false, 1);
    initSList(&L);
    check_isExistSList(L, true, 2);
    clearSList(L);
    check_isExistSList(L, true, 3);
    destroySList(&L);
    check_isExistSList(L, false, 4);
}

CHECK(getLenSList, flag, num)

void check_getLenSList(SList *L, int result, int num){
    bool flag;
    flag = (getLenSList(L) == result);
    check_getLenSList_0(flag, num);
}

void t_getLenSList(){
    SList *L = NULL;
    
    check_getLenSList(L, -1, 1);
    initSList(&L);
    check_getLenSList(L, 0, 2);
    insertSList(L, 0, 1);
    insertSList(L, 0, 2);
    check_getLenSList(L, 2, 3);
    deleteSList(L, 0);
    check_getLenSList(L, 1, 4);
    clearSList(L);
    check_getLenSList(L, 0, 5);
}

CHECK(getElemSList, flag, num)

void check_getElemSList(SList *L, int index, int result, int num){
    bool flag;
    flag = (getElemSList(L, index) == result);
    check_getElemSList_0(flag, num);
}

void t_getElemSList(){
    SList *L = NULL;
  
    check_getElemSList(L, 0, INT_MIN, 1);
    initSList(&L);
    check_getElemSList(L, 0, INT_MIN, 2);
    insertSList(L, 0, 1);
    insertSList(L, 0, 2);
    check_getElemSList(L, 1, 1, 3);
    check_getElemSList(L, 4, INT_MIN, 4);
    check_getElemSList(L, -1, INT_MIN, 5);
}

CHECK(locateELemSList, flag, num)

void check_locateELemSList(SList *L, ElemType e, int result, int num){
    bool flag;
    flag = (locateELemSList(L, e, compare) == result);
    check_locateELemSList_0(flag, num);
}

void t_locateELemSList(){
    SList *L = NULL;
    
    check_locateELemSList(L, 1, -1, 1);
    initSList(&L);
    check_locateELemSList(L, 0, -1, 2);
    insertSList(L, 0, 1);
    insertSList(L, 0, 2);
    check_locateELemSList(L, 0, -1, 3);
    check_locateELemSList(L, 1, 1, 4);
}

CHECK(priorElemSList, flag, num)

void check_priorElemSList(SList *L, ElemType e, int result, int num){
    bool flag;
    flag = (priorElemSList(L, e) == result);
    check_priorElemSList_0(flag, num);
}

void t_priorElemSList(){
    SList *L = NULL;
    
    check_priorElemSList(L, 2, INT_MIN, 1);
    initSList(&L);
    check_priorElemSList(L, 2, INT_MIN, 2);
    insertSList(L, 0, 1);
    check_priorElemSList(L, 2, INT_MIN, 3);
    insertSList(L, 0, 2);
    check_priorElemSList(L, 1, 2, 4);
}

CHECK(nextELemSList, flag, num)

void check_nextELemSList(SList *L, ElemType e, int result, int num){
    bool flag;
    flag = (nextELemSList(L, e) == result);
    check_nextELemSList_0(flag, num);
}

void t_nextELemSList(){
    SList *L = NULL;
    
    check_nextELemSList(L, 2, INT_MIN, 1);
    initSList(&L);
    check_nextELemSList(L, 2, INT_MIN, 2);
    insertSList(L, 0, 1);
    check_nextELemSList(L, 2, INT_MIN, 3);
    insertSList(L, 0, 2);
    check_nextELemSList(L, 2, 1, 4);
}

CHECK(insertSList, flag, num)

void check_insertSList(SList *L, ElemType e, int index, int result, int num){
    bool flag;
    ElemType e2;
    flag = insertSList(L, index, e);
    e2 = getElemSList(L, index);
    flag = (flag == (e2 == result));
    check_insertSList_0(flag, num);
}

void t_insertSList(){
    SList *L = NULL;
    
    check_insertSList(L, 2, 0, 2, 1);
    initSList(&L);
    check_insertSList(L, 2, -1, 2, 2);
    check_insertSList(L, 2, 3, 2, 3);
    check_insertSList(L, 2, 0, 2, 4);
    check_insertSList(L, 3, 1, 3, 5);
    check_insertSList(L, 4, 4, 2, 6);
}

CHECK(deleteSList, flag, num)

void check_deleteSList(SList *L,  int index, int num){
    bool flag;
    int index2;
    ElemType e;
    e = getElemSList(L, index);
    deleteSList(L, index);
    index2 = locateELemSList(L, e, compare);
    flag = (index2 == -1);
    check_deleteSList_0(flag, num);
}

void t_deleteSList(){
    SList *L = NULL;
    
    check_deleteSList(L, 2, 1);
    initSList(&L);
    check_deleteSList(L, 2, 2);
    insertSList(L, 0, 1);
    check_deleteSList(L, 0, 3);
    check_deleteSList(L, 2, 4);
    check_deleteSList(L, -1, 5);
}

//    void traverseSList(SList *L, void (* visit)(ElemType e));
//    SList * unionSList(SList *La, SList *Lb);
//    void mergeSList(SList *La, SList *Lb, SList **Lc);
