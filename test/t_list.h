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

#define check_init(func, type, type2)                                   \
void check_##func##type(type2 L, bool N, int num){    \
    bool flag;                                             \
                                                           \
    flag = isExist##type(L);                               \
    if(!N) flag = !flag;                                   \
    check_##func##type##_0(flag, num);                       \
}

#define t_init(func, type, type2)                                       \
void t_##func##type(){                                       \
    type2 L = NULL;                                     \
    type2 p = NULL;                                     \
                                                           \
    check_##func##type(L, false, 1);                         \
    func##type(&L);                                        \
    check_##func##type(L, true, 2);                          \
    p = L;                                                 \
    func##type(&L);                                        \
    check_##func##type(L, p == L, 3);                        \
}


#define check_destroy(func, type, type2)                                \
void check_destroy##type(type2 L, bool N, int num){     \
    bool flag;                                             \
    flag = isExist##type(L);                               \
    if(!N) flag = !flag;                                   \
check_destroy##type##_0(flag, num);                        \
}

#define t_destroy(func, type, type2)                                    \
void t_destroy##type(){                                    \
    type2 L = NULL;                                     \
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


#define check_clear(func, type, type2)                                  \
void check_clear##type(type2 *L, bool N, int num){      \
    bool flag;                                             \
                                                           \
    clear##type(L);                                        \
    flag = !(!isExist##type(*L) || (isExist##type(*L) && isEmpty##type(*L)));\
    if(!N) flag = !flag;                                   \
    check_clear##type##_0(flag, num);                      \
}

#define t_clear(func, type, type2)                                      \
void t_clear##type(){                                      \
    type2 L = NULL;                                     \
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


#define check_isEmpty(func, type, type2)\
void check_isEmpty##type(type2 L, bool N, int num){\
    bool flag;\
    flag = isEmpty##type(L);\
    if(!N) flag = !flag;\
    check_isEmpty##type##_0(flag, num);\
}

#define t_isEmpty(func, type, type2)\
void t_isEmpty##type(){\
    type2 L = NULL;\
    \
    check_isEmpty##type(L, true, 1);\
    init##type(&L);\
    check_isEmpty##type(L, true, 2);\
    insert##type(L, 0, 1);\
    check_isEmpty##type(L, false, 3);\
    delete##type(&L, 0);\
    check_isEmpty##type(L, true, 4);\
}

#define test(func, type, type2)                                   \
    CHECK(func##type, flag, num)                           \
    check_##func(func, type, type2)                                       \
    t_##func(func, type, type2)

#endif /* t_list_h */
