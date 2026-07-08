#include "commands.hpp"

#include <dpp/dpp.h>

/*
    Give info about the bot and every command.  
*/


void Commands::help
(
    const dpp::interaction_create_t &event
)
{
    event.reply
    (
        dpp::message
        (
            std::string("## Help\n"
                "\n"
                "### Info:\n"
                "This is the **ФСБ** discord bot.\n"
                "**Github:** https://github.com/ArkorByte/fsb-bot\n"
                "**Official discord server:** https://discord.gg/zkJ75UDVEV\n"
                "\n"
                "### Commands:\n"
                "**/help** Show this message\n"
                "**/ping** Give you the ping of the bot\n"
                "**/play** Shows you how to play MineWorld\n"
                "**/rules** Sends you the rules\n"
                "**/ban** Bans the specified player\n"
                "**/kick** Kick the specified player").set_flags(dpp::m_ephemeral)
    );
}
