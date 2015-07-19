#ifndef SQLITE_H_
#define SQLITE_H_

#include <iostream>
#include <sqlite3.h>

class SQLite 
{
	public:
		void create(const std::string& table_name);
		void insert(const std::string& table_name, const std::string& user_name, const std::string& user_pass);
		void delete_table(const std::string& table_name);
		void delete_data(const std::string& table_name, const std::string& user_id);
		
		void show_tables();
		void show_data(const std::string& table_name);

		SQLite(sqlite3 *user_db, std::string name);
		~SQLite();

	private:
		sqlite3 *sql_db;
		std::string db_name;
};

#endif
