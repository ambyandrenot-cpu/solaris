#include <QtTest>
#include "core/SolarCalculator.h"
#include "core/SimulationClock.h"
class TestSolar:public QObject{Q_OBJECT private slots:
 void validPosition(){auto p=SolarCalculator::calculate(QDateTime(QDate(2024,6,21),QTime(12,0),QTimeZone("UTC")),0,0);QVERIFY(p.altitude>60);QVERIFY(p.azimuth>=0&&p.azimuth<360);}
 void clockWraps(){SimulationClock c;c.setDateTime(QDateTime(QDate(2024,1,1),QTime(23,59),QTimeZone("UTC")));c.advanceMinutes(2);QCOMPARE(c.dateTime().date(),QDate(2024,1,2));}
 void limits(){auto p=SolarCalculator::calculate(QDateTime::currentDateTime(),90,0);QVERIFY(p.altitude>=-90&&p.altitude<=90);}
};
QTEST_MAIN(TestSolar)
#include "tst_Solar.moc"
