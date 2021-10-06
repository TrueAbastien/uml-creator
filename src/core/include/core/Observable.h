#pragma once
#include "core/Observer.h"

#include <vector>

namespace core
{
    template <typename Data>
    class Observable
    {
    private:
        std::vector<Obsserver*> m_observers(0);

    public:
        void add(Observer* obs)
        {
            m_observers.push_back(obs);
        }
        void clean()
        {
            m_observers.clear();
        }

        void notifyAll(const Data& data)
        {
            for (auto obs : m_observers)
            {
                obs->notify(data);
            }
        }
    };
}
