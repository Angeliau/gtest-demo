#include "MyClass.h"

MyClass::MyClass():pimp(new MyPimplClass())
{

}

MyClass::~MyClass(){
    if (pimp != nullptr){
        delete pimp;
        pimp = nullptr;
    }
}

int MyClass::square(int n){
    return n * n;
}
