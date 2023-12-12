#ifndef ISORT_H
#define ISORT_H

#include <iostream>
#include <vector>


class ISort {
protected:
	int _comparisonCount{}, _swapCount{};

public:
	virtual void sort(std::vector<int>& nums) = 0;
	virtual std::string getSortName() = 0;
	int getComparisons() const { return _comparisonCount; };
	int getSwaps() const { return _swapCount; };
	virtual ~ISort() = default;
};


class BubbleSort : public ISort {
public:
	std::string getSortName() { return "����������� ����������: "; }
	void sort(std::vector<int>& nums) override;
};


class SelectionSort : public ISort {
public:
	std::string getSortName() { return "���������� ������� ������: "; }
	void sort(std::vector<int>& nums) override;
};


class InsertionSort : public ISort {
public:
	std::string getSortName() { return "���������� ������� �������: "; }
	void sort(std::vector<int>& nums) override;
};


class ShellSort : public ISort {
public:
	std::string getSortName() { return "���������� ������� �����: "; }
	void sort(std::vector<int>& nums) override;
};


class QuickSort : public ISort {
public:
	std::string getSortName() { return "������� ����������: "; }
	void sortPartition(std::vector<int>& arr, int left, int right);
	void sort(std::vector<int>& arr) override;
};


#endif