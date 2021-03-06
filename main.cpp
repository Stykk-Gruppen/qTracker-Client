#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include "core/securesocket.h"
#include "model/user.h"
#include "handlers/uploadhandler.h"
#include "handlers/loginHandler.h"
#include "handlers/inviteHandler.h"
#include "handlers/textHandler.h"
#include "handlers/adminHandler.h"
#include "handlers/torrentHandler.h"
#include "handlers/hitandrunHandler.h"
/*! \mainpage QTracker-Client Documentation
 *
 * \section intro_sec Introduction
 *
 * This document describes all the C++ classes used in our QTracker-Client.<br>
 * There are no ads on this page, but due to the unforunate name of the software,
 * adblockers will disable some functionality. Disable it to view the webpage as
 * intended.
 */
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    //TorrentFileParser *t = new TorrentFileParser();
    //t->setTorrentPass("test");
   // t->getTorrentFile(2);
    //t->createFile();
    //t->getInfoHashFromFile("file:://home/tarves/ttest.torrent");

    QScopedPointer<SecureSocket> secureSocket(new SecureSocket);
    QScopedPointer<UploadHandler> uploadHandler(new UploadHandler);
    QScopedPointer<User> user(new User());
    QScopedPointer<InviteHandler> inviteHandler(new InviteHandler());
    QScopedPointer<LoginHandler> loginHandler(new LoginHandler());
    QScopedPointer<TextHandler> textHandler(new TextHandler());
    QScopedPointer<AdminHandler> adminHandler(new AdminHandler());
    QScopedPointer<TorrentHandler> torrentHandler(new TorrentHandler());
    QScopedPointer<HitAndRunHandler> hitAndRunHandler(new HitAndRunHandler());

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/view/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.rootContext()->setContextProperty("secureSocket", secureSocket.data());
    engine.rootContext()->setContextProperty("uploadHandler", uploadHandler.data());
    engine.rootContext()->setContextProperty("user", user.data());
    engine.rootContext()->setContextProperty("loginHandler", loginHandler.data());
    engine.rootContext()->setContextProperty("inviteHandler", inviteHandler.data());
    engine.rootContext()->setContextProperty("textHandler", textHandler.data());
    engine.rootContext()->setContextProperty("adminHandler", adminHandler.data());
    engine.rootContext()->setContextProperty("torrentHandler", torrentHandler.data());
    engine.rootContext()->setContextProperty("hitAndRunHandler", hitAndRunHandler.data());

    engine.load(url);

    return app.exec();
}
