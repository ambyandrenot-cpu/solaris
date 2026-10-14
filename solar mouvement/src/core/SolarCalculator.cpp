#include "SolarCalculator.h"
#include <QtMath>
namespace { constexpr double pi=3.14159265358979323846, rad=pi/180.0; double norm(double x){while(x<0)x+=360;while(x>=360)x-=360;return x;} }
SolarPosition SolarCalculator::calculate(const QDateTime& local, double lat, double lon) {
    const double jd=local.toUTC().toMSecsSinceEpoch()/86400000.0+2440587.5, n=jd-2451545.0;
    const double g=norm(357.529+0.98560028*n), q=norm(280.459+0.98564736*n);
    const double L=norm(q+1.915*qSin(g*rad)+0.020*qSin(2*g*rad));
    const double e=23.439-0.00000036*n, dec=qAsin(qSin(e*rad)*qSin(L*rad))/rad;
    const double eq=4*(qSin(2*q*rad)*0.0167/2 - 2*qSin(g*rad)*0.0167) / rad;
    const double minutes=local.time().msecsSinceStartOfDay()/60000.0;
    double solar=minutes+eq+4*lon-local.offsetFromUtc()/60.0, ha=solar/4-180;
    while(ha<-180)ha+=360; while(ha>180)ha-=360;
    const double alt=qAsin(qSin(lat*rad)*qSin(dec*rad)+qCos(lat*rad)*qCos(dec*rad)*qCos(ha*rad))/rad;
    double az=qAtan2(qSin(ha*rad),qCos(ha*rad)*qSin(lat*rad)-qTan(dec*rad)*qCos(lat*rad))/rad+180;
    return {alt,norm(az),dec,ha};
}
SolarEvents SolarCalculator::events(const QDate& date,double lat,double lon,const QTimeZone& zone){
    SolarEvents out; double x=(qCos(90.833*rad)/(qCos(lat*rad)*qCos(0.0))-qTan(lat*rad)*qTan(0.0)); Q_UNUSED(x);
    for(int m=0;m<1440;m+=2){ QDateTime t(date,QTime(0,0).addSecs(m*60),zone); auto a=calculate(t,lat,lon).altitude; auto b=calculate(t.addSecs(120),lat,lon).altitude;
      if(!out.sunrise && a<=-0.833 && b>-0.833) out.sunrise=t.time(); if(!out.sunset && a>=-0.833 && b<-0.833) out.sunset=t.time(); }
    return out;
}
