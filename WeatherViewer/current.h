#ifndef WEATHER_VIEWER_CURRENT_H
#define WEATHER_VIEWER_CURRENT_H

#include <ostream>
#include "observer.h"
#include "temperature.h"
#include "pressure.h"
#include "humidity.h"

namespace WeatherViewer
{
    class Current : public Observer
    {
        friend std::ostream& operator<<(std::ostream& os, Current const& current);

    private:
        WeatherStation::Station& station_;

		WeatherStation::Temperature temperature_{ WeatherStation::Temperature::default_value };
		WeatherStation::Humidity humidity_{ WeatherStation::Humidity::default_value };
		WeatherStation::Pressure pressure_{ WeatherStation::Pressure::default_value };

		void Update() override;

    public:
        explicit Current(WeatherStation::Station& station);

        WeatherStation::Station const& getStation() const;
    };
}

#endif // WEATHER_VIEWER_CURRENT_H
