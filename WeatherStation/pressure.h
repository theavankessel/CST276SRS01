#ifndef WEATHER_STATION_PRESSURE_H
#define WEATHER_STATION_PRESSURE_H

#include "weatherStationExport.h"
#include <limits>

namespace WeatherStation
{
    class WEATHERSTATION_API Pressure
    {
    public:
        using value_type = double; // inches Hg (29.9213 in Hg == 1 atmosphere)

        static value_type constexpr default_value{ std::numeric_limits<value_type>::quiet_NaN() };

    private:
        value_type value_{ default_value };

    public:
        explicit Pressure(value_type const value);

        bool is_good() const;

		value_type get() const;

		friend bool operator==(const Pressure& lhs, const Pressure& rhs);
		friend bool operator!=(const Pressure& lhs, const Pressure& rhs);
    };
}

#endif // WEATHER_STATION_PRESSURE_H
