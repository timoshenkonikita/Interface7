#include "levelfacade.h"
#include <QDir>

LevelFacade::LevelFacade(QObject *parent)
    : QObject(parent),
    directoryPath("C:/Users/79233/Desktop/lect6/levels") {
    // Соединяем сигнал выбора уровня из MainMenu со слотом обработки выбора уровня
}

void LevelFacade::onLevelSelected(const QString& levelName) {
    // Передаем выбранный уровень для загрузки в GameView через сигнал
    emit levelSelected(levelName);
}

QStringList LevelFacade::get_all_levels(){
    QDir directory(directoryPath);

    // Фильтр для выбора только файлов с расширением .txt
    QStringList filters;
    filters << "*.txt";
    directory.setNameFilters(filters);

    // Получаем список файлов уровней в директории
    return directory.entryList();
}
