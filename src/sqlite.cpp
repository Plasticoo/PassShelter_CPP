#include <iostream>

#include "sqlite.h"

SQLite::SQLite(sqlite3* user_db): sql_db(user_db)
{
	int rc;

	rc = sqlite3_open("pshelter.db", &sql_db);

	if(rc != SQLITE_OK)
	{
		std::cerr << "[ERROR] - Couldn't open database - " << __FILE__ << ":" << __LINE__ << "\n";
		std::cerr << "ErrorMsg - " << sqlite3_errmsg(sql_db) << "\n";

		sqlite3_close(sql_db);

		exit(EXIT_FAILURE);
	}	
}

SQLite::~SQLite()
{
	sqlite3_close(sql_db);
}

void SQLite::sql_insert(std::string table_name, std::string user_name, std::string user_pass)
{
	int rc;
	char* err_msg = 0;
	const std::string sql_stmt = "INSERT INTO " + table_name + " VALUES('" + user_name + "', '" + user_pass + "')";

	rc = sqlite3_exec(sql_db, sql_stmt.c_str(), 0, 0, &err_msg);

	if(rc != SQLITE_OK)
	{
		std::cerr << "Failed to insert data.\n";
		std::cerr << "SQL Error - " << err_msg << "\n";

		sqlite3_free(err_msg);
	}
	else
	{
		std::cout << "Data inserted successfully!\n";
		std::cout << "Data inserted: "
			<< "\tTable: " << table_name
			<< "\tUsername: " << user_name
			<< "\tPassword: " << user_pass
			<< "\n";
	}
}

void SQLite::sql_delete(std::string table_name, std::string user_name, std::string user_pass)
{
	int rc;
	char* err_msg = 0;                                                                                       
	// TODO
	const std::string sql_stmt = "INSERT INTO " + table_name + " VALUES('" + user_name + "', '" + user_pass + "')";

	rc = sqlite3_exec(sql_db, sql_stmt.c_str(), 0, 0, &err_msg);

	if(rc != SQLITE_OK)
	{
		std::cerr << "Failed to delete data.\n";
		std::cerr << "SQL Error - " << err_msg << "\n";

		sqlite3_free(err_msg);
	}
	else
	{
		std::cout << "Data deleted successfully!\n";
		std::cout << "Data delete: "
			<< "\tTable: " << table_name
			<< "\tUsername: " << user_name
			<< "\tPassword: " << user_pass
			<< "\n";
	}
}
