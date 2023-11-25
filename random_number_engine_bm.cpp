#include <benchmark/benchmark.h>
#include <random>
#include <faker-cxx/types/RandomGenerator.h>
#include <faker-cxx/String.h>
#include <xoshiro.h>
#include <pcg_random.hpp>

using namespace faker;

static void BM_rng_mt19937(benchmark::State& state)
{
    RandomGenerator<std::mt19937> gen;

    for (auto _ : state)
    {
        auto uuid = faker::String::uuid(gen);
        benchmark::DoNotOptimize(uuid);
    }
}
BENCHMARK(BM_rng_mt19937);

static void BM_rng_mt19937_64(benchmark::State& state)
{
    RandomGenerator<std::mt19937_64> gen;

    for (auto _ : state)
    {
        auto uuid = faker::String::uuid(gen);
        benchmark::DoNotOptimize(uuid);
    }
}
BENCHMARK(BM_rng_mt19937_64);

static void BM_rng_xoshiro_star_star_64(benchmark::State& state)
{
    RandomGenerator<xso::xoshiro_4x64_star_star> gen;

    for (auto _ : state)
    {
        auto uuid = faker::String::uuid(gen);
        benchmark::DoNotOptimize(uuid);
    }
}
BENCHMARK(BM_rng_xoshiro_star_star_64);

static void BM_rng_pcg_64(benchmark::State& state)
{
    RandomGenerator<pcg64> gen;

    for (auto _ : state)
    {
        auto uuid = faker::String::uuid(gen);
        benchmark::DoNotOptimize(uuid);
    }
}
BENCHMARK(BM_rng_pcg_64);

#if 0
static void BM_mt19937_sv(benchmark::State& state)
{
    std::mt19937 gen{ 12345 };

    for (auto _ : state)
    {
        for (int i = 0; i < n; ++i)
        {
            auto s = name_sv(gen);
            benchmark::DoNotOptimize(s);
        }
    }
}
BENCHMARK(BM_mt19937_sv);

static void BM_xoshiross64(benchmark::State& state)
{
    xso::rng64 gen{ 12345 };

    for (auto _ : state)
    {
        for (int i = 0; i < n; ++i)
        {
            auto s = name(gen);
            benchmark::DoNotOptimize(s);
        }
    }
}
BENCHMARK(BM_xoshiross64);

static void BM_xoshiross64_sv(benchmark::State& state)
{
    xso::rng64 gen{ 12345 };

    for (auto _ : state)
    {
        for (int i = 0; i < n; ++i)
        {
            auto s = name_sv(gen);
            benchmark::DoNotOptimize(s);
        }
    }
}
BENCHMARK(BM_xoshiross64_sv);

static void BM_pcg64(benchmark::State& state)
{
    pcg64 gen{ 12345 };

    for (auto _ : state)
    {
        for (int i = 0; i < n; ++i)
        {
            auto s = name(gen);
            benchmark::DoNotOptimize(s);
        }
    }
}
BENCHMARK(BM_pcg64);

static void BM_pcg64_sv(benchmark::State& state)
{
    pcg64 gen{ 12345 };

    for (auto _ : state)
    {
        for (int i = 0; i < n; ++i)
        {
            auto s = name_sv(gen);
            benchmark::DoNotOptimize(s);
        }
    }
}
BENCHMARK(BM_pcg64_sv);
#endif
