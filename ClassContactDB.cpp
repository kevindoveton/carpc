// --------------------------
// Kevin Doveton
// Copyright 2015
// --------------------------

#include "ClassContactDB.h"

ContactDB :: ContactDB()
{

}

QByteArray ContactDB :: getPictureFromNumber(QString number)
{
	QByteArray picture = "";

	try
	{
		SQLite::Database db(DBPATH);

		SQLite::Statement query(db, "SELECT photo FROM contacts WHERE mobileNumber == ?");
		query.bind(1, number.toStdString());

		while (query.executeStep())
		{
			picture = query.getColumn(0);
		}
	}

	catch (std::exception& e)
	{
		std::cout << "getPictureFromNumber - Exception: " << e.what() << std::endl;

	}


	if (picture == "")
	{
		if (number.data()[0] == '+')
		{
			number = "0" + number.split("+61")[1];
		}
		else
		{
			number = number.replace(0, 1, "+61");
		}
		try
		{
			SQLite::Database db(DBPATH);

			SQLite::Statement query(db, "SELECT photo FROM contacts WHERE mobileNumber == ?");
			query.bind(1, number.toStdString());

			while (query.executeStep())
			{
				picture = query.getColumn(0);
			}
		}

		catch (std::exception& e)
		{
			std::cout << "getPictureFromNumber - Exception: " << e.what() << std::endl;

		}
	}

	return picture;
}

QString ContactDB :: getNameFromNumber(QString number)
{
	QString name = "";
	try
	{
		SQLite::Database db(DBPATH);

		SQLite::Statement query(db, "SELECT firstName, lastName FROM contacts WHERE mobileNumber == ?");
		query.bind(1, number.toStdString());

		while (query.executeStep())
		{
			QString firstName = query.getColumn(0).getText();
			QString lastName = query.getColumn(1).getText();
			name = firstName + " " + lastName;
		}
	}

	catch (std::exception& e)
	{
		std::cout << "getNameFromNumber - Exception: " << e.what() << std::endl;

	}


	if (name == "")
	{
		if (number.data()[0] == '+')
		{
			number = "0" + number.split("+61")[1];
		}
		else
		{
			number = number.replace(0, 1, "+61");
		}
		try
		{
			SQLite::Database db(DBPATH);

			SQLite::Statement query(db, "SELECT firstName, lastName FROM contacts WHERE mobileNumber == ?");
			query.bind(1, number.toStdString());

			while (query.executeStep())
			{
				QString firstName = query.getColumn(0).getText();
				QString lastName = query.getColumn(1).getText();
				name = firstName + " " + lastName;
			}
		}

		catch (std::exception& e)
		{
			std::cout << "getNameFromNumber - Exception: " << e.what() << std::endl;

		}
	}

	return (name);
}
