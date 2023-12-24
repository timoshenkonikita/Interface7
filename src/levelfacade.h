#ifndef LEVELFACADE_H
#define LEVELFACADE_H

#include <QObject>
#include <string>
using namespace std;

class LevelFacade : public QObject {
    Q_OBJECT
public:
    explicit LevelFacade(QObject *parent = nullptr);

    void setupGame(); // Функция для настройки игры
    QStringList get_all_levels();
signals:
    void levelSelected(const QString &levelName);

public slots:
    void onLevelSelected(const QString &levelName);

private:
    const QString directoryPath;
};

#endif // LEVELFACADE_H
