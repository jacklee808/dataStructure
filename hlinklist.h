//
//  hlinkList.h
//  ds
//
//  Created by 李名韬 on 2019/3/29.
//  Copyright © 2019年 李名韬. All rights reserved.
//

#ifndef hlinklist_h
#define hlinklist_h

#include <stdio.h>
#include "std.h"
#include "linklist.h"

void initHList(linkList *L);
void destroyHList(linkList *L);
void clearHList(linkList *L);
bool isEmptyHList(linkList L);
bool isExistHList(linkList L);
int getLenHList(linkList L);
ElemType getElemHList(linkList L, int index);
//传递函数指针
int locateELemHList(linkList L, ElemType e, bool (* compare)(ElemType a, ElemType b));
ElemType priorElemHList(linkList L, ElemType cur_e);
ElemType nextELemHList(linkList L, ElemType cur_e);
bool insertHList(linkList L, int index, ElemType e);
bool bInsertHList(linkList *L, int index, ElemType e);
bool deleteHList(linkList *L, int index);
void traverseHList(linkList L, void (* visit)(ElemType e));
linkList unionHList(linkList La, linkList Lb);
void mergeHList(linkList La, linkList Lb, linkList *Lc);

#endif /* hlinklist_h */
