#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName);

void prnt_dir();
int create_db(sqlite3 *db);

int main(int argc, char const *argv[])
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	char *sql;

	prnt_dir();

	//rc = sqlite3_open("test.db", &db);
	rc = create_db(&db);

	if(rc){
		fprintf(stderr, "Can`t open db: %s\n", sqlite3_errmsg(db));
		return 0;
	}else {
		fprintf(stderr, "Opned db OK!\n");
	}



	sql = "CREATE TABLE IF NOT EXISTS COMPANY("  \
      "ID INT PRIMARY KEY     NOT NULL," \
      "NAME           TEXT    NOT NULL," \
      "AGE            INT     NOT NULL," \
      "ADDRESS        CHAR(50)," \
      "SALARY         REAL );";

       /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

   if(rc != SQLITE_OK){
   	fprintf(stderr, "SQL error : %s\n", zErrMsg);
   	sqlite3_free(zErrMsg);
   } else {
   	fprintf(stdout, "Table created seccessfully\n");
   }

	sqlite3_close(db);

	return 0;
}

void prnt_dir(){
	char dir[100];

	getcwd(dir, 100);
	printf("Working dir : %s\n", dir); 
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
	int i;
	for (i = 0; i < argc; ++i)
	{
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;

}

void create_db(sqlite3 *db){
	int check;

	check = sqlite3_open("test.db", &db);

	if(check){
		fprintf(stderr, "Can`t open db: %s\n", sqlite3_errmsg(db));
		return 0;
	}else {
		fprintf(stderr, "Opned db OK!\n");
		return 1;
	}

}






















