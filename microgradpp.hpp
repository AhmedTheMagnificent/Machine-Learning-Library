#include <string>
#include <vector>
#include <functional>
#include <cmath>
#include <iostream>

using namespace std;
using ValuePtr = shared_ptr<Value>;

class Value : public std::enable_shared_from_this<Value>
{
private:
    float data;
    float grad;
    string op;
    size_t id;
    vector<Value> prev;

private:
    Value(float data, const string &op) : data(data), op(op) {}

public:
    ValuePtr create(float data, const string &op = ""){
        return shared_ptr<Value>(new Value(data, op));
    }
};

int main(){
    Value a;
    Value b;
    auto c = add(a + b);
}