/*
 * This file is part of the `src-run/raspetub-arduino-app` package.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, view the LICENSE.md
 * file distributed with this source code.
 */

#include <Arduino.h>
#include <Regexp.h>

namespace Utilities
{
    class Word
    {
        private:
            const char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
            const String vowelRegexps[2] = {"[aeiou](w)", "[bcdfghjklmnpqrstvxz]*(y)[bcdfghjklmnpqrstvxz]*"};
            const char consonants[21] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'x', 'z'};
            String w;
            bool vowel(char character);
            bool consonant(char character);
        public:
            Word();
            Word(String word);
            unsigned int length();
            String value();
            String lower();
            String slice(unsigned int startIndex);
            String slice(unsigned int startIndex, unsigned int endIndex);
            String firstCharacters(unsigned int length);
            bool firstCharacters(String characters);
            char firstCharacter();
            bool firstCharacter(char character);
            String lastCharacters(unsigned int length);
            bool lastCharacters(String characters);
            char lastCharacter();
            bool lastCharacter(char character);
            bool lastCharVowel();
            char penultimateCharacter();
            bool penultimateCharacter(char character);
            bool penultimateCharVowel();
            char antepenultimateCharacter();
            bool antepenultimateCharacter(char character);
            bool antepenultimateCharVowel();
    }; // class Word
    
    class NounPluralizer
    {
        private:
            const String rulesPlural[19][2] = {
                {"(quiz)$", "zes"},
                {"^(ox)$", "en"},
                {"([m|l])ouse$", "ice"},
                {"(matr|vert|ind)ix|ex$", "ices"},
                {"(x|ch|ss|sh)$", "es"},
                {"([^aeiouy]|qu)y$", "ies"},
                {"(hive)$", "s"},
                {"(?:([^f])fe|([lr])f)$", "ves"},
                {"(shea|lea|loa|thie)f$", "ves"},
                {"sis$", "ses"},
                {"([ti])um$", "a"},
                {"(tomat|potat|ech|her|vet)o$", "oes"},
                {"(bu)s$", "ses"},
                {"(alias)$", "es"},
                {"(octop)us$", "i"},
                {"(ax|test)is$", "es"},
                {"(us)$", "es"},
                {"(.+)s$", "s"},
                {"(.+)$", "s"}
            };

            const String rulesSingular[28][2] = {
                {"(quiz)zes$", ""},
                {"(matr)ices$", "ix"},
                {"(vert|ind)ices$", "ex"},
                {"^(ox)en$", ""},
                {"(alias)es$", ""},
                {"(octop|vir)i$", "us"},
                {"(cris|ax|test)es$", "is"},
                {"(shoe)s$", ""},
                {"(o)es$", ""},
                {"(bus)es$", ""},
                {"([m|l])ice$", "ouse"},
                {"(x|ch|ss|sh)es$", ""},
                {"(m)ovies$", "ovie"},
                {"(s)eries$", "eries"},
                {"([^aeiouy]|qu)ies$", "y"},
                {"([lr])ves$", "f"},
                {"(tive)s$", ""},
                {"(hive)s$", ""},
                {"(li|wi|kni)ves$", "fe"},
                {"(shea|loa|lea|thie)ves$", "f"},
                {"(^analy)ses$", "sis"},
                {"((a)naly|(b)a|(d)iagno|(p)arenthe|(p)rogno|(s)ynop|(t)he)ses$", "sis"},
                {"([ti])a$", "um"},
                {"(n)ews$", "ews"},
                {"(h|bl)ouses$", "ouse"},
                {"(corpse)s$", ""},
                {"(us)es$", ""},
                {"(.+)s$", ""}
            };

            const String rulesIrregular[8][2] = {
                {"move$", "moves"},
                {"foot$", "feet"},
                {"goose$", "geese"},
                {"sex$", "sexes"},
                {"child$", "children"},
                {"man$", "men"},
                {"tooth$", "teeth"},
                {"person$", "people"}
            };

            const String rulesUncountable[9] = {
                "sheep", 
                "fish",
                "deer",
                "series",
                "species",
                "money",
                "rice",
                "information",
                "equipment"
            };

            Word w;

            bool ruleUncountable(String pattern, String replace, String &word);
            char ruleRegexMatch(String pattern, MatchState &state);
            String ruleRegexBuild(String endings, MatchState &state);
            String regexPluralize();
        public:
            NounPluralizer();
            NounPluralizer(String word);
            String pluralize();
            String pluralizeConditional(bool conditionalResult = true);

    }; /* class NounPluralizer */

}; /* namespace StringUtils */
