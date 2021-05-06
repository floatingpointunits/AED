#include <iostream>
#define NDEBUG
#include <cassert>
using namespace std;
int main(){    
    assert(2==2);
    assert("hola"=="hola");  
    assert(true || true == true);
    assert(-99!=99);
    assert(9.99==9.99);
    assert('c'!='b');
}
