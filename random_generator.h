#pragma once

#include <random>

// NOTE: faker lib has a warning in RandomGenerator that is treated as an error.
// A custom RandomGenerator that fixes this warning is used instead.

namespace area51
{
template <typename T>
requires std::uniform_random_bit_generator<T>
class RandomGenerator
{
public:
    RandomGenerator() : generator_{T(std::random_device{}())} {}
    ~RandomGenerator() = default;

    RandomGenerator(const RandomGenerator&) = default;
    RandomGenerator(RandomGenerator&&) = default;
    RandomGenerator& operator=(const RandomGenerator&) = default;
    RandomGenerator& operator=(RandomGenerator&&) = default;

    // NOTE: This function was hard coded to use int; it's now templated to work
    // with other integral types
    template <typename U>
    U operator()(std::uniform_int_distribution<U>& dist)
    {
        return dist(generator_);
    }

private:
    T generator_;
};

}
