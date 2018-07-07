#ifndef WEATHER_STATION_TEMPERATURE_H
#define WEATHER_STATION_TEMPERATURE_H

namespace WeatherStation
{
    class Temperature
    {
    public:
        using value_type = int; // Celsius

    private:
        static auto constexpr absolute_zero{ -273 }; // -273.15 rounded.

    public:
        static auto constexpr default_value{ absolute_zero - 1 };

    private:
        value_type value_{ default_value };

    public:
        explicit Temperature(value_type const value);

        value_type get() const;

        bool is_good() const;
    };
}

#endif // WEATHER_STATION_TEMPERATURE_H
