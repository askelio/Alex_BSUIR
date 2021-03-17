#include "App.h"
#include <assert.h>


int test_sum(){
    assert(get_num(0.5,0.0001)==3);
    
}

#undef main 
int main(){
    test_sum();    

}