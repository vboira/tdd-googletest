#include "gmock/gmock.h"
#include "Soundex.h"

TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
	Soundex soundex;

	auto encoded = soundex.encode("A");
}
