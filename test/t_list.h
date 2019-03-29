//
//  t_list.h
//  ds
//
//  Created by 李名韬 on 2019/3/30.
//  Copyright © 2019年 李名韬. All rights reserved.
//

#ifndef t_list_h
#define t_list_h

#include <stdio.h>

#define check_init(type)                                   \
    void check_init##type(linkList L, bool N, int num){    \
    bool flag;                                             \
    flag = isExist##type(L);                               \
    if(!N) flag = !flag;                                   \
    check_init##type##_0(flag, num);                       \
}

#define t_init(type)                    \
void t_init##type(){                    \
    linkList L = NULL;                  \
    linkList p = NULL;                  \
    check_init##type(L, false, 1);      \
    init##type(&L);                     \
    check_init##type(L, true, 2);       \
    p = L;                              \
    init##type(&L);                     \
    check_init##type(L, p == L, 3);     \
}

#endif /* t_list_h */
