#include "stdafx.h"
#include "pressure.h"
#include <limits>

namespace WeatherStation
{
    Pressure::Pressure(value_type const value):
        value_{ value }
    {
    }

    Pressure::value_type Pressure::get() const
    {
        return value_;
    }

    bool Pressure::is_good() const
    {
        auto const result{ value_ >= 0.0 && value_< std::numeric_limits<value_type>::max() };
        return result;
    }

}
