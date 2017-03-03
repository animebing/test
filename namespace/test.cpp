#include <iostream>

namespace a {
    namespace b {
        void f() {
            std::cout<<"bingbing"<<std::endl;
        }
    }
}

namespace b {
    void f() {
        std::cout << "haha" << std::endl;
    }
}
int main(){
    
    a::b::f();
    ::b::f();
    return 0;
}
