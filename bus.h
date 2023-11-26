#ifndef BUS_H
#define BUS_H
#include <string>
#include <iostream>

class Bus {
  private:
	std::string
		_driverInfo{},
		_busNumber{}, // example: A056EB
		_routeNumber{}, // example: 68A
		_brand{};
	int
		_startYear{},
		_mileage{};

  public:
	void setDriverInfo();
	void setDriverInfo(std::istream& input);

	void setBusNumber();
	void setBusNumber(std::istream& input);

	void setRouteNumber();
	void setRouteNumber(std::istream& input);

	void setBrand();
	void setBrand(std::istream& input);

	void setStartYear();
	void setStartYear(std::istream& input);

	void setMileage();
	void setMileage(std::istream& input);

	std::string getDriverInfo() { return _driverInfo; };
	std::string getBusNumber() { return _busNumber; };
	std::string getRouteNumber() { return _routeNumber; };
	std::string getBrand() { return _brand; };
	int getStartYear() { return _startYear; };
	int getMileage() { return _mileage; };

	void showBus();
	bool isEmpty();
};

#endif