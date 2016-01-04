//
//  common.h
//  JStudentManager
//
//  Created by James Swineson on 12/30/15.
//  Copyright © 2015 James Swineson. All rights reserved.
//

#ifndef common_h
#define common_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "sqlite3.h"

#ifdef __STDC_NO_ATOMICS__
#define _Atomic volatile
#else
#include <stdatomic.h>
#endif

// bstring library
#include "../bstrlib/bstrlib.h"
#include "../bstrlib/utf8util.h"
#include "../bstrlib/bstraux.h"
// uncommenting the following file will disable unsafe C calls
//#include "../bstrlib/bsafe.h"

#define new(X, ...) (X)malloc((__VA_ARGS__ +1) * sizeof(X))
#define gets_s(X, ...) gets(X)

#include "../ctrycatch/ctrycatch.h"

typedef char* string;
typedef sqlite3 database;

#endif /* common_h */
