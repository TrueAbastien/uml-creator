#pragma once

namespace core
{
    template <typename Data>
    class Observer
    {
    public:
        virtual void update(const Data& data) = 0;
    };
}
