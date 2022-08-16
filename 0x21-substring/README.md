<p align="center">
  <a href=#>
    <img src="https://user-images.githubusercontent.com/74752740/175812508-dc2482bf-bd5b-4c0a-b075-1bede95c488e.png" alt="Holberton School logo">
  </a>
</p>

# 0x21. Substring with concatenated words

## Table of Contents
* [Prompt](#prompt)
* [Files](#files)
* [Author](#author)

## Prompt
Write a function that finds all the possible substrings containing a list of words, within a given string.

Prototype: `int *find_substring(char const *s, char const **words, int nb_words, int *n);`

- `s` is the string to scan.
- `words` is the array of words all substrings must be a concatenation arrangement of.
- `nb_words` is the number of elements in the array words.
- `n` holds the address at which to store the number of elements in the returned array.

Your function must return an allocated array, storing each index in `s`, at which a substring was found. If no solution is found, `NULL` can be returned.
All words in the array words are the same length.
A valid substring of `s` is the concatenation of each word in words exactly once and without any intervening characters.

## Files
* `main.c`
* `substring.c`
* `substring.h`
* `README.md`

## Author
Justin Masayda [@keysmusician](https://github.com/keysmusician)
<pre align="center">
        _   _       _   _   _       _   _       _   _   _     
    ___//|_//|_____//|_//|_//|_____//|_//|_____//|_//|_//|___ 
   /  /// ///  /  /// /// ///  /  /// ///  /  /// /// ///  / |
  /  ||/ ||/  /  ||/ ||/ ||/  /  ||/ ||/  /  ||/ ||/ ||/  / / 
 /___/___/___/___/___/___/___/___/___/___/___/___/___/___/ /  
 |___|___|___|___|___|___|___|___|___|___|___|___|___|___|/   

</pre>
<p><span style="font-family: 'Lucida Console'; line-height: 14px; font-size: 14px; display: inline-block;">&nbsp;</span></p>
