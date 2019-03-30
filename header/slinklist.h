//
//  slinklist.h
//  ds
//
//  Created by 李名韬 on 2019/3/30.
//  Copyright © 2019年 李名韬. All rights reserved.
//

#ifndef slinklist_h
#define slinklist_h

#include <stdio.h>
#include "std.h"
#include "list.h"

#define MAXSIZE 100

typedef struct{
    ElemType data;
    int cur;
}Elem, *SLinklist;

void initSLinklist(SLinklist *L);
void destroySLinklist(SLinklist *L);
void clearSLinklist(SLinklist *L);
bool isEmptySLinklist(SLinklist L);
bool isExistSLinklist(SLinklist L);
int getLenSLinklist(SLinklist L);
ElemType getElemSLinklist(SLinklist L, int index);
//传递函数指针
int locateELemSLinklist(SLinklist L, ElemType e, bool (* compare)(ElemType a, ElemType b));
ElemType priorElemSLinklist(SLinklist L, ElemType cur_e);
ElemType nextELemSLinklist(SLinklist L, ElemType cur_e);
bool insertSLinklist(SLinklist L, int index, ElemType e);
bool deleteSLinklist(SLinklist *L, int index);
void traverseSLinklist(SLinklist L, void (* visit)(ElemType e));
SLinklist * unionSLinklist(SLinklist La, SLinklist Lb);
void mergeSLinklist(SLinklist La, SLinklist Lb, SLinklist Lc);

#endif /* slinklist_h */
