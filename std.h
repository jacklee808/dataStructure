//
//  std.h
//  ds
//
//  Created by 李名韬 on 2019/3/27.
//  Copyright © 2019年 李名韬. All rights reserved.
//

#ifndef std_h
#define std_h

#include <stdio.h>
#include <stdlib.h>

#define OVERFLOW 1;
#define INT_MIN ~(1 << 31)

#define bool int
#define false 0
#define true 1

#define ElemType int

bool compare(ElemType a, ElemType b);
void visit(ElemType e);
void printstr(char *str);
void println(char *str, int num);

#define CHECK(func, flag, num)                       \
void check_##func##_0(bool flag, int num){           \
    if(flag) println(#func" OK ", num);              \
    else println(#func" error ", num);               \
}

#endif /* std_h */
