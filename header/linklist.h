//
//  linklist.h
//  ds
//
//  Created by 李名韬 on 2019/3/28.
//  Copyright © 2019年 李名韬. All rights reserved.
//

//动态线性表

#ifndef linklist_h
#define linklist_h

#include <stdio.h>
#include "std.h"
#include "list.h"

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *linkList;

void initList(linkList *L);
void destroyList(linkList *L);
void clearList(linkList *L);
bool isEmptyList(linkList L);
bool isExistList(linkList L);
int getLenList(linkList L);
ElemType getElemList(linkList L, int index);
//传递函数指针
int locateELemList(linkList L, ElemType e, bool (* compare)(ElemType a, ElemType b));
ElemType priorElemList(linkList L, ElemType cur_e);
ElemType nextELemList(linkList L, ElemType cur_e);
bool insertList(linkList L, int index, ElemType e);
bool bInsertList(linkList *L, int index, ElemType e);
bool deleteList(linkList *L, int index);
void traverseList(linkList L, void (* visit)(ElemType e));
linkList unionList(linkList La, linkList Lb);
void mergeList(linkList La, linkList Lb, linkList *Lc);
#endif /* linklist_h */
