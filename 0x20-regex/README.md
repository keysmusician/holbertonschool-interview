<p align="center">
  <a href=#>
    <img src="https://user-images.githubusercontent.com/74752740/175812508-dc2482bf-bd5b-4c0a-b075-1bede95c488e.png" alt="Holberton School logo">
  </a>
</p>

# 0x20. RegEx

## Table of Contents
* [Prompt](#prompt)
* [Files](#files)
* [Author](#author)

## Prompt
Write a function that checks whether a given pattern matches a given string.

Prototype: `int regex_match(char const *str, char const *pattern);`

- `str` is the string to scan
- `pattern` is the regular expression

Your function must return `1` if the pattern matches the string, or `0` if it doesn’t.

`str` can be empty, and can contain any ASCII character except for '.' and '*'.

`pattern` can be empty, and can contain any ASCII character, including '.' and '\*'. The regular expression matching must support the characters '.' and '\*'.
- '.' matches any single character
- '*' matches zero or more of the preceding pattern character


## Files
* `regex.c`
* `regex.h`
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
