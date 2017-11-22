/*
Workshop 9 : Smart Pointers
File : List.h
Name : Samantha West (#128111168)
Date : 11/21/2017
Description -> Merge two lists and use a smart pointer to ensure that memory
is deallocated in the possible handling of an exception. Includes program
component of quadratic complexity and a smart pointer to move an object.
*/

#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <memory>

namespace w9 {
	template <typename T>
	class List {
		std::vector<T> list;
	public:
		List() { }
		List(const char* fn) {
			std::ifstream file(fn);
			if (!file)
				throw std::string("*** Failed to open file ") +
				std::string(fn) + std::string(" ***");
			while (file) {
				T e;
				if (e.load(file))
					list.push_back(*new T(e));
			}
		}
		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }
		// +=(T* p) to  unique ptr parameter :) 
		void operator+=(std::unique_ptr<T>& p) {
			list.push_back(*p);
		}
		void display(std::ostream& os) const {
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.display(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const List<T>& l) {
		l.display(os);
		return os;
	}
}
