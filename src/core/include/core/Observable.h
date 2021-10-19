#pragma once
#include "core/Observer.h"

#include <vector>

namespace core
{
    template <typename Data>
    class Observable
    {
    private:
        std::vector<Observer<Data>*> m_observers;

    public:
        void add(Observer<Data>* obs)
        {
            m_observers.push_back(obs);
        }
        void clean()
        {
            m_observers.clear();
        }

        void notify(const Data& data)
        {
            for (auto obs : m_observers)
            {
                obs->update(data);
            }
        }
    };
}
