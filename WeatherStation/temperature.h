#ifndef WEATHER_STATION_TEMPERATURE_H
#define WEATHER_STATION_TEMPERATURE_H
#include "weatherStationExport.h"

namespace WeatherStation
{
    class WEATHERSTATION_API Temperature
    {
    public:
        using value_type = int; // Celsius

    private:
        static auto constexpr absolute_zero{ -273 }; // -273.15 rounded.

    public:
        static value_type constexpr default_value{ absolute_zero - 1 };

    private:
        value_type value_{ default_value };

    public:
        explicit Temperature(value_type const value);

        value_type get() const;

        bool is_good() const;
    };
}

#endif // WEATHER_STATION_TEMPERATURE_H
