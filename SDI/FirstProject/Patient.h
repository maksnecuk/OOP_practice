#ifndef PATIENT_H
#define PATIENT_H

#include <QString>

class Patient
{
public:

    Patient();
    Patient(int id, const QString& lastName, const QString& firstName, const QString& middleName,
            const QString& address, const QString& phoneNumber, int medicalCardNumber, const QString& diagnosis);
    Patient(const Patient& other);
    ~Patient();


    int getId() const;
    QString getLastName() const;
    QString getFirstName() const;
    QString getMiddleName() const;
    QString getAddress() const;
    QString getPhoneNumber() const;
    int getMedicalCardNumber() const;
    QString getDiagnosis() const;


    void setId(int id);
    void setLastName(const QString& lastName);
    void setFirstName(const QString& firstName);
    void setMiddleName(const QString& middleName);
    void setAddress(const QString& address);
    void setPhoneNumber(const QString& phoneNumber);
    void setMedicalCardNumber(int medicalCardNumber);
    void setDiagnosis(const QString& diagnosis);

private:
    int id;
    QString lastName;
    QString firstName;
    QString middleName;
    QString address;
    QString phoneNumber;
    int medicalCardNumber;
    QString diagnosis;
};

#endif
