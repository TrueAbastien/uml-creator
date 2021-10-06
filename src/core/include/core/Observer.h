#pragma once

namespace core
{
    template <typename Data>
    class Observer
    {
    public:
        void notify(const Data& data);
    };
}
