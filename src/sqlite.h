#ifndef SQLITE_H_
#define SQLITE_H_

#include <iostream>
#include <sqlite3.h>

class SQLite 
{
	public:
		void sql_create(const std::string& table_name);
		void sql_insert(const std::string& table_name, const std::string& user_name, const std::string& user_pass);
		void sql_delete(const std::string& table_name, const std::string& user_id);
		
		void sql_show_tables();
		void sql_show_data(const std::string& table_name);

		SQLite(sqlite3 *user_db);
		~SQLite();

	private:
		sqlite3 *sql_db;
};

#endif
