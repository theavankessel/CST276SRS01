#ifndef WEATHER_STATION_HUMIDITY_H
#define WEATHER_STATION_HUMIDITY_H

namespace WeatherStation
{
    class Humidity
    {
    public:
        using value_type = int; // percent [0, 100]

        static auto constexpr default_value{ -1 };

    private:
        value_type const value_{ default_value };

    public:
        explicit Humidity(value_type const value);

        value_type get() const;

        bool is_good() const;
    };
}

#endif // WEATHER_STATION_HUMIDITY_H
