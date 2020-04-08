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

        VectorHori(Vector<C>&& other) : Vector<C>(std::move(other))
        {
        }

        ~VectorHori() = default;

        // operators and methods
        using Vector<C>::operator=;

        void Print(std::ostream& stream) const override;

    };

    template <class C>
    void VectorHori<C>::Print(std::ostream &stream) const{
        for (size_t i = 0; i < this->elements_.size(); ++i) {
            stream << this->elements_[i];

            if (i + 1 != this->elements_.size()) {
                stream << ' ';
            }
        }
    }


    template <class C>
    VectorHori<C> operator+(const Vector<C>& lhs, const Vector<C>& rhs) {
        if (lhs.size() != rhs.size()) {
            throw std::invalid_argument("Different sizes");
        }
        
        VectorHori<C> result = VectorHori<C>(lhs.size());

        size_t i = 0;
        
        omp_set_num_threads(4);
        
        #pragma omp parallel for shared(lhs, rhs, result) shared(i)
        for (i = 0; i < result.size(); ++i) {
            result[i] = lhs[i] + rhs[i];
        }

        return result;
    }

    template <class C>
    VectorHori<C> operator-(const Vector<C>& lhs, const Vector<C>& rhs) {
        if (lhs.size() != rhs.size()) {
            throw std::invalid_argument("Different sizes");
        }

        VectorHori<C> result = VectorHori<C>(lhs.size());

        size_t i = 0;
        
        omp_set_num_threads(4);
        
        #pragma omp parallel for shared(lhs, rhs, result) shared(i)
        for (i = 0; i < result.size(); ++i) {
            result[i] = lhs[i] - rhs[i];
        }

        return result;
    }

    template <class C>
    VectorHori<C> operator*(const Vector<C>& lhs, const Vector<C>& rhs) {
        if (lhs.size() != rhs.size()) {
            throw std::invalid_argument("Different sizes");
        }

        VectorHori<C> result = VectorHori<C>(lhs.size());

        size_t i = 0;
        
        omp_set_num_threads(4);
        
        #pragma omp parallel for shared(lhs, rhs, result) shared(i)
        for (i = 0; i < result.size(); ++i) {
            result[i] = lhs[i] * rhs[i];
        }

        return result;
    }

}

#endif //VECTORHORIVERT_VECTORHORI_H
