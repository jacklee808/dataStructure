//
//  list.h
//  ds
//
//  Created by 李名韬 on 2019/3/28.
//  Copyright © 2019年 李名韬. All rights reserved.
//

#ifndef list_h
#define list_h

#include <stdio.h>

#define destroy(type)               \
void destroy##type(linkList *L){    \
    LNode *p, *q;                   \
                                    \
    if(!isExist##type(*L)) return;  \
                                    \
    p = *L;                         \
    while (p != NULL){              \
    q = p;                          \
    p = p->next;                    \
    free(q);                        \
    }                               \
                                    \
    *L = NULL;                      \
}

#define isExist(type, type2)\
bool isExist##type(type2 L){\
    return L != NULL;\
}

#endif /* list_h */
