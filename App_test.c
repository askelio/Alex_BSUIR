#include "App.h"
#include <assert.h>


int test_sum(){
    assert(Get_Sum(1.234)==9);
    assert(Get_Sum(0.111)==3);
    assert(Get_Sum(3.824)==14);
}

#undef main 
int main(){
    test_sum();    

}