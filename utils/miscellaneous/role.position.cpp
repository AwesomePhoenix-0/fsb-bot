#include "utils.miscellaneous.hpp"

#include <dpp/dpp.h>
#include <vector>

/*
    Return the position of the highest role of a guild member.

    Tasks:
        1) Set highest_position to 0 (no role).
        2) For each role ID available, we get its position.
        3) If we found the highest position yet, we register as highest position.

    Parameters:
        - member / dpp::guild_member / Targeted member.

    Returns:
        A uint8_t containing the position index of the highest role of this member.
*/
uint8_t Miscellaneous::highest_role_position
(
    const dpp::guild_member &member
)
{
    uint8_t highest_position = 0;

    for (const dpp::snowflake &role_id : member.get_roles())
    {
        const dpp::role *role = dpp::find_role(role_id);
        const uint8_t position = role -> position;

        if (role && position > highest_position)
            highest_position = position;
    }

    return highest_position;
}
