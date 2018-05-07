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

		/**
		 * @brief Tests that CRC error can be detected.
		 */
		void TestCRCError();

		/**
		 * @brief Tests that even characters line will be detected.
		 */
		void TestEvenCharactersCount();

		/**
		 * @brief Tests that line without starting colon will be detected.
		 */
		void TestStartingColon();

		/**
		 * @brief Tests that line with wrong characters will be detected.
		 */
		void TestWrongCharactersLine();

		/**
		 * @brief Tests that line with wrong record length will be detected.
		 */
		void TestWrongReclen();

		/**
		 * @brief Tests that line with wrong record type will be detected.
		 */
		void TestWrongRectype();

		/**
		 * @brief Tests that wrong offset in EoF record will be detected.
		 */
		void TestEOFWrongOffset();

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

	Fossa::QiHex::Interfaces::IiHexReadonlyDataset* resultDataset = reader->ReadFile(":/fossa/libqihex-tests/resources/8bit_sequential.hex");

	// 8 bit mode
	QVERIFY2(resultDataset->Mode == Fossa::QiHex::iHexAddressingMode::Mode8bit, "Must be 8 bit mode.");

	// 32 bytes
	QVERIFY2(32 == resultDataset->Data.size(), "File contains 32 bytes of data.");

	// Data
	QVERIFY2(0x00 == resultDataset->Data[0x00], "Wrong data.");
	QVERIFY2(0x01 == resultDataset->Data[0x01], "Wrong data.");
	QVERIFY2(0x02 == resultDataset->Data[0x02], "Wrong data.");
	QVERIFY2(0x03 == resultDataset->Data[0x03], "Wrong data.");
	QVERIFY2(0x04 == resultDataset->Data[0x04], "Wrong data.");
	QVERIFY2(0x05 == resultDataset->Data[0x05], "Wrong data.");
	QVERIFY2(0x06 == resultDataset->Data[0x06], "Wrong data.");
	QVERIFY2(0x07 == resultDataset->Data[0x07], "Wrong data.");
	QVERIFY2(0x08 == resultDataset->Data[0x08], "Wrong data.");
	QVERIFY2(0x09 == resultDataset->Data[0x09], "Wrong data.");
	QVERIFY2(0x0A == resultDataset->Data[0x0A], "Wrong data.");
	QVERIFY2(0x0B == resultDataset->Data[0x0B], "Wrong data.");
	QVERIFY2(0x0C == resultDataset->Data[0x0C], "Wrong data.");
	QVERIFY2(0x0D == resultDataset->Data[0x0D], "Wrong data.");
	QVERIFY2(0x0E == resultDataset->Data[0x0E], "Wrong data.");
	QVERIFY2(0x0F == resultDataset->Data[0x0F], "Wrong data.");
	QVERIFY2(0xFF == resultDataset->Data[0x10], "Wrong data.");
	QVERIFY2(0xFE == resultDataset->Data[0x11], "Wrong data.");
	QVERIFY2(0xFD == resultDataset->Data[0x12], "Wrong data.");
	QVERIFY2(0xFC == resultDataset->Data[0x13], "Wrong data.");
	QVERIFY2(0xFB == resultDataset->Data[0x14], "Wrong data.");
	QVERIFY2(0xFA == resultDataset->Data[0x15], "Wrong data.");
	QVERIFY2(0xF9 == resultDataset->Data[0x16], "Wrong data.");
	QVERIFY2(0xF8 == resultDataset->Data[0x17], "Wrong data.");
	QVERIFY2(0xF7 == resultDataset->Data[0x18], "Wrong data.");
	QVERIFY2(0xF6 == resultDataset->Data[0x19], "Wrong data.");
	QVERIFY2(0xF5 == resultDataset->Data[0x1A], "Wrong data.");
	QVERIFY2(0xF4 == resultDataset->Data[0x1B], "Wrong data.");
	QVERIFY2(0xF3 == resultDataset->Data[0x1C], "Wrong data.");
	QVERIFY2(0xF2 == resultDataset->Data[0x1D], "Wrong data.");
	QVERIFY2(0xF1 == resultDataset->Data[0x1E], "Wrong data.");
	QVERIFY2(0xF0 == resultDataset->Data[0x1F], "Wrong data.");

	delete resultDataset;
	delete reader;
}

void libqihexTests::TestCRCError()
{
	Fossa::QiHex::Interfaces::IiHexReader* reader = _lib->GetReader();

	try
	{
		reader->ReadFile(":/fossa/libqihex-tests/resources/crc_error.hex");
		QFAIL("CRC error not detected.");
	}
	catch (...)
	{
	}

	delete reader;
}

void libqihexTests::TestEvenCharactersCount()
{
	Fossa::QiHex::Interfaces::IiHexReader* reader = _lib->GetReader();

	try
	{
		reader->ReadFile(":/fossa/libqihex-tests/resources/even_characters_error.hex");
		QFAIL("Even characters line not detected.");
	}
	catch (...)
	{
	}
}

void libqihexTests::TestStartingColon()
{
	Fossa::QiHex::Interfaces::IiHexReader* reader = _lib->GetReader();

	try
	{
		reader->ReadFile(":/fossa/libqihex-tests/resources/no_colon_error.hex");
		QFAIL("Line without colon not detected.");
	}
	catch (...)
	{
	}
}

void libqihexTests::TestWrongCharactersLine()
{
	Fossa::QiHex::Interfaces::IiHexReader* reader = _lib->GetReader();

	try
	{
		reader->ReadFile(":/fossa/libqihex-tests/resources/wrong_characters_error.hex");
		QFAIL("Line with wrong characters not detected.");
	}
	catch (...)
	{
	}
}

void libqihexTests::TestWrongReclen()
{
	Fossa::QiHex::Interfaces::IiHexReader* reader = _lib->GetReader();

	try
	{
		reader->ReadFile(":/fossa/libqihex-tests/resources/wrong_reclen_error.hex");
		QFAIL("Wrong record length not detected.");
	}
	catch (...)
	{
	}
}

void libqihexTests::TestWrongRectype()
{
	Fossa::QiHex::Interfaces::IiHexReader* reader = _lib->GetReader();

	try
	{
		reader->ReadFile(":/fossa/libqihex-tests/resources/wrong_rectype_error.hex");
		QFAIL("Wrong record type not detected.");
	}
	catch (...)
	{
	}
}

void libqihexTests::TestEOFWrongOffset()
{
Fossa::QiHex::Interfaces::IiHexReader* reader = _lib->GetReader();

	try
	{
		reader->ReadFile(":/fossa/libqihex-tests/resources/eof_wrong_offset.hex");
		QFAIL("Wrong offset for EoF record not detected.");
	}
	catch (...)
	{
	}
}

QTEST_APPLESS_MAIN(libqihexTests)

#include "libqihexTests.moc"
