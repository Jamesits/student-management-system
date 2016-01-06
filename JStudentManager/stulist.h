//
//  stulist.h
//  JStudentManager
//
//  Created by James Swineson on 1/5/16.
//  Copyright © 2016 James Swineson. All rights reserved.
//

#ifndef stulist_h
#define stulist_h

#include <stdio.h>

int stu_db_display_callback(void *p_data, int num_fields, char **p_fields, char **p_col_names);
void stu_db_display();

#endif /* stulist_h */
