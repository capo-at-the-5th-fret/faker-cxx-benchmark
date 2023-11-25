#include <benchmark/benchmark.h>

#include <random>
#include "string.h"

namespace area51
{
static void BM_uuid_from_faker(benchmark::State& state)
{
    // TODO: Need seed
    RandomGenerator<std::mt19937> gen;

    for (auto _ : state)
    {
        auto s = String::uuid(gen);
        benchmark::DoNotOptimize(s);
    }
}
BENCHMARK(BM_uuid_from_faker);

static void BM_uuid_8(benchmark::State& state)
{
    // TODO: Need seed
    RandomGenerator<std::mt19937> gen;

    for (auto _ : state)
    {
        auto s = uuid_8(gen);
        benchmark::DoNotOptimize(s);
    }
}
BENCHMARK(BM_uuid_8);

static void BM_uuid_8_like_std_sample(benchmark::State& state)
{
    // TODO: Need seed
    std::mt19937 gen{std::random_device{}()};

    for (auto _ : state)
    {
        auto s = uuid_8_like_std_sample(gen);
        benchmark::DoNotOptimize(s);
    }
}
BENCHMARK(BM_uuid_8_like_std_sample);

}
