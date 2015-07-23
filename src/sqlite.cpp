#include <iostream>

#include <stdio.h>
#include <stdlib.h>

#include "sqlite.h"
#include "callbacks.h"

SQLite::SQLite(sqlite3* user_db, std::string name): sql_db(user_db), db_name(name)
{
	int rc;

	rc = sqlite3_open(db_name.c_str(), &sql_db);

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

void SQLite::create(const std::string& table_name)
{
	int rc;
	char* err_msg = 0;
	const std::string sql_stmt = "DROP TABLE IF EXISTS " + table_name + ";"
		"CREATE TABLE " + table_name + " (id INTEGER PRIMARY KEY AUTOINCREMENT, username TEXT NOT NULL, password TEXT NOT NULL);"; 

	rc = sqlite3_exec(sql_db, sql_stmt.c_str(), 0, 0, &err_msg);

	if(rc != SQLITE_OK)
	{
		std::cerr << "\nFailed to create table.\n"
			<< "SQL Error - " << err_msg << "\n";

		sqlite3_free(err_msg);
	}
	else
	{
		std::cout << "\nTable created successfully!\n"
			<< "Table: " << table_name << "\n\n";
	}
}

void SQLite::insert(const std::string& table_name, const std::string& user_name, const std::string& user_pass)
{
	int rc;
	char* err_msg = 0;
	const std::string sql_stmt = "INSERT INTO " + table_name + " (username, password) VALUES('" + user_name + "', '" + user_pass + "');";

	rc = sqlite3_exec(sql_db, sql_stmt.c_str(), 0, 0, &err_msg);

	if(rc != SQLITE_OK)
	{
		std::cerr << "\nFailed to insert data.\n"
			<< "SQL Error - " << err_msg << "\n";

		sqlite3_free(err_msg);
	}
	else
	{
		std::cout << "\nData inserted successfully!\n"
			<< "Data inserted: \n"
			<< "\tTable: " << table_name
			<< "\n\tUsername: " << user_name
			<< "\n\tPassword: " << user_pass
			<< "\n\n";
	}
}

void SQLite::delete_table(const std::string& table_name)
{
	int rc;
	char* err_msg = 0;                                                                                       
	const std::string sql_stmt = "DROP TABLE " + table_name + ";";

	rc = sqlite3_exec(sql_db, sql_stmt.c_str(), 0, 0, &err_msg);

	if(rc != SQLITE_OK)
	{
		std::cerr << "\nFailed to delete table.\n"
			<< "SQL Error - " << err_msg << "\n";

		sqlite3_free(err_msg);
	}
	else
	{
		std::cout << "\nTable successfully deleted.\n";
	}
}

void SQLite::delete_data(const std::string& table_name, const std::string& user_id)
{
	int rc;
	char* err_msg = 0;                                                                                       
	const std::string sql_stmt = "DELETE FROM " + table_name + " WHERE ID = " + user_id + ";";

	rc = sqlite3_exec(sql_db, sql_stmt.c_str(), 0, 0, &err_msg);

	if(rc != SQLITE_OK)
	{
		std::cerr << "\nFailed to delete data.\n"
			<< "SQL Error - " << err_msg << "\n";

		sqlite3_free(err_msg);
	}
	else
	{
		std::cout << "\nData deleted successfully from " + table_name + "!\n";
	}
}

void SQLite::show_tables()
{
	int rc;
	char* err_msg = 0;
	const std::string sql_stmt = "SELECT name FROM sqlite_master WHERE type='table'";

	putchar('\n');
	printf("Tables:\n");

	rc = sqlite3_exec(sql_db, sql_stmt.c_str(), table_callback, 0, &err_msg);

	putchar('\n');

	if(rc != SQLITE_OK)
	{
		std::cerr << "\nFailed to delete data.\n"
			<< "SQL Error - " << err_msg << "\n";

		sqlite3_free(err_msg);
	}
}

void SQLite::show_data(const std::string& table_name)
{
	int rc;
	char* err_msg = 0;
	const std::string sql_stmt = "SELECT * FROM " + table_name;

	putchar('\n');
	printf("Data:\n");

	rc = sqlite3_exec(sql_db, sql_stmt.c_str(), column_callback, 0, &err_msg);

	if(rc != SQLITE_OK)
	{
		std::cerr << "\nFailed to delete data.\n"
			<< "SQL Error - " << err_msg << "\n";

		sqlite3_free(err_msg);
	}
}

