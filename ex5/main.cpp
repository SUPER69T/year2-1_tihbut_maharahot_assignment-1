#include "mathutils.h"
#include <iostream>
#include <vector>

using namespace MathUtils;

int main(int argc, char* argv[]){

    ////////////////////////// MAIN FOR QUESTION 2 //////////////////////////
    ///*
    std::cout << "================== Question 2 ==================\n" << std::endl;
    //*/
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
    std::cout << vector_average(vec) << std::endl;
}