#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QVariant>
#include <QVector>
#include <QMap>

class Database {
public:
    static Database& instance();
    bool initialize();
    bool isInitialized() const;

    // User Authentication
    bool createUser(const QString& email, const QString& password, 
                   const QString& firstName, const QString& lastName);
    bool loginUser(const QString& email, const QString& password);
    bool isValidBMCCEmail(const QString& email);

    // Profile Management
    struct UserProfile {
        int id;
        QString email;
        QString firstName;
        QString lastName;
        QString major;
        QVector<QString> skillsToOffer;
        QVector<QString> skillsToLearn;
    };

    bool updateProfile(int userId, const QString& major);
    bool addSkill(int userId, const QString& skill, bool isOffering);
    bool removeSkill(int userId, const QString& skill);
    UserProfile getUserProfile(int userId);
    
    // Matching System
    struct Match {
        int userId;
        QString name;
        QString major;
        QVector<QString> matchingSkills;
        float matchScore;
    };

    QVector<Match> findMatches(int userId);

private:
    Database(); // Private constructor for singleton
    ~Database();
    Database(const Database&) = delete;
    Database& operator=(const Database&) = delete;

    bool createTables();
    QString hashPassword(const QString& password); // Basic password hashing
    QString extractNameFromEmail(const QString& email);
    
    QSqlDatabase db;
    bool initialized;
};

#endif // DATABASE_H