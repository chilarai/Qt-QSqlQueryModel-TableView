#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>

#include "mysqlmodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;


    // Mysql connection
    // Change the credentials accrodingly

    if(QSqlDatabase::isDriverAvailable("QMYSQL")){

        QSqlDatabase dbMysql = QSqlDatabase::addDatabase("QMYSQL");
        dbMysql.setHostName("localhost");
        dbMysql.setPort(3306);
        dbMysql.setDatabaseName("grafieks_my");
        dbMysql.setUserName("root");
        dbMysql.setPassword("123@312QQl");


        if(!dbMysql.open()){
            qDebug() << "Connection to mysql failed";

        }
    }

    // Initiate mysql instance
    // And run a default query

    MysqlModel mysqlModel;
    mysqlModel.callSql("SELECT * FROM profiles");

    // Set the model for QML

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
