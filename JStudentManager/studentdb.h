//
//  studentdb.h
//  JStudentManager
//
//  Created by James Swineson on 12/30/15.
//  Copyright © 2015 James Swineson. All rights reserved.
//

#pragma once
#ifndef studentdb_h
#define studentdb_h
#include "common.h"

extern database* db;
extern const string db_path;

void database_initialize();
void database_close();
void database_query_all_orgs();
void database_query_all_students();
void database_to_org_list();

void list_print_all_orgs();

#define transaction_begin() sqlite_sql_stmt(db, "begin");
#define transaction_commit() sqlite_sql_stmt(db, "commit");
#define transaction_rollback() sqlite_sql_stmt(db, "rollback");

#define DB_OK           0   /* Successful result */
/* beginning-of-error-codes */
#define DB_ERROR        1   /* SQL error or missing database */
#define DB_INTERNAL     2   /* Internal logic error in DB */
#define DB_PERM         3   /* Access permission denied */
#define DB_ABORT        4   /* Callback routine requested an abort */
#define DB_BUSY         5   /* The database file is locked */
#define DB_LOCKED       6   /* A table in the database is locked */
#define DB_NOMEM        7   /* A malloc() failed */
#define DB_READONLY     8   /* Attempt to write a readonly database */
#define DB_INTERRUPT    9   /* Operation terminated by DB3_interrupt()*/
#define DB_IOERR       10   /* Some kind of disk I/O error occurred */
#define DB_CORRUPT     11   /* The database disk image is malformed */
#define DB_NOTFOUND    12   /* Unknown opcode in DB3_file_control() */
#define DB_FULL        13   /* Insertion failed because database is full */
#define DB_CANTOPEN    14   /* Unable to open the database file */
#define DB_PROTOCOL    15   /* Database lock protocol error */
#define DB_EMPTY       16   /* Database is empty */
#define DB_SCHEMA      17   /* The database schema changed */
#define DB_TOOBIG      18   /* String or BLOB exceeds size limit */
#define DB_CONSTRAINT  19   /* Abort due to constraint violation */
#define DB_MISMATCH    20   /* Data type mismatch */
#define DB_MISUSE      21   /* Library used incorrectly */
#define DB_NOLFS       22   /* Uses OS features not supported on host */
#define DB_AUTH        23   /* Authorization denied */
#define DB_FORMAT      24   /* Auxiliary database format error */
#define DB_RANGE       25   /* 2nd parameter to DB3_bind out of range */
#define DB_NOTADB      26   /* File opened that is not a database file */
#define DB_NOTICE      27   /* Notifications from DB3_log() */
#define DB_WARNING     28   /* Warnings from DB3_log() */
#define DB_ROW         100  /* DB3_step() has another row ready */
#define DB_DONE        101  /* DB3_step() has finished executing */
/* end-of-error-codes */

#endif /* studentdb_h */
