#include "ex5_mathutils.h"
#include <iostream>
#include <vector>

using namespace MathUtils;

int main(int argc, char* argv[]){

    ////////////////////////// MAIN FOR QUESTION 5 //////////////////////////
    ///*
    std::cout << "================== Question 5 ==================\n" << std::endl;
    
    std::cout << "Enter the number of elements: " << std::endl;
    int count = 0;
    std::cin >> count;
    std::vector<int> vec;
    vec.resize(static_cast<size_t>(count));

    std::cout << "Enter " << count << " integers: " << std::endl;
    try{ //GPT helped us really polish this try - exception statement.
        for(size_t i = 0; i < count; i++){
            std::cin >> vec[i];
            if(!std::cin){ //if a non - matching value enters with cin it enters a failed-state, and no value gets modified.
                throw std::runtime_error("Invalid input while reading vec[i]"); //manual exception throwing.
                return 1; //exiting with error code 1.
            }
        }
    }
    catch(const std::exception& e){
        std::cerr << "Error: " << e.what() << '\n';
    }
    std::cout << "average: " << vector_average(vec) << std::endl;
    //*/
    std::vector<int> vec1 = {1, 10, 2, 9, 3, 8, 4, 7, 5, 6};
    std::vector<int> vec2 = {5, 12, 3, 6, 20, 7, 1};
    std::cout << "primes in vec1: ";
    print_primes(vec1);
    std::cout << '\n';
    std::cout << "primes in vec2: ";
    print_primes(vec2);
    std::cout << '\n';
    std::cout << "perfect numbers in vec1: ";
    print_perfect_numbers(vec1);
    std::cout << '\n';
    std::cout << "perfect numbers in vec2: ";
    print_perfect_numbers(vec2);
    std::cout << '\n';
    return 0;
}