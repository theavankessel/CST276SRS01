#ifndef WEATHER_VIEWER_CURRENT_H
#define WEATHER_VIEWER_CURRENT_H

#include <ostream>

namespace WeatherViewer
{
    class Current
    {
        friend std::ostream& operator<<(std::ostream& os, Current const& current);

    private:
        WeatherStation::Station const& station_;

    public:
        explicit Current(WeatherStation::Station const& station);

        WeatherStation::Station const& getStation() const;
    };
}

#endif // WEATHER_VIEWER_CURRENT_H
