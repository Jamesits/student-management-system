//
//  error_handler.h
//  JStudentManager
//
//  Created by James Swineson on 12/30/15.
//  Copyright © 2015 James Swineson. All rights reserved.
//

#pragma once
#ifndef error_handler_h
#define error_handler_h

#include <setjmp.h>

#define try         if(!(exception_type=setjmp(exception_env)))
#define catch(X)    else if(exception_type==X)
#define throw(X)    longjmp(exception_env,X)

typedef int exception_types;
extern jmp_buf exception_env;
extern exception_types exception;

void on_error(exception_types e);

#endif /* error_handler_h */
