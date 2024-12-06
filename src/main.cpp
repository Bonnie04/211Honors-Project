#include <QApplication>
#include <QDebug>
#include "database.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Initialize database
    Database& db = Database::instance();
    if (!db.initialize()) {
        qDebug() << "Failed to initialize database";
        return 1;
    }

    // Test user creation
    bool userCreated = db.createUser(
        "test.student@stu.bmcc.cuny.edu",
        "password123",
        "Test",
        "Student"
    );
    qDebug() << "User created:" << userCreated;

    // Test login
    bool loginSuccess = db.loginUser(
        "test.student@stu.bmcc.cuny.edu",
        "password123"
    );
    qDebug() << "Login successful:" << loginSuccess;

    return app.exec();
}