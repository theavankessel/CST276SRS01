#ifndef WEATHER_VIEWER_STATISTICS_H
#define WEATHER_VIEWER_STATISTICS_H

#include <ostream>
#include <chrono>
#include "observer.h"
#include "temperature.h"
#include "humidity.h"
#include "pressure.h"

namespace WeatherStation
{
    class Station;
}

namespace WeatherViewer
{
    class Statistics : public Observer
    {
        friend std::ostream& operator<<(std::ostream& os, Statistics const& statistics);

    private:
        WeatherStation::Station& station_;
        std::chrono::system_clock::time_point const begin_{ std::chrono::system_clock::now() };
		WeatherStation::Temperature meanTemperature_{ WeatherStation::Temperature::default_value };
		WeatherStation::Humidity meanHumidity_{ WeatherStation::Humidity::default_value };
		WeatherStation::Pressure meanPressure_{ WeatherStation::Pressure::default_value };

		void Update() override;

    public:
        explicit Statistics(WeatherStation::Station& station);

        WeatherStation::Station const& getStation() const;
        std::chrono::system_clock::time_point getBegin() const;
    };
}

#endif // WEATHER_VIEWER_STATISTICS_H
