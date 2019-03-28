//
//  std.c
//  ds
//
//  Created by 李印臣 on 2019/3/27.
//  Copyright © 2019年 李印臣. All rights reserved.
//

#include "std.h"

bool compare(ElemType a, ElemType b){
    if(a == b) return true;
    return false;
}

void visit(ElemType e){
    printf("%d ", e);
}
