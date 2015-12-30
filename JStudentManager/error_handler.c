//
//  error_handler.c
//  JStudentManager
//
//  Created by James Swineson on 12/30/15.
//  Copyright © 2015 James Swineson. All rights reserved.
//

#include "common.h"
#include "error_handler.h"

jmp_buf exception_env;
int exception_type;