//
//  t_slinklist.h
//  ds
//
//  Created by 李名韬 on 2019/3/30.
//  Copyright © 2019年 李名韬. All rights reserved.
//

#ifndef t_slinkSLinklist_h
#define t_slinkSLinklist_h

#include <stdio.h>
#include "std.h"
#include "t_list.h"
#include "slinklist.h"

void t_initSLinklist(void);
void t_destroySLinklist(void);
void t_clearSLinklist(void);
void t_isEmptySLinklist(void);
void t_isExistSLinklist(void);
void t_getLenSLinklist(void);
void t_getElemSLinklist(void);
void t_locateELemSLinklist(void);
void t_priorElemSLinklist(void);
void t_nextELemSLinklist(void);
void t_insertSLinklist(void);
void t_deleteSLinklist(void);

#endif /* t_slinklist_h */
