//
//  linklist.h
//  ds
//
//  Created by 李印臣 on 2019/3/28.
//  Copyright © 2019年 李印臣. All rights reserved.
//

//动态线性表

#ifndef linklist_h
#define linklist_h

#include <stdio.h>
#include "std.h"

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *linkList;

void initList(linkList *L);
void destroyList(linkList *L);
void clearList(linkList *L);
bool isEmpty(linkList L);
bool isExist(linkList L);
int getLen(linkList L);
ElemType getElem(linkList L, int index);
//传递函数指针
int locateELem(linkList L, ElemType e, bool (* compare)(ElemType a, ElemType b));
ElemType priorElem(linkList L, ElemType cur_e);
ElemType nextELem(linkList L, ElemType cur_e);
bool insertList(linkList L, int index, ElemType e);
bool deleteList(linkList L, int index);
void traverseList(linkList L, void (* visit)(ElemType e));
linkList unionList(linkList La, linkList Lb);
void mergeList(linkList La, linkList Lb, linkList *Lc);
#endif /* linklist_h */
