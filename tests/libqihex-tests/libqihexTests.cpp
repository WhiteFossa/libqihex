#include <QString>
#include <QtTest>

// Including library header.
#include <QiHex.hpp>

/**
 * @brief Class with tests for QiHex library.
 */
class libqihexTests : public QObject
{
	Q_OBJECT

	public:
		libqihexTests();

	private Q_SLOTS:

		/**
		 * @brief Tests initialization.
		 */
		void initTestCase();

		/**
		 * @brief Tests cleanup.
		 */
		void cleanupTestCase();

		void justATest();

	private:
		/**
		 * @brief Pointer to library instance.
		 */
		Fossa::QiHex::QiHex* _lib;
};

libqihexTests::libqihexTests()
{
}

void libqihexTests::initTestCase()
{
	_lib = new Fossa::QiHex::QiHex();
}

void libqihexTests::cleanupTestCase()
{
	delete _lib;
}

void libqihexTests::justATest()
{
	QVERIFY2(_lib->Test(10, 20) == 30, "Failure");
}

QTEST_APPLESS_MAIN(libqihexTests)

#include "libqihexTests.moc"
