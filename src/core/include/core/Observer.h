#pragma once

namespace core
{
    template <typename Data>
    class Observer
    {
    public:
        virtual void notify(const Data& data) = 0;
    };
}
