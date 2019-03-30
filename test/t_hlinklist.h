//
//  t_hlinklist.h
//  ds
//
//  Created by 李名韬 on 2019/3/30.
//  Copyright © 2019年 李名韬. All rights reserved.
//

#ifndef t_hlinklist_h
#define t_hlinklist_h

#include <stdio.h>
#include "std.h"
#include "t_list.h"
#include "hlinklist.h"


void t_initHList(void);
void t_destroyHList(void);
void t_clearHList(void);
void t_isEmptyHList(void);
void t_isExistHList(void);
void t_getLenHList(void);
void t_getElemHList(void);
void t_locateELemHList(void);
void t_priorElemHList(void);
void t_nextELemHList(void);
void t_insertHList(void);
void t_bInsertHList(void);
void t_deleteHList(void);

#endif /* t_hlinklist_h */
