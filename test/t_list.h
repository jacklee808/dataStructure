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

#define check_init(func, type)                                   \
void check_##func##type(linkList L, bool N, int num){    \
    bool flag;                                             \
                                                           \
    flag = isExist##type(L);                               \
    if(!N) flag = !flag;                                   \
    check_##func##type##_0(flag, num);                       \
}

#define t_init(func, type)                                       \
void t_##func##type(){                                       \
    linkList L = NULL;                                     \
    linkList p = NULL;                                     \
                                                           \
    check_##func##type(L, false, 1);                         \
    func##type(&L);                                        \
    check_##func##type(L, true, 2);                          \
    p = L;                                                 \
    func##type(&L);                                        \
    check_##func##type(L, p == L, 3);                        \
}

#define check_destroy(func, type)                                \
void check_destroy##type(linkList L, bool N, int num){     \
    bool flag;                                             \
    flag = isExist##type(L);                               \
    if(!N) flag = !flag;                                   \
check_destroy##type##_0(flag, num);                        \
}

#define t_destroy(func, type)                                    \
void t_destroy##type(){                                    \
    linkList L = NULL;                                     \
                                                           \
    destroy##type(&L);                                     \
    check_destroy##type(L, false, 1);                      \
    init##type(&L);                                        \
    destroy##type(&L);                                     \
    check_destroy##type(L, false, 2);                      \
    init##type(&L);                                        \
    insert##type(L, 0, 1);                                 \
    insert##type(L, 1, 2);                                 \
    destroy##type(&L);                                     \
    check_destroy##type(L, false, 3);                      \
}

#define check_clear(func, type)                                  \
void check_clear##type(linkList *L, bool N, int num){      \
    bool flag;                                             \
                                                           \
    clear##type(L);                                        \
    flag = !(!isExist##type(*L) || (isExist##type(*L) && isEmpty##type(*L)));\
    if(!N) flag = !flag;                                   \
    check_clear##type##_0(flag, num);                      \
}

#define t_clear(func, type)                                      \
void t_clear##type(){                                      \
    linkList L = NULL;                                     \
                                                           \
    check_clear##type(&L, false, 1);                       \
    init##type(&L);                                        \
    check_clear##type(&L, false, 2);                       \
    insert##type(L, 0, 1);                                 \
    insert##type(L, 1, 2);                                 \
    check_clear##type(&L, false, 3);                       \
    insert##type(L, 0, 1);                                 \
    insert##type(L, 1, 2);                                 \
    destroy##type(&L);                                     \
    check_clear##type(&L, false, 4);                       \
}

#define test(func, type)                                   \
    CHECK(func##type, flag, num)                           \
    check_##func(func, type)                                       \
    t_##func(func, type)

#endif /* t_list_h */
