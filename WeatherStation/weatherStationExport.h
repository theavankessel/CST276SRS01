#pragma once

#ifdef WEATHERSTATION_EXPORTS
#	define WEATHERSTATION_API __declspec(dllexport)
#	define WEATHERSTATIONIMP_TEMPLATE
#else
#	define WEATHERSTATION_API __declspec(dllimport)
#	define WEATHERSTATIONIMP_TEMPLATE extern
#endif
