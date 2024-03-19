#ifndef GENERATOR_H
#define GENERATOR_H

#include <string>
#include <vector>
#include <random>
#include <chrono>

// alphabet for ASCII
#define RAND_GEN_MAX 99999
#define ALPHABET_MIN -25
#define ALPHABET_MAX 90
#define CAPITAL_ADD 32

class Generator{
    private:
        std::chrono::high_resolution_clock::time_point program_seed;

        int random(size_t low, size_t high);

    public:
        std::vector<int> generate_int(size_t size);
        std::vector<std::string> generate_string(size_t size);
        std::vector<char> generate_char(size_t size);

        Generator(std::chrono::high_resolution_clock::time_point program_seed);
};


#endif