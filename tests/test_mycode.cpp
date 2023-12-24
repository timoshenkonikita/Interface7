#include <QtTest/QtTest>
#include "../src/mycode.h"

#include <sstream>
using namespace std;

class TestMyCode: public QObject {
    Q_OBJECT
private slots:
    void testName() {
        stringstream input;
        stringstream output;
        input << "Никита";

        hello(input, output);

        qDebug() << "Actual output:" << QString::fromStdString(output.str());
        QVERIFY2(output.str() == "Привет, Никита!", "Actual output does not match expected UTF-8 string");
    }
    void testHelloWithEmptyName() {
        stringstream input;
        stringstream output;
        input << "";

        hello(input, output);

        qDebug() << "Actual output:" << QString::fromStdString(output.str());
        QString expectedOutput = "Извините, имя не было введено.";
        QVERIFY2(output.str() == expectedOutput.toUtf8().constData(), "Actual output does not match expected UTF-8 string");
    }
    void testHelloWithSpecialName() {
        stringstream input;
        stringstream output;
        input << "Чудакин";

        hello(input, output);

        qDebug() << "Actual output:" << QString::fromStdString(output.str());
        QString expectedOutput = "Привет, Здравствуйте, Игорь Андреевич!";
        QVERIFY2(output.str() == expectedOutput.toUtf8().constData(), "Actual output does not match expected UTF-8 string");
    }

};



QTEST_MAIN(TestMyCode)
#include "test_mycode.moc"
