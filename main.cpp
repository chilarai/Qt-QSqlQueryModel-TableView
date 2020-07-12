#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>

#include "mysqlmodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);


    if(QSqlDatabase::isDriverAvailable("QMYSQL")){

        QSqlDatabase dbMysql = QSqlDatabase::addDatabase("QMYSQL");
        dbMysql.setHostName("SERVER");
        dbMysql.setPort(3306);
        dbMysql.setDatabaseName("DATABASE");
        dbMysql.setUserName("DB_USER");
        dbMysql.setPassword("DB_PASSWORD");


        if(!dbMysql.open()){
            qDebug() << "Connection to mysql failed";

        }
    }

    MysqlModel mysqlModel;
    mysqlModel.callSql("SELECT * FROM users");

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("MysqlModel", &mysqlModel);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
