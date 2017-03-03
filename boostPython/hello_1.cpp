#include <boost/python.hpp>
using namespace boost::python;
struct Var{
    Var(std::string name): name(name), value(){}
    std::string const name;
    float value;
};

BOOST_PYTHON_MODULE(hello_1){
    class_<Var>("Var", init<std::string>())
        .def_readonly("name", &Var::name)
        .def_readwrite("value", &Var::value);
}

