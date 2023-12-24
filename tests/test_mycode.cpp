#include <QtTest/QtTest>
#include "../src/levelfacade.h"

#include <sstream>
using namespace std;

class TestMyCode: public QObject {
    Q_OBJECT
private slots:
    void testGetAllLevels();
    void testOnLevelSelected();
private:
    LevelFacade levelFacade;
};
void TestMyCode::testGetAllLevels() {
    QStringList levels = levelFacade.get_all_levels();

    QVERIFY2(!levels.isEmpty(), "Список уровней не должен быть пустым");
    qDebug() << "Levels in the directory:" << levels;
}

void TestMyCode::testOnLevelSelected() {
    // Тестирование функции onLevelSelected()

    // Создаем QSignalSpy для отслеживания сигнала levelSelected
    QSignalSpy spy(&levelFacade, SIGNAL(levelSelected(QString)));

    // Вызываем onLevelSelected с каким-то уровнем
    QString levelName = "test_level.txt";
    levelFacade.onLevelSelected(levelName);

    // Проверяем, был ли сигнал levelSelected отправлен
    QVERIFY2(spy.count() == 1, "Сигнал levelSelected должен быть отправлен один раз");

    // Проверяем, был ли переданный уровень правильным
    QList<QVariant> arguments = spy.takeFirst();
    QString emittedLevel = arguments.at(0).toString();
    QCOMPARE(emittedLevel, levelName);
}

QTEST_MAIN(TestMyCode)
#include "test_mycode.moc"
