#pragma once
#include <QDateTime>
#include <optional>
struct SolarPosition { double altitude=0, azimuth=0, declination=0, hourAngle=0; };
struct SolarEvents { std::optional<QTime> sunrise, sunset; };
class SolarCalculator {
public:
 static SolarPosition calculate(const QDateTime&, double latitude, double longitude);
 static SolarEvents events(const QDate&, double latitude, double longitude, const QTimeZone&);
};
