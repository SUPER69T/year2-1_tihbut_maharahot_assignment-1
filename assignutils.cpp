#include "assignutils.h"
#include <cstring>
#include <vector>
#include <typeinfo>
using namespace std;

char* duplicateVowels(const char* str){
    
    string output_str; //creating a local string for easy appending.
    size_t len = strlen(str); //length of str.

    if (len == 0) //checking whether str is empty.
    {
        return nullptr;
    }

    for (size_t i = 0 ; i < len ; ++i){
        char c = str[i];
        output_str.push_back(c);
        switch (c){ //checking whether c is a vowel and pushing that into the string.
            case 'a': case 'e': case 'i': case 'o': case 'u':
            case 'A': case 'E': case 'I': case 'O': case 'U':
                output_str.push_back(c);
                break;
        }
    }
    char* output_char_ptr = new char[output_str.size() + 1];
    strcpy(output_char_ptr, output_str.c_str()); //GPT recommends using memcpy here for safety and performance reasons. 
    return output_char_ptr;
}