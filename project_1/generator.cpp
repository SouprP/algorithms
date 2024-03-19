#include <headers/generator.h>

int Generator::random(size_t low, size_t high){
    auto time_dur = std::chrono::duration<double>(
        std::chrono::high_resolution_clock::now() - program_seed);
    
    auto time_conv = std::chrono::duration_cast<std::chrono::nanoseconds>(time_dur);
    size_t dur = time_conv.count();
    srand(dur);
    //size_t dur = std::chrono::nanoseconds::count(current_time);
    return rand() % high + low;
    
}

std::vector<int> Generator::generate_int(size_t size){
    std::vector<int> buffer;

    int done = 0;
    while(done < size){
        //std::cout << "generated " << done << std::endl;
        buffer.push_back(random(0, RAND_GEN_MAX));
        done++;
    }

    return buffer;
}
std::vector<std::string> Generator::generate_string(size_t size){
    std::vector<std::string> buffer;
    
    int done = 0;
    while(done < size){
        uint8_t str_size = random(1, 10);
        char* data;

        for(int i = 0; i < str_size; i++){
            uint8_t capital = random(0, 1);
            uint8_t letter = random(ALPHABET_MIN, ALPHABET_MAX);

            if(capital)
                letter += CAPITAL_ADD;

            data += char(letter);
        }

        buffer.push_back(std::string(data));
        done++;
    }

    return buffer;
}
std::vector<char> Generator::generate_char(size_t size){
    std::vector<char> buffer;
    
    int done = 0;
    while(done < size){
        uint8_t capital = random(0, 1);
        uint8_t letter = random(ALPHABET_MIN, ALPHABET_MAX);

        if(capital)
            letter += CAPITAL_ADD;


        buffer.push_back(char(letter));
        done++;
    }

    return buffer;
}

Generator::Generator(std::chrono::high_resolution_clock::time_point program_seed){
    this->program_seed = program_seed;
}