//
//  std.c
//  ds
//
//  Created by 李名韬 on 2019/3/27.
//  Copyright © 2019年 李名韬. All rights reserved.
//

#include "std.h"

bool compare(ElemType a, ElemType b){
    if(a == b) return true;
    return false;
}

void visit(ElemType e){
    printf("%d ", e);
}

void printstr(char *str){
    printf("%s%s", str, "\n");
}

void println(char *str, int num){
    printf("%s %d%s", str, num, "\n");
}
