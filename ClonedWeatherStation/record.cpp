#include "stdafx.h"
#include <chrono>
#include "record.h"
#include <chrono>
#include "temperature.h"
#include "humidity.h"
#include "pressure.h"

namespace WeatherStation
{
    Record::Record
    (
        Temperature const temperature,
        Humidity const humidity,
        Pressure const pressure
    ):
        temperature_{ temperature },
        humidity_{ humidity },
        pressure_{ pressure }
    {
    }

    std::chrono::system_clock::time_point Record::getTimepoint() const
    {
        return timepoint_;
    }

    Temperature Record::getTemperature() const
    {
        return temperature_;
    }

    Humidity Record::getHumidity() const
    {
        return humidity_;
    }

    Pressure Record::getPressure() const
    {
        return pressure_;
    }
}
