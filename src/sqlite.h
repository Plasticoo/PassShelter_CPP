#ifndef SQLITE_H_
#define SQLITE_H_

#include <iostream>
#include <sqlite3.h>

class SQLite 
{
	public:
		void sql_create(const std::string& table_name);
		void sql_insert(const std::string& table_name, const std::string& user_name, const std::string& user_pass);
		void sql_delete_table(const std::string& table_name);
		void sql_delete_data(const std::string& table_name, const std::string& user_id);
		
		void sql_show_tables();
		void sql_show_data(const std::string& table_name);

		SQLite(sqlite3 *user_db, std::string name);
		~SQLite();

	private:
		sqlite3 *sql_db;
		std::string db_name;
};

#endif
