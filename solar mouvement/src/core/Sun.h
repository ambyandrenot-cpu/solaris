#pragma once
#include <QObject>
#include "SolarCalculator.h"
class Sun: public QObject { Q_OBJECT Q_PROPERTY(double altitude READ altitude NOTIFY changed) Q_PROPERTY(double azimuth READ azimuth NOTIFY changed) Q_PROPERTY(double x READ x NOTIFY changed) Q_PROPERTY(double y READ y NOTIFY changed) Q_PROPERTY(QString phase READ phase NOTIFY changed)
 double m_alt=0,m_az=0,m_x=0,m_y=0; QString m_phase="Night";
public: explicit Sun(QObject*p=nullptr):QObject(p){} void update(const SolarPosition&); double altitude()const{return m_alt;} double azimuth()const{return m_az;} double x()const{return m_x;} double y()const{return m_y;} QString phase()const{return m_phase;} signals:void changed(); };
