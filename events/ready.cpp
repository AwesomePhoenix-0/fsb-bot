#include "events.hpp"

#include "../utils/utils.hpp"

#include <dpp/dpp.h>
#include <string>
#include <vector>

/*
    Code ran on bot startup.

    Tasks:
        1) Enable D++ logs.
        2) Set bot status on Discord.
        3) Deploy slash commands.

    Parameters:
        - bot / dpp::cluster / FSB client data.

    Returns:
        No object returned.
*/
void Events::ready
(
    dpp::cluster &bot
)
{
    Utils::Logs::log("Booting up ФСБ and deploying slash commands..");

    bot.on_log(dpp::utility::cout_logger());

    bot.on_ready([&bot](const dpp::ready_t &event)
    {
        if (dpp::run_once<struct register_bot_commands>())
        {
            // Command /ban.
            dpp::slashcommand ban_command("ban", "Permanently deport a member from the Discord server.", bot.me.id);
	        ban_command.add_option(dpp::command_option(dpp::co_user, "member", "Member to deport.", true));
            ban_command.add_option(dpp::command_option(dpp::co_string, "reason", "Reason of the deportation.", true));
            bot.global_command_create(ban_command);

            // Command /ping.
            bot.global_command_create(dpp::slashcommand("ping", "Get the latency of the bot.", bot.me.id));

            // Command /play.
            bot.global_command_create(dpp::slashcommand("play", "How to play to MineWorld.", bot.me.id));

            // Command /rules.
            bot.global_command_create(dpp::slashcommand("rules", "Display Discord and Minecraft server rules.", bot.me.id));

            // Bot status handler.
            const std::vector<std::string> status =
            {
                "Spying on you.",
                "Obey and you will not get deported.",
                "Monitoring global economy.",
                "Reporting bad behavior.",
                "Enforcing order worldwide.",
                "Reviewing classified documents.",
                "Closely surveilling AwesomePhoenix.",
                "Eliminating opposition.",
                "Deporting cheaters/troublemakers.",
                "Providing intel to Mossad.",
                "Censoring West propaganda.",
                "Enforcing sanctions.",
                "Censoring non State-approved stuff."
            };

            int index = 0;

            bot.start_timer([&bot, status, &index](const dpp::timer &timer)
            {
                index += 1;

                if (index >= status.size())
                    index = 0;

                bot.set_presence(dpp::presence(dpp::ps_online, dpp::at_custom, status[index]));
            }, 4);
	    }
    });

    Utils::Logs::log("ФСБ successfully booted up!");
}
