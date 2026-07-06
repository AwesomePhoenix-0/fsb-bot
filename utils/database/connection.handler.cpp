#include "utils.database.hpp"

#include "../logs/utils.logs.hpp"

#include <mysql/mysql.h>
#include <string>

///////////////////////////////////////////////////
//////////////////// Functions ////////////////////
///////////////////////////////////////////////////

/*
    Connect to the database.

    Tasks:
        1) Try to initialize MySQL.
        2) Try to connect to the database with the credentials provided.
        3) Verify connection.

    Parameters:
        - database_obj  / MYSQL* / Object that points to the database once connected.
        - database_name / string / Name of the database we want to use.
        - host          / string / IP address or domain name pointing to the database we want to use.
        - port          / int    / Port of the database we want to use.
        - user          / string / User we are going to use to connect to the database.
        - password      / string / Password of this user.

    Returns:
        No object returned.
*/
void Database::connect_database
(
    MYSQL*            &database_obj,
    const std::string &database_name,
    const std::string &host,
    const int         &port,
    const std::string &user,
    const std::string &password
)
{
    Logs::log("Connecting to the database..");
    database_obj = mysql_init(nullptr);

    if (database_obj == nullptr)
        Logs::crash_log("Failed to initialize mysql for database connection!");

    const bool reconnect = true;
    mysql_options(database_obj, MYSQL_OPT_RECONNECT, &reconnect);

    const MYSQL* connection = mysql_real_connect(database_obj, host.c_str(), user.c_str(), password.c_str(), database_name.c_str(), port, nullptr, 0);

    if (connection == nullptr)
    {
        const std::string error = std::string(mysql_error(database_obj));

        mysql_close(database_obj);
        Logs::crash_log("Failed to establish connection with the database! Error code -> " + error + ".");
    }

    Logs::log("Successfully connected to database " + database_name + "@" + host + " as " + user + "!");
}



/*
    Disconnect from a database.

    Tasks:
        1) Verify function parameters.
        2) Disconnect from the database.

    Parameters:
        - database / MYSQL* / Database to disconnect from.

    Returns:
        No object returned.
*/
void Database::disconnect_database
(
    MYSQL* &database
)
{
    if (database == nullptr)
    {
        Logs::log("Warning: Failed to disconnect from database! The database provided is not valid.");
        return;
    }

    Logs::log("Disconnecting from " + std::string(database -> db) + "@" + std::string(database -> host) + "..");

    mysql_close(database);
    database = nullptr;

    Logs::log("Successfully disconnected from the database!");
}

/////////////////////////////////////////////////
//////////////////// Classes ////////////////////
/////////////////////////////////////////////////

Database::database_handler::database_handler
(
    MYSQL*            &database_obj,
    const std::string &database_name,
    const std::string &host,
    const int         &port,
    const std::string &user,
    const std::string &password
)
    : database(database_obj)
{
    connect_database(database_obj, database_name, host, port, user, password);
}

Database::database_handler::~database_handler()
{
    disconnect_database(database);
}
