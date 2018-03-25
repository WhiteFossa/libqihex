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

		/**
		 * @brief Tests 8 bit iHEX read.
		 */
		void Test8BitRead();

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

void libqihexTests::Test8BitRead()
{
	Fossa::QiHex::Interfaces::IiHexReader* reader = _lib->GetReader();

	QVector<Fossa::QiHex::Interfaces::IiHexReadonlyDataset> resultDatasets = reader->ReadFile(":/fossa/libqihex-tests/resources/8bit_sequential.hex");

	// One data block
	QVERIFY2(resultDatasets.count() == 1, "Wrong datablocks count.");

	delete reader;
}

QTEST_APPLESS_MAIN(libqihexTests)

#include "libqihexTests.moc"
