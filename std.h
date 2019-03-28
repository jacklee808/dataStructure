//
//  std.h
//  ds
//
//  Created by 李印臣 on 2019/3/27.
//  Copyright © 2019年 李印臣. All rights reserved.
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

#endif /* std_h */
