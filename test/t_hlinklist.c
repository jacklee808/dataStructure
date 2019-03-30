//
//  t_hlinklist.c
//  ds
//
//  Created by 李名韬 on 2019/3/30.
//  Copyright © 2019年 李名韬. All rights reserved.
//

#include "t_hlinklist.h"

test(init, HList, linkList)
test(destroy, HList, linkList)
test(clear, HList, linkList)
test(isEmpty, HList, linkList)

CHECK(isExistHList, flag, num)

void check_isExistHList(linkList L, bool N, int num){
    bool flag;
    flag = isExistHList(L);
    if(!N) flag = !flag;
    check_isExistHList_0(flag, num);
}

void t_isExistHList(){
    linkList L = NULL;
    
    check_isExistHList(L, false, 1);
    initHList(&L);
    check_isExistHList(L, true, 2);
    clearHList(&L);
    check_isExistHList(L, true, 3);
    destroyHList(&L);
    check_isExistHList(L, false, 4);
}

CHECK(getLenHList, flag, num)

void check_getLenHList(linkList L, int result, int num){
    bool flag;
    flag = (getLenHList(L) == result);
    check_getLenHList_0(flag, num);
}

void t_getLenHList(){
    linkList L = NULL;
    
    check_getLenHList(L, -1, 1);
    initHList(&L);
    check_getLenHList(L, 0, 2);
    insertHList(L, 0, 1);
    insertHList(L, 0, 2);
    check_getLenHList(L, 2, 3);
    deleteHList(&L, 0);
    check_getLenHList(L, 1, 4);
    clearHList(&L);
    check_getLenHList(L, 0, 5);
}

CHECK(getElemHList, flag, num)

void check_getElemHList(linkList L, int index, int result, int num){
    bool flag;
    flag = (getElemHList(L, index) == result);
    check_getElemHList_0(flag, num);
}

void t_getElemHList(){
    linkList L = NULL;
    
    check_getElemHList(L, 0, INT_MIN, 1);
    initHList(&L);
    check_getElemHList(L, 0, INT_MIN, 2);
    insertHList(L, 0, 1);
    insertHList(L, 0, 2);
    check_getElemHList(L, 1, 2, 3);
    check_getElemHList(L, 4, INT_MIN, 4);
    check_getElemHList(L, -1, INT_MIN, 5);
}

CHECK(locateELemHList, flag, num)

void check_locateELemHList(linkList L, ElemType e, int result, int num){
    bool flag;
    flag = (locateELemHList(L, e, compare) == result);
    check_locateELemHList_0(flag, num);
}

void t_locateELemHList(){
    linkList L = NULL;
    
    check_locateELemHList(L, 1, -1, 1);
    initHList(&L);
    check_locateELemHList(L, 0, -1, 2);
    insertHList(L, 0, 1);
    insertHList(L, 0, 2);
    check_locateELemHList(L, 0, -1, 3);
    check_locateELemHList(L, 1, 0, 4);
}

CHECK(priorElemHList, flag, num)

void check_priorElemHList(linkList L, ElemType e, int result, int num){
    bool flag;
    flag = (priorElemHList(L, e) == result);
    check_priorElemHList_0(flag, num);
}

void t_priorElemHList(){
    linkList L = NULL;
    
    check_priorElemHList(L, 2, INT_MIN, 1);
    initHList(&L);
    check_priorElemHList(L, 2, INT_MIN, 2);
    insertHList(L, 0, 1);
    check_priorElemHList(L, 2, INT_MIN, 3);
    insertHList(L, 0, 2);
    check_priorElemHList(L, 2, 1, 4);
}

CHECK(nextELemHList, flag, num)

void check_nextELemHList(linkList L, ElemType e, int result, int num){
    bool flag;
    flag = (nextELemHList(L, e) == result);
    check_nextELemHList_0(flag, num);
}

void t_nextELemHList(){
    linkList L = NULL;
    
    check_nextELemHList(L, 2, INT_MIN, 1);
    initHList(&L);
    check_nextELemHList(L, 2, INT_MIN, 2);
    insertHList(L, 0, 1);
    check_nextELemHList(L, 2, INT_MIN, 3);
    insertHList(L, 0, 2);
    check_nextELemHList(L, 1, 2, 4);
}

CHECK(insertHList, flag, num)

void check_insertHList(linkList L, ElemType e, int index, int result, int num){
    bool flag;
    ElemType e2;
    flag = insertHList(L, index, e);
    e2 = getElemHList(L, index);
    flag = (flag == (e2 == result));
    check_insertHList_0(flag, num);
}

void t_insertHList(){
    linkList L = NULL;
    
    check_insertHList(L, 2, 0, 2, 1);
    initHList(&L);
    check_insertHList(L, 2, -1, 2, 2);
    check_insertHList(L, 2, 3, 2, 3);
    check_insertHList(L, 2, 0, 2, 4);
    check_insertHList(L, 3, 1, 3, 5);
    check_insertHList(L, 4, 4, 2, 6);
}

CHECK(deleteHList, flag, num)

void check_deleteHList(linkList L,  int index, int num){
    bool flag;
    int index2;
    ElemType e;
    e = getElemHList(L, index);
    deleteHList(&L, index);
    index2 = locateELemHList(L, e, compare);
    flag = (index2 == -1);
    check_deleteHList_0(flag, num);
}

void t_deleteHList(){
    linkList L = NULL;
    
    check_deleteHList(L, 2, 1);
    initHList(&L);
    check_deleteHList(L, 2, 2);
    insertHList(L, 0, 1);
    check_deleteHList(L, 0, 3);
    check_deleteHList(L, 2, 4);
    check_deleteHList(L, -1, 5);
}
