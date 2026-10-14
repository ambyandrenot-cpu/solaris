#pragma once
#include <QObject>
#include <QDateTime>
class SimulationClock: public QObject { Q_OBJECT Q_PROPERTY(QDateTime dateTime READ dateTime NOTIFY changed) Q_PROPERTY(double speed READ speed WRITE setSpeed NOTIFY changed) Q_PROPERTY(bool running READ running NOTIFY changed)
 QDateTime m_time; double m_speed=60; bool m_running=true;
public: explicit SimulationClock(QObject* p=nullptr); QDateTime dateTime()const{return m_time;} double speed()const{return m_speed;} bool running()const{return m_running;}
 void tick(qint64 ms); public slots: void setDateTime(QDateTime); void setSpeed(double); void pause(); void resume(); void advanceMinutes(int); signals: void changed(); };
