#include "database.h"
#include <QCryptographicHash>
#include <QDebug>
#include <QRegularExpression>
#include <QSqlError>

Database& Database::instance() {
    static Database instance;
    return instance;
}

Database::Database() : initialized(false) {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("skillswap.db");
}

Database::~Database() {
    if (db.isOpen()) {
        db.close();
    }
}

bool Database::initialize() {
    if (initialized) return true;

    if (!db.open()) {
        qDebug() << "Failed to open database:" << db.lastError().text();
        return false;
    }

    if (!createTables()) {
        qDebug() << "Failed to create tables";
        return false;
    }

    initialized = true;
    return true;
}

bool Database::createTables() {
    QSqlQuery query;
    
    // Users table
    if (!query.exec("CREATE TABLE IF NOT EXISTS users ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                   "email TEXT UNIQUE NOT NULL,"
                   "password TEXT NOT NULL,"
                   "firstName TEXT NOT NULL,"
                   "lastName TEXT NOT NULL,"
                   "major TEXT,"
                   "created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP)")) {
        qDebug() << "Error creating users table:" << query.lastError().text();
        return false;
    }

    // Skills table
    if (!query.exec("CREATE TABLE IF NOT EXISTS skills ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                   "user_id INTEGER,"
                   "skill TEXT NOT NULL,"
                   "is_offering BOOLEAN,"
                   "FOREIGN KEY(user_id) REFERENCES users(id))")) {
        qDebug() << "Error creating skills table:" << query.lastError().text();
        return false;
    }

    return true;
}

bool Database::isValidBMCCEmail(const QString& email) {
    QRegularExpression regex("^[a-zA-Z0-9._%+-]+@stu\\.bmcc\\.cuny\\.edu$");
    return regex.match(email).hasMatch();
}

QString Database::hashPassword(const QString& password) {
    QByteArray hash = QCryptographicHash::hash(
        password.toUtf8(), 
        QCryptographicHash::Sha256
    );
    return QString(hash.toHex());
}

bool Database::createUser(const QString& email, const QString& password,
                        const QString& firstName, const QString& lastName) {
    if (!isValidBMCCEmail(email)) {
        qDebug() << "Invalid BMCC email format";
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO users (email, password, firstName, lastName) "
                 "VALUES (:email, :password, :firstName, :lastName)");
    
    query.bindValue(":email", email.toLower());
    query.bindValue(":password", hashPassword(password));
    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);

    if (!query.exec()) {
        qDebug() << "Error creating user:" << query.lastError().text();
        return false;
    }

    return true;
}

bool Database::loginUser(const QString& email, const QString& password) {
    QSqlQuery query;
    query.prepare("SELECT id FROM users WHERE email = :email AND password = :password");
    
    query.bindValue(":email", email.toLower());
    query.bindValue(":password", hashPassword(password));

    if (!query.exec() || !query.next()) {
        return false;
    }

    return true;
}
