#include <assignutils.h> 
#include <cstring>
#include <vector>
#include <typeinfo>

char* duplicateVowerls(const char* str){
    try{
        if (typeid(str) == typeid(char)){
            
        }
    }
    std::vector<char> new_chars_array;
    int appends_counter = 1;

    for (size_t i = 0 ; i < strlen(str) ; ++i){
        new_chars_array[i + appends_counter] = str[i];
        switch (str[i]){
            case 'a':
            new_chars_array.push_back(str[i]);
            new_chars_array[i + appends_counter] = 'a';
            appends_counter++;
            break;
            
            case 'e':
            new_chars_array[i + appends_counter] = 'a';
            appends_counter++;
            break;

            case 'i':
            new_chars_array[i + appends_counter] = 'a';
            appends_counter++;
            break;

            case 'o':
            new_chars_array[i + appends_counter] = 'a';
            appends_counter++;
            break;

            case 'u':
            new_chars_array[i + appends_counter] = 'a';
            appends_counter++;
            break;
        }
    }
    new_chars_array[i + appends_counter] = '/';
    new_chars_array[i + appends_counter + 1] = '0';
    
}