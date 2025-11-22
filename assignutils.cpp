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

int* filterAboveThreshold(const int* arr, int size, int threshold, int& newSize){
    //vector<int> int_vec(begin(arr), end(arr)); //".begin()" and ".end()" use array overloads,      (X)
    //which require actual arrays and not a pointer.
    vector<int> int_vec(arr, arr + size); //so this works..for some reason.     (V)
    //GPT: "This works because pointer arithmetic is well-defined: arr + n means “pointer to element n slots ahead.”"

    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] <= threshold)
        {
            --newSize;
            int_vec.erase(int_vec.begin() + i); //now ".begin()" works well because we're 
            //dealing with the actual container type(in this instance a vector).
        }
    }
    //changing back from a vector(dynamic container) to an int* array:
        //
        int* rtn_arr = new int[size]; 
        copy(begin(int_vec), end(int_vec), rtn_arr);
        //
     return rtn_arr;
}

void printArray(const int* arr, int size){
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << '\n'; //unlike - "endl", '\n' does't flush.       (V)
        //each flush triggers a system call - slowing the system down, which is why it is much
        //faster to just stream the entire byte code data as a batch before flushing once,
        //which btw happens automatically in cpp - there is no requirement to manually flush.
        //(at least in our case - the program flushes automatically when the scope of a local 
        //std::ostream variable is closed[whatever the F that means..]).
        
        //std::cout << std::flush; no need to flush manually.       (X)
    }
}