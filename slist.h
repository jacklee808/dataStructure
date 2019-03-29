//
//  slist.h
//  ds
//
//  Created by 李名韬 on 2019/3/27.
//  Copyright © 2019年 李名韬. All rights reserved.
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
bool isEmptySList(SList *L);
bool isExistSList(SList *L);
int getLenSList(SList *L);
ElemType getElemSList(SList *L, int index);
//传递函数指针
int locateELemSList(SList *L, ElemType e, bool (* compare)(ElemType a, ElemType b));
ElemType priorElemSList(SList *L, ElemType cur_e);
ElemType nextELemSList(SList *L, ElemType cur_e);
bool insertSList(SList *L, int index, ElemType e);
bool deleteSList(SList *L, int index);
void traverseSList(SList *L, void (* visit)(ElemType e));
SList * unionSList(SList *La, SList *Lb);
void mergeSList(SList *La, SList *Lb, SList **Lc);
#endif /* slist_h */
