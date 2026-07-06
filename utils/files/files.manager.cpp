#include "utils.files.hpp"

#include "../logs/utils.logs.hpp"

#include <filesystem>
#include <fstream>
#include <string>

/*
    Create a new empty file.

    Tasks:
        1) Verify the file path.
        2) Verify that another file doesn't already exist.
        3) Try to create the file.

    Parameters:
        - file_path / string / Targeted path + new file name.

    Returns:
        A boolean confirming whether we successfully created the empty file or not.
*/
bool Files::create_new_empty_file
(
    const std::string &file_path
)
{
    const bool has_filename = std::filesystem::path(file_path).has_filename();

    if (!has_filename)
    {
        Logs::log("Warning: Empty file creation failed, path provided invalid -> \"" + file_path + "\".");
        return false;
    }

    const bool file_exists = std::filesystem::exists(file_path);

    if (file_exists)
    {
        Logs::log("Warning: Empty file creation failed, \"" + file_path + "\" already exists.");
        return false;
    }

    std::ofstream file(file_path);
    const bool file_opened = file.is_open();

    if (file_opened)
    {
        file.close();
        Logs::log("New empty file \"" + file_path + "\" created successfully!");
        return true;
    }

    Logs::log("Warning: Empty file creation failed, failed to create \"" + file_path + "\".");
    throw std::runtime_error("rerwer");
    return false;
}



/*
    Write some data into a file.
    Warning: If append is false, the file will be entirely overwritten and all previous data will be lost!

    Tasks:
        1) Verify the file path.
        2) If the file doesn't exist, we try to create it.
        3) Open the file in the selected mode.
        4) Write data into the file.

    Parameters:
        - append    / bool   / Append the file or overwrite.
        - data      / string / Data to write into the file.
        - file_path / string / Path to the file we want to write data into.

    Returns:
        A boolean confirming whether we successfully wrote into the file or not.
*/
bool Files::write_file
(
    const bool        &append,
    const std::string &data,
    const std::string &file_path
)
{
    std::ofstream file;
    const bool has_filename = std::filesystem::path(file_path).has_filename();

    if (!has_filename)
    {
        Logs::log("Warning: File writing failed, path provided invalid -> \"" + file_path + "\".");
        return false;
    }

    const bool file_exists(std::filesystem::exists(file_path));

    if (!file_exists)
    {
        const bool file_created = create_new_empty_file(file_path);

        if (!file_created)
        {
            Logs::log("Warning: File writing failed, failed to create \"" + file_path + "\".");
            return false;
        }
    }

    if (append)
        file.open(file_path, std::ios::out | std::ios::app);
    else
        file.open(file_path, std::ios::out | std::ios::trunc);

    const bool is_opened = file.is_open();

    if (!is_opened)
    {
        Logs::log("Warning: File writing failed, couldn't open file for writing -> \"" + file_path + "\".");
        return false;
    }

    file << data;
    file.close();

    return true;
}
