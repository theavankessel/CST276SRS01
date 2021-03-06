#include "stdafx.h"
#include <iomanip>
#include "station.h"
#include "statistics.h"

namespace WeatherViewer
{
    std::ostream& operator<<(std::ostream& os, WeatherViewer::Statistics const& statistics)
    {
		
        /*auto const& station{ statistics.getStation() };

        auto const& begin{ statistics.getBegin() };
        auto const& now{ std::chrono::system_clock::now() };

        auto const meanTemperature{ station.getMeanTemperature(begin, now) };
        auto const meanHumidity{ station.getMeanHumidity(begin, now) };
        auto const meanPressure{ station.getMeanPressure(begin, now) };*/

        os <<
            std::setw(3) << statistics.meanTemperature_.get() << " degree C, " <<
            std::setw(3) << statistics.meanHumidity_.get()    << "%, "  <<
            std::setw(4) << statistics.meanPressure_.get()    << " in. Hg";

        return os;
    }

	void Statistics::Update()
	{
		auto const now{ std::chrono::system_clock::now() };
		meanTemperature_ = station_.getMeanTemperature(begin_, now);
		meanHumidity_ = station_.getMeanHumidity(begin_, now);
		meanPressure_ = station_.getMeanPressure(begin_, now);
	}

	Statistics::Statistics(WeatherStation::Station& station) : station_{ station }
	{
		station_.Attach(*this);
	}

    WeatherStation::Station const& Statistics::getStation() const
    {
        return station_;
    }

    std::chrono::system_clock::time_point Statistics::getBegin() const
    {
        return begin_;
    }
}
