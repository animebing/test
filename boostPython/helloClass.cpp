#include <boost/python.hpp>
using namespace boost::python;

struct World{
    World(std::string msg):msg(msg) {} // added constructor
    void set(std::string msg) {this->msg = msg;}
    std::string greet() {return msg;}
    std::string msg;
};

BOOST_PYTHON_MODULE(helloClass){
    class_<World>("World", init<std::string>())
        .def("greet", &World::greet)
        .def("set", &World::set)
    ;
}
