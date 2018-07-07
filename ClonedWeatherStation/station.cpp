#include "stdafx.h"
#include <cassert>
#include <limits>
#include "gsl.h"
#include "temperature.h"
#include "humidity.h"
#include "pressure.h"
#include "station.h"
#include "statistics.h"
#include "current.h"

namespace WeatherStation
{
    Station::Station() noexcept: weather_viewer_statistics_{ *this }, weather_viewer_current_{ *this }
    {
    }

    void Station::measure()
    {
        Temperature const temperature{ getTemperature() };
        Humidity const humidity{ getHumidity() };
        Pressure const pressure{ getPressure() };

        WeatherStation::Record record{ temperature, humidity, pressure };

        history_.emplace_back(record);
    }

    WeatherViewer::Statistics Station::getWeatherViewerStatistics() const
    {
        return weather_viewer_statistics_;
    }

    WeatherViewer::Current Station::getWeatherViewerCurrent() const
    {
        return weather_viewer_current_;
    }

    Temperature Station::getTemperature() const
    {
        auto const result{ Temperature(Temperature::default_value) }; // TODO: Create a mock temperature reading.
        return result;
    }

    Humidity Station::getHumidity() const
    {
        auto const result{ Humidity(Humidity::default_value) }; // TODO: Create a mock humidity reading.
        return result;
    }

    Pressure Station::getPressure() const {
        auto const result{ Pressure(Pressure::default_value) }; // TODO: Create a mock pressure reading.
        return result;
    }

    Temperature Station::getMeanTemperature
    (
        std::chrono::system_clock::time_point const t0,
        std::chrono::system_clock::time_point const t1
    ) const
    {
        auto sum{ 0LL };
        auto total_duration{ std::chrono::system_clock::duration::zero() };

        auto period_start{ t0 };
        for (auto const& weather_record: history_)
        {
            auto const record_timepoint{ weather_record.getTimepoint() };
            if (record_timepoint >= period_start && record_timepoint < t1)
            {
                auto const value{ weather_record.getTemperature() };

                if (value.is_good())
                {
                    auto const duration{ record_timepoint - period_start };

                    auto const weighted_value{ duration.count() * value.get() };

                    if (weighted_value < 0)
                    {
                        assert(sum >= std::numeric_limits<decltype(sum)>::min() - weighted_value);
                    }
                    else
                    {
                        assert(sum < std::numeric_limits<decltype(sum)>::max() - weighted_value);
                    }

                    sum += weighted_value;
                    total_duration += duration;
                }

                period_start = record_timepoint;
            }
        }

        auto const duration_count{ total_duration.count() };
        auto mean{ Temperature::default_value };
        if (duration_count > 0)
        {
            mean = gsl::narrow<Temperature::value_type>(sum / duration_count);
        }
        auto const result{ Temperature(mean) };

        return result;
    }

    Humidity Station::getMeanHumidity
    (
        std::chrono::system_clock::time_point const t0,
        std::chrono::system_clock::time_point const t1
    ) const
    {
        auto sum{ 0LL };
        auto total_duration{ std::chrono::system_clock::duration::zero() };

        auto period_start{ t0 };
        for (auto const& weather_record: history_)
        {
            auto const record_timepoint{ weather_record.getTimepoint() };
            if (record_timepoint >= period_start && record_timepoint < t1)
            {
                auto const value{ weather_record.getHumidity() };

                if (value.is_good())
                {
                    auto const duration{ record_timepoint - period_start };

                    auto const weighted_value{ duration.count() * value.get() };

                    if (weighted_value < 0)
                    {
                        assert(sum >= std::numeric_limits<decltype(sum)>::min() - weighted_value);
                    }
                    else
                    {
                        assert(sum < std::numeric_limits<decltype(sum)>::max() - weighted_value);
                    }

                    sum += weighted_value;
                    total_duration += duration;
                }

                period_start = record_timepoint;
            }
        }

        auto const duration_count{ total_duration.count() };
        auto mean{ Humidity::default_value };
        if (duration_count > 0)
        {
            mean = gsl::narrow<Humidity::value_type>(sum / duration_count);
        }
        auto const result{ Humidity(mean) };

        return result;
    }

    Pressure Station::getMeanPressure
    (
        std::chrono::system_clock::time_point const t0,
        std::chrono::system_clock::time_point const t1
    ) const
    {
        auto sum{ 0.0 };
        auto total_duration{ std::chrono::system_clock::duration::zero() };

        auto period_start{ t0 };
        for (auto const& weather_record: history_)
        {
            auto const record_timepoint{ weather_record.getTimepoint() };
            if (record_timepoint >= period_start && record_timepoint < t1)
            {
                auto const value{ weather_record.getPressure() };

                if (value.is_good())
                {
                    auto const duration{ record_timepoint - period_start };

                    auto const weighted_value{ duration.count() * value.get() };

                    if (weighted_value < 0.0)
                    {
                        assert(sum >= std::numeric_limits<decltype(sum)>::min() - weighted_value);
                    }
                    else
                    {
                        assert(sum < std::numeric_limits<decltype(sum)>::max() - weighted_value);
                    }

                    sum += weighted_value;
                    total_duration += duration;
                }

                period_start = record_timepoint;
            }
        }

        auto const duration_count{ total_duration.count() };
        auto mean{ Pressure::default_value };
        if (duration_count > 0)
        {
            mean = sum / duration_count;
        }
        auto const result{ Pressure(mean) };

        return result;
    }
}
