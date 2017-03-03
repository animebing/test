#include <map>
#include <string>
std::map<std::string, int> reg;

void regist(std::string name, int val){
    reg[name] = val;
}

