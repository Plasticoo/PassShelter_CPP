#ifndef SQLITE_H_
#define SQLITE_H_

#include <iostream>
#include <sqlite3.h>

class SQLite 
{
	public:
		int callback(void* not_used, int argc, char** argv, char** col_name);

		void sql_create(const std::string& table_name);
		void sql_insert(const std::string& table_name, const std::string& user_name, const std::string& user_pass);
		void sql_delete(const std::string& table_name, const std::string& user_name, const std::string& user_pass);

		SQLite(sqlite3 *user_db);
		~SQLite();

	private:
		sqlite3 *sql_db;
};

#endif
