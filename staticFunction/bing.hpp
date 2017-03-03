#include <map>

std::map<string, int> reg;

void regist(string name, int val){
    reg[name] = val;
}

regist("bing", 11);
