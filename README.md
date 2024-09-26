# Braille-Translator

Braille Translator

This is a command-line Braille-to-English and English-to-Braille translator built in C++. The application can automatically detect the input type (Braille or English) and convert it accordingly, without requiring any mode selection from the user. This project was created for the Shopify Eng Intern Challenge (Fall-Winter 2025).

Features:

Bi-directional Translation: Converts Braille to English text and vice-versa.
Auto-Detection: The program automatically determines if the input is in Braille or English.
Support for Uppercase Letters and Numbers: Capitalization and number prefixes are handled appropriately in both conversions.
Efficient CLI Usage: The program reads input directly from the command line, making it simple to use in terminal environments.
Flexible Input Format: For Braille input, users can either provide Braille characters with spaces between them or as a continuous string of six-character Braille cells.

Usage:

To translate from English to Braille:
Copy code
./braille_translator "Hello World"

To translate from Braille to English:
Copy code
./braille_translator "0.....0.0...00....0.00..0..0.."

Technology:

C++
Standard libraries (unordered_map, string, cctype)

How It Works:

The program utilizes two unordered maps for Braille-to-English and English-to-Braille conversions. It splits the input into chunks (of six characters for Braille) and translates each chunk sequentially. Capital letters and digits are identified through specific Braille patterns and handled with prefixes.
