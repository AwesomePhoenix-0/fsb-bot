#include "events.hpp"

#include "../utils/utils.hpp"

#include <dpp/dpp.h>

/*
    Event that triggers when a member leaves the server.
*/
void Events::guild_member_remove
(
    dpp::cluster &bot
)
{
    bot.on_guild_member_remove([&bot](const dpp::guild_member_remove_t &event)
    {
        Utils::Logs::log("Member left -> " + std::to_string(event.removed.id) + "!");
    });
}
