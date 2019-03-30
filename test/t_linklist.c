//
//  t_linklist.c
//  ds
//
//  Created by 李名韬 on 2019/3/29.
//  Copyright © 2019年 李名韬. All rights reserved.
//

#include "t_linklist.h"

test(init, List)
test(destroy, List)
test(clear, List)

CHECK(isEmptyList, flag, num)

void check_isEmptyList(linkList L, bool N, int num){
    bool flag;
    flag = isEmptyList(L);
    if(!N) flag = !flag;
    check_isEmptyList_0(flag, num);
}

void t_isEmptyList(){
    linkList L = NULL;
    
    check_isEmptyList(L, true, 1);
    initList(&L);
    check_isEmptyList(L, true, 2);
    insertList(L, 0, 1);
    check_isEmptyList(L, false, 3);
    deleteList(&L, 0);
    check_isEmptyList(L, true, 4);
}

CHECK(isExistList, flag, num)

void check_isExistList(linkList L, bool N, int num){
    bool flag;
    flag = isExistList(L);
    if(!N) flag = !flag;
    check_isExistList_0(flag, num);
}

void t_isExistList(){
    linkList L = NULL;
    
    check_isExistList(L, false, 1);
    initList(&L);
    check_isExistList(L, true, 2);
    clearList(&L);
    check_isExistList(L, false, 3);
    destroyList(&L);
    check_isExistList(L, false, 4);
}

CHECK(getLenList, flag, num)

void check_getLenList(linkList L, int result, int num){
    bool flag;
    flag = (getLenList(L) == result);
    check_getLenList_0(flag, num);
}

void t_getLenList(){
    linkList L = NULL;
    
    check_getLenList(L, -1, 1);
    initList(&L);
    check_getLenList(L, -1, 2);
    insertList(L, 0, 1);
    insertList(L, 0, 2);
    check_getLenList(L, 2, 3);
    deleteList(&L, 0);
    check_getLenList(L, 1, 4);
    clearList(&L);
    check_getLenList(L, -1, 5);
}

CHECK(getElemList, flag, num)

void check_getElemList(linkList L, int index, int result, int num){
    bool flag;
    flag = (getElemList(L, index) == result);
    check_getElemList_0(flag, num);
}

void t_getElemList(){
    linkList L = NULL;
    
    check_getElemList(L, 0, INT_MIN, 1);
    initList(&L);
    check_getElemList(L, 0, INT_MIN, 2);
    insertList(L, 0, 1);
    insertList(L, 0, 2);
    check_getElemList(L, 1, 2, 3);
    check_getElemList(L, 4, INT_MIN, 4);
    check_getElemList(L, -1, INT_MIN, 5);
}

CHECK(locateELemList, flag, num)

void check_locateELemList(linkList L, ElemType e, int result, int num){
    bool flag;
    flag = (locateELemList(L, e, compare) == result);
    check_locateELemList_0(flag, num);
}

void t_locateELemList(){
    linkList L = NULL;
    
    check_locateELemList(L, 1, -1, 1);
    initList(&L);
    check_locateELemList(L, 0, -1, 2);
    insertList(L, 0, 1);
    insertList(L, 0, 2);
    check_locateELemList(L, 0, -1, 3);
    check_locateELemList(L, 2, 1, 4);
}

CHECK(priorElemList, flag, num)

void check_priorElemList(linkList L, ElemType e, int result, int num){
    bool flag;
    flag = (priorElemList(L, e) == result);
    check_priorElemList_0(flag, num);
}

void t_priorElemList(){
    linkList L = NULL;
    
    check_priorElemList(L, 2, INT_MIN, 1);
    initList(&L);
    check_priorElemList(L, 2, INT_MIN, 2);
    insertList(L, 0, 1);
    check_priorElemList(L, 2, INT_MIN, 3);
    insertList(L, 0, 2);
    check_priorElemList(L, 2, 1, 4);
}

CHECK(nextELemList, flag, num)

void check_nextELemList(linkList L, ElemType e, int result, int num){
    bool flag;
    flag = (nextELemList(L, e) == result);
    check_nextELemList_0(flag, num);
}

void t_nextELemList(){
    linkList L = NULL;
    
    check_nextELemList(L, 2, INT_MIN, 1);
    initList(&L);
    check_nextELemList(L, 2, INT_MIN, 2);
    insertList(L, 0, 1);
    check_nextELemList(L, 2, INT_MIN, 3);
    insertList(L, 0, 2);
    check_nextELemList(L, 1, 2, 4);
}

CHECK(insertList, flag, num)

void check_insertList(linkList L, ElemType e, int index, int result, int num){
    bool flag;
    ElemType e2;
    flag = insertList(L, index, e);
    e2 = getElemList(L, index);
    flag = (flag == (e2 == result));
    check_insertList_0(flag, num);
}

void t_insertList(){
    linkList L = NULL;
    
    check_insertList(L, 2, 0, 2, 1);
    initList(&L);
    check_insertList(L, 2, -1, 2, 2);
    check_insertList(L, 2, 3, 2, 3);
    check_insertList(L, 2, 0, 2, 4);
    check_insertList(L, 3, 1, 3, 5);
    check_insertList(L, 4, 4, 2, 6);
}

CHECK(deleteList, flag, num)

void check_deleteList(linkList L,  int index, bool result, int num){
    bool flag;
    int index2;
    ElemType e;
    e = getElemList(L, index);
    flag = deleteList(&L, index);
    index2 = locateELemList(L, e, compare);
    flag = (flag == result) && (index2 == -1);
    check_deleteList_0(flag, num);
}

void t_deleteList(){
    linkList L = NULL;
    
    check_deleteList(L, 2, false, 1);
    initList(&L);
    check_deleteList(L, 2, false, 2);
    insertList(L, 0, 1);
    check_deleteList(L, 2, false, 3);
    check_deleteList(L, -1, false, 4);
    check_deleteList(L, 0, true, 5);
}
