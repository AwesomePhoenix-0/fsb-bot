#include "commands.hpp"

#include <dpp/dpp.h>

/*
    Gives some information about how to play to MineWorld.

    Tasks:
        1) Reply to the interaction.

    Parameters:
        - event / dpp::interaction_create_t / Event information.

    Returns:
        No object returned.
*/
void Commands::play
(
    const dpp::interaction_create_t &event
)
{
    event.reply
    (
        dpp::message(":warning: **Not available** at the time. Beta 2.0 **coming soon**!").set_flags(dpp::m_ephemeral)
    );
}
