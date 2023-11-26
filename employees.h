#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include "worker.h"

class HourlyEmployee : public Worker {
private:
    int _workTime{};

public:
    void show() const override;
    void setSalary() override;
    void setWorkTime();
    void setWorkTime(std::istream& input);
    void setSalary(std::istream& input);

    int getWorkTime() const { return _workTime; };

    ~HourlyEmployee() = default;
};

class StateEmployee : public Worker {
private:
    int _workExperience{};

public:
    void show() const override;
    void setSalary() override;
    void setWorkExperience();
    void setWorkExperience(std::istream& input);
    void setSalary(std::istream& input);

    int getWorkExperience() const { return _workExperience; };

    ~StateEmployee() = default;
};

#endif