#include "Sun.h"
void Sun::update(const SolarPosition&p){m_alt=p.altitude;m_az=p.azimuth;m_x=0.5+0.46*qSin(p.hourAngle*3.14159265/180);m_y=0.78-0.68*qSin(qMax(0.0,p.altitude)*3.14159265/180);m_phase=m_alt<-6?"Night":m_alt<0?"Twilight":m_alt<10?"Sunrise/Sunset":"Day";emit changed();}
