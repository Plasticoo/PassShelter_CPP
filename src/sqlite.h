#ifndef SQLITE_H_
#define SQLITE_H_

#include <sqlite3.h>

class SQLite 
{
	public:
		void sql_insert(std::string table_name, std::string user_name, std::string user_pass);
		void sql_delete();

		SQLite(sqlite3 *user_db);
		~SQLite();

	private:
		sqlite3 *sql_db;
}

#endif
