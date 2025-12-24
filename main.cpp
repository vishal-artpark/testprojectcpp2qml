#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include"controller.h"
#include<QQmlContext>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    std::unique_ptr<Controller>controller=std::make_unique<Controller>();
    if(!controller){
        qDebug()<<"Failed to allocate memory for Controller!";
        return -1;
    }
    engine.rootContext()->setContextProperty("controller",controller.get());

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
