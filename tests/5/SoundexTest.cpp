#include "gmock/gmock.h"
#include "Soundex.h"

using namespace testing;

class SoundexEncoding: public Test {
	public:
		Soundex soundex;
};

// Al heredar de Test, TEST_F, habilita dins de la macro utilitzar soundex, com si la classe ja estigues instanciada!!!
TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
	ASSERT_THAT(soundex.encode("A"), Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {
	ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}

///TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
///	Soundex soundex;
///
///	auto encoded = soundex.encode("A");
///
///	ASSERT_THAT(encoded, testing::Eq("A"));
///}
