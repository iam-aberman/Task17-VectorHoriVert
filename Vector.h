//
// Created by Osip Chin-Go-Pin on 2020-02-26.
//

#ifndef VECTORHORIVERT_VECTOR_H
#define VECTORHORIVERT_VECTOR_H

#include <iostream>
#include <vector>
#include <utility>

namespace VECTOR_HORI_VERT {
    // abstract vector class
    template <class C>
    class Vector {
    public:
        // constructors / destructor
        Vector() = delete;
        explicit Vector(const size_t len);

        Vector(const Vector& other);
        Vector(Vector&& temp) noexcept;

        virtual ~Vector() = default;

        // "get" methods
        size_t size() const;

        const std::vector<C>& getElements() const;

        // operators
        C operator[](const size_t index) const;
        C& operator[](const size_t index);

        Vector& operator=(const Vector& other);
        Vector& operator=(Vector&& temp) noexcept;

        // methods
        virtual void Print(std::ostream& stream) const = 0;

        void PushBack(C newElement);
        void PushBack(C&& temp);

        typename std::vector<C>::iterator begin();
        typename std::vector<C>::iterator end();

        typename std::vector<C>::const_iterator begin() const;
        typename std::vector<C>::const_iterator end() const;

    protected:
        std::vector<C> elements_;
    };

    template <class C>
    Vector<C>::Vector(const size_t len) {
        elements_.resize(len);
    }

    template <class C>
    Vector<C>::Vector(const Vector<C> &other) {
        elements_ = other.getElements();
    }

    template <class C>
    Vector<C>::Vector(Vector<C> &&temp) noexcept {
        elements_ = std::move(temp.elements_);
    }

    template <class C>
    size_t Vector<C>::size() const {
        return elements_.size();
    }

    template <class C>
    const std::vector<C>& Vector<C>::getElements() const {
        return elements_;
    }

    template <class C>
    C Vector<C>::operator[](const size_t index) const {
        return elements_.at(index);
    }

    template <class C>
    C& Vector<C>::operator[](const size_t index) {
        return elements_.at(index);
    }

    template <class C>
    Vector<C>& Vector<C>::operator=(const Vector<C>& other) {
        elements_ = other.getElements();

        return *this;
    }

    template <class C>
    Vector<C>& Vector<C>::operator=(Vector<C>&& temp) noexcept {
        elements_ = std::move(temp.elements_);

        return *this;
    }

    template <class C>
    void Vector<C>::PushBack(C newElement) {
        elements_.push_back(newElement);
    }

    template <class C>
    void Vector<C>::PushBack(C&& temp) {
        elements_.push_back(std::move(temp));
    }

    template <class C>
    typename std::vector<C>::iterator Vector<C>::begin() {
        return elements_.begin();
    }

    template <class C>
    typename std::vector<C>::iterator Vector<C>::end() {
        return elements_.end();
    }

    template <class C>
    typename std::vector<C>::const_iterator Vector<C>::begin() const {
        return elements_.begin();
    }

    template <class C>
    typename std::vector<C>::const_iterator Vector<C>::end() const {
        return elements_.end();
    }

}


#endif //VECTORHORIVERT_VECTOR_H
