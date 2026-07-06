#include "utils.logs.hpp"

#include "../files/utils.files.hpp"
#include "../miscellaneous/utils.miscellaneous.hpp"
#include "../text/utils.text.hpp"
#include "../../config/tweaks.hpp"

#include <iostream>
#include <stdexcept>
#include <string>
#include <time.h>
#include <vector>

/*
    Send a message in the terminal and write it into the logs file (if enabled).

    Tasks:
        1) Verify function parameters.
        2) We log the message in the terminal.
        3) If logs file is enabled, we write the message into the logs file.

    Parameters:
        - message  / string / Message to log.

    Returns:
        No object returned.
*/
void Logs::log
(
    const std::string &message
)
{
    if (Text::trim(message).size() < 1)
        return;

    const time_t timestamp = Miscellaneous::get_current_timestamp();
    const std::vector<std::string> date = Miscellaneous::get_date_from_timestamp(timestamp);

    // Date format: DD.MM.YY-HH:MN:SS.
    const std::string date_format = date[2] + "." + date[1] + "." + date[0] + "-" + date[3] + ":" + date[4] + ":" + date[5];
    const std::string log = "[" + date_format + "] " + message + "\n"; // [time] message

    std::cout << log;

    if constexpr (Tweaks::ENABLE_LOGS_FILE)
        Files::write_file(true, log, "fsb.logs");
}



/*
    Send a message in the terminal, write it into the logs file (if enabled) and throw a runtime error.

    Tasks:
        1) We log the message in the terminal..
        2) If logs file is enabled, we write the message into the logs file.
        3) Throw runtime error with message.

    Parameters:
        - message / string / Message to log as a crash.

    Returns:
        No object returned.
*/
void Logs::crash_log
(
    const std::string &message
)
{
    std::cout << "[crash] " << message << "\n";

    if constexpr (Tweaks::ENABLE_LOGS_FILE)
        Files::write_file(true, message, "fsb.logs");

    throw std::runtime_error(message);
}
