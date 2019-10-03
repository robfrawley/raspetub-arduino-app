/*
 * This file is part of the `src-run/raspetub-arduino-app` package.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, view the LICENSE.md
 * file distributed with this source code.
 */

#include "Utilities.h"

namespace Utilities
{
    Word::Word()
    {
    }

    Word::Word(String word)
    {
        this->w = word;
    }

    bool Word::vowel(char character)
    {
        unsigned int sd = sizeof(vowels) / sizeof(vowels[0]);
        unsigned int sr = sizeof(vowelRegexps) / sizeof(vowelRegexps[0]);
        MatchState matchState;
        char matchResult;
        char matchCapture[1];
        char * word = this->w.toCharArray();

        matchState.Target(word);

        for (unsigned int i = 0; i < sd; i++) {
            if (tolower(character) == tolower(vowels[i])) {
                return true;
            }
        }

        for (unsigned int i = 0; i < sr; i++) {
            matchResult = matchState.Match((vowelRegexps[i]).c_str);

            if (!matchResult) {
                continue;
            }

            matchState.GetCapture(matchCapture, 0);

            if (matchCapture[0] == character) {
                return true;
            }
        }

        return false;
    }

    bool Word::consonant(char character)
    {
        unsigned int sd = sizeof(consonants) / sizeof(consonants);

        for (unsigned int i = 0; i < sd; i++) {
            if (tolower(character) == tolower(consonants[i])) {
                return true;
            }
        }

        return this->vowel(character) ? false : true;
    }

    unsigned int Word::length()
    {
        return w.length();
    }

    String Word::value() {
        return w;
    }

    String Word::lower() {
        String lower = w.value();
        lower.toLowerCase();

        return lower;
    }

    String Word::slice(unsigned int startIndex)
    {
        w.substring(startIndex);
    }

    String Word::slice(unsigned int startIndex, unsigned int endIndex)
    {
        w.substring(startIndex, endIndex);
    }

    String Word::firstCharacters(unsigned int length)
    {
        return w.substring(0, (length >= this->length() ? this->length() : length));
    }

    bool Word::firstCharacters(String characters)
    {
        return characters == this->firstCharacters(characters.length());
    }

    char Word::firstCharacter()
    {
        return (this->slice(0, 1)).c_str;
    }

    bool Word::firstCharacter(char character)
    {
        return character == this->firstCharacter();
    }

    String Word::lastCharacters(unsigned int length)
    {
        return w.substring(length >= this->length() ? 0 : this->length() - length);
    }

    bool Word::lastCharacters(String characters)
    {
        return characters == this->lastCharacters(characters.length());
    }

    char Word::lastCharacter()
    {
        return this->length() >= 1 ? (this->slice(this->length() - 1)).c_str : '\0';
    }

    bool Word::lastCharacter(char character)
    {
        return character == this->lastCharacter();
    }

    bool Word::lastCharVowel()
    {
        return this->vowel(this->lastCharacter());
    }

    char Word::penultimateCharacter()
    {
        return this->length() >= 2 ? (this->slice(this->length() - 2, this->length() - 1)).c_str : '\0';
    }

    bool Word::penultimateCharacter(char character)
    {
        return character == this->penultimateCharacter();
    }

    bool Word::penultimateCharVowel()
    {
        return this->vowel(this->penultimateCharacter());
    }

    char Word::antepenultimateCharacter()
    {
        return this->length() >= 3 ? (this->slice(this->length() - 3, this->length() - 2)).c_str : '\0';
    }

    bool Word::antepenultimateCharacter(char character)
    {
        return character == this->antepenultimateCharacter();
    }

    bool Word::antepenultimateCharVowel()
    {
        return this->vowel(this->antepenultimateCharacter());
    }

    NounPluralizer::NounPluralizer()
    {
        throw;
    }

    NounPluralizer::NounPluralizer(String word)
    {
        Word w(word);
    }

    bool NounPluralizer::ruleUncountable(String pattern, String replace, String &word)
    {
        if (pattern == word) {
            word.replace(pattern.c_str, replace.c_str);
            return true;
        }

        return false;
    }

    char NounPluralizer::ruleRegexMatch(String pattern, MatchState &state)
    {
        state.Target(w.lower().c_str);

        return state.Match(pattern.c_str);
    }

    String NounPluralizer::ruleRegexBuild(String endings, MatchState &state)
    {
        String build;

        for (int i = 0; i < state.level; i++) {
            char group[30];

            state.GetCapture(group, i);
            build = build + String(group);
        }
        
        return build + endings;
    }

    String NounPluralizer::pluralize()
    {
        String wv = w.value();
        int su = sizeof(rulesUncountable) / sizeof(rulesUncountable[0]);
        int si = sizeof(rulesIrregular) / sizeof(rulesIrregular[0]);
        int sp = sizeof(rulesPlural) / sizeof(rulesPlural[0]);
        int sg;

        wv.toLowerCase();

        for (int i = 0; i < su; i++) {
            String word = w.value();

            if (this->ruleUncountable(rulesUncountable[i], rulesUncountable[i], word)) {
                return word;
            }
        }

        for (int i = 0; i < si; i++) {
            MatchState state;

            if (this->ruleRegexMatch(rulesIrregular[i][0], state)) {
                return this->ruleRegexBuild(rulesIrregular[i][1], state);
            }
        }

        for (int i = 0; i < sp; i++) {
            MatchState state;

            if (this->ruleRegexMatch(rulesPlural[i][0], state)) {
                return this->ruleRegexBuild(rulesPlural[i][1], state);
            }
        }

        return w.value();
    }

    String NounPluralizer::pluralizeConditional(bool conditionalResult = true)
    {
        return conditionalResult ? this->pluralize() : w.value();
    }
}; // namespace StringUtils
