#include <iostream>

#include <stdio.h>

#include "sqlite.h"
#include "callbacks.h"

SQLite::SQLite(sqlite3* user_db): sql_db(user_db)
{
	int rc;

	rc = sqlite3_open("pshelter.db", &sql_db);

	if(rc != SQLITE_OK)
	{
		std::cerr << "[ERROR] - Couldn't open database - " 
			<< __FILE__ << ":" << __LINE__ << "\n"
			<< "ErrorMsg - " << sqlite3_errmsg(sql_db) << "\n";

		sqlite3_close(sql_db);

		exit(EXIT_FAILURE);
	}	
}

SQLite::~SQLite()
{
	sqlite3_close(sql_db);
}

void SQLite::sql_create(const std::string& table_name)
{
	int rc;
	char* err_msg = 0;
	const std::string sql_stmt = "DROP TABLE IF EXISTS " + table_name + ";"
		"CREATE TABLE " + table_name + "(Id INT, username TEXT, password TEXT);"; 

	rc = sqlite3_exec(sql_db, sql_stmt.c_str(), 0, 0, &err_msg);

	if(rc != SQLITE_OK)
	{
		std::cerr << "Failed to create table.\n"
			<< "SQL Error - " << err_msg << "\n";

		sqlite3_free(err_msg);
	}
	else
	{
		std::cout << "Table created successfully!\n"
			<< "Table: " << table_name << "\n";
	}
}

void SQLite::sql_insert(const std::string& table_name, const std::string& user_name, const std::string& user_pass)
{
	int rc;
	char* err_msg = 0;
	const std::string sql_stmt = "INSERT INTO " + table_name + " VALUES('" + user_name + "', '" + user_pass + "');";

	rc = sqlite3_exec(sql_db, sql_stmt.c_str(), 0, 0, &err_msg);

	if(rc != SQLITE_OK)
	{
		std::cerr << "Failed to insert data.\n"
			<< "SQL Error - " << err_msg << "\n";

		sqlite3_free(err_msg);
	}
	else
	{
		std::cout << "Data inserted successfully!\n"
			<< "Data inserted: \n"
			<< "\tTable: " << table_name
			<< "\tUsername: " << user_name
			<< "\tPassword: " << user_pass
			<< "\n";
	}
}

void SQLite::sql_delete(const std::string& table_name, const std::string& user_name, const std::string& user_pass)
{
	int rc;
	char* err_msg = 0;                                                                                       
	const std::string sql_stmt = "INSERT INTO " + table_name + " VALUES('" + user_name + "', '" + user_pass + "')";

	rc = sqlite3_exec(sql_db, sql_stmt.c_str(), 0, 0, &err_msg);

	if(rc != SQLITE_OK)
	{
		std::cerr << "Failed to delete data.\n"
			<< "SQL Error - " << err_msg << "\n";

		sqlite3_free(err_msg);
	}
	else
	{
		std::cout << "Data deleted successfully!\n"
			<< "Data delete: \n"
			<< "\tTable: " << table_name
			<< "\tUsername: " << user_name
			<< "\tPassword: " << user_pass
			<< "\n";
	}
}

void SQLite::sql_show_tables()
{
	int rc;
	char* err_msg = 0;
	const std::string sql_stmt = "SELECT name FROM sqlite_master WHERE type='table'";

	rc = sqlite3_exec(sql_db, sql_stmt.c_str(), table_callback, 0, &err_msg);

	if(rc != SQLITE_OK)
	{
		std::cerr << "Failed to delete data.\n"
			<< "SQL Error - " << err_msg << "\n";

		sqlite3_free(err_msg);
	}
}

void SQLite::sql_show_data(const std::string& table_name)
{
	int rc;
	char* err_msg = 0;
	const std::string sql_stmt = "SELECT * FROM " + table_name;

	rc = sqlite3_exec(sql_db, sql_stmt.c_str(), column_callback, 0, &err_msg);

	if(rc != SQLITE_OK)
	{
		std::cerr << "Failed to delete data.\n"
			<< "SQL Error - " << err_msg << "\n";

		sqlite3_free(err_msg);
	}
}

