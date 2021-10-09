#include <stdio.h>
#include <sqlite3.h>
#include <string>
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

using namespace std;

class DB_class
{
private:
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	string db_name = "test_class.db";
	char *clike_name;
	char *sql;

public:
	DB_class();
	~DB_class(){ cout << " destructor\n";};
	void prnt_dbname();
	void prnt_dir();
	
};


int main(int argc, char const *argv[])
{

	DB_class db_obj1;
	db_obj1.prnt_dir();
	return 0;
}

// DB_class methods ------------------------------------------
DB_class :: DB_class(){
	int len = db_name.length();
	clike_name = (char*) malloc(len * sizeof(char));
	
	if (clike_name == NULL){cout << "Memory allocation error!" << endl;len = 0;}
	else {cout << "DB name coppied.\n";len = 1;}

	if (len == 1){strcpy(clike_name, db_name.c_str());}
	cout << "DB name car* = " << clike_name << endl;
};

void DB_class :: prnt_dbname(){ cout << db_name << endl;}


void DB_class :: prnt_dir(){
	char dir[100];

	getcwd(dir, 100);
	printf(" Working dir : %s\n", dir); 
}
// ----------------------------------------------- DB_class methods