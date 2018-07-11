#ifndef WEATHER_STATION_STATION_H
#define WEATHER_STATION_STATION_H

#include <vector>
#include <chrono>
#include "temperature.h"
#include "humidity.h"
#include "pressure.h"
#include "record.h"
#include "subject.h"
#include "weatherStationExport.h"

//#include "statistics.h" // TODO: Delete #include.
//#include "current.h" // TODO: Delete #include.

//WEATHERSTATIONIMP_TEMPLATE template class WEATHERSTATION_API std::vector<std::reference_wrapper<WeatherStation::Record>>;


namespace WeatherStation
{
    class WEATHERSTATION_API Station : public Subject // DONE: Make this a ConcreteSubject.
    {
    private:
		std::chrono::system_clock::time_point const begin_{ std::chrono::system_clock::now() };
        std::vector<std::reference_wrapper <WeatherStation::Record>> history_{};

        //WeatherViewer::Current weather_viewer_current_;       // TODO: Remove this ConcreteObserver.
        //WeatherViewer::Statistics weather_viewer_statistics_; // TODO: Remove this ConcreteObserver.

    public:
        Station() noexcept;

       // WeatherViewer::Statistics getWeatherViewerStatistics() const;
       // WeatherViewer::Current getWeatherViewerCurrent() const;

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
