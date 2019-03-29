//
//  t_linklist.c
//  ds
//
//  Created by 李名韬 on 2019/3/29.
//  Copyright © 2019年 李名韬. All rights reserved.
//

#include "t_linklist.h"

CHECK(initList, flag, num)

void check_initList(linkList L, bool N, int num){
    bool flag;
    flag = isExist(L);
    if(!N) flag = !flag;
    check_initList_0(flag, num);
}

void t_initList(){
    linkList L = NULL;
    linkList p = NULL;
    
    check_initList(L, false, 1);
    initList(&L);
    check_initList(L, true, 2);
    p = L;
    initList(&L);
    check_initList(L, p == L, 3);
}

CHECK(destroyList, flag, num)

void check_destroyList(linkList L, bool N, int num){
    bool flag;
    flag = isExist(L);
    if(!N) flag = !flag;
    check_destroyList_0(flag, num);
}

void t_destroyList(){
    linkList L = NULL;
    
    destroyList(&L);
    check_destroyList(L, false, 1);
    initList(&L);
    destroyList(&L);
    check_destroyList(L, false, 2);
    initList(&L);
    insertList(L, 0, 1);
    insertList(L, 1, 2);
    destroyList(&L);
    check_destroyList(L, false, 3);
}

CHECK(clearList, flag, num)

void check_clearList(linkList *L, bool N, int num){
    bool flag;
    clearList(L);
    flag = !(!isExist(*L) || (isExist(*L) && isEmpty(*L)));
    if(!N) flag = !flag;
    check_clearList_0(flag, num);
}

void t_clearList(){
    linkList L = NULL;
    
    check_clearList(&L, false, 1);
    initList(&L);
    check_clearList(&L, false, 2);
    insertList(L, 0, 1);
    insertList(L, 1, 2);
    check_clearList(&L, false, 3);
    insertList(L, 0, 1);
    insertList(L, 1, 2);
    destroyList(&L);
    check_clearList(&L, false, 4);
}

CHECK(isEmpty, flag, num)

void check_isEmpty(linkList L, bool N, int num){
    bool flag;
    flag = isEmpty(L);
    if(!N) flag = !flag;
    check_isEmpty_0(flag, num);
}

void t_isEmpty(){
    linkList L = NULL;
    
    check_isEmpty(L, true, 1);
    initList(&L);
    check_isEmpty(L, true, 2);
    insertList(L, 0, 1);
    check_isEmpty(L, false, 3);
    deleteList(&L, 0);
    check_isEmpty(L, true, 4);
}

CHECK(isExist, flag, num)

void check_isExist(linkList L, bool N, int num){
    bool flag;
    flag = isExist(L);
    if(!N) flag = !flag;
    check_isExist_0(flag, num);
}

void t_isExist(){
    linkList L = NULL;
    
    check_isExist(L, false, 1);
    initList(&L);
    check_isExist(L, true, 2);
    clearList(&L);
    check_isExist(L, false, 3);
    destroyList(&L);
    check_isExist(L, false, 4);
}

CHECK(getLen, flag, num)

void check_getLen(linkList L, int result, int num){
    bool flag;
    flag = (getLen(L) == result);
    check_getLen_0(flag, num);
}

void t_getLen(){
    linkList L = NULL;
    
    check_getLen(L, -1, 1);
    initList(&L);
    check_getLen(L, -1, 2);
    insertList(L, 0, 1);
    insertList(L, 0, 2);
    check_getLen(L, 2, 3);
    deleteList(&L, 0);
    check_getLen(L, 1, 4);
    clearList(&L);
    check_getLen(L, -1, 5);
}

CHECK(getElem, flag, num)

void check_getElem(linkList L, int index, int result, int num){
    bool flag;
    flag = (getElem(L, index) == result);
    check_getElem_0(flag, num);
}

void t_getElem(){
    linkList L = NULL;
    
    check_getElem(L, 0, INT_MIN, 1);
    initList(&L);
    check_getElem(L, 0, INT_MIN, 2);
    insertList(L, 0, 1);
    insertList(L, 0, 2);
    check_getElem(L, 1, 2, 3);
    check_getElem(L, 4, INT_MIN, 4);
    check_getElem(L, -1, INT_MIN, 5);
}

CHECK(locateELem, flag, num)

void check_locateELem(linkList L, ElemType e, int result, int num){
    bool flag;
    flag = (locateELem(L, e, compare) == result);
    check_locateELem_0(flag, num);
}

void t_locateELem(){
    linkList L = NULL;
    
    check_locateELem(L, 1, -1, 1);
    initList(&L);
    check_locateELem(L, 0, -1, 2);
    insertList(L, 0, 1);
    insertList(L, 0, 2);
    check_locateELem(L, 0, -1, 3);
    check_locateELem(L, 2, 1, 4);
}

CHECK(priorElem, flag, num)

void check_priorElem(linkList L, ElemType e, int result, int num){
    bool flag;
    flag = (priorElem(L, e) == result);
    check_priorElem_0(flag, num);
}

void t_priorElem(){
    linkList L = NULL;
    
    check_priorElem(L, 2, INT_MIN, 1);
    initList(&L);
    check_priorElem(L, 2, INT_MIN, 2);
    insertList(L, 0, 1);
    check_priorElem(L, 2, INT_MIN, 3);
    insertList(L, 0, 2);
    check_priorElem(L, 2, 1, 4);
}

CHECK(nextELem, flag, num)

void check_nextELem(linkList L, ElemType e, int result, int num){
    bool flag;
    flag = (nextELem(L, e) == result);
    check_nextELem_0(flag, num);
}

void t_nextELem(){
    linkList L = NULL;
    
    check_nextELem(L, 2, INT_MIN, 1);
    initList(&L);
    check_nextELem(L, 2, INT_MIN, 2);
    insertList(L, 0, 1);
    check_nextELem(L, 2, INT_MIN, 3);
    insertList(L, 0, 2);
    check_nextELem(L, 1, 2, 4);
}

CHECK(insertList, flag, num)

void check_insertList(linkList L, ElemType e, int index, int result, int num){
    bool flag;
    ElemType e2;
    flag = insertList(L, index, e);
    e2 = getElem(L, index);
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
    e = getElem(L, index);
    flag = deleteList(&L, index);
    index2 = locateELem(L, e, compare);
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
