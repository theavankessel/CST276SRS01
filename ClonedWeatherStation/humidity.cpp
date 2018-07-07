#include "stdafx.h"
#include "humidity.h"
#include <limits>

namespace WeatherStation
{
    Humidity::Humidity(value_type const value) :
        value_{ value }
    {
    }

    Humidity::value_type Humidity::get() const
    {
        return value_;
    }

    bool Humidity::is_good() const
    {
        auto const result{ value_ >= 0 && value_<= 100 };
        return result;
    }
}
