#include "QiHex.hpp"
#include "Implementations/iHexReader.hpp"


Fossa::QiHex::QiHex::QiHex()
{
}

Fossa::QiHex::Interfaces::IiHexReader* Fossa::QiHex::QiHex::GetReader()
{
	//return nullptr;
	return new Fossa::QiHex::iHexReader();
}
