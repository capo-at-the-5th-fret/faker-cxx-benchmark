#pragma once

#include <string>
#include <random>
#include <array>
#include <sstream>
#include "random_generator.h"

namespace area51
{
class String
{
public:
// NOTE: faker lib has a warning in RandomGenerator that is treated as an error.
// A version of RandomGenerator that fixes this warning is used instead. The
// following code is copied from faker
template <typename T = std::mt19937>
static std::string uuid(RandomGenerator<T> gen = RandomGenerator<std::mt19937>{})
{
    static std::uniform_int_distribution<> dist(0, 15);
    static std::uniform_int_distribution<> dist2(8, 11);

    std::stringstream ss;
    ss << std::hex;

    for (int i = 0; i < 8; i++)
    {
        ss << gen(dist);
    }

    ss << "-";
    for (int i = 0; i < 4; i++)
    {
        ss << gen(dist);
    }

    ss << "-4";
    for (int i = 0; i < 3; i++)
    {
        ss << gen(dist);
    }

    ss << "-";

    ss << gen(dist2);

    for (int i = 0; i < 3; i++)
    {
        ss << gen(dist);
    }

    ss << "-";

    for (int i = 0; i < 12; i++)
    {
        ss << gen(dist);
    };

    return ss.str();
}
};

#if 0
template <typename URBG>
std::string uuid(URBG&& g = std::mt19937{std::random_device{}()})
{
    std::uniform_int_distribution<> dist(0, 15);
    std::uniform_int_distribution<> dist2(8, 11);

    std::stringstream ss;
    ss << std::hex;

    for (int i = 0; i < 8; i++)
    {
        ss << dist(g);
    }

    ss << "-";
    for (int i = 0; i < 4; i++)
    {
        ss << dist(g);
    }

    ss << "-4";
    for (int i = 0; i < 3; i++)
    {
        ss << dist(g);
    }

    ss << "-";

    ss << dist2(g);

    for (int i = 0; i < 3; i++)
    {
        ss << dist(g);
    }

    ss << "-";

    for (int i = 0; i < 12; i++)
    {
        ss << dist(g);
    };

    return ss.str();
}

template <typename T = std::mt19937>
std::string uuid_2(RandomGenerator<T> gen = RandomGenerator<std::mt19937>{})
{
    static std::uniform_int_distribution<> dist(0, 15);
    static std::uniform_int_distribution<> dist2(8, 11);

    static constexpr std::array uuid_digits =
    {
        '0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
    };

    // xxxxxxxx-xxxx-4xxx-[8-b]xxx-xxxxxxxxxxxx

    std::string ret;
    ret.resize(36);

    for (int i = 0; i < 8; i++)
    {
        ret[i] = uuid_digits[gen(dist)];
    }

    ret[8] = '-';

    for (int i = 9; i < 13; i++)
    {
        ret[i] = uuid_digits[gen(dist)];
    }

    ret[13] = '-';
    ret[14] = '4';

    for (int i = 15; i < 18; i++)
    {
        ret[i] = uuid_digits[gen(dist)];
    }

    ret[18] = '-';
    ret[19] = gen(dist2);

    for (int i = 20; i < 23; i++)
    {
        ret[i] = uuid_digits[gen(dist)];
    }

    ret[23] = '-';

    for (int i = 24; i < 36; i++)
    {
        ret[i] = uuid_digits[gen(dist)];
    };

    return ret;
}

/*
template <typename Gen>
requires std::uniform_random_bit_generator<std::remove_reference_t<Gen>>
std::string uuid_2(Gen&& gen = std::mt19937{std::random_device{}()})
{
    std::uniform_int_distribution<> dist(0, 15);
    std::uniform_int_distribution<> dist2(8, 11);

    static constexpr std::array uuid_digits =
    {
        '0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
    };

    // xxxxxxxx-xxxx-4xxx-[8-b]xxx-xxxxxxxxxxxx

    std::string ret;
    ret.reserve(36);

    for (int i = 0; i < 8; i++)
    {
        ret[i] = uuid_digits[dist(gen)];
    }

    ret[8] = '-';

    for (int i = 9; i < 13; i++)
    {
        ret[i] = uuid_digits[dist(gen)];
    }

    ret[13] = '-';
    ret[14] = '4';

    for (int i = 15; i < 18; i++)
    {
        ret[i] = uuid_digits[dist(gen)];
    }

    ret[18] = '-';
    ret[19] = dist2(gen);

    for (int i = 20; i < 23; i++)
    {
        ret[i] = uuid_digits[dist(gen)];
    }

    ret[23] = '-';

    for (int i = 24; i < 36; i++)
    {
        ret[i] = uuid_digits[dist(gen)];
    };

    return ret;
}
*/

template <typename T = std::mt19937>
std::string uuid_3(RandomGenerator<T> gen = RandomGenerator<std::mt19937>{})
{
    static std::uniform_int_distribution<> dist(0, 15);
    static std::uniform_int_distribution<> dist2(8, 11);

    static constexpr std::array uuid_digits =
    {
        '0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
    };

    // xxxxxxxx-xxxx-4xxx-[8-b]xxx-xxxxxxxxxxxx
    return
    {
        uuid_digits[gen(dist)],
        uuid_digits[gen(dist)],
        uuid_digits[gen(dist)],
        uuid_digits[gen(dist)],
        uuid_digits[gen(dist)],
        uuid_digits[gen(dist)],
        uuid_digits[gen(dist)],
        uuid_digits[gen(dist)],
        '-',
        uuid_digits[gen(dist)],
        uuid_digits[gen(dist)],
        uuid_digits[gen(dist)],
        uuid_digits[gen(dist)],
        '-',
        '4',
        uuid_digits[gen(dist)],
        uuid_digits[gen(dist)],
        uuid_digits[gen(dist)],
        '-',
        uuid_digits[gen(dist2)],
        uuid_digits[gen(dist)],
        uuid_digits[gen(dist)],
        uuid_digits[gen(dist)],
        '-',
        uuid_digits[gen(dist)],
        uuid_digits[gen(dist)],
        uuid_digits[gen(dist)],
        uuid_digits[gen(dist)],
        uuid_digits[gen(dist)],
        uuid_digits[gen(dist)],
        uuid_digits[gen(dist)],
        uuid_digits[gen(dist)],
        uuid_digits[gen(dist)],
        uuid_digits[gen(dist)],
        uuid_digits[gen(dist)],
        uuid_digits[gen(dist)]
    };
}

/*
template <typename Gen>
requires std::uniform_random_bit_generator<std::remove_reference_t<Gen>>
std::string uuid_3(Gen&& gen = std::mt19937{std::random_device{}()})
{
    std::uniform_int_distribution<> dist(0, 15);
    std::uniform_int_distribution<> dist2(8, 11);

    static constexpr std::array uuid_digits =
    {
        '0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
    };

    // xxxxxxxx-xxxx-4xxx-[8-b]xxx-xxxxxxxxxxxx
    return std::initializer_list
    {
        uuid_digits[dist(gen)],
        uuid_digits[dist(gen)],
        uuid_digits[dist(gen)],
        uuid_digits[dist(gen)],
        uuid_digits[dist(gen)],
        uuid_digits[dist(gen)],
        uuid_digits[dist(gen)],
        uuid_digits[dist(gen)],
        '-',
        uuid_digits[dist(gen)],
        uuid_digits[dist(gen)],
        uuid_digits[dist(gen)],
        uuid_digits[dist(gen)],
        '-',
        '4',
        uuid_digits[dist(gen)],
        uuid_digits[dist(gen)],
        uuid_digits[dist(gen)],
        '-',
        uuid_digits[dist2(gen)],
        uuid_digits[dist(gen)],
        uuid_digits[dist(gen)],
        uuid_digits[dist(gen)],
        '-',
        uuid_digits[dist(gen)],
        uuid_digits[dist(gen)],
        uuid_digits[dist(gen)],
        uuid_digits[dist(gen)],
        uuid_digits[dist(gen)],
        uuid_digits[dist(gen)],
        uuid_digits[dist(gen)],
        uuid_digits[dist(gen)],
        uuid_digits[dist(gen)],
        uuid_digits[dist(gen)],
        uuid_digits[dist(gen)],
        uuid_digits[dist(gen)]
    };
}
*/

template <typename T = std::mt19937>
std::string uuid_4(RandomGenerator<T> gen = RandomGenerator<std::mt19937>{})
{
    std::uniform_int_distribution<> dist(0, 15);
    std::uniform_int_distribution<> dist2(8, 11);

    static constexpr std::array uuid_digits =
    {
        '0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
    };

    std::string ret;
    ret.resize(36);

    // xxxxxxxx-xxxx-4xxx-[8-b]xxx-xxxxxxxxxxxx
    ret[0] = uuid_digits[gen(dist)];
    ret[1] = uuid_digits[gen(dist)];
    ret[2] = uuid_digits[gen(dist)];
    ret[3] = uuid_digits[gen(dist)];
    ret[4] = uuid_digits[gen(dist)];
    ret[5] = uuid_digits[gen(dist)];
    ret[6] = uuid_digits[gen(dist)];
    ret[7] = uuid_digits[gen(dist)];
    ret[8] = '-';
    ret[9] = uuid_digits[gen(dist)];
    ret[10] = uuid_digits[gen(dist)];
    ret[11] = uuid_digits[gen(dist)];
    ret[12] = uuid_digits[gen(dist)];
    ret[13] = '-';
    ret[14] = '4';
    ret[15] = uuid_digits[gen(dist)];
    ret[16] = uuid_digits[gen(dist)];
    ret[17] = uuid_digits[gen(dist)];
    ret[18] = '-';
    ret[19] = uuid_digits[gen(dist2)];
    ret[20] = uuid_digits[gen(dist)];
    ret[21] = uuid_digits[gen(dist)];
    ret[22] = uuid_digits[gen(dist)];
    ret[23] = '-';
    ret[24] = uuid_digits[gen(dist)];
    ret[25] = uuid_digits[gen(dist)];
    ret[26] = uuid_digits[gen(dist)];
    ret[27] = uuid_digits[gen(dist)];
    ret[28] = uuid_digits[gen(dist)];
    ret[29] = uuid_digits[gen(dist)];
    ret[30] = uuid_digits[gen(dist)];
    ret[31] = uuid_digits[gen(dist)];
    ret[32] = uuid_digits[gen(dist)];
    ret[33] = uuid_digits[gen(dist)];
    ret[34] = uuid_digits[gen(dist)];
    ret[35] = uuid_digits[gen(dist)];

    return ret;
}

/*
template <typename Gen>
requires std::uniform_random_bit_generator<std::remove_reference_t<Gen>>
std::string uuid_4(Gen&& gen = std::mt19937{std::random_device{}()})
{
    std::uniform_int_distribution<> dist(0, 15);
    std::uniform_int_distribution<> dist2(8, 11);

    static constexpr std::array uuid_digits =
    {
        '0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
    };

    std::string ret;
    ret.resize(36);

    // xxxxxxxx-xxxx-4xxx-[8-b]xxx-xxxxxxxxxxxx
    ret[0] = uuid_digits[dist(gen)];
    ret[1] = uuid_digits[dist(gen)];
    ret[2] = uuid_digits[dist(gen)];
    ret[3] = uuid_digits[dist(gen)];
    ret[4] = uuid_digits[dist(gen)];
    ret[5] = uuid_digits[dist(gen)];
    ret[6] = uuid_digits[dist(gen)];
    ret[7] = uuid_digits[dist(gen)];
    ret[8] = '-';
    ret[9] = uuid_digits[dist(gen)];
    ret[10] = uuid_digits[dist(gen)];
    ret[11] = uuid_digits[dist(gen)];
    ret[12] = uuid_digits[dist(gen)];
    ret[13] = '-';
    ret[14] = '4';
    ret[15] = uuid_digits[dist(gen)];
    ret[16] = uuid_digits[dist(gen)];
    ret[17] = uuid_digits[dist(gen)];
    ret[18] = '-';
    ret[19] = uuid_digits[dist2(gen)];
    ret[20] = uuid_digits[dist(gen)];
    ret[21] = uuid_digits[dist(gen)];
    ret[22] = uuid_digits[dist(gen)];
    ret[23] = '-';
    ret[24] = uuid_digits[dist(gen)];
    ret[25] = uuid_digits[dist(gen)];
    ret[26] = uuid_digits[dist(gen)];
    ret[27] = uuid_digits[dist(gen)];
    ret[28] = uuid_digits[dist(gen)];
    ret[29] = uuid_digits[dist(gen)];
    ret[30] = uuid_digits[dist(gen)];
    ret[31] = uuid_digits[dist(gen)];
    ret[32] = uuid_digits[dist(gen)];
    ret[33] = uuid_digits[dist(gen)];
    ret[34] = uuid_digits[dist(gen)];
    ret[35] = uuid_digits[dist(gen)];

    return ret;
}
*/

template <typename T = std::mt19937>
std::string uuid_5(RandomGenerator<T> gen = RandomGenerator<std::mt19937>{})
{
    std::uniform_int_distribution<> dist(0, 15);
    std::uniform_int_distribution<> dist2(8, 11);

    static constexpr std::array uuid_digits =
    {
        '0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
    };

    std::string ret;
    /*ret.resize_and_overwrite(36, [&](char* buffer, std::size_t count)
    {
        // xxxxxxxx-xxxx-4xxx-[8-b]xxx-xxxxxxxxxxxx
        buffer[0] = uuid_digits[gen(dist)];
        buffer[1] = uuid_digits[gen(dist)];
        buffer[2] = uuid_digits[gen(dist)];
        buffer[3] = uuid_digits[gen(dist)];
        buffer[4] = uuid_digits[gen(dist)];
        buffer[5] = uuid_digits[gen(dist)];
        buffer[6] = uuid_digits[gen(dist)];
        buffer[7] = uuid_digits[gen(dist)];
        buffer[8] = '-';
        buffer[9] = uuid_digits[gen(dist)];
        buffer[10] = uuid_digits[gen(dist)];
        buffer[11] = uuid_digits[gen(dist)];
        buffer[12] = uuid_digits[gen(dist)];
        buffer[13] = '-';
        buffer[14] = '4';
        buffer[15] = uuid_digits[gen(dist)];
        buffer[16] = uuid_digits[gen(dist)];
        buffer[17] = uuid_digits[gen(dist)];
        buffer[18] = '-';
        buffer[19] = uuid_digits[gen(dist2)];
        buffer[20] = uuid_digits[gen(dist)];
        buffer[21] = uuid_digits[gen(dist)];
        buffer[22] = uuid_digits[gen(dist)];
        buffer[23] = '-';
        buffer[24] = uuid_digits[gen(dist)];
        buffer[25] = uuid_digits[gen(dist)];
        buffer[26] = uuid_digits[gen(dist)];
        buffer[27] = uuid_digits[gen(dist)];
        buffer[28] = uuid_digits[gen(dist)];
        buffer[29] = uuid_digits[gen(dist)];
        buffer[30] = uuid_digits[gen(dist)];
        buffer[31] = uuid_digits[gen(dist)];
        buffer[32] = uuid_digits[gen(dist)];
        buffer[33] = uuid_digits[gen(dist)];
        buffer[34] = uuid_digits[gen(dist)];
        buffer[35] = uuid_digits[gen(dist)];

        return 36;
    });*/

    
    return ret;
}

template <typename T = std::mt19937>
std::string uuid_6(RandomGenerator<T> gen = RandomGenerator<std::mt19937>{})
{
    static std::uniform_int_distribution<> dist(0, 15);
    static std::uniform_int_distribution<> dist2(8, 11);

    static constexpr std::array uuid_digits =
    {
        '0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
    };

    // xxxxxxxx-xxxx-4xxx-[8-b]xxx-xxxxxxxxxxxx

    std::string ret;
    ret.reserve(36);

    for (int i = 0; i < 8; i++)
    {
        ret += uuid_digits[gen(dist)];
    }

    ret += '-';

    for (int i = 9; i < 13; i++)
    {
        ret += uuid_digits[gen(dist)];
    }

    ret += '-';
    ret += '4';

    for (int i = 15; i < 18; i++)
    {
        ret += uuid_digits[gen(dist)];
    }

    ret += '-';
    ret += gen(dist2);

    for (int i = 20; i < 23; i++)
    {
        ret += uuid_digits[gen(dist)];
    }

    ret += '-';

    for (int i = 24; i < 36; i++)
    {
        ret += uuid_digits[gen(dist)];
    };

    return ret;
}

template <typename T = std::mt19937>
std::string uuid_7(RandomGenerator<T> gen = RandomGenerator<std::mt19937>{})
{
    static constexpr std::array digits =
    {
        '0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
    };

    // uuid v4 format
    // b = random bit (0 or 1)
    // x = random 4-bit value = bbbb (0-9, a-f)
    // xxxxxxxx-xxxx-0100xxx-10bbxxx-xxxxxxxxxxxx
    // xxxxxxxx-xxxx-4xxx-[8-b]xxx-xxxxxxxxxxxx
    //
    // Reference: https://datatracker.ietf.org/doc/html/rfc4122#page-14
    //
    // The version 4 UUID is meant for generating UUIDs from truly-random or
    // pseudo-random numbers.
    //
    // The algorithm is as follows:
    //
    // o Set the two most significant bits (bits 6 and 7) of the
    //   clock_seq_hi_and_reserved to zero and one, respectively.
    //
    // o Set the four most significant bits (bits 12 through 15) of the
    //   time_hi_and_version field to the 4-bit version number from
    //   Section 4.1.3.
    //
    // o Set all the other bits to randomly (or pseudo-randomly) chosen
    //   values.

    std::string ret;
    ret.resize(36);

    std::uniform_int_distribution<std::uint64_t> dist;

    const auto hi = gen(dist);
    const auto lo = gen(dist);

    ret[0] = digits[(0xf000'0000'0000'0000ull & hi) >> 60];
    ret[1] = digits[(0x0f00'0000'0000'0000ull & hi) >> 56];
    ret[2] = digits[(0x00f0'0000'0000'0000ull & hi) >> 52];
    ret[3] = digits[(0x000f'0000'0000'0000ull & hi) >> 48];
    ret[4] = digits[(0x0000'f000'0000'0000ull & hi) >> 44];
    ret[5] = digits[(0x0000'0f00'0000'0000ull & hi) >> 40];
    ret[6] = digits[(0x0000'00f0'0000'0000ull & hi) >> 36];
    ret[7] = digits[(0x0000'000f'0000'0000ull & hi) >> 32];
    ret[8] = '-';
    ret[9] = digits[(0x0000'0000'f000'0000ull & hi) >> 28];
    ret[10] = digits[(0x0000'0000'0f00'0000ull & hi) >> 24];
    ret[11] = digits[(0x0000'0000'00f0'0000ull & hi) >> 20];
    ret[12] = digits[(0x0000'0000'000f'0000ull & hi) >> 16];
    ret[13] = '-';
    ret[14] = '4';
    ret[15] = digits[(0x0000'0000'0000'0f00ull & hi) >> 8];
    ret[16] = digits[(0x0000'0000'0000'00f0ull & hi) >> 4];
    ret[17] = digits[(0x0000'0000'0000'000full & hi)];
    ret[18] = '-';
    ret[19] = digits[0b1000 | ((0x3000'0000'0000'0000ull & lo) >> 60)];
    ret[20] = digits[(0x0f00'0000'0000'0000ull & lo) >> 56];
    ret[21] = digits[(0x00f0'0000'0000'0000ull & lo) >> 52];
    ret[22] = digits[(0x000f'0000'0000'0000ull & lo) >> 48];
    ret[23] = '-';
    ret[24] = digits[(0x0000'f000'0000'0000ull & lo) >> 44];
    ret[25] = digits[(0x0000'0f00'0000'0000ull & lo) >> 40];
    ret[26] = digits[(0x0000'00f0'0000'0000ull & lo) >> 36];
    ret[27] = digits[(0x0000'000f'0000'0000ull & lo) >> 32];
    ret[28] = digits[(0x0000'0000'f000'0000ull & lo) >> 28];
    ret[29] = digits[(0x0000'0000'0f00'0000ull & lo) >> 24];
    ret[30] = digits[(0x0000'0000'00f0'0000ull & lo) >> 20];
    ret[31] = digits[(0x0000'0000'000f'0000ull & lo) >> 16];
    ret[32] = digits[(0x0000'0000'0000'f000ull & lo) >> 12];
    ret[33] = digits[(0x0000'0000'0000'0f00ull & lo) >> 8];
    ret[34] = digits[(0x0000'0000'0000'00f0ull & lo) >> 4];
    ret[35] = digits[(0x0000'0000'0000'000full & lo)];

    return ret;
}
#endif

template <typename T = std::mt19937>
std::string uuid_8(RandomGenerator<T> gen = RandomGenerator<std::mt19937>{})
{
    // uuid v4 format
    // b = random bit (0 or 1)
    // x = random 4-bit value = bbbb (0-9, a-f)
    // xxxxxxxx-xxxx-0100xxx-10bbxxx-xxxxxxxxxxxx
    // xxxxxxxx-xxxx-4xxx-[8-b]xxx-xxxxxxxxxxxx
    //
    // Reference: https://datatracker.ietf.org/doc/html/rfc4122#page-14
    //
    // The version 4 UUID is meant for generating UUIDs from truly-random or
    // pseudo-random numbers.
    //
    // The algorithm is as follows:
    //
    // o Set the two most significant bits (bits 6 and 7) of the
    //   clock_seq_hi_and_reserved to zero and one, respectively.
    //
    // o Set the four most significant bits (bits 12 through 15) of the
    //   time_hi_and_version field to the 4-bit version number from
    //   Section 4.1.3.
    //
    // o Set all the other bits to randomly (or pseudo-randomly) chosen
    //   values.

    static constexpr std::array digits =
    {
        '0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
    };

    std::uniform_int_distribution<std::uint64_t> dist;

    const auto hi = gen(dist);
    const auto lo = gen(dist);

    return
    {
        digits[(0xf000'0000'0000'0000ull & hi) >> 60],
        digits[(0x0f00'0000'0000'0000ull & hi) >> 56],
        digits[(0x00f0'0000'0000'0000ull & hi) >> 52],
        digits[(0x000f'0000'0000'0000ull & hi) >> 48],
        digits[(0x0000'f000'0000'0000ull & hi) >> 44],
        digits[(0x0000'0f00'0000'0000ull & hi) >> 40],
        digits[(0x0000'00f0'0000'0000ull & hi) >> 36],
        digits[(0x0000'000f'0000'0000ull & hi) >> 32],
        '-',
        digits[(0x0000'0000'f000'0000ull & hi) >> 28],
        digits[(0x0000'0000'0f00'0000ull & hi) >> 24],
        digits[(0x0000'0000'00f0'0000ull & hi) >> 20],
        digits[(0x0000'0000'000f'0000ull & hi) >> 16],
        '-',
        '4',
        digits[(0x0000'0000'0000'0f00ull & hi) >> 8],
        digits[(0x0000'0000'0000'00f0ull & hi) >> 4],
        digits[(0x0000'0000'0000'000full & hi)],
        '-',
        digits[0b1000 | ((0x3000'0000'0000'0000ull & lo) >> 60)],
        digits[(0x0f00'0000'0000'0000ull & lo) >> 56],
        digits[(0x00f0'0000'0000'0000ull & lo) >> 52],
        digits[(0x000f'0000'0000'0000ull & lo) >> 48],
        '-',
        digits[(0x0000'f000'0000'0000ull & lo) >> 44],
        digits[(0x0000'0f00'0000'0000ull & lo) >> 40],
        digits[(0x0000'00f0'0000'0000ull & lo) >> 36],
        digits[(0x0000'000f'0000'0000ull & lo) >> 32],
        digits[(0x0000'0000'f000'0000ull & lo) >> 28],
        digits[(0x0000'0000'0f00'0000ull & lo) >> 24],
        digits[(0x0000'0000'00f0'0000ull & lo) >> 20],
        digits[(0x0000'0000'000f'0000ull & lo) >> 16],
        digits[(0x0000'0000'0000'f000ull & lo) >> 12],
        digits[(0x0000'0000'0000'0f00ull & lo) >> 8],
        digits[(0x0000'0000'0000'00f0ull & lo) >> 4],
        digits[(0x0000'0000'0000'000full & lo)]
    };
}

template <typename Gen>
requires (std::uniform_random_bit_generator<std::remove_reference_t<Gen>>)
std::string uuid_8_like_std_sample(Gen&& gen)
{
    // uuid v4 format
    // b = random bit (0 or 1)
    // x = random 4-bit value = bbbb (0-9, a-f)
    // xxxxxxxx-xxxx-0100xxx-10bbxxx-xxxxxxxxxxxx
    // xxxxxxxx-xxxx-4xxx-[8-b]xxx-xxxxxxxxxxxx
    //
    // Reference: https://datatracker.ietf.org/doc/html/rfc4122#page-14
    //
    // The version 4 UUID is meant for generating UUIDs from truly-random or
    // pseudo-random numbers.
    //
    // The algorithm is as follows:
    //
    // o Set the two most significant bits (bits 6 and 7) of the
    //   clock_seq_hi_and_reserved to zero and one, respectively.
    //
    // o Set the four most significant bits (bits 12 through 15) of the
    //   time_hi_and_version field to the 4-bit version number from
    //   Section 4.1.3.
    //
    // o Set all the other bits to randomly (or pseudo-randomly) chosen
    //   values.

    static constexpr std::array digits =
    {
        '0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
    };

    std::uniform_int_distribution<std::uint64_t> dist;

    const auto hi = dist(std::forward<Gen>(gen));
    const auto lo = dist(std::forward<Gen>(gen));

    return
    {
        digits[(0xf000'0000'0000'0000ull & hi) >> 60],
        digits[(0x0f00'0000'0000'0000ull & hi) >> 56],
        digits[(0x00f0'0000'0000'0000ull & hi) >> 52],
        digits[(0x000f'0000'0000'0000ull & hi) >> 48],
        digits[(0x0000'f000'0000'0000ull & hi) >> 44],
        digits[(0x0000'0f00'0000'0000ull & hi) >> 40],
        digits[(0x0000'00f0'0000'0000ull & hi) >> 36],
        digits[(0x0000'000f'0000'0000ull & hi) >> 32],
        '-',
        digits[(0x0000'0000'f000'0000ull & hi) >> 28],
        digits[(0x0000'0000'0f00'0000ull & hi) >> 24],
        digits[(0x0000'0000'00f0'0000ull & hi) >> 20],
        digits[(0x0000'0000'000f'0000ull & hi) >> 16],
        '-',
        '4',
        digits[(0x0000'0000'0000'0f00ull & hi) >> 8],
        digits[(0x0000'0000'0000'00f0ull & hi) >> 4],
        digits[(0x0000'0000'0000'000full & hi)],
        '-',
        digits[0b1000 | ((0x3000'0000'0000'0000ull & lo) >> 60)],
        digits[(0x0f00'0000'0000'0000ull & lo) >> 56],
        digits[(0x00f0'0000'0000'0000ull & lo) >> 52],
        digits[(0x000f'0000'0000'0000ull & lo) >> 48],
        '-',
        digits[(0x0000'f000'0000'0000ull & lo) >> 44],
        digits[(0x0000'0f00'0000'0000ull & lo) >> 40],
        digits[(0x0000'00f0'0000'0000ull & lo) >> 36],
        digits[(0x0000'000f'0000'0000ull & lo) >> 32],
        digits[(0x0000'0000'f000'0000ull & lo) >> 28],
        digits[(0x0000'0000'0f00'0000ull & lo) >> 24],
        digits[(0x0000'0000'00f0'0000ull & lo) >> 20],
        digits[(0x0000'0000'000f'0000ull & lo) >> 16],
        digits[(0x0000'0000'0000'f000ull & lo) >> 12],
        digits[(0x0000'0000'0000'0f00ull & lo) >> 8],
        digits[(0x0000'0000'0000'00f0ull & lo) >> 4],
        digits[(0x0000'0000'0000'000full & lo)]
    };
}

#if 0
template <typename T = std::mt19937>
std::string uuid_9(RandomGenerator<T>& gen = RandomGenerator<std::mt19937>{})
{
    // uuid v4 format
    // b = random bit (0 or 1)
    // x = random 4-bit value = bbbb (0-9, a-f)
    // xxxxxxxx-xxxx-0100xxx-10bbxxx-xxxxxxxxxxxx
    // xxxxxxxx-xxxx-4xxx-[8-b]xxx-xxxxxxxxxxxx
    //
    // Reference: https://datatracker.ietf.org/doc/html/rfc4122#page-14
    //
    // The version 4 UUID is meant for generating UUIDs from truly-random or
    // pseudo-random numbers.
    //
    // The algorithm is as follows:
    //
    // o Set the two most significant bits (bits 6 and 7) of the
    //   clock_seq_hi_and_reserved to zero and one, respectively.
    //
    // o Set the four most significant bits (bits 12 through 15) of the
    //   time_hi_and_version field to the 4-bit version number from
    //   Section 4.1.3.
    //
    // o Set all the other bits to randomly (or pseudo-randomly) chosen
    //   values.

    std::uniform_int_distribution<std::uint64_t> dist;

    const auto hi = gen(dist);
    const auto lo = gen(dist);

    std::string ret;

#if 0
    ret.resize_and_overwrite(36, [hi, lo](char* buffer, size_t size)
    {
        static constexpr std::array digits =
        {
            '0', '1', '2', '3', '4', '5', '6', '7',
            '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
        };

        buffer[0] = digits[(0xf000'0000'0000'0000ull & hi) >> 60];
        buffer[1] = digits[(0x0f00'0000'0000'0000ull & hi) >> 56];
        buffer[2] = digits[(0x00f0'0000'0000'0000ull & hi) >> 52];
        buffer[3] = digits[(0x000f'0000'0000'0000ull & hi) >> 48];
        buffer[4] = digits[(0x0000'f000'0000'0000ull & hi) >> 44];
        buffer[5] = digits[(0x0000'0f00'0000'0000ull & hi) >> 40];
        buffer[6] = digits[(0x0000'00f0'0000'0000ull & hi) >> 36];
        buffer[7] = digits[(0x0000'000f'0000'0000ull & hi) >> 32];
        buffer[8] = '-';
        buffer[9] = digits[(0x0000'0000'f000'0000ull & hi) >> 28];
        buffer[10] = digits[(0x0000'0000'0f00'0000ull & hi) >> 24];
        buffer[11] = digits[(0x0000'0000'00f0'0000ull & hi) >> 20];
        buffer[12] = digits[(0x0000'0000'000f'0000ull & hi) >> 16];
        buffer[13] = '-';
        buffer[14] = '4';
        buffer[15] = digits[(0x0000'0000'0000'0f00ull & hi) >> 8];
        buffer[16] = digits[(0x0000'0000'0000'00f0ull & hi) >> 4];
        buffer[17] = digits[(0x0000'0000'0000'000full & hi)];
        buffer[18] = '-';
        buffer[19] = digits[0b1000 | ((0x3000'0000'0000'0000ull & lo) >> 60)];
        buffer[20] = digits[(0x0f00'0000'0000'0000ull & lo) >> 56];
        buffer[21] = digits[(0x00f0'0000'0000'0000ull & lo) >> 52];
        buffer[22] = digits[(0x000f'0000'0000'0000ull & lo) >> 48];
        buffer[23] = '-';
        buffer[24] = digits[(0x0000'f000'0000'0000ull & lo) >> 44];
        buffer[25] = digits[(0x0000'0f00'0000'0000ull & lo) >> 40];
        buffer[26] = digits[(0x0000'00f0'0000'0000ull & lo) >> 36];
        buffer[27] = digits[(0x0000'000f'0000'0000ull & lo) >> 32];
        buffer[28] = digits[(0x0000'0000'f000'0000ull & lo) >> 28];
        buffer[29] = digits[(0x0000'0000'0f00'0000ull & lo) >> 24];
        buffer[30] = digits[(0x0000'0000'00f0'0000ull & lo) >> 20];
        buffer[31] = digits[(0x0000'0000'000f'0000ull & lo) >> 16];
        buffer[32] = digits[(0x0000'0000'0000'f000ull & lo) >> 12];
        buffer[33] = digits[(0x0000'0000'0000'0f00ull & lo) >> 8];
        buffer[34] = digits[(0x0000'0000'0000'00f0ull & lo) >> 4];
        buffer[35] = digits[(0x0000'0000'0000'000full & lo)];
        return 36;
    });
#endif

    return ret;
}
#endif
}
