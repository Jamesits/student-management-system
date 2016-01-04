//
//  studentdb.c
//  JStudentManager
//
//  Created by James Swineson on 12/30/15.
//  Copyright © 2015 James Swineson. All rights reserved.
//

#include "studentdb.h"
#include "common.h"
#include "model.h"

static database* db;
static string db_path = "/Users/james/Copy/Code/Data Structure/JStudentManager/JStudentManager/studentdb";

bool fileExists(const char *filename)
{
    FILE *fp = fopen (filename, "r");
    if (fp!=NULL) fclose (fp);
    return (fp!=NULL);
}

void database_initialize()
{
    if (!fileExists(db_path)) throw(FileNotFoundException, "Unable to open database file");
    sqlite3_open(db_path, &db);
    if(db == NULL) throw(FormatException, "Unable to parse database");
}

void database_close()
{
    if (db == NULL) throw(IOException, "Database is not opened");
    sqlite3_close(db);
    db = NULL;
}

void database_query_all_orgs()
{
    if (db == NULL) throw(DbException, "Database does not exist");
    sqlite_select_stmt(db, "select * from `organizations`");
}

void database_query_all_students()
{
    if (db == NULL) throw(DbException, "Database does not exist");
    sqlite_select_stmt(db, "select * from `students`");
}