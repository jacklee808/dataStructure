//
//  slist.h
//  ds
//
//  Created by 李印臣 on 2019/3/27.
//  Copyright © 2019年 李印臣. All rights reserved.
//

#ifndef slist_h
#define slist_h

#include <stdio.h>
#include "std.h"

#define ElemType int
#define SList_INIT_SIZE 100
#define SListINCREMENT 10

typedef struct{
    ElemType *elem;
    int len;
    int SListSize;
}SList;

void initSList(SList **L);
void destroySList(SList **L);
void clearSList(SList *L);
bool isEmpty(SList *L);
bool isExist(SList *L);
int getLen(SList *L);
ElemType getElem(SList *L, int index);
//传递函数指针
bool compare(ElemType a, ElemType b);
int locateELem(SList *L, ElemType e, bool (* compare)(ElemType a, ElemType b));
ElemType priorElem(SList *L, ElemType cur_e);
ElemType nextELem(SList *L, ElemType cur_e);
bool insertSList(SList *L, int index, ElemType e);
bool deleteSList(SList *L, int index);
void visit(ElemType e);
void traverseSList(SList *L, void (* visit)(ElemType e));

#endif /* slist_h */
