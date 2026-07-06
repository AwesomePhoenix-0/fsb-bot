#ifndef UTILS_HPP
#define UTILS_HPP

#include "database/utils.database.hpp"
#include "files/utils.files.hpp"
#include "logs/utils.logs.hpp"
#include "miscellaneous/utils.miscellaneous.hpp"
#include "parsers/utils.parsers.hpp"
#include "text/utils.text.hpp"

namespace Utils
{
    ///////////////////////////////////////
    ///// database/utils.database.hpp /////
    ///////////////////////////////////////

    namespace Database = ::Database;

    /////////////////////////////////
    ///// files/utils.files.hpp /////
    /////////////////////////////////

    namespace Files = ::Files;

    ///////////////////////////////
    ///// logs/utils.logs.hpp /////
    ///////////////////////////////

    namespace Logs = ::Logs;

    /////////////////////////////////////////////////
    ///// miscellaneous/utils.miscellaneous.hpp /////
    /////////////////////////////////////////////////

    namespace Miscellaneous = ::Miscellaneous;

    /////////////////////////////////////
    ///// parsers/utils.parsers.hpp /////
    /////////////////////////////////////

    namespace Parsers = ::Parsers;

    ///////////////////////////////
    ///// text/utils.text.hpp /////
    ///////////////////////////////

    namespace Text = ::Text;
}

#endif
