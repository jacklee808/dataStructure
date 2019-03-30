//
//  t_slist.h
//  ds
//
//  Created by 李名韬 on 2019/3/29.
//  Copyright © 2019年 李名韬. All rights reserved.
//

#ifndef t_slist_h
#define t_slist_h

#include <stdio.h>
#include "std.h"
#include "slist.h"
#include "t_list.h"

void t_initSList(void);
void t_destroySList(void);
void t_clearSList(void);
void t_isEmptySList(void);
void t_isExistSList(void);
void t_getLenSList(void);
void t_getElemSList(void);
void t_locateELemSList(void);
void t_priorElemSList(void);
void t_nextELemSList(void);
void t_insertSList(void);
void t_deleteSList(void);
#endif /* t_slist_h */
