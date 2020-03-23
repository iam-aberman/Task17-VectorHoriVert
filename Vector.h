//
// Created by Osip Chin-Go-Pin on 2020-02-26.
//

#ifndef VECTORHORIVERT_VECTOR_H
#define VECTORHORIVERT_VECTOR_H

#include <iostream>
#include <vector>

namespace VectorHoriVert {
    // abstract vector class
    template <class C>
    class Vector {
    public:
        // constructors / destructor
        Vector() = delete;

        explicit Vector(const size_t len) {
            elements_.resize(len);
        }

        Vector(const Vector<C>& other) {
            elements_ = other.getElements();
        }

        virtual ~Vector() {}

        // "get" methods
        size_t getSize() const {
            return elements_.size();
        }

        std::vector<C> getElements() const {
            return elements_;
        }

        // operators
        C operator[](const int index) const {
            return elements_.at(index);
        }

        C& operator[](const int index) {
            return elements_.at(index);
        }

        Vector& operator=(const Vector<C>& other) {
            elements_ = other.getElements();

            return *this;
        }

        // methods
        virtual void Print(std::ostream& stream) const = 0;

        void PushBack(C newElement) {
            elements_.push_back(newElement);
        }
        
        typename std::vector<C>::iterator begin() {
            return elements_.begin();
        }
        
        typename std::vector<C>::iterator end() {
            return elements_.end();
        }

    protected:
        std::vector<C> elements_;
    };

}


#endif //VECTORHORIVERT_VECTOR_H
