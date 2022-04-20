#include "MockFooImpl.h"

MockFooImpl::MockFooImpl(Foo* f) : foo(f)
{

}

int MockFooImpl::count(){
    return foo->count();
}
