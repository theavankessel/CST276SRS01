#ifndef WEATHER_STATION_STATION_H
#define WEATHER_STATION_STATION_H

#include <vector>
#include <chrono>
#include "temperature.h"
#include "humidity.h"
#include "pressure.h"
#include "record.h"
#include "statistics.h" // TODO: Delete #include.
#include "current.h" // TODO: Delete #include.

namespace WeatherStation
{
    class Station // TODO: Make this a ConcreteSubject.
    {
    private:
        std::vector<WeatherStation::Record> history_{};

        WeatherViewer::Current weather_viewer_current_;       // TODO: Remove this ConcreteObserver.
        WeatherViewer::Statistics weather_viewer_statistics_; // TODO: Remove this ConcreteObserver.

    public:
        Station() noexcept;

        WeatherViewer::Statistics getWeatherViewerStatistics() const;
        WeatherViewer::Current getWeatherViewerCurrent() const;

        Temperature getTemperature() const;
        Humidity getHumidity() const;
        Pressure getPressure() const;

        Temperature getMeanTemperature(std::chrono::system_clock::time_point const t0, std::chrono::system_clock::time_point const t1) const;
        Humidity getMeanHumidity(std::chrono::system_clock::time_point const t0, std::chrono::system_clock::time_point const t1) const;
        Pressure getMeanPressure(std::chrono::system_clock::time_point const t0, std::chrono::system_clock::time_point const t1) const;

        void measure();
    };
}

#endif // WEATHER_STATION_STATION_H
