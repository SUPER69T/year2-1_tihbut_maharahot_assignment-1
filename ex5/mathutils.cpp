#include "mathutils.h"
#include <iostream>
#include <vector>
#include <cmath>

namespace MathUtils {

////////////////////////// FUNCTIONS FOR QUESTION 1 //////////////////////////

    long vector_average(const std::vector<int>& vec){
        int sum = 0;
        long average;
        for(size_t i = 0; i < vec.size(); i++){
            sum += vec[i];
        }
        average = sum / vec.size();
        return average;
    }

    void print_primes(const std::vector<int>& vec){
        std::vector<int> primes_vec;
        bool is_prime;
        for(size_t i = 0; i < vec.size(); i++){ //iterating through the input vector.
            is_prime = true; //assuming the number is prime.
            for(size_t j = 2; j <= sqrt(vec[i]); j++){ //checking for factors up to the square root of vec[i].
                if(vec[i] % j == 0){
                    is_prime = false;
                    break;
                }
            }
            if(is_prime && vec[i] > 1){
                primes_vec.push_back(vec[i]);
            }
        }
        for(size_t i = 0; i < primes_vec.size(); i++){ //printing primes.
            std::cout << primes_vec[i] << " ";
        }
        std::cout << std::endl; //flushing after printing all primes.
    }

    void print_perfect_numbers(const std::vector<int>& vec){
        std::vector<int> perfects_vec;
        int sum_of_divisors;
        for(size_t i = 0; i < vec.size(); i++){ //iterating through the input vector.
            sum_of_divisors = 0;
            for(size_t j = 1; j <= vec[i] / 2; j++){ //checking for divisors up to half of vec[i].
                if(vec[i] % j == 0){
                    sum_of_divisors += j;
                }
            }
            if(sum_of_divisors == vec[i] && vec[i] != 0){
                perfects_vec.push_back(vec[i]);
            }
        }
        
    for(size_t i = 0; i < perfects_vec.size(); i++){ //printing perfect numbers.
            std::cout << perfects_vec[i] << " ";
        }
        std::cout << std::endl; //flushing.
    }
} // namespace MathUtils