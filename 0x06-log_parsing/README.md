<p align="center">
  <a href=#>
    <img src="https://intranet.hbtn.io/assets/holberton-logo-full-black-157ccfa3d2134776c1e3f78c0fe682968e8848b64fcacc6187976044f75f35a8.png" alt="Holberton School logo">
  </a>
</p>

# 0x06. Log Parsing

## Table of Contents
* [Prompt](#prompt)
* [Files](#files)
* [Author](#author)

## Prompt
Write a script that reads stdin line by line and computes metrics:

Input format: <IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size> (if the format is not this one, the line must be skipped)
After every 10 lines and/or a keyboard interruption (CTRL + C), print these statistics from the beginning:
Total file size: File size: <total size>
where <total size> is the sum of all previous <file size> (see input format above)
Number of lines by status code:
possible status code: 200, 301, 400, 401, 403, 404, 405 and 500
if a status code doesn’t appear or is not an integer, don’t print anything for this status code
format: <status code>: <number>
status codes should be printed in ascending order

## Files
* `0-generator.py`
* `0-stats.py`
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
