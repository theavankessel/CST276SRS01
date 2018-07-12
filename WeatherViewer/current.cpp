#include "stdafx.h"
#include <iomanip>
#include "station.h"
#include "current.h"

namespace WeatherViewer
{
    std::ostream& operator<<(std::ostream& os, WeatherViewer::Current const& current)
    {
        /*auto const& station{ current.getStation() };

        auto const temperature{ station.getTemperature() };
        auto const humidity{ station.getHumidity() };
        auto const pressure{ station.getPressure() };*/

        os <<
            std::setw(3) << current.temperature_.get() << " degree C, " <<
            std::setw(3) << current.humidity_.get()    << "%, "  <<
            std::setw(4) << current.pressure_.get()    << " in. Hg";

        return os;
    }

	void Current::Update()
	{
		temperature_ = station_.getTemperature();
		humidity_ = station_.getHumidity();
		pressure_ = station_.getPressure();
	}

	Current::Current(WeatherStation::Station& station): station_{ station }
    {
		station_.Attach(*this);
    }

    WeatherStation::Station const& Current::getStation() const
    {
        return station_;
    }
}
