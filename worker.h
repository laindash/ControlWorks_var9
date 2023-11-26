#ifndef WORKER_H
#define WORKER_H

#include <iostream>
#include <string>
#include <vector>

class Worker {
protected:
    std::string _name{}, _position{};
    int _age{};
    double _salary{};

public:
    virtual void show() const = 0; 
    virtual void setSalary() = 0;
    void setName();
    void setName(std::istream& input);
    void setPosition();
    void setPosition(std::istream& input);
    void setAge();
    void setAge(std::istream& input);


    std::string getName() const { return _name; };
    std::string getPosition() const { return _position; };
    int getAge() const { return _age; };
    double getSalary() const { return _salary; };

    virtual ~Worker() = default;
};

#endif 
