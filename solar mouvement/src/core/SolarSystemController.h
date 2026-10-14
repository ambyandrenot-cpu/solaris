#pragma once
#include <QObject>
#include "Sun.h"
#include "SimulationClock.h"
class SolarSystemController: public QObject { Q_OBJECT Q_PROPERTY(Sun* sun READ sun CONSTANT) Q_PROPERTY(QDateTime dateTime READ dateTime NOTIFY changed) Q_PROPERTY(double latitude READ latitude WRITE setLatitude NOTIFY changed) Q_PROPERTY(double longitude READ longitude WRITE setLongitude NOTIFY changed) Q_PROPERTY(double speed READ speed WRITE setSpeed NOTIFY changed) Q_PROPERTY(bool running READ running NOTIFY changed) Q_PROPERTY(QString sunrise READ sunrise NOTIFY changed) Q_PROPERTY(QString sunset READ sunset NOTIFY changed) Q_PROPERTY(int minuteOfDay READ minuteOfDay NOTIFY changed)
 Sun m_sun; SimulationClock m_clock; double m_lat=-18.8792,m_lon=47.5079; QString m_sunrise="--:--",m_sunset="--:--";
 void refresh(); public: explicit SolarSystemController(QObject*p=nullptr); Sun*sun(){return &m_sun;} QDateTime dateTime()const{return m_clock.dateTime();} double latitude()const{return m_lat;} double longitude()const{return m_lon;} double speed()const{return m_clock.speed();}
 public: bool running()const{return m_clock.running();} QString sunrise()const{return m_sunrise;} QString sunset()const{return m_sunset;} int minuteOfDay()const{return m_clock.dateTime().time().hour()*60+m_clock.dateTime().time().minute();}
 public slots: void tick(); void setLatitude(double);void setLongitude(double);void setSpeed(double);void pauseResume();void advance(int);void setDateTime(QDateTime);void setMinuteOfDay(int);void realTime();void sunriseTime();void solarNoon();void sunsetTime();signals:void changed();};
