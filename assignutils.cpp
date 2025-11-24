#include "assignutils.h"
#include <cstring>
#include <vector>
#include <typeinfo>
using namespace std;

////////////////////////// FUNCTION FOR QUESTION 1 //////////////////////////

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

////////////////////////// FUNCTIONS FOR QUESTION 2 //////////////////////////

int* filterAboveThreshold(const int* arr, int size, int threshold, int& newSize){
    newSize = size;
    //vector<int> int_vec(begin(arr), end(arr)); //".begin()" and ".end()" use array overloads,      (X)
    //which require actual arrays and not a pointer.
    vector<int> int_vec(arr, arr + size); //so this works..for some reason.     (V)
    //GPT: "This works because pointer arithmetic is well-defined: arr + n means “pointer to element n slots ahead.”"
    int erased_counter = 0;
    for (size_t i = 0; i < newSize; i++){
        if (int_vec[i] <= threshold)
        {
            int_vec.erase(int_vec.begin() + i); //now ".begin()" works well because we're 
            //dealing with the actual container type(in this instance a vector).
            --newSize;
            --i;
        }
    }
    //changing back from a vector(dynamic container) to an int* array:
        //
        int* rtn_arr = new int[newSize]; 
        copy(begin(int_vec), end(int_vec), rtn_arr);
        //
     return rtn_arr;
}

void printArray(const int* arr, int size){
    if (size > 0){
        for (size_t i = 0; i < size - 1; i++){
            cout << arr[i] << ", "; //unlike - "endl", '\n' does't flush. (ended up not using \n though).       (V)
            //each flush triggers a system call - slowing the system down, which is why it is much
            //faster to just stream the entire byte code data as a batch before flushing once,
            //which btw happens automatically in cpp - there is no requirement to manually flush.
            //(at least in our case - the program flushes automatically when the scope of a local 
            //std::ostream variable is closed[whatever the F that means..]).
            
            //std::cout << std::flush; no need to flush manually.       (X)
        }
        cout << arr[size - 1] << ". " << endl;
        return;
    }
    cout << "tried to print an empty array" << endl; //an else statement redundant because I used "return in the if statement".
}

////////////////////////// FUNCTIONS FOR QUESTION 3 //////////////////////////

void readVector(vector<int>& vec){
    size_t len = vec.size();
    for (size_t i = 0; i < len; i++){
        cin >> vec[i];
    }
}

void modifyVector(vector<int>& vec){
    size_t len = vec.size();
    int temp = vec[0]; //assigning the first index.
    for(size_t i = 1; i < len; i++){ //iteration should start from the second index.
        vec[i] = vec[i] + temp;
        temp = vec[i];
    }
}

void printVector(const vector<int>& vec){
    for(int x : vec){
        cout << x << " ";
    }
    cout << endl;
}

void reverseAndCapitalize(char* str){ //fix: skipping the first element.
    int size = strlen(str);
    cout << "Array: " << str << ", size: " << size << "\n";
    size_t iter = size / 2;
    char start;
    char end;
    for(size_t i = 0; i < iter; i++){
        start = str[i];
        end = str[size - i - 1];
        if(64 < start && start < 91){ //turning uppercase into lowercase.
        start += 32;
        }
        else if(96 < start && start < 123){ //turning lowercase into uppercase.
            start -= 32;
        }
        if(64 < end && end < 91){ //turning uppercase into lowercase.
        end += 32;
        }
        else if(96 < end && end < 123){ //turning lowercase into uppercase.
            end -= 32;
        }

        //debugging:
        /*
        cout << "start: " << start << "\n";
        cout << "end: " << end << "\n";
        */

        str[i] = end;
        str[size - i - 1] = start;
    }
    if(size % 2 != 0){
        char mid_elem = str[size / 2];
        if(64 < mid_elem && mid_elem < 91){ //turning uppercase into lowercase.
        mid_elem += 32;
        }
        else if(96 < mid_elem && mid_elem < 123){ //turning lowercase into uppercase.
            mid_elem -= 32;
        }

        //debugging:
        /*
        cout << "mid_elem: " << mid_elem << "\n";
        */

        str[size / 2] = mid_elem;
    }
    
}