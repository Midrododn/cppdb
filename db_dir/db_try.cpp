#include <stdio.h>
#include <sqlite3.h>
#include <string>
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

using namespace std;

int create_db (string db_name);
void prnt_dir();
static int callback(void *NotUsed, int argc, char **argv, char **azColName);
void create_tabe_company(sqlite3 *db);

int main(int argc, char const *argv[])
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	string db_name = "testcpp.db";
	char fname[db_name.length()+1];	strcpy(fname, db_name.c_str());
	char *sql;

	prnt_dir();
	rc = create_db(db_name);

	if(rc == 0){
		cout << stderr << " Can`t open db: " << sqlite3_errmsg(db) << endl;
		return 0;
	}else {
		sqlite3_open(fname, &db);
		cout << " Opned db OK!" << endl;
	}

	sqlite3_close(db);

	return 0;
}

int create_db(string db_name){
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	char fname[db_name.length()+1];	strcpy(fname, db_name.c_str());

	rc = sqlite3_open(fname, &db);

	if(rc){
		cout << stderr << " Can`t open db: " << sqlite3_errmsg(db) << endl;
		return 0;
	}else {
		cout << " DB with name " << fname << " exist.\n";
	}

	sqlite3_close(db);
	return 1;
}

void prnt_dir(){
	char dir[100];

	getcwd(dir, 100);
	printf("Working dir : %s\n", dir); 
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
	int i;
	string s_null ;
	s_null = argv[i] ? argv[i] : "NULL";
	for (i = 0; i < argc; ++i)
	{
		cout << azColName[i] << " = " << s_null << endl;
	}
	cout << endl;
	return 0;
}