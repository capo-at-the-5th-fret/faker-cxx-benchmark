#pragma once

#include <optional>
#include <algorithm>

inline constexpr bool is_valid_uuid(std::string_view uuid)
{
    if (uuid.size() != 36)
    {
        return false;
    }
    else if ((uuid[8] != '-') || (uuid[13] != '-') || (uuid[18] != '-') ||
        (uuid[23] != '-'))
    {
        return false;
    }
    else if (uuid[14] != '4')
    {
        return false;
    }
    else if (!(uuid[19] == '8' || uuid[19] == '9' || uuid[19] == 'a' ||
        uuid[19] == 'b'))
    {
        return false;
    }

    std::array chunks =
    {
        uuid.substr(0, 8),
        uuid.substr(9, 4),
        uuid.substr(15, 3),
        uuid.substr(20, 3),
        uuid.substr(24, 12)
    };

    if ((chunks[0].size() != 8) || (chunks[1].size() != 4) ||
        (chunks[2].size() != 3) || (chunks[3].size() != 3) ||
        (chunks[4].size() != 12))
    {
        return false;
    }

    for (auto chunk : chunks)
    {
        if (auto pos = chunk.find_first_not_of("0123456789abcdef");
            pos != std::string::npos)
        {
            return false;
        }
    }

    return true;
}