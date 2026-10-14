#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QTimer>
#include "core/SolarSystemController.h"
int main(int argc,char**argv){QGuiApplication app(argc,argv);SolarSystemController c;QTimer timer;QObject::connect(&timer,&QTimer::timeout,&c,&SolarSystemController::tick);timer.start(1000);QQmlApplicationEngine e;e.rootContext()->setContextProperty("solar",&c);e.loadFromModule("Solaris","Main");if(e.rootObjects().isEmpty())return 1;return app.exec();}
