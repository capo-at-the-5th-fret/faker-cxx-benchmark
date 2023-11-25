#include <benchmark/benchmark.h>
//#include <random>
//#include <xoshiro.h>
//#include "string.h"

const int n = 1000;

#if 0
static void BM_uuid(benchmark::State& state)
{
    std::mt19937 gen{ 12345 };

    for (auto _ : state)
    {
        for (int i = 0; i < n; ++i)
        {
            auto s = uuid(gen);
            benchmark::DoNotOptimize(s);
        }
    }
}
BENCHMARK(BM_uuid);
#endif

#if 0
static void BM_uuid_2(benchmark::State& state)
{
    //std::mt19937 gen{ 12345 };
    RandomGenerator<std::mt19937> gen{ 12345u };

    for (auto _ : state)
    {
        for (int i = 0; i < n; ++i)
        {
            auto s = uuid_2(gen);
            benchmark::DoNotOptimize(s);
        }
    }
}
BENCHMARK(BM_uuid_2);

static void BM_uuid_3(benchmark::State& state)
{
    //std::mt19937 gen{ 12345 };
    RandomGenerator<std::mt19937> gen{ 12345u };

    for (auto _ : state)
    {
        for (int i = 0; i < n; ++i)
        {
            auto s = uuid_3(gen);
            benchmark::DoNotOptimize(s);
        }
    }
}
BENCHMARK(BM_uuid_3);

static void BM_uuid_4(benchmark::State& state)
{
    //std::mt19937 gen{ 12345 };
    RandomGenerator<std::mt19937> gen{ 12345u };

    for (auto _ : state)
    {
        for (int i = 0; i < n; ++i)
        {
            auto s = uuid_4(gen);
            benchmark::DoNotOptimize(s);
        }
    }
}
BENCHMARK(BM_uuid_4);

static void BM_uuid_5(benchmark::State& state)
{
    //std::mt19937 gen{ 12345 };
    RandomGenerator<std::mt19937> gen{ 12345u };

    for (auto _ : state)
    {
        for (int i = 0; i < n; ++i)
        {
            auto s = uuid_5(gen);
            benchmark::DoNotOptimize(s);
        }
    }
}
BENCHMARK(BM_uuid_5);

static void BM_uuid_6(benchmark::State& state)
{
    //std::mt19937 gen{ 12345 };
    RandomGenerator<std::mt19937> gen{ 12345u };

    for (auto _ : state)
    {
        for (int i = 0; i < n; ++i)
        {
            auto s = uuid_6(gen);
            benchmark::DoNotOptimize(s);
        }
    }
}
BENCHMARK(BM_uuid_6);

static void BM_uuid_7(benchmark::State& state)
{
    //std::mt19937 gen{ 12345 };
    RandomGenerator<std::mt19937> gen{ 12345u };

    for (auto _ : state)
    {
        for (int i = 0; i < n; ++i)
        {
            auto s = uuid_7(gen);
            benchmark::DoNotOptimize(s);
        }
    }
}
BENCHMARK(BM_uuid_7);

static void BM_uuid_8(benchmark::State& state)
{
    //std::mt19937 gen{ 12345 };
    RandomGenerator<std::mt19937> gen{ 12345u };

    for (auto _ : state)
    {
        for (int i = 0; i < n; ++i)
        {
            auto s = uuid_8(gen);
            benchmark::DoNotOptimize(s);
        }
    }
}
BENCHMARK(BM_uuid_8);

static void BM_uuid_9(benchmark::State& state)
{
    //std::mt19937 gen{ 12345 };
    RandomGenerator<std::mt19937> gen{ 12345u };

    for (auto _ : state)
    {
        for (int i = 0; i < n; ++i)
        {
            auto s = uuid_9(gen);
            benchmark::DoNotOptimize(s);
        }
    }
}
BENCHMARK(BM_uuid_9);

static void BM_uuid_10(benchmark::State& state)
{
    //std::mt19937 gen{ 12345 };
    RandomGenerator<xso::rng64> gen{ 12345u };

    for (auto _ : state)
    {
        for (int i = 0; i < n; ++i)
        {
            auto s = uuid_9(gen);
            benchmark::DoNotOptimize(s);
        }
    }
}
BENCHMARK(BM_uuid_10);
#endif
