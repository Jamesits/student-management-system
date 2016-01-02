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

#ifdef __STDC_NO_ATOMICS__
#define _Atomic volatile
#else
#include <stdatomic.h>
#endif

typedef char* string;

#endif /* common_h */
