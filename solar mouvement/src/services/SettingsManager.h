#pragma once
#include <QSettings>
class SettingsManager { public: static void save(double lat,double lon){QSettings s("Solaris","Solaris");s.setValue("lat",lat);s.setValue("lon",lon);} };
