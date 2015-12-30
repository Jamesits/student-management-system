//
//  studentdb.c
//  JStudentManager
//
//  Created by James Swineson on 12/30/15.
//  Copyright © 2015 James Swineson. All rights reserved.
//

#include "studentdb.h"
#include "common.h"
#include "db.h"

static database* db;

bool database_initialize()
{
    sqlite3_open("/Users/james/Copy/Code/Data Structure/JStudentManager/JStudentManager/studentdb", &db);
    if(db == NULL) return false;
    return true;
}

bool database_close()
{
    sqlite3_close(db);
    return true;
}