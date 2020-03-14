//
// Created by Osip on 2020-02-26.
//

#ifndef VECTORHORIVERT_VECTORFACTORY_H
#define VECTORHORIVERT_VECTORFACTORY_H

#include <memory>

#include "Vector.h"
#include "VectorHori.h"
#include "VectorVert.h"

namespace VectorHoriVert {

    // abstract vector factory
    template <class C>
    struct Factory {
        virtual std::shared_ptr<Vector<C>> Create(const size_t len) = 0;

        virtual ~Factory() = default;
    };


    // horizontal vector factory
    template <class C>
    struct HoriFactory : public Factory<C> {
        std::shared_ptr<Vector<C>> Create(const size_t len) {
            return std::make_shared<VectorHori<C>>(len);
        }

        ~HoriFactory() = default;
    };


    //vertical vector factory
    template <class C>
    struct VertFactory : public Factory<C> {
        std::shared_ptr<Vector<C>> Create(const size_t len) {
            return std::make_shared<VectorVert<C>>(len);
        }

        ~VertFactory() = default;
    };
}

#endif //VECTORHORIVERT_VECTORFACTORY_H
