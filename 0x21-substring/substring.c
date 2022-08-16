#include "substring.h"

/**
 * substring_matches - Confirms if any combination of the arrangement of the
 * provided words can form a substring which exists in another string
 *
 * @s: String
 * @words: List of equal length words
 * @nb_words: The number of words in `words`
 * @word_length: The length of the words in `words`
 *
 * Return: Whether the a substring formed by `words` may be found in `s`
 */
boolean substring_matches(
	const char *s, const char **words, int nb_words, int word_length)
{
	boolean_list words_matched = calloc(nb_words, sizeof(boolean));
	boolean any_word_matched, any_word_remains;
	index_t words_;
	const char *word;

	while (TRUE)
	{
		any_word_matched = FALSE;
		any_word_remains = FALSE;
		for (words_ = 0; words_ < nb_words; words_++)
		{
			if (words_matched[words_])
				continue;
			any_word_remains = TRUE;
			word = words[words_];
			if (strstr(s, word) - s == 0)
			{
				words_matched[words_] = TRUE;
				s += word_length;
				any_word_matched = TRUE;
				break;
			}
		}
		if (!any_word_matched)
		{
			free(words_matched);
			if (any_word_remains)
				return (FALSE);
			else
				return (TRUE);
		}
	}
}

/**
 * find_substring - Finds all substrings which match any concatenation of all
 * words in `words`
 *
 * @s: A string in which to find substrings
 * @words: An array of strings of equal length which all substrings must be a
 * concatenation arrangement of. All words must be used once in the
 * concatenation
 * @nb_words: The number of strings in `words`
 * @param: The address at which to store the number of elements in the returned
 * array
 *
 * Return: Each index in `s` at which any concatenation of all words in `words`
 * was found, or NULL if no match was found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	index_t s_, match_, search_end_;
	boolean_list s_indexes;
	int *match_indexes, word_length;

	if (!s or !words or !nb_words or !n)
		return (NULL);

	*n = 0;
	word_length = strlen(words[0]);
	search_end_ = (int)strlen(s) - word_length * nb_words;
	s_indexes = calloc(search_end_, sizeof(char));

	for (s_ = 0; s[s_]; s_++)
	{
		if (s_ > search_end_ and *n == 0)
			return (NULL);
		if (substring_matches(s + s_, words, nb_words, word_length))
		{
			*n = *n + 1;
			s_indexes[s_] = TRUE;
		}
	}
	match_indexes = malloc(sizeof(int) * (*n));
	match_ = 0;
	for (s_ = 0; s_ <= search_end_; s_++)
		if (s_indexes[s_])
			match_indexes[match_++] = s_;

	free(s_indexes);

	return (match_indexes);
}
