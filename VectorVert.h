//
// Created by Osip Chin-Go-Pin on 2020-02-26.
//

#ifndef VECTORHORIVERT_VECTORVERT_H
#define VECTORHORIVERT_VECTORVERT_H

#include "Vector.h"

namespace VECTOR_HORI_VERT {
    // derived class : vertical "print" function
    template <class C>
    class VectorVert final : public Vector<C> {
    public:
        // constructors / destructor
        VectorVert() = delete;

        explicit VectorVert(const size_t len) : Vector<C>(len)
        {
        }

        VectorVert(const Vector<C>& other) : Vector<C>(other)
        {
        }

        VectorVert(Vector<C>&& other) : Vector<C>(std::move(other))
        {
        }

        ~VectorVert() = default;

        // operators and methods
        using Vector<C>::operator=;

        void Print(std::ostream& stream) const override;
    };

    template <class C>
    void VectorVert<C>::Print(std::ostream &stream) const {
        for (size_t i = 0; i < this->size(); ++i) {
            stream << this->elements_[i];

            if (i + 1 != this->elements_.size()) {
                stream << "\n";
            }
        }
    }

}

#endif //VECTORHORIVERT_VECTORVERT_H
