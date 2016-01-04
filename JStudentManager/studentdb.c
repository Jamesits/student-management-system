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
#include "organization_list.h"

static database* db;
static string db_path = "/Users/james/Copy/Code/Data Structure/JStudentManager/JStudentManager/studentdb";
static int first_row;

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

int database_to_org_list_callback(void *p_data, int num_fields, char **p_fields, char **p_col_names) {
    
    int i;
    int *p_rn = (int*)p_data;
    if (orginzations != NULL) list_delete(orginzations);
    list_new(&orginzations, org_list_data_init);
    if (first_row) {
        first_row = 0;
        
        //for(i=0; i < num_fields; i++) {
        //    printf("%20s", p_col_names[i]);
        //}
        //printf("\n");
        //for(i=0; i< num_fields*20; i++) {
        //    printf("=");
        //}
        //printf("\n");
    }
    
    (*p_rn)++;
    
    for(i=0; i < num_fields; i++) {
        printf("%20s", p_fields[i]);
        fflush(stdout);
        //continue;
        list_node new_org_node = new(list_node);
        org_list_node_data_init(new_org_node);
        org_list_data data = (org_list_data)new_org_node->data;
        switch (i) {
            case 0:
                sscanf(p_fields[i], "%ld", &(data->id));
                break;
            case 1:
                data->name = malloc((strlen(p_fields[i]) + 1) * sizeof(char));
                sscanf(p_fields[i], "%s", data->name);
            case 2:
                if (p_fields[i] == NULL) {
                    data->parent = data->id;
                } else {
                    sscanf(p_fields[i], "%ld", &(data->parent));
                }
            default:
                break;
        }
        list_append(orginzations, new_org_node);
    }
    
    printf("\n");
    return 0;
}

void database_to_org_list()
{
    sqlite_select_stmt_with_custom_callback(db, "select * from `organizations`", database_to_org_list_callback);
}