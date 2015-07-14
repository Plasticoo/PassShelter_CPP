#ifndef SQLITE_H_
#define SQLITE_H_

#include <iostream>
#include <sqlite3.h>

class SQLite 
{
	public:
		int callback(void* not_used, int argc, char** argv, char** azCol_name);

		void sql_create(std::string table_name);
		void sql_insert(std::string table_name, std::string user_name, std::string user_pass);
		void sql_delete(std::string table_name, std::string user_name, std::string user_pass);

		SQLite(sqlite3 *user_db);
		~SQLite();

	private:
		sqlite3 *sql_db;
};

#endif
