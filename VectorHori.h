//
// Created by Osip Chin-Go-Pin on 2020-02-26.
//

#ifndef VECTORHORIVERT_VECTORHORI_H
#define VECTORHORIVERT_VECTORHORI_H

#include <omp.h>

#include "Vector.h"

namespace VECTOR_HORI_VERT {
    // derived class : horizontal "print" function

    template <class C>
    class VectorHori final : public Vector<C> {
    public:
        // constructors / destructor
        VectorHori() = delete;

        explicit VectorHori (const size_t len) : Vector<C>(len)
        {
        }

        VectorHori(const Vector<C>& other) : Vector<C>(other)
        {
        }

        VectorHori(const VectorHori<C>& other) : Vector<C>(other)
        {
        }

        ~VectorHori() = default;

        // operators and methods
        using Vector<C>::operator=;

        void Print(std::ostream& stream) const override {
            for (size_t i = 0; i < this->elements_.size(); ++i) {
                stream << this->elements_[i];

                if (i + 1 != this->elements_.size()) {
                    stream << ' ';
                }
            }
        }

    };

    template <class T>
    VectorHori<T> operator+(const Vector<T>& lhs, const Vector<T>& rhs) {
        if (lhs.getSize() != rhs.getSize()) {
            throw std::invalid_argument("Different sizes");
        }

        VectorHori<T> result = VectorHori<T>(lhs.getSize());

        #pragma omp parallel for
        for (size_t i = 0; i < result.getSize(); ++i) {
            result[i] = lhs[i] + rhs[i];
        }

        return result;
    }

    template <class T>
    VectorHori<T> operator-(const Vector<T>& lhs, const Vector<T>& rhs) {
        if (lhs.getSize() != rhs.getSize()) {
            throw std::invalid_argument("Different sizes");
        }

        VectorHori<T> result = VectorHori<T>(lhs.getSize());

        #pragma omp parallel for
        for (size_t i = 0; i < result.getSize(); ++i) {
            result[i] = lhs[i] - rhs[i];
        }

        return result;
    }

    template <class T>
    VectorHori<T> operator*(const Vector<T>& lhs, const Vector<T>& rhs) {
        if (lhs.getSize() != rhs.getSize()) {
            throw std::invalid_argument("Different sizes");
        }

        VectorHori<T> result = VectorHori<T>(lhs.getSize());

        #pragma omp parallel for
        for (size_t i = 0; i < result.getSize(); ++i) {
            result[i] = lhs[i] * rhs[i];
        }

        return result;
    }

}

#endif //VECTORHORIVERT_VECTORHORI_H
