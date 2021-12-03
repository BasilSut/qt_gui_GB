#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "saving.h"
#include "checkn.h"
int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    qmlRegisterType<Saving>("SavingData", 1, 0, "Saving");
    qmlRegisterType<CheckN>("Monty", 1, 0, "CheckName");//add component for qml
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);


    //engine.rootContext()->setContextProperty("_name","???");
    engine.load(url);
    return app.exec();
}
