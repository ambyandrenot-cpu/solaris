#include "SimulationClock.h"
SimulationClock::SimulationClock(QObject*p):QObject(p),m_time(QDateTime::currentDateTime()){}
void SimulationClock::tick(qint64 ms){if(m_running)m_time=m_time.addMSecs(qRound64(ms*m_speed));emit changed();}
void SimulationClock::setDateTime(QDateTime v){if(v.isValid()){m_time=v;emit changed();}} void SimulationClock::setSpeed(double v){m_speed=qBound(0.0,v,3600.0);emit changed();} void SimulationClock::pause(){m_running=false;emit changed();} void SimulationClock::resume(){m_running=true;emit changed();} void SimulationClock::advanceMinutes(int n){m_time=m_time.addSecs(n*60);emit changed();}
